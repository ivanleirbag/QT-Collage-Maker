#include "BrushSizePreview.h"
#include "PaintArea.h"

BrushSizePreview::BrushSizePreview(QWidget *parent)
    : QWidget(parent)
    , m_brushSize(PaintArea::MIN_PEN_WIDTH)
    , m_brushColor(Qt::black)
{
    setFixedSize(PaintArea::MAX_PEN_WIDTH+20, PaintArea::MAX_PEN_WIDTH+20);
}

BrushSizePreview::~BrushSizePreview()
{
}

void BrushSizePreview::setBrushSize(int size)
{
    m_brushSize = size;
    update();
}

int BrushSizePreview::getBrushSize() const
{
    return m_brushSize;
}

void BrushSizePreview::setBrushColor(const QColor &color)
{
    m_brushColor = color;
}

QColor BrushSizePreview::getBrushColor() const
{
    return m_brushColor;
}

void BrushSizePreview::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.fillRect(rect(), palette().window());

    painter.setBrush(m_brushColor);
    painter.setPen(Qt::NoPen);

    int x = (width() - m_brushSize)/2;
    int y = (height() - m_brushSize)/2;

    painter.drawEllipse(x, y, m_brushSize, m_brushSize);
}
