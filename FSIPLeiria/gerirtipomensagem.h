#ifndef GERIRTIPOMENSAGEM_H
#define GERIRTIPOMENSAGEM_H

#include <QDialog>

namespace Ui {
class GerirTipoMensagem;
}

class GerirTipoMensagem : public QDialog
{
    Q_OBJECT

public:
    explicit GerirTipoMensagem(QWidget *parent = nullptr);
    ~GerirTipoMensagem();

private:
    Ui::GerirTipoMensagem *ui;
};

#endif // GERIRTIPOMENSAGEM_H
