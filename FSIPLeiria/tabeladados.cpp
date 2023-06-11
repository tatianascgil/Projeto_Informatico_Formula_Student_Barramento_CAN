#include "tabeladados.h"
#include "ui_tabeladados.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QFileDialog>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QMessageBox>

TabelaDados::TabelaDados(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TabelaDados)
{
    ui->setupUi(this);
}

TabelaDados::~TabelaDados()
{
    delete ui;
}

void TabelaDados::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome);
}

void TabelaDados::setModulos(const QString& nome){

    // Construct the path to the car's folder
    QString folderName = nome;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString filePath = folderPath + "/modulos.txt";
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + filePath);
        return;
    }

    QTextStream in(&file);

    QString placeholderText = ui->comboBoxModulo->placeholderText();
    ui->comboBoxModulo->addItem(placeholderText);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(";");

        for (const QString& value : values) {
            QString firstValue = value.trimmed();
            if (!firstValue.isEmpty()) {
                ui->comboBoxModulo->addItem(firstValue);
                break;  // Add only the first value of each line
            }
        }
    }

    file.close();

}

void TabelaDados::setCodigosHex(const QString& nome){

    // Construct the path to the car's folder
    QString folderName = nome;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + filePath);
        return;
    }

    QTextStream in(&file);

    QString placeholderText = ui->comboBoxCodigoHEX->placeholderText();
    ui->comboBoxCodigoHEX->addItem(placeholderText);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(";");

        if (values.size() >= 2) {
            QString secondValue = values.at(1).trimmed();
            if (!secondValue.isEmpty()) {
                ui->comboBoxCodigoHEX->addItem(secondValue);
            }
        }
    }
    file.close();

}

void TabelaDados::setCampos(const QString& nome){
    // Construct the path to the car's folder
    QString folderName = nome;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + filePath);
        return;
    }

    QTextStream in(&file);
    QStringList campos;

    QString placeholderText = ui->comboBoxCampo->placeholderText();
    campos.append(placeholderText);

    // Read the file line by line
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(';');

        if (values.size() >= 5) {
            QString value = values.at(4).trimmed();
            campos.append(value);
        }

        for (int i = 10; i < values.size(); i += 6) {
            if (values.size() >= i + 1) {
                QString value = values.at(i).trimmed();
                if (!value.isEmpty()) {
                    campos.append(value);
                }
            }
        }
    }

    file.close();

    // Add the values to the comboBoxCampo
    ui->comboBoxCampo->clear();
    ui->comboBoxCampo->addItems(campos);
}

void TabelaDados::setOperador(){
    ui->comboBoxOperador->setPlaceholderText(" ");
    QString placeholderText = ui->comboBoxOperador->placeholderText();

    ui->comboBoxOperador->addItem(placeholderText);
    ui->comboBoxOperador->addItem("=");
    ui->comboBoxOperador->addItem("<=");
    ui->comboBoxOperador->addItem(">=");
    ui->comboBoxOperador->addItem("<");
    ui->comboBoxOperador->addItem(">");
}

void TabelaDados::loadMensagens(){
    QString filePath = QFileDialog::getOpenFileName(this, "Selecione um ficheiro", QDir::homePath(), "Text Files (*.txt)");

    if (!filePath.isEmpty()) {
        QFile file(filePath);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QStandardItemModel* model = new QStandardItemModel(this);

            // Read the file line by line
            while (!in.atEnd()) {
                QString line = in.readLine();

                // Split the line into columns
                QStringList columns = line.split(';');

                // Create a list of items for the row
                QList<QStandardItem*> rowItems;
                for (const QString& column : columns) {
                    QStandardItem* item = new QStandardItem(column);
                    rowItems.append(item);
                }

                // Add the row to the model
                model->appendRow(rowItems);
            }

            // Close the file
            file.close();

            // Set the model for the tableViewTabelaDados
            ui->tableViewTabelaDados->setModel(model);
        } else {
            // Failed to open the file, handle the error
            QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + filePath);
        }
    }
}

void TabelaDados::on_btnFiltrar_clicked()
{

}


void TabelaDados::on_commandButtonVoltar_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

