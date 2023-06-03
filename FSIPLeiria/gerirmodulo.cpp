#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"
#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QStandardItemModel>
#include <QDebug>
#include <QMessageBox>


GerirModulo::GerirModulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GerirModulo)
{
    ui->setupUi(this);
}

GerirModulo::~GerirModulo()
{
    delete ui;
}

void GerirModulo::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome);
}

void GerirModulo::loadModuloData(const QStringList& data)
{
    QString nomeModulo = data.at(0);

    ui->labelNomeModulo->setText(nomeModulo);
    QString folderName = ui->labelNomeCarro->text();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString modulosPath = folderPath + "/modulos.txt";
    QFile modulos(modulosPath);

    if (modulos.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&modulos);

        QList<QStringList> filteredData; // To store the filtered data

        // Read all the lines and filter the data based on nomeModulo
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(";");
            if (values.size() > 0 && values.at(0) == nomeModulo) {
                filteredData.append(values);
            }
        }

        modulos.close();

        if (!filteredData.isEmpty()) {
            // Display the filtered data in the QTableView
            QStandardItemModel* model = new QStandardItemModel(filteredData.count(), filteredData[0].count(), this);

            // Set the headers
            model->setHorizontalHeaderLabels({"Nome", "Modulo", "Endianess", "Observações"});

            // Populate the model with filtered data
            for (int row = 0; row < filteredData.count(); ++row) {
                for (int col = 0; col < filteredData[row].count(); ++col) {
                    model->setItem(row, col, new QStandardItem(filteredData[row][col]));
                }
            }

            // Set the mode of resizing for other columns
            QHeaderView* horizontalHeader = ui->tableViewModulosCarro->horizontalHeader();

            horizontalHeader->setSectionResizeMode(QHeaderView::Stretch);
            horizontalHeader->setStretchLastSection(false);

            // Set the model to the QTableView
            ui->tableViewModulosCarro->setModel(model);
        } else {
            // Handle the case when there is no filtered data
            // For example, you can display an empty model or show a message to the user
            QStandardItemModel* emptyModel = new QStandardItemModel(0, 4, this);
            // Set the headers
            emptyModel->setHorizontalHeaderLabels({"Nome", "Modulo", "Endianess", "Observações"});
            // Set the empty model to the QTableView
            ui->tableViewModulosCarro->setModel(emptyModel);
            // Show a message to the user
            QMessageBox::information(this, "Sem Módulos", "Não foram encontrados módulos correspondentes.");
        }
    }
}



void GerirModulo::on_btnGuardarModulo_clicked()
{
    QAbstractItemModel* model = ui->tableViewModulosCarro->model();
    int rowCount = model->rowCount();
    int columnCount = model->columnCount();

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
    QString filePath = folderPath + "/modulos.txt";

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
        for (int row = 0; row < tableViewData.size(); ++row) {
            QStringList tableViewRowData = tableViewData[row];
            QStringList fileRowData = fileData.value(row);

            if (fileRowData != tableViewRowData) {
                allValuesMatch = false;
                break;
            }
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

                // Write the modified line to the file
                for (int row = 0; row < tableViewData.size(); ++row) {
                    if (tableViewData[row] != fileData.value(row)) {
                        out << tableViewData[row].join(";") << "\n";
                    } else {
                        out << fileData.value(row).join(";") << "\n";
                    }
                }

                // Write the remaining lines from the file if any
                for (int row = tableViewData.size(); row < fileData.size(); ++row) {
                    out << fileData.value(row).join(";") << "\n";
                }

                file.close();
            } else {
                QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para escrita."));
            }
        }
    } else {
        QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para leitura."));
    }
}



void GerirModulo::on_commandButtonVoltar_clicked()
{
    const int gerircarroWidth = 800;
    const int gerircarroHeight = 500;

    // Cria a janela GerirCarro
    GerirCarro *gerircarro = new GerirCarro();

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();

    gerircarro->setNome(nomeCarro);
    qDebug() << "Nome do carro: " << nomeCarro;

    // Define o tamanho mínimo e máximo da janela
    gerircarro->setMinimumSize(gerircarroWidth, gerircarroHeight);
    gerircarro->setMaximumSize(gerircarroWidth, gerircarroHeight);
    gerircarro->lerDadosCarro(nomeCarro);

    gerircarro->show();
    this->close();
}


void GerirModulo::on_btnApagarModulo_clicked()
{
    QString folderName = ui->labelNomeCarro->text().trimmed();
    QString moduloName = ui->labelNomeModulo->text().trimmed();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString modulosPath = folderPath + "/modulos.txt";


    qDebug() << "Modulos: " << modulosPath;

    // Check if the modulos.txt file exists
    if (!QFile::exists(modulosPath)) {
        qDebug() << "modulos.txt file does not exist: " << modulosPath;
        QMessageBox::critical(this, tr("Erro"), tr("O arquivo modulos.txt não existe!"));
        return;
    }

    // Display confirmation dialog
    QMessageBox confirmation(this);

    confirmation.setWindowTitle("Apagar Módulo");
    confirmation.setText("Tem certeza que deseja apagar o módulo " + moduloName + "? Todos os dados serão excluídos!");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    QPushButton* yesButton = confirmation.addButton("Sim", QMessageBox::YesRole);
    confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == yesButton) {
        // Open the modulos.txt file
        QFile modulosFile(modulosPath);

        if (modulosFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream stream(&modulosFile);

            // Read all the lines and create a new list without the line to be deleted
            QList<QStringList> newModulosData;
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                QStringList values = line.split(";");
                if (values[0] != moduloName) {  // Change index to match the column of the module name
                    newModulosData.append(values);
                }
            }

            modulosFile.resize(0); // Clear the file content

            // Write the updated data to the modulos.txt file
            for (const QStringList& rowData : newModulosData) {
                QString line = rowData.join(";") + "\n";
                stream << line;
            }

            modulosFile.close();

            // Folder deleted successfully
            QMessageBox::information(this, "Módulo Removido", "O módulo \"" + moduloName + "\" foi removido com sucesso!");

            this->close();

            // Cria a janela GerirCarro
            GerirCarro *gerircarro = new GerirCarro();

            QString nomeCarro = ui->labelNomeCarro->text().trimmed();

            gerircarro->setNome(nomeCarro);
            gerircarro->lerDadosCarro(nomeCarro);
            gerircarro->show();

        } else {
            // Failed to open modulos.txt file for editing
            qDebug() << "Failed to open modulos.txt file for editing: " << modulosPath;
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o arquivo modulos.txt para edição!"));
        }
    } else {
        // User canceled the deletion
        qDebug() << "Module deletion canceled by user.";
    }
}




