#include "criartipomensagem.h"
#include "ui_criartipomensagem.h"

CriarTipoMensagem::CriarTipoMensagem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CriarTipoMensagem)
{
    ui->setupUi(this);
}

CriarTipoMensagem::~CriarTipoMensagem()
{
    delete ui;
}
