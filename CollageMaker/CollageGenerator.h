#ifndef COLLAGEGENERATOR_H
#define COLLAGEGENERATOR_H

#include <QImage>
#include <vector>
#include <QPainter>
#include <QDebug>
#include <QRandomGenerator>

#include "AvgColorMatrix.h"
#include "ImageData.h"
#include "PaintArea.h"

static const int DEFAULT_COLLAGE_WIDTH = PaintArea::DEFAULT_WIDTH*4;
static const int DEFAULT_COLLAGE_HEIGHT = PaintArea::DEFAULT_HEIGHT*4;
static const int MAX_COLLAGE_WIDTH = 50000;
static const int MAX_COLLAGE_HEIGHT = 50000;
static const float DEFAULT_RANDOMNESS = 0.0;
static const float MAX_RANDOMNESS = 1000.0;


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
