#include "PaintWidget.h"

PaintWidget::PaintWidget(QWidget *parent)
    : QWidget(parent)
    , m_selectedLayer(0)
{
    QCursor cursor;
    cursor.setShape(Qt::CrossCursor);
    setCursor(cursor);

    QBitmap bitmap;
    if (!bitmap.load(QStringLiteral(":/background.bmp")))
        qDebug() <<"Could not load bitmap...";

    m_chekeredBackground.setTexture(bitmap);
    m_chekeredBackground.setColor(Qt::white);
}

void PaintWidget::mouseMoveEvent(QMouseEvent *event)
{
    emit mouseMove(event->pos(), m_layers[0].getImage());
}

void PaintWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && m_layers[0].isVisible())
        emit mousePress(event->pos(), m_layers[0].getImage());
}

void PaintWidget::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        emit mouseRelease(event->pos(), m_layers[0].getImage());
}

void PaintWidget::paintEvent(QPaintEvent *event)
{
    auto eventRect = event->rect();
    QPainter painter(this);
    painter.fillRect(rect(), m_chekeredBackground);
    if(m_layers.size() == 0){
        qDebug() << "There are no layers...";
        return;
    }
    qreal scaleX = size().width() / qreal(m_layers[0].getImage()->size().width());
    qreal scaleY = size().height() / qreal(m_layers[0].getImage()->size().height());
    qreal scale = qMin(scaleX, scaleY);
    auto imageRect = QRectF(eventRect.topLeft() / scale, eventRect.bottomRight() / scale);
    for (int i = 0; i < m_layers.size(); i++){
        if(m_layers[i].isVisible()){
            painter.drawImage(eventRect, *m_layers[i].getImage(), imageRect);
        }
    }
    painter.drawPixmap(eventRect, m_toolLayer, imageRect);
}

void PaintWidget::setSingleLayer(const QImage &image)
{
    m_layers.clear();
    m_layers.append(Layer(image));
    m_selectedLayer = 0;
    resize(image.size());
    setToolLayer(image.size());
    repaint();
}

void PaintWidget::setToolLayer(const QSize &size)
{
    m_toolLayer = QPixmap(size);
    m_toolLayer.fill(Qt::transparent);
}

Layer PaintWidget::getLayer(int layerIndex)
{
    if(layerIndex <= m_layers.size()-1){
        return m_layers[layerIndex];
    }else{
        return Layer();
    }
}

QImage PaintWidget::renderImage()
{
    if(m_layers.size() == 0){
        qDebug() << "There are no layers to render...";
        return QImage();
    }

    auto pixmap = QPixmap(size());
    pixmap.fill(Qt::transparent);
    QPainter painter(&pixmap);
    for(int i = 0; i < m_layers.size(); i++){
        if(m_layers[i].isVisible()){
            auto image = m_layers[i].getImage();
            painter.drawImage(QPoint(0,0), *image);
        }
    }
    //qDebug() << "Rendering image...";
    return pixmap.toImage();
}

QPixmap *PaintWidget::getToolLayer()
{
    return &m_toolLayer;
}

void PaintWidget::rezoom(int newZoom)
{
    if(m_layers.size() == 0){
        return;
    }
    auto layerSize = m_layers[0].getImage()->size();
    auto newSize = layerSize * (newZoom/100.0);

    resize(newSize);
}
