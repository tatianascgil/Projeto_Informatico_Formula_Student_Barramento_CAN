#include "vercarro.h"
#include "ui_vercarro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gerircarro.h"
#include "ui_gerircarro.h"
#include "estatisticas.h"
#include "ui_estatisticas.h"
#include "alterarcarro.h"
#include "ui_alterarcarro.h"

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


void VerCarro::on_btnAlterarCarro_clicked()
{
    const int alterarcarroWidth = 800;
    const int alterarcarroHeight = 500;

    // Cria a janela
    AlterarCarro *alterarcarro = new AlterarCarro();

    // Define o tamanho mínimo e máximo da janela
    alterarcarro->setMinimumSize(alterarcarroWidth, alterarcarroHeight);
    alterarcarro->setMaximumSize(alterarcarroWidth, alterarcarroHeight);
    alterarcarro->show();
    this->close();
}

