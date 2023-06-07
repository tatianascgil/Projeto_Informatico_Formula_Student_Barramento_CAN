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

public slots:
    void setNome(const QString& nome);
    void setNomeModulo(const QString& nome);
    void setCodigoHexadecimal(const QString& codHex);
    void setObservacoes(const QString& obs);

private slots:
    void on_spinBox_valueChanged(int arg1);
    void on_commandButtonVoltar_clicked();

    void on_btnGuardarCarro_clicked();

private:
    Ui::GerirTipoMensagem *ui;
};

#endif // GERIRTIPOMENSAGEM_H
