#include "BrushSizePopUp.h"
#include "ui_BrushSizePopUp.h"
#include "BrushSizePreview.h"
#include "PaintArea.h"

#include <QVBoxLayout>

BrushSizePopUp::BrushSizePopUp(QWidget *parent)
    : QDialog(parent, Qt::Popup)
    , ui(new Ui::BrushSizePopUp)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);

    m_previewWidget = new BrushSizePreview(this);
    layout->addWidget(m_previewWidget);

    m_slider = new QSlider(Qt::Horizontal, this);
    m_slider->setMinimum(PaintArea::MIN_PEN_WIDTH);
    m_slider->setMaximum(PaintArea::MAX_PEN_WIDTH);
    m_slider->setValue(10);
    layout->addWidget(m_slider);

    connect(m_slider,
            &QSlider::valueChanged,
            this,
            &BrushSizePopUp::resizeBrushPreview);

    setLayout(layout);
}

BrushSizePopUp::~BrushSizePopUp()
{
    delete ui;
}

QSlider *BrushSizePopUp::getSlider()
{
    return m_slider;
}

void BrushSizePopUp::setColor(const QColor &color)
{
    m_previewWidget->setBrushColor(color);
}

void BrushSizePopUp::setSliderValue(int size)
{
    m_slider->setValue(size);
}

void BrushSizePopUp::resizeBrushPreview()
{
    int newSize = m_slider->value();
    m_previewWidget->setBrushSize(newSize);
}
