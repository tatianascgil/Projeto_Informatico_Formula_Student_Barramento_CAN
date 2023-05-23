#include "vercarro.h"
#include "ui_vercarro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "estatisticas.h"
#include "ui_estatisticas.h"


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
    const int gerircarroWidth = 800;
    const int gerircarroHeight = 500;

    // Cria a janela GerirCarro
    GerirCarro *gerircarro = new GerirCarro();

    gerircarro->setNome(ui->labelNomeCarro->text());

    // Define o tamanho mínimo e máximo da janela
    gerircarro->setMinimumSize(gerircarroWidth, gerircarroHeight);
    gerircarro->setMaximumSize(gerircarroWidth, gerircarroHeight);
    gerircarro->show();
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




