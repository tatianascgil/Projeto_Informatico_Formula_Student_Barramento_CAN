#include "vercarro.h"
#include "ui_vercarro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "estatisticas.h"
#include "ui_estatisticas.h"

#include <QFileDialog>
#include <QMessageBox>
#include <QDir>
#include <QProcess>




VerCarro::VerCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VerCarro)
{
    ui->setupUi(this);



}


VerCarro::~VerCarro()
{
    delete ui;
}


void VerCarro::setNome(const QString& nome) {
    ui->labelNomeCarro->setText(nome);
}

void VerCarro::setTipo(const QString& tipo) {
    ui->labelTipoCarro->setText(tipo);
}

void VerCarro::setObservacoes(const QString& obs) {
    ui->labelObsCarro->setText(obs);
}


void VerCarro::on_commandButtonVoltar_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();

}


void VerCarro::on_btnDefinicoes_clicked()
{
    const int gerirCarroWidth = 800;
    const int gerirCarroHeight = 500;

    // Cria a janela GerirCarro
    GerirCarro *gerirCarro = new GerirCarro();

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();

    gerirCarro->setNome(nomeCarro);
    qDebug() << "Nome do carro: " << nomeCarro;

    // Define o tamanho mínimo e máximo da janela
    gerirCarro->setMinimumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->setMaximumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->lerDadosCarro(nomeCarro);

    gerirCarro->show();
    this->close();
}


void VerCarro::on_btnEstatistica_clicked()
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



void VerCarro::on_btnGuardarComo_clicked()
{
    QString nomeCarro = ui->labelNomeCarro->text().trimmed();
    QString folderName = nomeCarro.trimmed();

    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString sourceFolderPath = targetDir + "/" + folderName;

    QString backupDirPath = currentPath + "/../FSIPLeiria/backups";

    // Check if the "backups" directory exists
    QDir backupDir(backupDirPath);
    if (!backupDir.exists()) {
        // Create the "backups" directory
        if (!backupDir.mkpath(".")) {
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível criar o diretório de backups!"));
            return;
        }
    }

    // Open file dialog to choose the save location for the .zip file
    QString saveFilePath = QFileDialog::getSaveFileName(this, tr("Guardar como"), backupDirPath, tr("Arquivo ZIP (*.zip)"));

    if (!saveFilePath.isEmpty()) {
        // Check if the file already exists
        if (QFile::exists(saveFilePath)) {
            // Ask the user if they want to overwrite the existing file
            QMessageBox msgBox(QMessageBox::Question, tr("Confirmar Sobrescrita"), tr("O arquivo já existe. Deseja substituí-lo?"), QMessageBox::Yes | QMessageBox::No, this);

            QAbstractButton* yesButton = msgBox.addButton(tr("Sim"), QMessageBox::YesRole);
            msgBox.addButton(tr("Não"), QMessageBox::NoRole);

            msgBox.exec();

            if (msgBox.clickedButton() == yesButton) {
                // Remove the existing file
                if (!QFile::remove(saveFilePath)) {
                    QMessageBox::critical(this, tr("Erro"), tr("Não foi possível remover o arquivo existente!"));
                    return;
                }
            } else {
                // User chose not to overwrite, return without further action
                return;
            }
        }

        // Create the command to create the zip archive using 7z utility
        QString command = "7z a -r -tzip \"" + saveFilePath + "\" \"" + sourceFolderPath + "\"";

        // Create a QProcess to execute the command
        QProcess zipProcess;
        zipProcess.start("cmd.exe", QStringList() << "/C" << command);
        if (zipProcess.waitForFinished() && zipProcess.exitCode() == 0) {
            // Zip creation succeeded
            QMessageBox::information(this, tr("Arquivo ZIP Criado"), tr("O arquivo ZIP foi criado com sucesso!"));
        } else {
            // Zip creation failed
            QMessageBox::critical(this, tr("Erro"), tr("Não foi possível criar o arquivo ZIP!"));
        }
    }
}









