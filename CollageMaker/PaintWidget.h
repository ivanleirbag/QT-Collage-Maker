#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QBitmap>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <memory>
#include "Layer.h"

class PaintWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PaintWidget(QWidget *parent = nullptr);

    //QWidget overrides
    void mouseMoveEvent(QMouseEvent *event) override;

    void mousePressEvent(QMouseEvent *event) override;

    void mouseReleaseEvent(QMouseEvent *event) override;

    void paintEvent(QPaintEvent *event) override;
    //End QWidget overrides

    void setSingleLayer(const QImage &image);

    void setToolLayer(const QSize &size);

    Layer getLayer(int layerIndex);

    QImage renderImage();

    QPixmap *getToolLayer();

private:

    int m_selectedLayer;

    QBrush m_chekeredBackground;

    QPixmap m_toolLayer;

    QVector<Layer> m_layers;


signals:
    void mousePress(const QPoint &pos, QImage *);

    void mouseRelease(const QPoint &pos, QImage *);

    void mouseMove(const QPoint &pos, QImage *);
};

#endif // PAINTWIDGET_H
