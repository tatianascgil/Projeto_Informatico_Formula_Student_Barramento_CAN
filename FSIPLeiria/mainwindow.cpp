#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QCoreApplication>
#include <QtWidgets>
#include <QComboBox>
#include <QPushButton>
#include <QDir>
#include <QSettings>
#include <QDebug>

#include <QTextStream>
#include <QStandardItemModel>
#include <QStandardItem>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "modulo.h"
#include "ui_modulo.h"
#include "vercarro.h"
#include "ui_vercarro.h"
#include "criarcarro.h"
#include "ui_criarcarro.h"
#include "estatisticas.h"
#include "ui_estatisticas.h"

#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    ui->btnSaveFile->setVisible(false);

    // Connect the modelChanged() signal of the table view's model to a slot
    connect(ui->tableView->model(), SIGNAL(modelChanged()), this, SLOT(updateSaveButtonVisibility()));

    // Connect the currentIndexChanged signal of the comboBoxCarro to a custom slot
    connect(ui->comboBoxCarro, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &MainWindow::handleComboBoxIndexChanged);

    // Update the initial visibility of the button
    handleComboBoxIndexChanged(ui->comboBoxCarro->currentIndex());


    // Load the last selected option:
    QString lastSelectedOption = loadLastSelectedOption();
    populateComboBox(lastSelectedOption);

    // Connect the currentIndexChanged signal of comboBoxCarro to a lambda slot:
    QObject::connect(ui->comboBoxCarro, QOverload<int>::of(&QComboBox::currentIndexChanged), this, [this](int index) {
        QString selectedOption = ui->comboBoxCarro->currentText();
        saveLastSelectedOption(selectedOption);
    });


}

MainWindow::~MainWindow()
{
    delete ui;
}

struct MyData {
    int intValue;
    char stringValue[16];
};\

void MainWindow::on_btnReadFile_clicked()
{
    // Open a file dialog to select a file
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"), "",
                                                    tr("Excel Files (*.xls *.xlsx *.csv);;Binary Files (*.bin)"));

    if (fileName.isEmpty()) {
        return;
    }

    // Determine the file type
    QString fileType = QFileInfo(fileName).suffix();

    // Read the binary data from the file
    if (fileType == "bin") {
        // Read the binary data from the file
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to open file."));
            return;
        }

        QByteArray data = file.readAll();
        file.close();

        // Convert binary data to hexadecimal format
        QString hexData = QString(data.toHex());

        // Split the hex data into rows of 16 bytes
        QStringList hexRows;
        for (int i = 0; i < hexData.size(); i += 32) {
            QString row = hexData.mid(i, 32);
            hexRows.append(row);
        }

        // Create a model to store the data
        QStandardItemModel* model = new QStandardItemModel();

        model->setColumnCount(16);
        model->setRowCount(hexRows.size());

        // Set the headers of the model
        QStringList headers;
        for (int i = 0; i < 16; ++i) {
            headers << QString("%1").arg(i, 2, 16, QLatin1Char('0')).toUpper();
        }
        model->setHorizontalHeaderLabels(headers);

        // Set the data of the model
        for (int row = 0; row < hexRows.size(); ++row) {
            QString hexRow = hexRows.at(row);
            QStringList hexCells = hexRow.split("", Qt::SkipEmptyParts);
            for (int col = 0; col < 16; ++col) {
                if (col*2+1 < hexCells.size()) {
                    QString hexByte = hexCells.at(col*2) + hexCells.at(col*2+1);
                    QString textByte = QString::number(hexByte.toUInt(nullptr, 16));
                    QStandardItem* item = new QStandardItem(textByte);
                    model->setItem(row, col, item);
                }
            }
        }

        // Set the model for the existing table view
        ui->tableView->setModel(model);
        // Set the table view to resize the rows and columns to fit the contents
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();

    } else if (fileType == "xls" || fileType == "xlsx") {
        QXlsx::Document xlsx(fileName);
        if (xlsx.load()) {
            QStringList headers;
            QList<QList<QString>> rows;
            for (int row = 1; row <= xlsx.dimension().rowCount(); ++row) {
                QList<QString> rowData;
                for (int col = 1; col <= xlsx.dimension().columnCount(); ++col) {
                    QXlsx::Cell *cell = xlsx.cellAt(row, col);
                    if (cell != nullptr) {
                        QString value = cell->value().toString();
                        if (row == 1) {
                            headers.append(value);
                        } else {
                            rowData.append(value);
                        }
                    }
                }
                if (row != 1 && !rowData.isEmpty()) {
                    rows.append(rowData);
                }
            }

            // Create a table model and add the headers and rows
            QStandardItemModel *model = new QStandardItemModel(rows.count(), headers.count(), this);
            model->setHorizontalHeaderLabels(headers);
            for (int i = 0; i < rows.count(); ++i) {
                QList<QString> row = rows.at(i);
                for (int j = 0; j < row.count(); ++j) {
                    QString value = row.at(j);
                    QStandardItem *item = new QStandardItem(value);
                    model->setItem(i, j, item);
                }
            }
            // Set the model for the existing table view
            ui->tableView->setModel(model);
            // Set the table view to resize the rows and columns to fit the contents
            ui->tableView->resizeColumnsToContents();
            ui->tableView->resizeRowsToContents();
        }

    }
    else if (fileType == "csv") {
        // Read the CSV data from the file
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly)) {
            QMessageBox::critical(this, tr("Error"), tr("Unable to open file."));
            return;
        }

        QTextStream stream(&file);
        QStringList headers;
        QList<QList<QString>> rows;
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values;
            QChar delimiter;
            for (int i = 0; i < line.length(); ++i) {
                QChar c = line.at(i);
                if (c == ',' || c == ';' || c == '\t') {
                    if (!delimiter.isNull() && delimiter != c) {
                        // If multiple delimiters are used in the same line, assume the most frequently used delimiter
                        // as the actual delimiter.
                        break;
                    }
                    delimiter = c;
                }
            }
            if (delimiter.isNull()) {
                // No delimiter found, treat the whole line as a single value.
                values.append(line);
            } else {
                values = line.split(delimiter);
            }
            if (headers.isEmpty()) {
                headers = values;
            } else {
                QList<QString> row;
                for (int i = 0; i < values.count(); ++i) {
                    QString value = values.at(i);
                    if (!value.isEmpty()) {
                        row.append(value);
                    }
                }
                if (!row.isEmpty()) {
                    rows.append(row);
                }
            }
        }
        file.close();

        // Create a table model and add the headers and rows
        QStandardItemModel *model = new QStandardItemModel(rows.count(), headers.count(), this);
        model->setHorizontalHeaderLabels(headers);
        for (int i = 0; i < rows.count(); ++i) {
            QList<QString> row = rows.at(i);
            for (int j = 0; j < row.count(); ++j) {
                QString value = row.at(j);
                QStandardItem *item = new QStandardItem(value);
                model->setItem(i, j, item);
            }
        }
        // Set the model for the existing table view
        ui->tableView->setModel(model);
        // Set the table view to resize the rows and columns to fit the contents
        ui->tableView->resizeColumnsToContents();
        ui->tableView->resizeRowsToContents();
    }


    else {
        // Show an error message if the file type is not supported
        QMessageBox::critical(this, tr("Error"), tr("Tipo de ficheiro não suportado."));
        return;
    }


    // qt.core.qobject.connect: QObject::connect: Cannot connect (nullptr)::modelChanged() to MainWindow::updateSaveButtonVisibility()
    //Corrigir warning
    updateSaveButtonVisibility();
}




void MainWindow::updateSaveButtonVisibility()
{
    bool hasData = ui->tableView->model() && ui->tableView->model()->rowCount() > 0;
    ui->btnSaveFile->setVisible(hasData);
}



void MainWindow::on_btnSaveFile_clicked()
{
    // Create a QFileDialog object to allow the user to select the output file location and name.
    QFileDialog fileDialog;
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setNameFilter(tr("Excel files (.xlsx);;CSV files (.csv);;Binary files (.bin)"));
    fileDialog.setDefaultSuffix("xlsx");
    QString fileName = fileDialog.getSaveFileName();

    // Check if the output file name is valid.
    if (fileName.isEmpty()) {
        return;
    }

    // Determine the file format based on the selected file extension.
    QString fileExt = QFileInfo(fileName).suffix();
    if (fileExt == "csv") {
        // Update the CSV file.
        // Open the file for reading and writing.
        QFile csvFile(fileName);
        if (csvFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            // Store the updated header names and data rows in separate QStringLists.
            QStringList headerNames;
            QStringList dataRows;
            QAbstractItemModel* model = ui->tableView->model();
            for (int col = 0; col < model->columnCount(); ++col) {
                headerNames << model->headerData(col, Qt::Horizontal).toString();
            }
            for (int row = 0; row < model->rowCount(); ++row) {
                QStringList rowData;
                for (int col = 0; col < model->columnCount(); ++col) {
                    QModelIndex index = model->index(row, col);
                    QVariant data = model->data(index);
                    if (data.isValid()) {
                        rowData << data.toString();
                    }
                }
                dataRows << rowData.join(",");
            }

            // Write the updated header names and data rows to the file.
            QTextStream csvStream(&csvFile);
            csvFile.seek(0);
            csvStream << headerNames.join(",") << "\n";
            csvStream << dataRows.join("\n") << "\n";
            csvFile.close();
        }
    } else if (fileExt == "xls") {
        // Save to an XLS file using the QXlsx library.
        QXlsx::Document xlsDoc;
        xlsDoc.addSheet("Sheet1");
        QAbstractItemModel* model = ui->tableView->model();
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QModelIndex index = model->index(row, col);
                QVariant data = model->data(index);
                if (data.isValid()) {
                    xlsDoc.write(row + 1, col + 1, data.toString());
                }
            }
        }
        xlsDoc.saveAs(fileName);
    } else {
        // Save to an XLSX file (default).
        QXlsx::Document xlsxDoc(fileName);
        xlsxDoc.addSheet("Sheet1");
        QAbstractItemModel* model = ui->tableView->model();
        for (int row = 0; row < model->rowCount(); ++row) {
            for (int col = 0; col < model->columnCount(); ++col) {
                QModelIndex index = model->index(row, col);
                QVariant data = model->data(index);
                if (data.isValid()) {
                    xlsxDoc.write(row + 1, col + 1, data.toString());
                }
            }
        }
        xlsxDoc.saveAs(fileName);
    }
}

void MainWindow::on_btnCreateFile_activated(int index)
{
    if (ui->btnCreateFile->currentText() == "Configurar BD") {
        const int moduloWidth = 1355;
        const int moduloHeight = 555;

        // Cria a janela Modulo
        Modulo *modulo = new Modulo();

        // Define o tamanho mínimo e máximo da janela
        modulo->setMinimumSize(moduloWidth, moduloHeight);
        modulo->setMaximumSize(moduloWidth, moduloHeight);
        modulo->show();
        this->close();
    }

}


void MainWindow::on_btnVerCarro_clicked()
{

    // Construct the path to the car's folder
    QString folderName = ui->comboBoxCarro->currentText();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Open the "caracteristicas.txt" file within the car's folder
    QString filePath = folderPath + "/caracteristicas.txt";
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        // Read the data
        QString line = stream.readLine();
        QStringList values = line.split(";");

        file.close();

        const int verCarroWidth = 700;
        const int verCarroHeight = 350;

        // Cria a janela VerCarro
        VerCarro *verCarro = new VerCarro();

        // Define o tamanho mínimo e máximo da janela
        verCarro->setMinimumSize(verCarroWidth, verCarroHeight);
        verCarro->setMaximumSize(verCarroWidth, verCarroHeight);


        // Set the data in the "vercarro" window's QLabel widgets
        verCarro->setNome(values[0]);
        verCarro->setTipo(values[1]);
        verCarro->setObservacoes(values[2]);

        verCarro->show();
        this->close();
    }

}


void MainWindow::on_btnCriarCarro_clicked()
{
        const int criarcarroWidth = 600;
        const int criarcarroHeight = 250;


        // Cria a janela principal
        CriarCarro *criarcarro = new CriarCarro();


        // Define o tamanho mínimo e máximo da janela
        criarcarro->setMinimumSize(criarcarroWidth, criarcarroHeight);
        criarcarro->setMaximumSize(criarcarroWidth, criarcarroHeight);

        // Connect the carNameEntered signal to the setComboBoxSelectedValue slot
//        connect(criarcarro, &CriarCarro::carNameEntered, this, &MainWindow::setComboBoxSelectedValue);

        criarcarro->show();
        this->close();
}


void MainWindow::on_btnEstatisticas_clicked()
{
        const int estatisticasWidth = 800;
        const int estatisticasHeight = 500;

        // Cria a janela principal
        Estatisticas *estatisticas = new Estatisticas();

        // Define o tamanho mínimo e máximo da janela
        estatisticas->setMinimumSize(estatisticasWidth, estatisticasHeight);
        estatisticas->setMaximumSize(estatisticasWidth, estatisticasHeight);
        estatisticas->show();
        this->close();
}

QString MainWindow::loadLastSelectedOption()
{
        QSettings settings("FSIPLeiria", "FSIPLeiria");
        return settings.value("lastSelectedOption").toString();
}

void MainWindow::saveLastSelectedOption(const QString& selectedOption)
{
        QSettings settings("FSIPLeiria", "FSIPLeiria");
        settings.setValue("lastSelectedOption", selectedOption);
}

//void MainWindow::setComboBoxSelectedValue(const QString& value)
//{
//        qDebug() << "Value: " << value;

//        QTimer::singleShot(100, this, [this, value]() {
//            int index = ui->comboBoxCarro->findText(value); // Find the index of the desired value

//            qDebug() << "Value Index: " << index;
//            if (index != -1) {
//                ui->comboBoxCarro->setCurrentIndex(index); // Set the selected value based on the index
//            }
//        });
//}

void MainWindow::populateComboBox(QString option)
{
        QComboBox* comboBox = ui->comboBoxCarro;

        QString settingsDir = QDir::currentPath() + "/../FSIPLeiria/settings";
        QDir directory(settingsDir);
        QStringList folders = directory.entryList(QDir::Dirs | QDir::NoDotAndDotDot);

        qDebug() << "Folders: " << folders;
        ui->comboBoxCarro->clear();
        ui->comboBoxCarro->addItems(folders);

        qDebug() << "Combo Box Items: " << comboBox->count();

        ui->comboBoxCarro->setCurrentText(option);
}

void MainWindow::handleComboBoxIndexChanged(int index)
{
    if (ui->btnVerCarro && ui->btnDuplicarCarro) {
        // If index is -1, no option is selected
        bool isButtonVisible = (index != -1);
        ui->btnVerCarro->setVisible(isButtonVisible);
        ui->btnDuplicarCarro->setVisible(isButtonVisible);
    }
}




void MainWindow::on_btnDuplicarCarro_clicked()
{
    QString nomeCarro = ui->comboBoxCarro->currentText();

    QString folderName = nomeCarro.trimmed();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString sourceFolderPath = targetDir + "/" + folderName;

    // Ask the user for the new folder name
    QString newFolderName = QInputDialog::getText(this, tr("Nome da Pasta"), tr("Digite o nome da nova pasta:"));

    while (!newFolderName.isEmpty() && QDir(targetDir + "/" + newFolderName).exists()) {
        QMessageBox::critical(this, tr("Erro"), tr("A pasta com o nome especificado já existe!"));

        newFolderName = QInputDialog::getText(this, tr("Nome da Pasta"), tr("Digite outro nome para a nova pasta:"));
    }

    if (!newFolderName.isEmpty()) {

        // Check if the new folder name contains the invalid character ";"
        if (newFolderName.contains(';')) {
            QMessageBox::critical(this, tr("Erro"), tr("O nome da pasta não pode conter o caracter ';'."));

            newFolderName = QInputDialog::getText(this, tr("Nome da Pasta"), tr("Digite outro nome para a nova pasta:"));
        }

        QString newFolderPath = targetDir + "/" + newFolderName;

        // Create the new folder
        if (!QDir().mkdir(newFolderPath)) {
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível criar a nova pasta!"));
            return;
        }

        // Copy the contents of the source folder to the new folder
        QDir(sourceFolderPath).setNameFilters(QStringList("*.*"));
        QStringList files = QDir(sourceFolderPath).entryList();
        foreach (QString file, files) {
            QString sourceFilePath = sourceFolderPath + "/" + file;
            QString destFilePath = newFolderPath + "/" + file;
            QFile::copy(sourceFilePath, destFilePath);
        }

        // Iterate over the .txt files in the new folder and replace the first element with the new folder's name
        QDir newFolderDir(newFolderPath);
        QStringList txtFiles = QStringList("caracteristicas.txt");

        foreach (const QString& txtFile, txtFiles) {
            QString filePath = newFolderDir.absoluteFilePath(txtFile);

            QFile file(filePath);
            if (file.open(QIODevice::ReadWrite | QIODevice::Text)) {
                QString content = file.readAll();
                file.seek(0);

                // Replace the first element with the new folder's name
                QStringList elements = content.split(';');
                elements.replace(0, newFolderName);
                QString newContent = elements.join(';');

                file.write(newContent.toUtf8());
                file.close();
            } else {
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o arquivo: ") + txtFile);
            }
        }


        // Inform the user that the folder has been duplicated
        QMessageBox::information(this, tr("Pasta Duplicada"), tr("A pasta foi duplicada com sucesso!"));

        populateComboBox(newFolderName);
    }
}




