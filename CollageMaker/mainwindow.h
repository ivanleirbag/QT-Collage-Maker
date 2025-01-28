#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QDebug>
#include <QFileDialog>

#include "PaintArea.h"
#include "ImageProcessor.h"
#include "AvgColorMatrix.h"
#include "CollageGenerator.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    PaintArea *paintArea() const;


private:
    Ui::MainWindow *ui;
    PaintArea *m_paintArea;
    QImage m_savedDrawing;
    ImageProcessor m_imageProcessor;
    int m_collageWidth;
    int m_collageHeight;
    int m_matrixCols;
    int m_matrixRows;
    float m_randomFloor;

private slots:
    void saveDrawing();
    void selectImages();
    void selectSingleImage();
    void generateCollage();
    void generateMatrix();
    void changeCollageHeight();
    void changeCollageWidth();
    void changeCollageRandomFloor();
    void changeColorMatrixCols();
    void changeColorMatrixRows();
    void changePenWidth();
    void changePenColor();

};
#endif // MAINWINDOW_H
