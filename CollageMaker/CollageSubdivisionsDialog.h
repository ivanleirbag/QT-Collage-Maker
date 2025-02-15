#ifndef COLLAGESUBDIVISIONSDIALOG_H
#define COLLAGESUBDIVISIONSDIALOG_H

#include "qspinbox.h"
#include <QDialog>

namespace Ui {
class CollageSubdivisionsDialog;
}

class CollageSubdivisionsDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CollageSubdivisionsDialog(QWidget *parent = nullptr, int columns = 1, int rows = 1);
    ~CollageSubdivisionsDialog();
    int getColumns();
    int getRows();

private slots:
    void keepAspectRatio();
    void setColumns();
    void setRows();

private:
    Ui::CollageSubdivisionsDialog *ui;
    bool m_flag;
    double m_aspectRatio;
};

#endif // COLLAGESUBDIVISIONSDIALOG_H
