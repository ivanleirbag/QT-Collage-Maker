#ifndef IMAGEPREVIEW_H
#define IMAGEPREVIEW_H

#include <QWidget>

static const int PREVIEW_WIDTH = 130;
static const int PREVIEW_HEIGHT = 98;

class ImagePreview : public QWidget
{
    Q_OBJECT

public:
    explicit ImagePreview(QWidget *parent = nullptr);
    ~ImagePreview();
    void loadImage(const QString &imagePath);
    void setColor(const QColor &color);
private:
    void paintEvent(QPaintEvent *event) override;
    QSize m_size;
    QImage m_image;
    QColor m_color;
    QString m_imagePath;
};

#endif // IMAGEPREVIEW_H
