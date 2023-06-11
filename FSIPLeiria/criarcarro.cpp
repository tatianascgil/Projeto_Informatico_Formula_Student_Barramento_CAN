#include "criarcarro.h"
#include "ui_criarcarro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDir>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QColor>

CriarCarro::CriarCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CriarCarro)
{
    ui->setupUi(this);
}

CriarCarro::~CriarCarro()
{
    delete ui;
}

void CriarCarro::on_btnCancelar_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


void CriarCarro::on_btnCriarCarro_clicked()
{

    QString nomeCarro = ui->textEditNomeCarro->toPlainText().trimmed();
    QString tipoCarro = ui->btnTipoCarro->currentText();
    QString obsCarro = ui->textEditObsCarro->toPlainText().trimmed();

    bool nomeCarroEmpty = nomeCarro.isEmpty();
    bool tipoCarroEmpty = tipoCarro.isEmpty();

    if (nomeCarroEmpty && tipoCarroEmpty) {
        QMessageBox::critical(this, "Erro", "É obrigatório preencher os campos 'Nome' e 'Tipo'!");
        return;
    }

    if (nomeCarroEmpty) {
        QMessageBox::critical(this, "Erro", "É obrigatório preencher o campo 'Nome'!");
        return;
    }

    if (tipoCarroEmpty) {
        QMessageBox::critical(this, "Erro", "É obrigatório preencher o campo 'Tipo'!");
        return;
    }

    if(nomeCarro.contains(";") || obsCarro.contains(";")){
        QMessageBox::critical(this, "Erro", "É proíbido utilizar semi-vírgulas ';'!");
        return;
    }

    QString folderName = nomeCarro;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QDir dir(targetDir);
    if (!dir.exists() && !dir.mkpath(targetDir)) {
        QMessageBox::critical(this, "Erro", "Erro ao criar a diretoria " + targetDir);
        return;
    }

    QDir folderDir(folderPath);
    if (folderDir.exists()) {
        QMessageBox::information(this, "Erro", "Erro. A pasta " + folderName + " já existe!");
        return;
    }

    if (!folderDir.mkpath(folderPath)) {
        QMessageBox::critical(this, "Erro", "Erro ao criar a pasta " + folderName);
        return;
    }

    // Saving the car data in a TXT file
    QString filePath = folderPath + "/caracteristicas.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Erro ao abrir o arquivo " + filePath + " para escrita!");
        return;
    }

    QTextStream stream(&file);

    // Write the data
    stream << nomeCarro << ";" << tipoCarro << ";" << obsCarro << ";\n";

    file.close();

    QMessageBox::information(this, "Guardar Dados", "Dados salvados com sucesso!");

    MainWindow *mainWindow = new MainWindow();
    mainWindow->populateComboBox(nomeCarro);
    mainWindow->show();
    this->close();

}


void CriarCarro::on_commandButtonVoltar_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

