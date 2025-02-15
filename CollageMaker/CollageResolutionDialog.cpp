#include "CollageResolutionDialog.h"
#include "CollageGenerator.h"
#include "ui_CollageResolutionDialog.h"

CollageResolutionDialog::CollageResolutionDialog(QWidget *parent, int width, int height)
    : QDialog(parent)
    , ui(new Ui::CollageResolutionDialog)
    , m_aspectRatio(1.0)
{
    ui->setupUi(this);

    ui->widthSpinBox->setValue(width);
    ui->heightSpinBox->setValue(height);
    ui->heightSpinBox->setMaximum(MAX_COLLAGE_HEIGHT);
    ui->widthSpinBox->setMaximum(MAX_COLLAGE_WIDTH);

    m_aspectRatio = static_cast<double>(ui->widthSpinBox->value()) / static_cast<double>(ui->heightSpinBox->value());
    connect(ui->widthSpinBox,
            &QSpinBox::valueChanged,
            this,
            &CollageResolutionDialog::setWidth);
    connect(ui->heightSpinBox,
            &QSpinBox::valueChanged,
            this,
            &CollageResolutionDialog::setHeight);
    connect(ui->aspectRatioCheckBox,
            &QCheckBox::checkStateChanged,
            this,
            &CollageResolutionDialog::keepAspectRatio);
}

CollageResolutionDialog::~CollageResolutionDialog()
{
    delete ui;
}

int CollageResolutionDialog::getWidth()
{
    return ui->widthSpinBox->value();
}

int CollageResolutionDialog::getHeight()
{
    return ui->heightSpinBox->value();
}


void CollageResolutionDialog::setWidth()
{
    qDebug() << "New aspect ratio: "<<m_aspectRatio;
    if(ui->aspectRatioCheckBox->isChecked()){
        int adjusted = ui->widthSpinBox->value() / m_aspectRatio;
        qDebug() << "Adjusted width: " << adjusted;
        ui->heightSpinBox->blockSignals(true);
        ui->heightSpinBox->setValue(adjusted);
        ui->heightSpinBox->blockSignals(false);
    }
}

void CollageResolutionDialog::setHeight()
{
    qDebug() << "New aspect ratio: "<< m_aspectRatio;
    if(ui->aspectRatioCheckBox->isChecked()){
        int adjusted = ui->heightSpinBox->value() * m_aspectRatio;
        qDebug() << "Adjusted height: " << adjusted;
        ui->widthSpinBox->blockSignals(true);
        ui->widthSpinBox->setValue(adjusted);
        ui->widthSpinBox->blockSignals(false);
    }
}

void CollageResolutionDialog::keepAspectRatio()
{
    if(ui->aspectRatioCheckBox->isChecked())
        m_aspectRatio = static_cast<double>(ui->widthSpinBox->value()) / static_cast<double>(ui->heightSpinBox->value());
}
