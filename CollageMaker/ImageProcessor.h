#ifndef IMAGEPROCESSOR_H
#define IMAGEPROCESSOR_H

#include <QImage>
#include <QColor>
#include <QDebug>
#include <vector>
#include "ImageData.h"


class ImageProcessor
{
public:
    ImageProcessor();

    void addImage(const QString &filePath);

    const std::vector<ImageData> &getProcessedImages() const;

    void clearImages();

    void deleteImage(int index);

private:
    QColor calculateAvgColor(const QImage &image) const;

private:
    std::vector<ImageData> m_images;
};

#endif // IMAGEPROCESSOR_H
