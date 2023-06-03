#ifndef MODULO_H
#define MODULO_H

#include <QDialog>

namespace Ui {
class Modulo;
}

class Modulo : public QDialog
{
    Q_OBJECT

public:
    explicit Modulo(QWidget *parent = nullptr);
    ~Modulo();

private slots:
    void on_commandLinkButton_clicked();

    void on_pushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::Modulo *ui;
};

#endif // MODULO_H
