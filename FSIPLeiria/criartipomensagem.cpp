#include "criartipomensagem.h"
#include "ui_criartipomensagem.h"
#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"
#include <QMessageBox>
#include <QDir>
#include <QFile>
#include <QPlainTextEdit>
#include <QDebug>


CriarTipoMensagem::CriarTipoMensagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CriarTipoMensagem)
{
    ui->setupUi(this);

}

CriarTipoMensagem::~CriarTipoMensagem()
{
    delete ui;
}

void CriarTipoMensagem::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome);
}


void CriarTipoMensagem::setNomeModulo(const QString& nome){
    ui->labelNomeModulo->setText(nome);
}


void CriarTipoMensagem::on_commandButtonVoltar_clicked()
{

    const int gerirModuloWidth = 800;
    const int gerirModuloHeight = 500;

    // Cria a janela GerirCarro
    GerirModulo *gerirModulo = new GerirModulo();

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();
    QString nomeModulo = ui->labelNomeModulo->text().trimmed();

    gerirModulo->setMinimumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->setMaximumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->setNome(nomeCarro);
    gerirModulo->setNomeModulo(nomeModulo);
    gerirModulo->lerDadosModulo(nomeModulo);
    gerirModulo->lerDadosTiposMensagem(nomeModulo);

    this->close();
    gerirModulo->show();
}


void CriarTipoMensagem::on_btnCriarTipoMensagem_clicked()
{

    QString codHex = ui->plainTextEditCodHex->toPlainText().toUpper();
    QString obs = ui->plainTextEditObs->toPlainText();
    QString nomeCarro = ui->labelNomeCarro->text().trimmed();
    QString nomeModulo = ui->labelNomeModulo->text().trimmed();


    if (obs.contains(";")) {
        QMessageBox::critical(this, "Erro", "É proibido utilizar semi-vírgulas ';'!");
        return;
    }

    QString folderName = nomeCarro;
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QDir folderDir(folderPath);
    if (!folderDir.exists()) {
        QMessageBox::information(this, "Erro", "Erro. A pasta " + folderPath + " não existe!");
        return;
    }

    if (!folderDir.mkpath(folderPath)) {
        QMessageBox::critical(this, "Erro", "Erro. A pasta " + folderPath + " não existe!");
        return;
    }

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile file(filePath);

    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Erro ao abrir o arquivo " + filePath + " para escrita!");
        return;
    }

    QTextStream stream(&file);

    // Check if codHex already exists
    bool codHexExists = false;
    while (!stream.atEnd()) {
        QString line = stream.readLine();
        QStringList fields = line.split(';');
        if (fields.size() >= 2) {
            QString existingCodHex = fields[1];
            if (existingCodHex == codHex) {
                codHexExists = true;
                break;
            }
        }
    }

    if (codHexExists) {
        file.close();
        QMessageBox::critical(this, "Erro", "O código Hexadecimal já existe!");
        return;
    }

    stream << nomeModulo << ";" << codHex << ";" << obs << ";\n";
    file.close();

    QMessageBox::information(this, "Guardar Dados", "Dados salvados com sucesso!");
    on_commandButtonVoltar_clicked();
}




