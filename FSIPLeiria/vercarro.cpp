#include "vercarro.h"
#include "ui_vercarro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "estatisticas.h"
#include "ui_estatisticas.h"

#include <QMessageBox>


VerCarro::VerCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VerCarro)
{
    ui->setupUi(this);
     //ui->btnCreateFile->setPlaceholderText("Criar");


}


VerCarro::~VerCarro()
{
    delete ui;
}


void VerCarro::setNome(const QString& nome) {
    ui->labelNomeCarro->setText(nome.trimmed());
}

void VerCarro::setTipo(const QString& tipo) {
    ui->labelTipoCarro->setText(tipo);
}

void VerCarro::setObservacoes(const QString& obs) {
    ui->labelObsCarro->setText(obs.trimmed());
}


void VerCarro::on_commandButtonVoltar_clicked()
{

    QMessageBox::StandardButton confirmation = QMessageBox::question(this, "Voltar atrás", "Tem a certeza que pretende voltar atrás? Todos os dados serão perdidos!", QMessageBox::Yes | QMessageBox::No);
    if (confirmation == QMessageBox::No) {
        // User canceled the operation
        return;
    }

    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();

}


void VerCarro::on_btnDefinicoes_clicked()
{

    // Cria a janela GerirCarro
    GerirCarro *gerirCarro = new GerirCarro();

    QString nomeCarro = ui->labelNomeCarro->text();


    // Define o tamanho mínimo e máximo da janela
    const int gerirCarroWidth = 800;
    const int gerirCarroHeight = 500;
    gerirCarro->setMinimumSize(gerirCarroWidth, gerirCarroHeight);
    gerirCarro->setMaximumSize(gerirCarroWidth, gerirCarroHeight);

    gerirCarro->setNome(nomeCarro);
    gerirCarro->lerDadosCarro(nomeCarro);
    gerirCarro->lerDadosModulo(nomeCarro);
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




