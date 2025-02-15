#include "RandomPickDialog.h"
#include "CollageGenerator.h"
#include "ui_RandomPickDialog.h"

RandomPickDialog::RandomPickDialog(QWidget *parent, float randomValue)
    : QDialog(parent)
    , ui(new Ui::RandomPickDialog)
{
    ui->setupUi(this);

    ui->horizontalSlider->setMinimum(0);
    ui->horizontalSlider->setMaximum(MAX_RANDOMNESS);
    ui->horizontalSlider->setValue(randomValue);
    QString percentage = QString::number(randomValue) + QStringLiteral("%");
    ui->percentageLabel->setText(percentage);

    connect(ui->horizontalSlider,
            &QSlider::valueChanged,
            this,
            &RandomPickDialog::changePercentageLabel);
}

RandomPickDialog::~RandomPickDialog()
{
    delete ui;
}

float RandomPickDialog::getValue()
{
    return ui->horizontalSlider->value();
}

void RandomPickDialog::changePercentageLabel()
{
    QString percentage = QString::number(((ui->horizontalSlider->value()/MAX_RANDOMNESS))*100) + QStringLiteral("%");
    ui->percentageLabel->setText(percentage);
}

