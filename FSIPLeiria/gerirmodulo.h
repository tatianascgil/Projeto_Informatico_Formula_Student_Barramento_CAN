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

private:
    Ui::GerirModulo *ui;
};

#endif // GERIRMODULO_H
