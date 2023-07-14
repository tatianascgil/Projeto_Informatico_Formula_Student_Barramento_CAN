#include "criarmodulo.h"
#include "ui_criarmodulo.h"
#include "gerircarro.h"
#include "ui_gerircarro.h"

#include <QDir>
#include <QDebug>
#include <QMessageBox>

CriarModulo::CriarModulo(GerirCarro* gerirCarro, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CriarModulo)
{
    ui->setupUi(this);
    this->gerirCarro = gerirCarro;
}

CriarModulo::~CriarModulo()
{
    delete ui;
}


void CriarModulo::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome.trimmed());
}



void CriarModulo::on_btnCriarModulo_clicked()
{

    QString nomeModulo = ui->textEditNomeModulo->toPlainText().trimmed();
    QString obsModulo = ui->textEditObsModulo->toPlainText().trimmed();
    QString nomeCarro = ui->labelNomeCarro->text();

    bool nomeModuloEmpty = nomeModulo.isEmpty();

    if (nomeModuloEmpty) {
        QMessageBox::critical(this, "Erro", "É obrigatório preencher o campo 'Nome'!");
        return;
    }

    if((nomeModulo.contains(";")) || (obsModulo.contains(";"))){
        QMessageBox::critical(this, "Erro", "É proíbido utilizar semi-vírgulas ';'!");
        return;
    }

    if(nomeModulo.contains("\n")){
        QMessageBox::critical(this, "Erro", "Não é permitido criar novas linhas no campo 'Nome'!");
        return;
    }

    if(obsModulo.contains("\n")){
        QMessageBox::critical(this, "Erro", "Não é permitido criar novas linhas no campo 'Observações'!");
        return;
    }


    QString folderName = nomeCarro;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
    QString folderPath = targetDir + "/" + folderName;

    QDir folderDir(folderPath);
    if (!folderDir.exists()) {
        QMessageBox::information(this, "Erro", "Erro. A pasta " + folderPath + " não existe!");
        return;
    }

    if (!folderDir.mkpath(folderPath)) {
        QMessageBox::critical(this, "Erro", "Erro ao criar a pasta " + folderName);
        return;
    }

    // Saving the car data in a TXT file
    QString filePath = folderPath + "/modulos.txt";

    // Open the file for reading and check if nomeModulo already exists
    QFile readFile(filePath);
    if (!readFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        if (readFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            readFile.close();
        }else {
            // Failed to create the file
            QMessageBox::critical(this, "Erro", "Erro ao criar o arquivo " + filePath + "!");
            return;
        }
    }

    QTextStream readStream(&readFile);

    while (!readStream.atEnd()) {
        QString line = readStream.readLine();
        QStringList values = line.split(";");
        if (!values.isEmpty() && values.first() == nomeModulo) {
            QMessageBox::critical(this, "Erro", "O módulo " + nomeModulo + " já existe!");
            readFile.close();
            return;
        }
    }

    readFile.close();

    QString endianess;
    if (ui->radioButton_Littleendian->isChecked()) {
        endianess = "Little Endian";
    } else {
        endianess = "Big Endian";
    }

    // Display confirmation dialog
    QMessageBox confirmation(this);
    confirmation.setWindowTitle("Guardar Dados");
    confirmation.setText("Tem a certeza que pretende criar o módulo " + nomeModulo + "?");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    confirmation.addButton("Sim", QMessageBox::YesRole);
    QPushButton* noButton = confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == noButton) {
        // User canceled the operation
        return;
    }

    // Open the file for appending the new module information
    QFile writeFile(filePath);
    if (!writeFile.open(QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Erro ao abrir o arquivo " + filePath + " para escrita!");
        return;
    }

    QTextStream writeStream(&writeFile);
    writeStream << nomeModulo << ";" << endianess << ";" << obsModulo << ";\n";

    writeFile.close();

    QMessageBox::information(this, "Guardar Dados", "Dados salvados com sucesso!");

    previousWindow();
}

void CriarModulo::on_commandButtonVoltar_clicked()
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

    // Close the confirmation dialog
    confirmation.close();

    previousWindow();
}

void CriarModulo::previousWindow(){


    QString nomeCarro = ui->labelNomeCarro->text().trimmed();


    gerirCarro->setNome(nomeCarro);
    gerirCarro->lerDadosCarro(nomeCarro);
    gerirCarro->lerDadosModulo(nomeCarro);


    this->close();
}
