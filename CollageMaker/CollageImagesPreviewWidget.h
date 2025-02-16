#ifndef COLLAGEIMAGESPREVIEWWIDGET_H
#define COLLAGEIMAGESPREVIEWWIDGET_H

#include <QWidget>
#include "ImagePreview.h"

namespace Ui {
class CollageImagesPreviewWidget;
}

class CollageImagesPreviewWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CollageImagesPreviewWidget(QWidget *parent = nullptr, QString imagePath = "", QColor color = Qt::black);
    ~CollageImagesPreviewWidget();

private:
    ImagePreview *m_imagePreview;
    Ui::CollageImagesPreviewWidget *ui;
};

#endif // COLLAGEIMAGESPREVIEWWIDGET_H
