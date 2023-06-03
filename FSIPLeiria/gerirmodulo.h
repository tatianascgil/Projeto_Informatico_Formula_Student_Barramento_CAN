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
public slots:
    void loadModuloData(const QStringList& data);
    void setNome(const QString& nome);
private slots:
    void on_btnGuardarModulo_clicked();

    void on_commandButtonVoltar_clicked();

    void on_btnApagarModulo_clicked();

private:
    Ui::GerirModulo *ui;
};

#endif // GERIRMODULO_H
