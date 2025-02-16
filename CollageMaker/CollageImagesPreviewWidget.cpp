#include "CollageImagesPreviewWidget.h"
#include "qboxlayout.h"
#include "ui_CollageImagesPreviewWidget.h"

CollageImagesPreviewWidget::CollageImagesPreviewWidget(QWidget *parent, QString imagePath, QColor color)
    : QWidget(parent)
    , ui(new Ui::CollageImagesPreviewWidget)
{
    ui->setupUi(this);
    QVBoxLayout *layout = new QVBoxLayout(this);

    m_imagePreview = new ImagePreview(this);
    m_imagePreview->loadImage(imagePath);
    m_imagePreview->setColor(color);

    layout->addWidget(m_imagePreview);
}

CollageImagesPreviewWidget::~CollageImagesPreviewWidget()
{
    delete ui;
}
