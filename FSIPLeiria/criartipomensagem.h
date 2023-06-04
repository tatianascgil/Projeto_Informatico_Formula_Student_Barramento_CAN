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

public slots:
    void setNome(const QString& nome);
    void setNomeModulo(const QString& nome);

private slots:
    void on_commandButtonVoltar_clicked();

    void on_btnCriarTipoMensagem_clicked();

private:
    Ui::CriarTipoMensagem *ui;
};

#endif // CRIARTIPOMENSAGEM_H
