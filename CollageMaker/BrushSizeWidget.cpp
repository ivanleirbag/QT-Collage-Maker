#include "BrushSizeWidget.h"
#include "ui_BrushSizeWidget.h"

BrushSizeWidget::BrushSizeWidget(QWidget *parent)
    : QWidget(parent)
    , m_toolName("Brush")
    , ui(new Ui::BrushSizeWidget)
{
    ui->setupUi(this);
    popup = new BrushSizePopUp(this);

    connect(ui->brushSizePushButton,
            &QPushButton::pressed,
            this,
            &BrushSizeWidget::showPopup);

    connect(popup->getSlider(),
            &QSlider::valueChanged,
            this,
            &BrushSizeWidget::setBrushSize);
}

BrushSizeWidget::~BrushSizeWidget()
{
    delete ui;
}

void BrushSizeWidget::changeToolName(QString tool)
{
    m_toolName = tool;
}

void BrushSizeWidget::setPopupSliderValue(int size)
{
    popup->setSliderValue(size);
}

QSlider *BrushSizeWidget::getSlider() const
{
    return popup->getSlider();
}

void BrushSizeWidget::setBrushColor(const QColor &color)
{
    popup->setColor(color);
}

void BrushSizeWidget::setBrushSize()
{
    m_brushSize = popup->getSlider()->value();
    QString labelMsg = m_toolName + QStringLiteral(" size: ") + QString::number(m_brushSize) + QStringLiteral(" px");
    ui->brushSizePushButton->setText(labelMsg);
    qDebug() << "new brush size: " << m_brushSize;
}


void BrushSizeWidget::showPopup()
{
    QPoint globalPos = mapToGlobal(QPoint(-12, -215));
    popup->move(globalPos);
    popup->show();
}
