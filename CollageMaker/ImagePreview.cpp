#include "ImagePreview.h"
#include "qpainter.h"

ImagePreview::ImagePreview(QWidget *parent)
    : QWidget(parent)
{
    m_size = QSize(PREVIEW_WIDTH, PREVIEW_HEIGHT);
    setFixedSize(m_size);
}

ImagePreview::~ImagePreview()
{
}

void ImagePreview::loadImage(const QString &imagePath)
{
    m_imagePath = imagePath;
    if(m_imagePath.isNull()){
        qDebug() << "Path for image preview is null...";
        return;
    }

    m_image = QImage(imagePath);
    if(m_image.isNull()){
        qDebug() << "Could not load image for preview correctly...";
        return;
    }

    m_image = m_image.scaled(m_size, Qt::KeepAspectRatio);
}

void ImagePreview::setColor(const QColor &color)
{
    m_color = color;
}

void ImagePreview::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    painter.fillRect(rect(), palette().window());
    painter.setPen(Qt::NoPen);

    int x = (width()/2) - (m_image.width()/2);
    int y = (height()/2) - (m_image.height()/2);
    QPoint point(x, y);
    painter.drawImage(point, m_image);

    painter.setBrush(Qt::black);
    painter.drawRect(0, PREVIEW_HEIGHT-25, 25, 25);
    painter.setBrush(m_color);
    painter.drawRect(2, PREVIEW_HEIGHT-23, 21, 21);
}

