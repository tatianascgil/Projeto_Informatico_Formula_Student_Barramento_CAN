#include "criartipomensagem.h"
#include "ui_criartipomensagem.h"
#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"
#include <QMessageBox>
#include <QDir>
#include <QFile>

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

    gerirModulo->setNome(nomeCarro);
    gerirModulo->setNomeModulo(nomeModulo);


    gerirModulo->setMinimumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->setMaximumSize(gerirModuloWidth, gerirModuloHeight);
    gerirModulo->lerDadosModulo(nomeModulo);
    gerirModulo->lerDadosTiposMensagem(nomeModulo);

    this->close();
    gerirModulo->show();
}


void CriarTipoMensagem::on_btnCriarTipoMensagem_clicked()
{
    int nMensagens = ui->spinBoxNMsg->value();
    int codHex = ui->spinBoxCodHex->value();
    QString obs = ui->plainTextEditObs->toPlainText();
    QString nomeCarro = ui->labelNomeCarro->text().trimmed();
    QString nomeModulo = ui->labelNomeModulo->text().trimmed();

    if (obs.contains(";")) {
        QMessageBox::critical(this, "Erro", "É proibido utilizar semi-vírgulas ';'!");
        return;
    }

    QString folderName = nomeCarro.trimmed();
    QString currentPath = QDir::currentPath();
    QString targetDir = currentPath + "/../FSIPLeiria/settings";
    QString folderPath = targetDir + "/" + folderName;

    QDir folderDir(folderPath);
    if (!folderDir.exists()) {
        QMessageBox::information(this, "Erro", "Erro. A pasta " + folderPath + " não existe!");
        return;
    }

    if (folderDir.mkpath(folderPath)) {
        QString filePath = folderPath + "/tiposMensagem.txt";
        QFile file(filePath);

        // Check if codHex already exists
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            while (!in.atEnd()) {
                QString line = in.readLine();
                QStringList fields = line.split(';');
                if (fields.size() >= 2) {
                    int existingCodHex = fields[1].toInt();
                    if (existingCodHex == codHex) {
                        file.close();
                        QMessageBox::critical(this, "Erro", "O código Hexadecimal já existe!");
                        return;
                    }
                }
            }
            file.close();
        }

        if (file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text)) {
            QTextStream stream(&file);
            stream << nomeModulo << ";" << codHex << ";" << nMensagens << ";" << obs << "\n";
            file.close();

            QMessageBox::information(this, "Guardar Dados", "Dados salvados com sucesso!");
            on_commandButtonVoltar_clicked();
        } else {
            QMessageBox::critical(this, "Erro", "Erro ao guardar os dados!");
        }
    }
}


