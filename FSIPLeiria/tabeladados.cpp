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

    connect(ui->comboBoxModulo, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::setCodigosHex);
    connect(ui->comboBoxCodigoHEX, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &TabelaDados::setCampos);

}

TabelaDados::~TabelaDados()
{
    delete ui;
}

void TabelaDados::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome.trimmed());
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

void TabelaDados::setCodigosHex(int index){

    QString selectedModulo = ui->comboBoxModulo->itemText(index);
    ui->comboBoxCodigoHEX->clear();

    // Construct the path to the car's folder
    QString folderName = ui->labelNomeCarro->text();
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + filePath);
        return;
    }

    QTextStream in(&file);

    QString placeholderText = ui->comboBoxCodigoHEX->placeholderText();
    ui->comboBoxCodigoHEX->addItem(placeholderText);

    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(";");

        if (values.size() >= 2 && values.at(0).trimmed() == selectedModulo) {
            QString secondValue = values.at(1).trimmed();
            if (!secondValue.isEmpty()) {
                ui->comboBoxCodigoHEX->addItem(secondValue);
            }
        }
    }

    file.close();

}

void TabelaDados::setCampos(int index){
    QString selectedCodHex = ui->comboBoxCodigoHEX->itemText(index);
    ui->comboBoxCampo->clear();

    // Construct the path to the car's folder
    QString folderName = ui->labelNomeCarro->text();
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
    if (!placeholderText.isEmpty()) {
        campos.append(placeholderText);
    }

    // Read the file line by line
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList values = line.split(';');

        if (values.size() >= 5 && values.at(1).trimmed() == selectedCodHex) {
            QString value = values.at(4).trimmed();
            if (!value.isEmpty()) {
                campos.append(value);
            }
        }

        for (int i = 10; i < values.size(); i += 6) {
            if (values.size() >= i + 1 && values.at(1).trimmed() == selectedCodHex) {
                QString value = values.at(i).trimmed();
                if (!value.isEmpty()) {
                    campos.append(value);
                }
            }
        }
    }

    file.close();

    // Add the non-empty values to the comboBoxCampo
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

void TabelaDados::loadMensagens(const QString& filePath) {
    QFile file(filePath);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QStandardItemModel* model = new QStandardItemModel(this);

        // Step 1: Read "tiposMensagem.txt" and store its contents
        QMap<QString, QString> tiposMensagem;

        QString nomeCarro = ui->labelNomeCarro->text();
        QString folderName = nomeCarro;
        QString currentPath = QDir::currentPath();
        QString targetDir = currentPath + "/../FSIPLeiria/settings";
        QString folderPath = targetDir + "/" + folderName;
        QString tiposMensagemPath = folderPath + "/tiposMensagem.txt";
        QFile tiposFile(tiposMensagemPath);
        if (tiposFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream tiposIn(&tiposFile);

            while (!tiposIn.atEnd()) {
                QString tiposLine = tiposIn.readLine();
                QStringList tiposColumns = tiposLine.split(';');

                if (tiposColumns.length() > 3) {
                    QString secondValue = tiposColumns[1];
                    tiposMensagem[secondValue] = tiposLine;
                }
            }

            tiposFile.close();
        }

        // Step 2: Read the file line by line and modify the data
        while (!in.atEnd()) {
            QString line = in.readLine();
            QStringList columns = line.split(';');
            QList<QStandardItem*> rowItems;

            for (int i = 0; i < columns.length(); i++) {
                QString column = columns[i];

                if (i == 1 && tiposMensagem.contains(column)) {
                    QString tiposLine = tiposMensagem[column];
                    QStringList tiposColumns = tiposLine.split(';');

                    // Calculate field length
                    int fieldStartIndex = 5 + 6 * (tiposColumns[3].toInt() - 1);
                    int fieldEndIndex = fieldStartIndex + tiposColumns[2].toInt() - 1;
                    int fieldLength = fieldEndIndex - fieldStartIndex + 1;

                    // Append modified field value
                    QString fieldValue = column + line.mid(fieldStartIndex, fieldLength);
                    rowItems.append(new QStandardItem(fieldValue));
                } else {
                    rowItems.append(new QStandardItem(column));
                }
            }

            model->appendRow(rowItems);
        }

        file.close();

        // Step 3: Set the model for the tableViewTabelaDados
        ui->tableViewTabelaDados->setModel(model);
    }
}


void TabelaDados::on_btnFiltrar_clicked()
{

}


void TabelaDados::on_commandButtonVoltar_clicked()
{

    QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Voltar atrás", "Tem a certeza que pretende voltar atrás?", QMessageBox::Yes | QMessageBox::No);
    if (confirmation == QMessageBox::No) {
        // User canceled the operation
        return;
    }

    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

