#ifndef CRIARTIPOMENSAGEM_H
#define CRIARTIPOMENSAGEM_H

#include <QDialog>

namespace Ui {
class CriarTipoMensagem;
}

class CriarTipoMensagem : public QDialog
{
    Q_OBJECT

public:
    explicit CriarTipoMensagem(QWidget *parent = nullptr);
    ~CriarTipoMensagem();

private:
    Ui::CriarTipoMensagem *ui;
};

#endif // CRIARTIPOMENSAGEM_H
