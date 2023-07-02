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

void CriarTipoMensagem::on_btnCriarTipoMensagem_clicked()
{

    QString codHex = ui->plainTextEditCodHex->toPlainText().toUpper();
    QString obs = ui->plainTextEditObs->toPlainText();
    QString nomeCarro = ui->labelNomeCarro->text().trimmed();
    QString nomeModulo = ui->labelNomeModulo->text().trimmed();

    // Iterate through each character in codHex
    for (const QChar& ch : codHex){
        // Check if the character is a valid hexadecimal digit
        if (!ch.isDigit() && (ch < 'A' || ch > 'F')) {
            QMessageBox::critical(this, "Erro", "O código Hexadecimal contém caracteres inválidos!");
            return;
        }
    }
    if(codHex.length() > 3){
        QMessageBox::critical(this, "Erro", "O código Hexadecimal só pode ter até 3 caractéres!");
        return;
    }

    if(codHex.isEmpty()){
        QMessageBox::critical(this, "Erro", "O campo Código Hexadecimal não pode estar vazio!");
        return;
    }

    if (obs.contains(";")) {
        QMessageBox::critical(this, "Erro", "É proibido utilizar semi-vírgulas ';'!");
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
        QMessageBox::critical(this, "Erro", "Erro. A pasta " + folderPath + " não existe!");
        return;
    }

    QString filePath = folderPath + "/tiposMensagem.txt";
    QFile readFile(filePath);

    if (!readFile.open(QIODevice::ReadOnly  | QIODevice::Text)) {
        if (readFile.open(QIODevice::WriteOnly  | QIODevice::Text)) {
            readFile.close();
        }else {
            // Failed to create the file
            QMessageBox::critical(this, "Erro", "Erro ao criar o arquivo " + filePath + "!");
            return;
        }
    }

    QTextStream readStream(&readFile);

    // Check if codHex already exists
    bool codHexExists = false;
    while (!readStream.atEnd()) {
        QString line = readStream.readLine();
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
        readFile.close();
        QMessageBox::critical(this, "Erro", "O código Hexadecimal já existe!");
        return;
    }

    readFile.close();


    // Display confirmation dialog
    QMessageBox confirmation(this);
    confirmation.setWindowTitle("Guardar Dados");
    confirmation.setText("Tem a certeza que pretende criar o Tipo de Mensagem 0x" + codHex + "?");
    confirmation.setIcon(QMessageBox::Question);

    // Translate the buttons
    confirmation.addButton("Sim", QMessageBox::YesRole);
    QPushButton* noButton = confirmation.addButton("Não", QMessageBox::NoRole);

    confirmation.exec();

    if (confirmation.clickedButton() == noButton) {
        // User canceled the operation
        return;
    }

    QFile writeFile(filePath);
    if (!writeFile.open(QIODevice::Append  | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Erro ao abrir o arquivo " + filePath + " para escrita!");
        return;
    }

    QTextStream writeStream(&writeFile);
    writeStream << nomeModulo << ";" << codHex << ";" << obs << ";\n";

    writeFile.close();

    QMessageBox::information(this, "Guardar Dados", "Dados salvados com sucesso!");

    previousWindow();
}


void CriarTipoMensagem::on_commandButtonVoltar_clicked()
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

    previousWindow();

}

void CriarTipoMensagem::previousWindow()
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






