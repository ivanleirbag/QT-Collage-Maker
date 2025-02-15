#include "PaintArea.h"

PaintArea::PaintArea(QWidget *parent)
    : QScrollArea(parent)
    , m_paintWidget(new PaintWidget())
{
    m_selectedTool = 0;
    m_brush = QColor(Qt::black);
    m_zoom = DEFAULT_ZOOM;

    setAlignment(Qt::AlignCenter);
    setBackgroundRole(QPalette::Midlight);
    setBlankLayer();
    setDefaultPen();
    setWidget(m_paintWidget);

    connect(m_paintWidget, &PaintWidget::mouseMove, this, &PaintArea::mouseMove);
    connect(m_paintWidget, &PaintWidget::mousePress, this, &PaintArea::mousePress);
    connect(m_paintWidget, &PaintWidget::mouseRelease, this, &PaintArea::mouseRelease);
}

PaintArea::~PaintArea()
{
    delete m_paintWidget;
}

QPen PaintArea::getPen()
{
    return m_pen;
}

void PaintArea::setBlankLayer(int width, int height, QColor fill)
{
    auto pixmap = QPixmap(width, height);
    pixmap.fill(fill);
    QImage image = pixmap.toImage().convertToFormat(QImage::Format_ARGB32_Premultiplied);
    m_paintWidget->setSingleLayer(image);
}

QImage PaintArea::saveImage()
{
    return m_paintWidget->renderImage();
}

QSize PaintArea::imageSize() const
{
    return m_paintWidget->size();
}

bool PaintArea::loadImage(const QString &path)
{
    QImage image = QImage();
    bool success = image.load(path);
    if(!success) {
        return false;
    }
    image = image.convertToFormat(QImage::Format_ARGB32_Premultiplied);
    m_paintWidget->setSingleLayer(image);
    return true;
}

int PaintArea::zoom() const
{
    return m_zoom;
}

void PaintArea::setZoom(int newZoom)
{
    m_zoom = newZoom;
    m_paintWidget->rezoom(m_zoom);
}

void PaintArea::setPenColor(const QColor &color)
{
    m_pen.setColor(color);
}

void PaintArea::setPenWidth(int width)
{
    m_pen.setWidth(width);
}

void PaintArea::mouseMove(const QPoint &pos, QImage *layer)
{
    if(m_collectMouseMove){
        QPoint adjusted = adjustedPos(pos);
        std::shared_ptr<PaintEvent> event(fillPaintEvent(adjusted, layer));
        m_tools[m_selectedTool]->onMouseMove(event.get());
        m_previousPoint = adjusted;
        m_paintWidget->repaint();
    }
}

void PaintArea::mousePress(const QPoint &pos, QImage *layer)
{
    m_collectMouseMove = true;
    QPoint adjusted = adjustedPos(pos);
    m_previousPoint = adjusted;
    std::shared_ptr<PaintEvent> event(fillPaintEvent(adjusted, layer));
    m_tools[m_selectedTool]->onMousePress(event.get());
    m_paintWidget->repaint();
}

void PaintArea::mouseRelease(const QPoint &pos, QImage *layer)
{
    m_collectMouseMove = false;
    QPoint adjusted = adjustedPos(pos);
    std::shared_ptr<PaintEvent> event(fillPaintEvent(adjusted, layer));
    m_tools[m_selectedTool]->onMouseRelease(event.get());
    m_paintWidget->repaint();
}

void PaintArea::setDefaultPen()
{
    static const int DEFAULT_PEN_WIDTH = 5;
    static const QColor DEFAULT_PEN_COLOR = QColor(Qt::black);
    m_pen.setCapStyle(Qt::RoundCap);
    m_pen.setJoinStyle(Qt::MiterJoin);
    m_pen.setColor(DEFAULT_PEN_COLOR);
    m_pen.setWidth(DEFAULT_PEN_WIDTH);
}

PaintEvent *PaintArea::fillPaintEvent(const QPoint &point, QImage *layer)
{
    auto event = new PaintEvent;
    event->brush = m_brush;
    event->currentPoint = point;
    event->pen = m_pen;
    event->previousPoint = m_previousPoint;
    event->selectedLayer = layer;
    event->toolLayer = m_paintWidget->getToolLayer();
    return event;
}

QPoint PaintArea::adjustedPos(const QPoint &pos)
{
    auto factor = 100.0 / m_zoom;
    return pos * factor;
}
