#ifndef TABELADADOS_H
#define TABELADADOS_H

#include <QDialog>

namespace Ui {
class TabelaDados;
}

class TabelaDados : public QDialog
{
    Q_OBJECT

public:
    explicit TabelaDados(QWidget *parent = nullptr);
    ~TabelaDados();

public slots:
    void loadMensagens(const QString& filePath);
    void setNome(const QString& nome);
    void setModulos(const QString& nome);
    void setCodigosHex(int index);
    void setCampos(int index);
    void setOperador();

private slots:
    void on_btnFiltrar_clicked();

    void on_commandButtonVoltar_clicked();

private:
    Ui::TabelaDados *ui;
};

#endif // TABELADADOS_H
