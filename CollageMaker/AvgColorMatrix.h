#ifndef AVGCOLORMATRIX_H
#define AVGCOLORMATRIX_H

#include "PaintArea.h"
#include <QImage>
#include <vector>
#include <QColor>
#include <QDebug>

static const int DEFAULT_MATRIX_COLS = PaintArea::DEFAULT_WIDTH*0.04;
static const int DEFAULT_MATRIX_ROWS = PaintArea::DEFAULT_HEIGHT*0.04;
static const int MAX_MATRIX_COLS = DEFAULT_MATRIX_COLS*100;
static const int MAX_MATRIX_ROWS = DEFAULT_MATRIX_ROWS*100;

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
