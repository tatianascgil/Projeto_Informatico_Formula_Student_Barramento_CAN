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


public slots:
    void setNome(const QString& nome);
    void setTipo(const QString& tipo);
    void setObservacoes(const QString& obs);


private slots:

    void on_commandButtonVoltar_clicked();

    void on_btnDefinicoes_clicked();

    void on_btnEstatistica_clicked();

    void on_btnGuardarComo_clicked();

private:
    Ui::VerCarro *ui;
};

#endif // VERCARRO_H
