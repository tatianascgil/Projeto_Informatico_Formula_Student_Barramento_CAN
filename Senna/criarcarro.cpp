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

bool CriarCarro::loadTiposCarro(){

    QString currentPath = QDir::currentPath();
    QString targetFile = currentPath + "/../Senna/tiposCarro.txt";

    QFile file(targetFile);
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(&file);
        QString line = in.readLine();

        if (!line.isEmpty()) {
            QStringList values = line.split(';');
            for (const QString& value : values) {
                QString trimmedValue = value.trimmed();
                if (!trimmedValue.isEmpty()) {
                    ui->btnTipoCarro->addItem(trimmedValue);
                }
            }
        }

        file.close();
        return true;

    } else {
        QMessageBox::critical(this, "Erro", "Não foi possível abrir o ficheiro " + targetFile);
        return false;
    }
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

    // Ask the user for confirmation
    QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Guardar Dados", "Tem a certeza que pretende criar o carro " + nomeCarro + "?", QMessageBox::Yes | QMessageBox::No);
    if (confirmation == QMessageBox::No) {
        // User canceled the operation
        return;
    }

    QString folderName = nomeCarro;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../Senna/settings";
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


