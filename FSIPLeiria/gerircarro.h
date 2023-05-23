#ifndef GERIRCARRO_H
#define GERIRCARRO_H

#include <QWidget>

namespace Ui {
class GerirCarro;
}

class GerirCarro : public QWidget
{
    Q_OBJECT

public:
    explicit GerirCarro(QWidget *parent = nullptr);
    ~GerirCarro();

public slots:
    void setNome(const QString& nome);
    void lerDadosCarro();

private slots:
    void on_commandButtonVoltar_clicked();

    void on_btnCriarModulo_clicked();

private:
    Ui::GerirCarro *ui;
};

#endif // GERIRCARRO_H
