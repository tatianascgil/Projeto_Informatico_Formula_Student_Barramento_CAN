#ifndef CRIARTIPOMENSAGEM_H
#define CRIARTIPOMENSAGEM_H

#include <QDialog>
#include <gerirmodulo.h>
#include <ui_gerirmodulo.h>

namespace Ui {
class CriarTipoMensagem;
}

class CriarTipoMensagem : public QDialog
{
    Q_OBJECT

public:
    explicit CriarTipoMensagem(GerirModulo* gerirModulo, QWidget *parent = nullptr);
    ~CriarTipoMensagem();

public slots:
    void setNome(const QString& nome);
    void setNomeModulo(const QString& nome);

private slots:

    void on_btnCriarTipoMensagem_clicked();

    void on_commandButtonVoltar_clicked();

    void previousWindow();

private:
    Ui::CriarTipoMensagem *ui;
    GerirModulo* gerirModulo;
};

#endif // CRIARTIPOMENSAGEM_H
