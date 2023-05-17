#include "criarcarro.h"
#include "ui_criarcarro.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

CriarCarro::CriarCarro(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CriarCarro)
{
    ui->setupUi(this);
}

CriarCarro::~CriarCarro()
{
    delete ui;
}

void CriarCarro::on_btnCancelar_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


void CriarCarro::on_btnCriarCarro_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}


void CriarCarro::on_commandButtonVoltar_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

