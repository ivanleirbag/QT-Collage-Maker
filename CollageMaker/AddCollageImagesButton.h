#ifndef ADDCOLLAGEIMAGESBUTTON_H
#define ADDCOLLAGEIMAGESBUTTON_H

#include "qpushbutton.h"
#include <QWidget>

namespace Ui {
class AddCollageImagesButton;
}

class AddCollageImagesButton : public QWidget
{
    Q_OBJECT

public:
    explicit AddCollageImagesButton(QWidget *parent = nullptr);
    ~AddCollageImagesButton();
    QPushButton *getButton();

private:
    Ui::AddCollageImagesButton *ui;
};

#endif // ADDCOLLAGEIMAGESBUTTON_H
