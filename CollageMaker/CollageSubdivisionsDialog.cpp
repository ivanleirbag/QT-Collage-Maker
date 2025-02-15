#include "CollageSubdivisionsDialog.h"
#include "AvgColorMatrix.h"
#include "ui_CollageSubdivisionsDialog.h"

CollageSubdivisionsDialog::CollageSubdivisionsDialog(QWidget *parent, int columns, int rows)
    : QDialog(parent)
    , ui(new Ui::CollageSubdivisionsDialog)
    , m_aspectRatio(1.0)
{
    ui->setupUi(this);

    ui->colsSpinBox->setValue(columns);
    ui->rowsSpinBox->setValue(rows);
    ui->rowsSpinBox->setMaximum(MAX_MATRIX_ROWS);
    ui->colsSpinBox->setMaximum(MAX_MATRIX_COLS);

    m_aspectRatio = static_cast<double>(ui->colsSpinBox->value()) / static_cast<double>(ui->rowsSpinBox->value());

    connect(ui->colsSpinBox,
            &QSpinBox::valueChanged,
            this,
            &CollageSubdivisionsDialog::setColumns);
    connect(ui->rowsSpinBox,
            &QSpinBox::valueChanged,
            this,
            &CollageSubdivisionsDialog::setRows);
    connect(ui->aspectRatioCheckBox,
            &QCheckBox::checkStateChanged,
            this,
            &CollageSubdivisionsDialog::keepAspectRatio);
}

CollageSubdivisionsDialog::~CollageSubdivisionsDialog()
{
    delete ui;
}

int CollageSubdivisionsDialog::getColumns()
{
    return ui->colsSpinBox->value();
}

int CollageSubdivisionsDialog::getRows()
{
    return ui->rowsSpinBox->value();
}

void CollageSubdivisionsDialog::keepAspectRatio()
{
    if(ui->aspectRatioCheckBox->isChecked())
        m_aspectRatio = static_cast<double>(ui->colsSpinBox->value()) / static_cast<double>(ui->rowsSpinBox->value());
}

void CollageSubdivisionsDialog::setColumns()
{
    qDebug() << "New aspect ratio: "<< m_aspectRatio;
    if(ui->aspectRatioCheckBox->isChecked()){
        int adjusted = ui->colsSpinBox->value() / m_aspectRatio;
        qDebug() << "Adjusted columns: " << adjusted;
        ui->rowsSpinBox->blockSignals(true);
        ui->rowsSpinBox->setValue(adjusted);
        ui->rowsSpinBox->blockSignals(false);
    }
}

void CollageSubdivisionsDialog::setRows()
{
    qDebug() << "New aspect ratio: "<< m_aspectRatio;
    if(ui->aspectRatioCheckBox->isChecked()){
        int adjusted = ui->rowsSpinBox->value() * m_aspectRatio;
        qDebug() << "Adjusted height: " << adjusted;
        ui->colsSpinBox->blockSignals(true);
        ui->colsSpinBox->setValue(adjusted);
        ui->colsSpinBox->blockSignals(false);
    }
}
