#ifndef GERIRCARRO_H
#define GERIRCARRO_H

#include <QWidget>

namespace Ui {
class GerirCarro;
}

class GerirCarro : public QWidget
{
    Q_OBJECT

public:
    explicit GerirCarro(QWidget *parent = nullptr);
    ~GerirCarro();

public slots:
    void setNome(const QString& nome);
    void lerDadosCarro(const QString& nome);
    void lerDadosModulo(const QString& nome);
    void openGerirModuloWindow(const QModelIndex& index);

private slots:
    void on_commandButtonVoltar_clicked();

    void on_btnCriarModulo_clicked();

    void on_btnApagarCarro_clicked();

    void on_btnGuardarCarro_clicked();

    void handleTableViewDoubleClick(const QModelIndex& index);


    void on_commandButtonMenuPrincipal_clicked();

private:
    Ui::GerirCarro *ui;
};

#endif // GERIRCARRO_H
