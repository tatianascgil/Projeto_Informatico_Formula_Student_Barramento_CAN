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

void GerirModulo::loadModuloData(const QStringList& data)
{
    if (data.size() >= 4) {
        QString nome = data.at(0);

        ui->labelNomeModulo->setText(nome);
    }
    else {
        // Handle the case where the data size is not as expected
    }
}
