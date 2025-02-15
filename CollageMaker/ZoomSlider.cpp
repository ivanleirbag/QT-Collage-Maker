#include "ZoomSlider.h"
#include "PaintArea.h"
#include "ui_ZoomSlider.h"

ZoomSlider::ZoomSlider(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ZoomSlider)
{
    ui->setupUi(this);
    ui->zoomSlider->setValue(PaintArea::DEFAULT_ZOOM);
    connect(ui->zoomSlider,
            &QSlider::valueChanged,
            this,
            &ZoomSlider::showZoomValue);
}

ZoomSlider::~ZoomSlider()
{
    delete ui;
}

QSlider *ZoomSlider::slider()
{
    return ui->zoomSlider;
}

void ZoomSlider::showZoomValue(int value)
{
    ui->zoomPercentageLabel->setText(QString::number(value) + QStringLiteral("%"));
}
