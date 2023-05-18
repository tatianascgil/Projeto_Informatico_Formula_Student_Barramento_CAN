#ifndef ALTERARCARRO_H
#define ALTERARCARRO_H

#include <QWidget>

namespace Ui {
class AlterarCarro;
}

class AlterarCarro : public QWidget
{
    Q_OBJECT

public:
    explicit AlterarCarro(QWidget *parent = nullptr);
    ~AlterarCarro();

private slots:
    void on_commandButtonVoltar_clicked();


private:
    Ui::AlterarCarro *ui;
};

#endif // ALTERARCARRO_H
