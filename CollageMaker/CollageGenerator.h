#ifndef COLLAGEGENERATOR_H
#define COLLAGEGENERATOR_H

#include <QImage>
#include <vector>
#include <QPainter>
#include <QDebug>
#include <QRandomGenerator>

#include "AvgColorMatrix.h"
#include "ImageData.h"

static const int DEFAULT_COLLAGE_WIDTH = 1920;
static const int DEFAULT_COLLAGE_HEIGHT = 1440;
static const float DEFAULT_RANDOMNESS = 0.0;


class CollageGenerator
{
public:
    CollageGenerator(const AvgColorMatrix &matrix,
                     const std::vector<ImageData> &images,
                     int width = DEFAULT_COLLAGE_WIDTH,
                     int height = DEFAULT_COLLAGE_HEIGHT,
                     float randomFloor = DEFAULT_RANDOMNESS);
    QImage generateCollage();
    void setHeight(int collageHeight);
    void setWidth(int collageWidth);

private:
    const AvgColorMatrix &m_matrix;
    const std::vector<ImageData> &m_images;
    int m_collageHeight;
    int m_collageWidth;
    float m_randomFloor;

    QImage findBestMatch(const QColor &targetColor);
};

#endif // COLLAGEGENERATOR_H
