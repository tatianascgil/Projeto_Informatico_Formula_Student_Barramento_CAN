#ifndef TABELADADOS_H
#define TABELADADOS_H

#include <QDialog>
#include <QStandardItemModel>

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
    void filtrarComboBoxs();

    bool rowHasMatchingCampo(int row, const QString& selectedCampo) const;

    void on_commandButtonVoltar_clicked();

    void on_btnFiltrar_clicked();

private:
    Ui::TabelaDados *ui;
    QStandardItemModel* model;
};

#endif // TABELADADOS_H