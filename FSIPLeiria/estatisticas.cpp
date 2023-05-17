#include "estatisticas.h"
#include "ui_estatisticas.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Estatisticas::Estatisticas(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Estatisticas)
{
    ui->setupUi(this);
}

Estatisticas::~Estatisticas()
{
    delete ui;
}

void Estatisticas::on_commandButtonVoltar_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();

}

