#include "ImageProcessor.h"
#include "AvgColorMatrix.h"



ImageProcessor::ImageProcessor()
{}

void ImageProcessor::addImage(const QString &filePath)
{
    ImageData imgData;
    QImage image(filePath);

    if(image.isNull()){
        qDebug() <<"Could not load image from" << filePath;
        return;
    }

    QColor avgColor = calculateAvgColor(image);
    imgData.image = image;
    imgData.avgColor = avgColor;
    imgData.imgPath= filePath;
    m_images.push_back(imgData);
}

const std::vector<ImageData>& ImageProcessor::getProcessedImages() const
{
    return m_images;
}

void ImageProcessor::clearImages()
{
    m_images.clear();
}

void ImageProcessor::deleteImage(int index)
{
    if(index > 0 && index < m_images.size()){
        m_images.erase(m_images.begin() + index);
        qDebug() << "Succesfully deleted image at index " << index;
    }
}

QColor ImageProcessor::calculateAvgColor(const QImage &image) const
{
    const int size = 1;
    AvgColorMatrix avgColor(&image, size, size);
    auto matrix = avgColor.getMatrix();
    //qDebug() << "Avg color: " << matrix[0][0].name();
    return matrix[0][0];
}
