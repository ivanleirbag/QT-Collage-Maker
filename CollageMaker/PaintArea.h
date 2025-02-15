#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QWidget>
#include <QScrollArea>
#include <QLabel>
#include <QOpenGLWidget>
#include <QPen>
#include <QPixmap>
#include <QVector>
#include <QApplication>
#include <QBitmap>
#include <QClipboard>
#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QTimer>
#include <QTransform>
#include <memory>

#include "PaintWidget.h"
#include "PaintEvent.h"

#include "BrushTool.h"

class PaintArea : public QScrollArea
{
    Q_OBJECT

public:
    explicit PaintArea(QWidget *parent = nullptr);

    ~PaintArea();

    enum PaintLimits {
        MAX_PEN_WIDTH = 150,
        MAX_ZOOM = 300,
        MIN_PEN_WIDTH = 1,
        MAX_IMAGE_SIZE = 3000,
        MIN_IMAGE_SIZE = 1,
        DEFAULT_WIDTH = 800,
        DEFAULT_HEIGHT = 600,
        DEFAULT_ZOOM = 100
    };

    QPen getPen();

    void setBlankLayer(int width = DEFAULT_WIDTH,
                       int height = DEFAULT_HEIGHT,
                       QColor fill = QColor(Qt::white));

    QImage saveImage();

    QSize imageSize() const;

    bool loadImage(const QString &path);

    int zoom() const;

    void setZoom(int newZoom);

public slots:

    void setPenColor(const QColor &color);

    void setPenWidth(int width);

    void mouseMove(const QPoint &pos, QImage *layer);

    void mousePress(const QPoint &pos, QImage *layer);

    void mouseRelease(const QPoint &pos, QImage *layer);

private:
    void setDefaultPen();

    PaintEvent *fillPaintEvent(const QPoint &point, QImage *layer);

    QPoint adjustedPos(const QPoint &pos);

    const QVector<PaintTool *> m_tools{new BrushTool()};
    int m_zoom;
    bool m_collectMouseMove;
    int m_selectedTool; //
    PaintWidget *m_paintWidget;
    QPoint m_previousPoint;
    QPen m_pen;
    QBrush m_brush;

};

#endif // PAINTAREA_H
