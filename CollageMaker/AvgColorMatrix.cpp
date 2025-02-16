#include "AvgColorMatrix.h"

AvgColorMatrix::AvgColorMatrix(const QImage *image, const int rows, const int cols)
    :m_rows(rows)
    ,m_columns(cols)
    ,m_image(image)
{
    generateMatrix();
}

AvgColorMatrix::~AvgColorMatrix()
{}

const std::vector<std::vector<QColor> > &AvgColorMatrix::getMatrix() const
{
    return m_colorMatrix;
}

QColor AvgColorMatrix::getColorFrom(int row, int col) const
{
    return m_colorMatrix[row][col];
}

int AvgColorMatrix::getColumns() const
{
    return m_columns;
}

int AvgColorMatrix::getRows() const
{
    return m_rows;
}

void AvgColorMatrix::generateMatrix()
{
    int cellWidth = m_image->width()/m_columns;
    int cellHeight = m_image->height()/m_rows;

    m_colorMatrix.resize(m_rows, std::vector<QColor>(m_columns));

    for(int row = 0; row < m_rows; row++){
        for(int col = 0; col < m_columns; col++){
            int startX = col * cellWidth;
            int startY = row * cellHeight;
            int endX = startX + cellWidth;
            int endY = startY + cellHeight;

            //Total color variables
            long long redSum = 0;
            long long greenSum = 0;
            long long blueSum = 0;
            long long pixelCount = 0;

            for(int y = startY; y < endY && y < m_image->height(); y++){
                for(int x = startX; x < endX && x < m_image->width(); x++){
                    QColor pixelColor = QColor(m_image->pixel(x, y));
                    redSum += pixelColor.red();
                    blueSum += pixelColor.blue();
                    greenSum += pixelColor.green();
                    pixelCount++;
                }
            }

            if(pixelCount > 0){
                int avgRed = redSum/pixelCount;
                int avgGreen = greenSum/pixelCount;
                int avgBlue = blueSum/pixelCount;
                m_colorMatrix[row][col] = QColor(avgRed, avgGreen, avgBlue);
                //qDebug() << "Average color: "<< m_colorMatrix[row][col];
            }
        }
    }
}
