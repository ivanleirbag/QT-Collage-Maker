#include "CollageGenerator.h"

CollageGenerator::CollageGenerator(const AvgColorMatrix &matrix, const std::vector<ImageData> &images, int width, int height, float randomFloor)
    :m_matrix(matrix)
    ,m_images(images)
    ,m_collageHeight(height)
    ,m_collageWidth(width)
    ,m_randomFloor(randomFloor)
{}

QImage CollageGenerator::generateCollage()
{
    const auto &matrix = m_matrix.getMatrix();
    int cellWidth = m_collageWidth / m_matrix.getColumns();
    int cellHeight = m_collageHeight / m_matrix.getRows();

    QImage collage(m_collageWidth, m_collageHeight, QImage::Format_RGB32);
    QPainter painter(&collage);

    for(size_t row = 0; row < matrix.size(); row++){
        for(size_t col = 0; col < matrix[row].size(); col++){
            QImage bestMatch = findBestMatch(matrix[row][col]);
            QImage scaledImage = bestMatch.scaled(cellWidth, cellHeight, Qt::IgnoreAspectRatio);

            painter.drawImage(col * cellWidth, row * cellHeight, scaledImage);
        }
    }

    return collage;
}

void CollageGenerator::setHeight(int collageHeight)
{
    m_collageHeight = collageHeight;
}

void CollageGenerator::setWidth(int collageWidth)
{
    m_collageWidth = collageWidth;
}

QImage CollageGenerator::findBestMatch(const QColor &targetColor)
{
    //starts with the highest value possible
    double minDistance = std::numeric_limits<double>::max();
    QImage bestMatch;
    QRandomGenerator *randomGen = QRandomGenerator::global();

    for(const ImageData &imageData : m_images){
        const QImage &image = imageData.image;

        if (image.isNull()) {
            qDebug() << "Skipping invalid image from " << imageData.imgPath;
            continue;
        }

        double randomDeviation = randomGen->bounded(m_randomFloor);

        QColor color = imageData.avgColor;
        double distanceSqrd =   std::pow(color.red() - targetColor.red() - randomDeviation, 2)+
                                std::pow(color.green() - targetColor.green() - randomDeviation, 2)+
                                std::pow(color.blue() - targetColor.blue() - randomDeviation, 2);

        if(distanceSqrd < minDistance){
            minDistance = distanceSqrd;
           // qDebug()<<"Best match distance: "<< distanceSqrd;
           // qDebug()<<"Best match color: "<< color;
            bestMatch = image;
        }

    }
    return bestMatch;
}
