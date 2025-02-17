#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QDebug>
#include <QFileDialog>
#include <QStandardPaths>

#include "PaintArea.h"
#include "ImageProcessor.h"
#include "AvgColorMatrix.h"
#include "CollageGenerator.h"
#include "ZoomSlider.h"
#include "ColorPicker.h"
#include "CollageResolutionDialog.h"
#include "CollageSubdivisionsDialog.h"
#include "RandomPickDialog.h"
#include "BrushSizeWidget.h"
#include "CollageImagesPreviewWidget.h"
#include "qboxlayout.h"
#include "AddCollageImagesButton.h"

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
    ColorPicker m_colorPicker;
    BrushSizeWidget *m_brushSizeWidget;
    QSlider *m_brushSizeWidgetSlider;

    QScrollArea *m_previewScrollArea;
    QWidget *m_previewContainer;
    QVBoxLayout *m_previewLayout;
    AddCollageImagesButton *m_addImagesButton;

private:
    void saveDrawing();
    void setStatusBar();
    void setMenuBar();
    void setPreviewSidePanel();

private slots:
    void selectImages();
    void generateCollage();
    void changeCollageResolution();
    void changeCollageSubdivisions();
    void changeCollageRandomPick();
    void changePenWidth();
    void changePenColor(const QColor &color);
    void openFile();
};
#endif // MAINWINDOW_H
