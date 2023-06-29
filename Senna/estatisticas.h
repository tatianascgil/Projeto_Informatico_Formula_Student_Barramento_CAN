#ifndef ESTATISTICAS_H
#define ESTATISTICAS_H

#include <QWidget>

namespace Ui {
class Estatisticas;
}

class Estatisticas : public QWidget
{
    Q_OBJECT

public:
    explicit Estatisticas(QWidget *parent = nullptr);
    ~Estatisticas();

private slots:
    void on_commandButtonVoltar_clicked();

private:
    Ui::Estatisticas *ui;
};

#endif // ESTATISTICAS_H
