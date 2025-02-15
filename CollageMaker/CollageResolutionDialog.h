#ifndef COLLAGERESOLUTIONDIALOG_H
#define COLLAGERESOLUTIONDIALOG_H

#include "qdialogbuttonbox.h"
#include <QDialog>

namespace Ui {
class CollageResolutionDialog;
}

class CollageResolutionDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CollageResolutionDialog(QWidget *parent = nullptr, int width = 1, int height = 1);
    ~CollageResolutionDialog();
    int getWidth();
    int getHeight();

private slots:
    void keepAspectRatio();
    void setWidth();
    void setHeight();

private:
    Ui::CollageResolutionDialog *ui;
    bool m_flag;
    double m_aspectRatio;
};

#endif // COLLAGERESOLUTIONDIALOG_H
