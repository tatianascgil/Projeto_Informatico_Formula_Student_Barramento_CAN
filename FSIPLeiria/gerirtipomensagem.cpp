#include "gerirtipomensagem.h"
#include "ui_gerirtipomensagem.h"

GerirTipoMensagem::GerirTipoMensagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GerirTipoMensagem)
{
    ui->setupUi(this);
}

GerirTipoMensagem::~GerirTipoMensagem()
{
    delete ui;
}
