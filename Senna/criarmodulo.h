#ifndef CRIARMODULO_H
#define CRIARMODULO_H

#include <QWidget>
#include <gerircarro.h>
#include <ui_gerircarro.h>

namespace Ui {
class CriarModulo;
}

class CriarModulo : public QWidget
{
    Q_OBJECT

public:
    explicit CriarModulo(GerirCarro* gerirCarro,QWidget *parent = nullptr);
    ~CriarModulo();

public slots:
    void setNome(const QString& nome);

private slots:
    void on_btnCriarModulo_clicked();

    void on_commandButtonVoltar_clicked();

    void previousWindow();



private:
    Ui::CriarModulo *ui;
    GerirCarro* gerirCarro;
};

#endif // CRIARMODULO_H
