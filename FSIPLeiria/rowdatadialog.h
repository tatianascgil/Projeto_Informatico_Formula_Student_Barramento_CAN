#ifndef ROWDATADIALOG_H
#define ROWDATADIALOG_H

#include <QDialog>
#include <QList>

namespace Ui {
class RowDataDialog;
}

class RowDataDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RowDataDialog(QWidget *parent = nullptr);
    ~RowDataDialog();
    void setRowData(const QList<QString>& rowData);

private:
    Ui::RowDataDialog *ui;
    // Other member variables and functions
};

#endif // ROWDATADIALOG_H
