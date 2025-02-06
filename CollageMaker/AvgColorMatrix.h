#ifndef AVGCOLORMATRIX_H
#define AVGCOLORMATRIX_H

#include <QImage>
#include <vector>
#include <QColor>
#include <QDebug>

static const int DEFAULT_MATRIX_COLS = 32;
static const int DEFAULT_MATRIX_ROWS = 24;

class AvgColorMatrix
{
public:
    AvgColorMatrix(const QImage *image, const int rows = DEFAULT_MATRIX_ROWS, const int cols = DEFAULT_MATRIX_COLS);
    ~AvgColorMatrix();

    const std::vector<std::vector<QColor>> &getMatrix() const;

    QColor getColorFrom(int row, int col) const;
    int getColumns() const;
    int getRows() const;
private:
    void generateMatrix();

private:
    int m_rows;
    int m_columns;
    const QImage *m_image;
    std::vector<std::vector<QColor>> m_colorMatrix;
};

#endif // AVGCOLORMATRIX_H
