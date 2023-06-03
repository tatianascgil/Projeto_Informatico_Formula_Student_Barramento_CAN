#ifndef CRIARMODULO_H
#define CRIARMODULO_H

#include <QWidget>

namespace Ui {
class CriarModulo;
}

class CriarModulo : public QWidget
{
    Q_OBJECT

public:
    explicit CriarModulo(QWidget *parent = nullptr);
    ~CriarModulo();

public slots:
    void setNome(const QString& nome);

private slots:
    void on_commandButtonVoltar_clicked();

    void on_btnCriarModulo_clicked();

    void on_btnCancelar_clicked();


private:
    Ui::CriarModulo *ui;
};

#endif // CRIARMODULO_H
