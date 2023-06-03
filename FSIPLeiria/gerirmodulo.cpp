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

    //  QString folderName = nome;

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Open the "modulos.txt" file within the car's folder
    QString modulosPath = folderPath + "/modulos.txt";
    QFile modulos(modulosPath);

    qDebug() << "Modulos: " << modulosPath;
    if (modulos.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&modulos);

        QList<QStringList> data;

        // Read all the lines and populate the data list
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            QStringList values = line.split(";");
            data.append(values);
        }

        modulos.close();

        // Display the data in the QTableView
        QStandardItemModel* model = new QStandardItemModel(data.count(), data[0].count(), this);

        // Set the headers
        model->setHorizontalHeaderLabels({"Nome", "Modulo", "Endianess", "Observações"});

        // Populate the model with data
            for (int row = 0; row < data.count(); ++row) {
                for (int col = 0; col < data[row].count(); ++col) {
                         model->setItem(row, col, new QStandardItem(data[row][col]));
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
    folderName.remove(' ');

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;
    QString filePath = folderPath + "/modulos.txt";

    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);

        // Read the data from the file
        int row = 0;
        bool allValuesMatch = true;
        while (!in.atEnd() && row < tableViewData.size()) {
            QString line = in.readLine();

            // Split the line into values (assuming tab-separated values)
            QStringList fileData = line.split(";");

            // Compare each value with the corresponding value from the QTableView
            for (int column = 0; column < fileData.size(); ++column) {
                QString fileValue = fileData[column];
                QString tableViewValue = tableViewData[row][column];

                // Perform the necessary comparison
                if (fileValue != tableViewValue) {
                    allValuesMatch = false;
                    break;
                }
            }

            ++row;
        }

        file.close();

        // Update the visibility of the btnGuardarFicheiro button based on the comparison results
        ui->btnGuardarModulo->setVisible(!allValuesMatch);

        // If at least one value does not match, prompt the user for confirmation before updating the file
        if (!allValuesMatch) {
            // Set the translated button texts
            QMessageBox msgBox(QMessageBox::Question, tr("Confirmar Atualização"), tr("Algumas informações foram alteradas. Tem certeza de que deseja atualizar os dados?"), QMessageBox::Yes | QMessageBox::No, this);

            QAbstractButton* yesButton = msgBox.addButton(tr("Sim"), QMessageBox::YesRole);
            msgBox.addButton(tr("Não"), QMessageBox::NoRole);

            msgBox.exec();

            if (msgBox.clickedButton() == yesButton) {
                // User confirmed, write the data from the QTableView to the file
                if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                    QTextStream out(&file);
                    for (const QStringList& rowData : tableViewData) {
                        out << rowData.join(";") << "\n";
                    }
                    file.close();
                } else {
                    QMessageBox::critical(this, tr("Erro"), tr("Não foi possível abrir o ficheiro para escrita."));
                }
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
    QString folderName = ui->labelNomeModulo->text();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    // Display confirmation dialog
    QMessageBox confirmation(this);

    confirmation.setWindowTitle("Apagar Módulo");
    confirmation.setText("Tem certeza que deseja apagar o módulo " + folderName + "? Todos os dados serão excluídos!");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    QPushButton* yesButton = confirmation.addButton("Sim", QMessageBox::YesRole);
    confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == yesButton) {
        // Open the modulos.txt file
        QString modulosPath = folderPath + "/modulos.txt";
        QFile modulosFile(modulosPath);

        if (modulosFile.open(QIODevice::ReadWrite | QIODevice::Text)) {
            QTextStream stream(&modulosFile);

            // Read all the lines and create a new list without the line to be deleted
            QList<QStringList> newModulosData;
            while (!stream.atEnd()) {
                QString line = stream.readLine();
                QStringList values = line.split(";");
                if (values[1] != folderName) {
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
            QMessageBox::information(this, "Módulo Removido", "O módulo \"" + folderName + "\" foi removido com sucesso!");

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



