#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "vercarro.h"
#include "ui_vercarro.h"
#include "criarmodulo.h"
#include "ui_criarmodulo.h"

GerirCarro::GerirCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GerirCarro)
{
    ui->setupUi(this);
}

GerirCarro::~GerirCarro()
{
    delete ui;
}

void GerirCarro::on_commandButtonVoltar_clicked()
{
    const int vercarroWidth = 700;
    const int vercarroHeight = 350;

    // Cria a janela principal
    VerCarro *vercarro = new VerCarro();

    // Define o tamanho mínimo e máximo da janela
    vercarro->setMinimumSize(vercarroWidth, vercarroHeight);
    vercarro->setMaximumSize(vercarroWidth, vercarroHeight);
    vercarro->show();
    this->close();
}


void GerirCarro::on_btnCriarModulo_clicked()
{
    const int criarmoduloWidth = 600;
    const int criarmoduloHeight = 250;

    // Cria a janela
    CriarModulo *criarmodulo = new CriarModulo();

    // Define o tamanho mínimo e máximo da janela
    criarmodulo->setMinimumSize(criarmoduloWidth, criarmoduloHeight);
    criarmodulo->setMaximumSize(criarmoduloWidth, criarmoduloHeight);
    criarmodulo->show();
    this->close();

}

