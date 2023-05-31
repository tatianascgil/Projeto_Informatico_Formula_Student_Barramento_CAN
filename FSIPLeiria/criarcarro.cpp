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

    QString nomeCarro = ui->textEditNomeCarro->toPlainText();
    QString tipoCarro = ui->btnTipoCarro->currentText();
    QString obsCarro = ui->textEditObsCarro->toPlainText();

//    // Emit the carNameEntered signal after a delay
//    QMetaObject::invokeMethod(this, [this, nomeCarro]() {
//            emit carNameEntered(nomeCarro);
//        }, Qt::QueuedConnection);;

    bool nomeCarroEmpty = nomeCarro.trimmed().isEmpty();
    bool tipoCarroEmpty = tipoCarro.isEmpty();

    if (nomeCarroEmpty && tipoCarroEmpty) {
        QMessageBox::critical(this, "Erro", "É obrigatório preencher os campos 'Nome' e 'Tipo'!");
        return;
    } else if (nomeCarroEmpty) {
        QMessageBox::critical(this, "Erro", "É obrigatório preencher o campo 'Nome'!");
        return;
    } else if (tipoCarroEmpty) {
        QMessageBox::critical(this, "Erro", "É obrigatório preencher o campo 'Tipo'!");
        return;
    }

    if(nomeCarro.contains(";")){
        QMessageBox::critical(this, "Erro", "É proíbido utilizar semi-vírgulas ';'!");
        return;
    }

    QString folderName = nomeCarro.trimmed();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QDir dir(targetDir);
    if (!dir.exists()) {
        if (dir.mkpath(targetDir)) {
        } else {
            QMessageBox::critical(this, "Error", "Failed to create target directory!");
            return;
        }
    }

    QDir folderDir(folderPath);
    if (!folderDir.exists()) {
        if (folderDir.mkpath(folderPath)) {
            QMessageBox::information(this, "Successo", "Pasta " + folderName + " criada com sucesso!");

//            // Emit the signal with the car name
//            emit carNameEntered(nomeCarro);

//            // Set the selected value of the QComboBox
//            MainWindow* mainWindow = qobject_cast<MainWindow*>(parent());
//            if (mainWindow) {
//                mainWindow->setComboBoxSelectedValue(nomeCarro);
//            }

            // Saving the car data in a TXT file
            QString filePath = folderPath + "/caracteristicas.txt";
            QFile file(filePath);
            if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QTextStream stream(&file);

                // Write the data
                QString nome = nomeCarro;
                QString tipo = tipoCarro;
                QString observacoes = obsCarro;
                stream << nome << ";" << tipo << ";" << observacoes << "\n";

                file.close();

                QMessageBox::information(this, "Guardar Dados", "Dados salvados com sucesso!");


                MainWindow *mainWindow = new MainWindow();

                mainWindow->populateComboBox(nomeCarro);
                mainWindow->show();
                this->close();
            } else {
                QMessageBox::critical(this, "Erro", "Erro ao guardar os dados!");
            }
        }
    } else {
        QMessageBox::information(this, "Erro", "Erro. A pasta " + folderName + " já existe!");
    }

}


void CriarCarro::on_commandButtonVoltar_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

