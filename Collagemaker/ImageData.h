#ifndef IMAGEDATA_H
#define IMAGEDATA_H

#include <QColor>
#include <QImage>

struct ImageData
{
    QImage image;
    QString imgPath;
    QColor avgColor;
};

#endif // IMAGEDATA_H
