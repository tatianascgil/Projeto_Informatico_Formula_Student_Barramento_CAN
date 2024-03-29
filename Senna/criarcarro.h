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

public slots:
    bool loadTiposCarro();

private slots:

    void on_btnCriarCarro_clicked();

    void on_commandButtonVoltar_clicked();

private:
    Ui::CriarCarro *ui;
};

#endif // CRIARCARRO_H
