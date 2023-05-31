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

}

