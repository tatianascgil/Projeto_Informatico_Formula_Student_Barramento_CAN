#include "criarmodulo.h"
#include "ui_criarmodulo.h"
#include "gerircarro.h"
#include "ui_gerircarro.h"

#include <QDir>
#include <QDebug>
#include <QMessageBox>

CriarModulo::CriarModulo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CriarModulo)
{
    ui->setupUi(this);
}

CriarModulo::~CriarModulo()
{
    delete ui;
}


void CriarModulo::setNome(const QString& nome){
    ui->labelNomeCarro->setText(nome);
}

void CriarModulo::on_commandButtonVoltar_clicked()
{
    const int gerirCarroWidth = 800;
    const int gerirCarroHeight = 500;

    // Cria a janela GerirCarro
    GerirCarro *gerirCarro = new GerirCarro();

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();


    gerirCarro->setNome(nomeCarro);
    gerirCarro->lerDadosCarro(nomeCarro);
    gerirCarro->lerDadosModulo(nomeCarro);

    // Define o tamanho mínimo e máximo da janela
    gerirCarro->setMinimumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->setMaximumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->show();
    this->close();
}


void CriarModulo::on_btnCriarModulo_clicked()
{

    QString nomeModulo = ui->textEditNomeModulo->toPlainText();
    QString obsModulo = ui->textEditObsModulo->toPlainText();
    QString nomeCarro = ui->labelNomeCarro->text().trimmed();

    bool nomeModuloEmpty = nomeModulo.trimmed().isEmpty();

    if (nomeModuloEmpty) {
        QMessageBox::critical(this, "Erro", "É obrigatório preencher o campo 'Nome'!");
        return;
    }

    if((nomeModulo.contains(";")) || (obsModulo.contains(";"))){
        QMessageBox::critical(this, "Erro", "É proíbido utilizar semi-vírgulas ';'!");
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
        QMessageBox::critical(this, "Erro", "Erro ao criar a pasta " + folderName);
        return;
    }

    // Saving the car data in a TXT file
    QString filePath = folderPath + "/modulos.txt";
    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
        QMessageBox::critical(this, "Erro", "Erro ao abrir o arquivo " + filePath + " para escrita!");
        return;
    }

    QString endianess;
    if (ui->radioButton_Littleendian->isChecked()) {
        endianess = "Little Endian";
    } else {
        endianess = "Big Endian";
    }

    QTextStream stream(&file);
    stream << nomeModulo << ";" << endianess << ";" << obsModulo << ";\n";

    file.close();

    QMessageBox::information(this, "Guardar Dados", "Dados salvados com sucesso!");
    on_commandButtonVoltar_clicked();

}




void CriarModulo::on_btnCancelar_clicked()
{

    //TODO - Verificar se os campos estão preenchidos
    const int gerirCarroWidth = 800;
    const int gerirCarroHeight = 500;

    // Cria a janela GerirCarro
    GerirCarro *gerirCarro = new GerirCarro();

    QString nomeCarro = ui->labelNomeCarro->text().trimmed();

    gerirCarro->setNome(nomeCarro);

    // Define o tamanho mínimo e máximo da janela
    gerirCarro->setMinimumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->setMaximumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->lerDadosCarro(nomeCarro);
    gerirCarro->lerDadosModulo(nomeCarro);

    gerirCarro->show();
    this->close();
}

