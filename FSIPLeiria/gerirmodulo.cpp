#include "gerirmodulo.h"
#include "ui_gerirmodulo.h"

GerirModulo::GerirModulo(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GerirModulo)
{
    ui->setupUi(this);
}

GerirModulo::~GerirModulo()
{
    delete ui;
}
