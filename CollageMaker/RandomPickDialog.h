#ifndef RANDOMPICKDIALOG_H
#define RANDOMPICKDIALOG_H

#include "CollageGenerator.h"
#include <QDialog>

namespace Ui {
class RandomPickDialog;
}

class RandomPickDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RandomPickDialog(QWidget *parent = nullptr, float randomValue = DEFAULT_RANDOMNESS);
    ~RandomPickDialog();
    float getValue();

private slots:
    void changePercentageLabel();

private:
    Ui::RandomPickDialog *ui;
};

#endif // RANDOMPICKDIALOG_H
