#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "criarmodulo.h"
#include "ui_criarmodulo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"

#include <QElapsedTimer>
#include <QDir>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>
#include <QInputDialog>


GerirCarro::GerirCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GerirCarro)
{
    ui->setupUi(this);
    connect(ui->tableViewModulosCarro, &QTableView::doubleClicked, this, &GerirCarro::openGerirModuloWindow);

    connect(ui->tableViewCarro, &QTableView::doubleClicked, this, &GerirCarro::handleTableViewDoubleClick);


}

GerirCarro::~GerirCarro()
{
    delete ui;
}

void GerirCarro::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome.trimmed());
}

void GerirCarro::openGerirModuloWindow(const QModelIndex& index)
{
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->tableViewModulosCarro->model());
    if (!model)
        return;

    int row = index.row();
    QStringList rowData;

    for (int col = 0; col < model->columnCount(); ++col) {
        QString value = model->index(row, col).data().toString();
        rowData.append(value);
    }

    QString nomeModulo = rowData.at(0);

    this->close();

    GerirModulo* gerirModulo = new GerirModulo(this);

    QString nomeCarro = ui->labelNomeCarro->text();

    // Passar os dados filtrados para a nova janela
    gerirModulo->setNome(nomeCarro);
    gerirModulo->lerDadosModulo(nomeModulo);
    gerirModulo->lerDadosTiposMensagem(nomeModulo);

    // Define o tamanho mínimo e máximo da janela
    const int gerirModuloWidth = 800;
    const int gerirModuloHeight = 500;

    gerirModulo->setMinimumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->setMaximumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->show();

}


void GerirCarro::lerDadosCarro(const QString& nome) {

    // Construct the path to the car's folder
    QString folderName = nome;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Open the "caracteristicas.txt" file within the car's folder
    QString filePath = folderPath + "/caracteristicas.txt";
    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        QList<QStringList> data;

        // Read the data
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(";");
            if (values.size() > 2) {
                data.append(values.mid(0, 3));
            }
        }

        file.close();

        if (!data.isEmpty()) {
            // Display the data in the QTableView
            QStandardItemModel* model = new QStandardItemModel(data.count(), data[0].count(), this);

            // Set the headers
            model->setHorizontalHeaderLabels({"Nome", "Tipo", "Observações"});

            // Populate the model with data
            for (int row = 0; row < data.count(); ++row) {
                for (int col = 0; col < data[row].count(); ++col) {
                    QStandardItem* item = new QStandardItem(data[row][col]);

                    // Set the first two cells as non-editable
                    if (col < 2) {
                        item->setEditable(false);
                    }

                    model->setItem(row, col, item);
                }
            }

            // Set the mode of resizing for other columns
            QHeaderView* horizontalHeader = ui->tableViewCarro->horizontalHeader();
            horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
            horizontalHeader->setStretchLastSection(false);

            // Set the model to the QTableView
            ui->tableViewCarro->setModel(model);
        }
    }
}




void GerirCarro::lerDadosModulo(const QString& nome) {

    // Construct the path to the car's folder
    QString folderName = nome;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Open the "modulos.txt" file within the car's folder
    QString filePath = folderPath + "/modulos.txt";
    QFile file(filePath);


    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);

        QList<QStringList> data;

        // Read all the lines and populate the data list
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(";");
            data.append(values.mid(0, 3));
        }

        file.close();

        // Create the model and set the data
        QStandardItemModel* model = new QStandardItemModel(data.count(), data[0].count(), this);
        model->setHorizontalHeaderLabels({"Nome", "Endianess", "Observações"});

        if (data.isEmpty()) {
            // If data is empty, set an empty model with headers to the QTableView
            ui->tableViewCarro->setModel(model);
            return;
        }

        for (int row = 0; row < data.count(); ++row) {
            for (int col = 0; col < data[row].count(); ++col) {
                QStandardItem* item = new QStandardItem(data[row][col]);
                // Set the item as read-only
                item->setEditable(false);
                model->setItem(row, col, item);
            }
        }

        // Set the mode of resizing for other columns
        QHeaderView* horizontalHeader = ui->tableViewModulosCarro->horizontalHeader();
        horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
        horizontalHeader->setStretchLastSection(false);

        // Set the model to the QTableView
        ui->tableViewModulosCarro->setModel(model);

    }
}

void GerirCarro::on_commandButtonVoltar_clicked()
{

    // Display confirmation dialog
    QMessageBox confirmation(this);
    confirmation.setWindowTitle("Voltar atrás");
    confirmation.setText("Tem a certeza que pretende voltar atrás? Todos os dados serão perdidos!");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    confirmation.addButton("Sim", QMessageBox::YesRole);
    QPushButton* noButton = confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == noButton) {
        // User canceled the operation
        return;
    }

    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


void GerirCarro::on_btnCriarModulo_clicked()
{
    CriarModulo *criarModulo = new CriarModulo();

    QString nomeCarro = ui->labelNomeCarro->text();

    criarModulo->setNome(nomeCarro);

    // Define o tamanho mínimo e máximo da janela
    const int criarModuloWidth = 600;
    const int criarModuloHeight = 250;

    criarModulo->setMinimumSize(criarModuloWidth, criarModuloHeight);
    criarModulo->setMaximumSize(criarModuloWidth, criarModuloHeight);

    criarModulo->show();
    this->close();
}


void GerirCarro::on_btnApagarCarro_clicked()
{
    QString folderName = ui->labelNomeCarro->text();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Display confirmation dialog
    QMessageBox confirmation(this);

    confirmation.setWindowTitle("Apagar Pasta");
    confirmation.setText("Tem certeza que deseja apagar o carro " + folderName + "? Todos os dados serão excluídos!");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    QPushButton* yesButton = confirmation.addButton("Sim", QMessageBox::YesRole);
    confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == yesButton) {
        QDir dir(folderPath);

        if (!(dir.exists() && dir.removeRecursively())) {
            // Failed to delete folder
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível apagar a pasta " + folderName.toUtf8() + "!"));
            return;
        }

        // Folder deleted successfully
        QMessageBox::information(this, "Carro Removido", "O carro " + folderName + " foi removido com sucesso!");
        this->close();
        MainWindow* mainWindow = new MainWindow();
        mainWindow->show();
    }
}

void GerirCarro::handleTableViewDoubleClick(const QModelIndex& index)
{
    if (index.isValid() && index.column() == 1) {
        QString currentPath = QDir::currentPath();
        QString targetFile = currentPath + "/../FSIPLeiria/tiposCarro.txt";

        QFile tiposCarroFile(targetFile);
        if (tiposCarroFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream tiposCarroIn(&tiposCarroFile);
            QString line = tiposCarroIn.readLine();
            QStringList tiposCarroData;
            QStringList values = line.split(';');
            for (const QString& value : values) {
                if (!value.isEmpty()) {
                    tiposCarroData.append(value);
                }
            }
            tiposCarroFile.close();

            // Get the current value of the double-clicked cell
            QAbstractItemModel* model = ui->tableViewCarro->model();
            QVariant currentValue = model->data(index);

            // Display a dialog to let the user choose from the available options
            bool ok;
            QString selectedTipoCarro = QInputDialog::getItem(this, tr("Selecionar Tipo de Carro"), tr("Tipo de Carro:"), tiposCarroData, tiposCarroData.indexOf(currentValue.toString()), false, &ok);
            if (ok) {
                // Update the selected value in the QTableView
                model->setData(index, selectedTipoCarro);
            }
        } else {
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro tiposCarro.txt."));
            return;
        }
    }
}




void GerirCarro::on_btnGuardarCarro_clicked()
{
    QAbstractItemModel* model = ui->tableViewCarro->model();
    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

    QString obs = ui->tableViewCarro->model()->index(0, 2).data().toString();

    if (obs.contains(';'))
    {
        QMessageBox::critical(this, tr("Erro"), tr("É proíbido utilizar semi-vírgulas ';'!"));
        return;
    }

    // Create a QVector to store the data from the QTableView
    QVector<QStringList> tableViewData;
    for (int row = 0; row < rowCount; ++row) {
        QStringList rowData;
        for (int column = 0; column < columnCount; ++column) {
            QModelIndex index = model->index(row, column);
            QVariant data = model->data(index);
            rowData.append(data.toString());
        }
        tableViewData.append(rowData);
    }

    QString folderName = ui->labelNomeCarro->text();
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;
    QString filePath = folderPath + "/caracteristicas.txt";

    QFile file(filePath);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        // Read the data from the file
        QVector<QStringList> fileData;
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList values = line.split(";");
            fileData.append(values);
        }

        file.close();

        bool allValuesMatch = true;
        // Compare the file data with the modified data from the QTableView
        if (tableViewData.size() == fileData.size()) {
            for (int row = 0; row < tableViewData.size(); ++row) {
                QStringList tableViewRowData = tableViewData[row];
                QStringList fileRowData = fileData[row];

                tableViewRowData.sort();
                fileRowData.sort();

                if (fileRowData != tableViewRowData) {
                    allValuesMatch = false;
                    break;
                }
            }
        } else {
            allValuesMatch = false;
        }


        // If all values match, prompt the user with an error message
        if (allValuesMatch) {
            QMessageBox::critical(this, tr("Erro"), tr("Não houve dados alterados!"));
                return;
        }

        // Display confirmation dialog
        QMessageBox confirmation(this);
        confirmation.setWindowTitle("Confirmar Atualização");
        confirmation.setText("Algumas informações foram alteradas. Tem certeza de que deseja atualizar os dados?");
        confirmation.setIcon(QMessageBox::Question);

        // Translate the buttons
        QPushButton* yesButton = confirmation.addButton("Sim", QMessageBox::YesRole);
        confirmation.addButton("Não", QMessageBox::NoRole);

        confirmation.exec();

        if (confirmation.clickedButton() == yesButton) {
            // User confirmed, write the data from the QTableView to the file
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream out(&file);
                for (const QStringList& rowData : tableViewData) {
                    out << rowData.join(";") << "\n";
                }
                file.close();

                // Inform the user about successful saving
                QMessageBox::information(this, tr("Sucesso"), tr("Dados guardados com sucesso!"));
            } else {
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para escrita."));
            }
        }

    } else {
        QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para leitura."));
    }
}

