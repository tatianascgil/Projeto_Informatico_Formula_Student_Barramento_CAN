#include "alterarcarro.h"
#include "ui_alterarcarro.h"
#include "vercarro.h"
#include "ui_vercarro.h"
#include "criarcarro.h"
#include "ui_criarcarro.h"

AlterarCarro::AlterarCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AlterarCarro)
{
    ui->setupUi(this);
}

AlterarCarro::~AlterarCarro()
{
    delete ui;
}

void AlterarCarro::on_commandButtonVoltar_clicked()
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


void AlterarCarro::on_btnCriarCarro_clicked()
{
    const int criarcarroWidth = 600;
    const int criarcarroHeight = 250;

    // Cria a janela principal
    CriarCarro *criarcarro = new CriarCarro();

    // Define o tamanho mínimo e máximo da janela
    criarcarro->setMinimumSize(criarcarroWidth, criarcarroHeight);
    criarcarro->setMaximumSize(criarcarroWidth, criarcarroHeight);
    criarcarro->show();
    this->close();

}

