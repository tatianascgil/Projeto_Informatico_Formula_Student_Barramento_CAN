#ifndef VERCARRO_H
#define VERCARRO_H

#include <QWidget>

namespace Ui {
class VerCarro;
}

class VerCarro : public QWidget
{
    Q_OBJECT

public:
    explicit VerCarro(QWidget *parent = nullptr);
    ~VerCarro();

private slots:

    void on_commandButtonVoltar_clicked();

    void on_btnDefinicoes_clicked();

    void on_btnEstatistica_clicked();

    void on_btnAlterarCarro_clicked();

private:
    Ui::VerCarro *ui;
};

#endif // VERCARRO_H
