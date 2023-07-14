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

private slots:
    double bigEndianConversion(const QStringList& fieldValues);

    double littleEndianConversion(const QStringList& fieldValues);

    void filtrarComboBoxs();

    void on_commandButtonVoltar_clicked();

    void on_btnGuardar_clicked();

private:
    Ui::TabelaDados *ui;
    QStandardItemModel* model;
    QStandardItemModel* filteredModel;
};

#endif // TABELADADOS_H
