#include "mainwindow.h"
#include "ui_mainwindow.h"

static const QString FORMATS_FILTER = QStringLiteral(
    "Images (*.png *.bmp *.jpg *.jpeg *.gif);;All files (*.*)");
static const QString PICTURES_PATH = QStandardPaths::writableLocation(
    QStandardPaths::PicturesLocation);

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

    setStatusBar();
    setMenuBar();
    setPreviewSidePanel();
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
        //qDebug() << "Rendered drawing is null. Save failed...";
        return;
    }

    //qDebug() << "Loaded drawing succesfully...";
    QString fileName = QDir::currentPath() + "/collages/drawing_" + QDateTime::currentDateTime().toString("yyyyMMdd_HHmmss") + ".png";

    if(m_savedDrawing.save(fileName)){
        qDebug() << "Drawing saved in folder: " << fileName;
    }else{
        qDebug() << "Could not save drawing in folder: " << fileName;
    }
}

void MainWindow::setStatusBar()
{
    //brush size
    m_brushSizeWidget = new BrushSizeWidget(this);
    m_brushSizeWidget->setPopupSliderValue(m_paintArea->getPen().width());
    ui->statusbar->addPermanentWidget(m_brushSizeWidget);
    m_brushSizeWidgetSlider = m_brushSizeWidget->getSlider();
    connect(m_brushSizeWidgetSlider,
            &QSlider::valueChanged,
            this,
            &MainWindow::changePenWidth);

    //color picker
    ui->statusbar->addPermanentWidget(new QLabel(QStringLiteral("Color: ")));
    ui->statusbar->addPermanentWidget(&m_colorPicker);
    m_colorPicker.setColor(m_paintArea->getPen().color());
    connect(m_colorPicker.dialog(),
            &QColorDialog::colorSelected,
            this,
            &MainWindow::changePenColor);

    //zoom slider
    ui->statusbar->addPermanentWidget(new QLabel(QStringLiteral("Zoom: ")));
    ZoomSlider *zoom = new ZoomSlider();
    connect(zoom->slider(),
            &QSlider::valueChanged,
            m_paintArea,
            &PaintArea::setZoom);
    ui->statusbar->addPermanentWidget(zoom);
}

void MainWindow::setMenuBar()
{
    connect(ui->actionChange_resolution,
            &QAction::triggered,
            this,
            &MainWindow::changeCollageResolution);

    connect(ui->actionChange_Subdivitions,
            &QAction::triggered,
            this,
            &MainWindow::changeCollageSubdivisions);

    connect(ui->actionOpen_file,
            &QAction::triggered,
            this,
            &MainWindow::openFile);

    connect(ui->actionChange_random_pick,
            &QAction::triggered,
            this,
            &MainWindow::changeCollageRandomPick);

    connect(ui->actionSelect_images,
            &QAction::triggered,
            this,
            &MainWindow::selectImages);

    ui->actionGenerate_collage->setEnabled(false);
    connect(ui->actionGenerate_collage,
            &QAction::triggered,
            this,
            &MainWindow::generateCollage);
}

void MainWindow::setPreviewSidePanel()
{
    m_previewContainer = new QWidget(this);
    m_previewLayout = new QVBoxLayout(m_previewContainer);
    m_previewScrollArea = new QScrollArea(this);

    m_previewContainer->setLayout(m_previewLayout);

    m_previewScrollArea->setMaximumWidth(PREVIEW_WIDTH+55);
    m_previewScrollArea->setWidget(m_previewContainer);
    m_previewScrollArea->setWidgetResizable(true);

    ui->horizontalLayout->addWidget(m_previewScrollArea);
}

void MainWindow::selectImages()
{
    QStringList filePaths = QFileDialog::getOpenFileNames(
        this,
        QStringLiteral("Open images"),
        PICTURES_PATH,
        FORMATS_FILTER);

    if(filePaths.isEmpty()){
        qDebug() << "No images were selected...";
        return;
    }

    for(const QString &filePath : filePaths){
        m_imageProcessor.addImage(filePath);
    }

    for(const ImageData &imageData : m_imageProcessor.getProcessedImages()){
        CollageImagesPreviewWidget *preview = new CollageImagesPreviewWidget(this, imageData.imgPath, imageData.avgColor);
        m_previewLayout->addWidget(preview);
    }

    if(m_imageProcessor.getProcessedImages().size() > 0)
        ui->actionGenerate_collage->setEnabled(true);

    qDebug() << "Stored images: " << m_imageProcessor.getProcessedImages().size();
}

void MainWindow::generateCollage()
{
    saveDrawing();

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

void MainWindow::changeCollageResolution()
{
    auto dialog = new CollageResolutionDialog(this, m_collageWidth, m_collageHeight);
    dialog->setWindowModality(Qt::WindowModal);
    if (dialog->exec()){
        m_collageHeight = dialog->getHeight();
        m_collageWidth = dialog->getWidth();
        qDebug() << "New height value " << m_collageHeight;
        qDebug() << "New width value " << m_collageWidth;
    }
}

void MainWindow::changeCollageSubdivisions()
{
    auto dialog = new CollageSubdivisionsDialog(this, m_matrixCols, m_matrixRows);
    dialog->setWindowModality(Qt::WindowModal);
    if (dialog->exec()){
        m_matrixCols = dialog->getColumns();
        m_matrixRows = dialog->getRows();
        qDebug() << "New columns value " << m_matrixCols;
        qDebug() << "New rows value " << m_matrixRows;
    }
}

void MainWindow::changeCollageRandomPick()
{
    auto dialog = new RandomPickDialog(this, m_randomFloor);
    dialog->setWindowModality(Qt::WindowModal);
    if(dialog->exec()){
        m_randomFloor = dialog->getValue();
        qDebug() << "New random pick value " << m_randomFloor;
    }
}


void MainWindow::changePenWidth()
{
    int newWidth = m_brushSizeWidgetSlider->value();
    m_paintArea->setPenWidth(newWidth);
}

void MainWindow::changePenColor(const QColor &color)
{
    m_paintArea->setPenColor(color);
    m_brushSizeWidget->setBrushColor(color);
}


void MainWindow::openFile()
{
    auto file = QFileDialog::getOpenFileName(this,
                                             QStringLiteral("Open image"),
                                             PICTURES_PATH,
                                             FORMATS_FILTER);
    if (file.isNull()) {
        return;
    }
    if (m_paintArea->loadImage(file)) {
        qDebug() << "Succesfully opened file " << file;
    }else{
        qDebug() << "Could not open file " << file;
    }

    QImage selectedImage(file);
    if(selectedImage.isNull()){
        qDebug() << "There was a problem loading the image at " << file;
        return;
    }
    m_collageHeight = selectedImage.height()*4;
    m_collageWidth = selectedImage.width()*4;
    m_matrixCols = selectedImage.height()*0.04;
    m_matrixRows = selectedImage.width()*0.04;
    m_savedDrawing = selectedImage;
}
