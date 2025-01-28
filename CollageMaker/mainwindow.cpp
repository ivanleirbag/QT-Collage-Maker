#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_paintArea = ui->paintArea;
    m_collageHeight = DEFAULT_COLLAGE_HEIGHT;
    m_collageWidth = DEFAULT_COLLAGE_WIDTH;
    m_randomFloor = DEFAULT_RANDOMNESS;
    m_matrixCols = DEFAULT_MATRIX_COLS;
    m_matrixRows = DEFAULT_MATRIX_ROWS;

    connect(ui->saveDrawing, &QPushButton::clicked, this, &MainWindow::saveDrawing);
    connect(ui->selectImages, &QPushButton::clicked, this, &MainWindow::selectImages);
    connect(ui->generateCollage, &QPushButton::clicked, this, &MainWindow::generateCollage);

    connect(ui->imageWidthSpinBox, &QSpinBox::valueChanged, this, &MainWindow::changeCollageWidth);
    connect(ui->imageHeightSpinBox, &QSpinBox::valueChanged, this, &MainWindow::changeCollageHeight);

    connect(ui->matrixColsSpinBox, &QSpinBox::valueChanged, this, &MainWindow::changeColorMatrixCols);
    connect(ui->matrixRowsSpinBox, &QSpinBox::valueChanged, this, &MainWindow::changeColorMatrixRows);

    connect(ui->collageRandomHorizontalSlider, &QSlider::valueChanged, this, &MainWindow::changeCollageRandomFloor);
}

MainWindow::~MainWindow()
{
    delete ui;
}

PaintArea *MainWindow::paintArea() const{
    return m_paintArea;
}

void MainWindow::saveDrawing()
{
    m_savedDrawing = m_paintArea->saveImage();

    if(m_savedDrawing.isNull()){
        qDebug() << "Rendered drawing is null. Save failed...";
        return;
    }

    qDebug() << "Saved drawing succesfully...";
    QString fileName = QDir::currentPath() + "/collages/drawing_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".png";

    if(m_savedDrawing.save(fileName)){
        qDebug() << "Drawing saved in folder: " << fileName;
    }else{
        qDebug() << "Could not save drawing...";
    }
}

void MainWindow::selectImages()
{
    QStringList filePaths = QFileDialog::getOpenFileNames(
        this,
        tr("Seleccionar Imágenes"),
        QString(),
        tr("Imágenes(*.png *.jpg *.jpeg)"));

    if(filePaths.isEmpty()){
        qDebug() << "No images were selected...";
        return;
    }

    for(const QString &filePath : filePaths){
        m_imageProcessor.addImage(filePath);
    }

    qDebug() << "Stored images: " << m_imageProcessor.getProcessedImages().size();
}

void MainWindow::generateCollage()
{
    if(m_savedDrawing.isNull()){
        qDebug() << "Could not analize drawing...";
        return;
    }

    const auto &processedImages = m_imageProcessor.getProcessedImages();
    if(processedImages.empty()){
        qDebug() << "There are no images analized for collage...";
        return;
    }

    AvgColorMatrix colorMatrix(&m_savedDrawing, m_matrixRows, m_matrixCols);

    CollageGenerator generator(colorMatrix, processedImages, m_collageWidth, m_collageHeight, m_randomFloor);
    QImage collage = generator.generateCollage();
    QString fileName = QDir::currentPath() + "/collages/collage_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".png";

    if(collage.save(fileName)){
        qDebug() << "Collage saved in folder: " << fileName;
    }else{
        qDebug() << "Could not save collage...";
    }
}

void MainWindow::generateMatrix()
{
}

void MainWindow::changeCollageHeight()
{
    m_collageHeight = ui->imageHeightSpinBox->value();
    qDebug() << "New height value " << m_collageHeight;
}

void MainWindow::changeCollageWidth()
{
    m_collageWidth = ui->imageWidthSpinBox->value();
    qDebug() << "New width value " << m_collageWidth;
}

void MainWindow::changeCollageRandomFloor()
{
    m_randomFloor = static_cast<float>(ui->collageRandomHorizontalSlider->value());
    qDebug() << "New random value " << m_randomFloor;
}

void MainWindow::changeColorMatrixCols()
{
    m_matrixCols = ui->matrixColsSpinBox->value();
    qDebug() << "New columns value " << m_matrixCols;
}

void MainWindow::changeColorMatrixRows()
{
    m_matrixRows = ui->matrixRowsSpinBox->value();
    qDebug() << "New rows value " << m_matrixRows;
}
