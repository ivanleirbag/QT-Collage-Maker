#ifndef PAINTEVENT_H
#define PAINTEVENT_H

#include <QBrush>
#include <QPen>
#include <QPixmap>

struct PaintEvent{
    QPen pen;
    QBrush brush;
    QPixmap *toolLayer;
    QImage *selectedLayer;
    QPoint currentPoint;
    QPoint previousPoint;
};

#endif // PAINTEVENT_H
