#ifndef CRIARCARRO_H
#define CRIARCARRO_H

#include <QWidget>

namespace Ui {
class CriarCarro;
}

class CriarCarro : public QWidget
{
    Q_OBJECT

public:
    explicit CriarCarro(QWidget *parent = nullptr);
    ~CriarCarro();


signals:
    void carNameEntered(const QString& carName);

private slots:
    void on_btnCancelar_clicked();

    void on_btnCriarCarro_clicked();

    void on_commandButtonVoltar_clicked();

private:
    Ui::CriarCarro *ui;
};

#endif // CRIARCARRO_H
