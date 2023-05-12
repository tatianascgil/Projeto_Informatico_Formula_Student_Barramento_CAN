#include "modulo.h"
#include "ui_modulo.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

Modulo::Modulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modulo)
{
    ui->setupUi(this);
}

Modulo::~Modulo()
{
    delete ui;
}

void Modulo::on_commandLinkButton_clicked()
{
    MainWindow *mainWindow = new MainWindow();
    mainWindow->show();
    this->close();
}

