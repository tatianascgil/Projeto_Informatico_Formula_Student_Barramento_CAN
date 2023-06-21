#ifndef GERIRMODULO_H
#define GERIRMODULO_H

#include <QDialog>

namespace Ui {
class GerirModulo;
}

class GerirModulo : public QDialog
{
    Q_OBJECT

public:
    explicit GerirModulo(QWidget *parent = nullptr);
    ~GerirModulo();
public slots:
    void lerDadosModulo(const QString& nomeModulo);
    void lerDadosTiposMensagem(const QString& nomeModulo);
    void openGerirTipoMensagemWindow(const QModelIndex& index);
    void setNome(const QString& nome);
    void setNomeModulo(const QString& nome);

private slots:
    void on_btnGuardarModulo_clicked();

    void on_commandButtonVoltar_clicked();

    void on_btnApagarModulo_clicked();

    void on_btnCriarTipoMensagem_clicked();

    void handleDoubleClick(const QModelIndex& index);

    void on_commandButtonMenuPrincipal_clicked();

private:
    Ui::GerirModulo *ui;
};

#endif // GERIRMODULO_H
