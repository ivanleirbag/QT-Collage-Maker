/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <PaintArea.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    PaintArea *paintArea;
    QGroupBox *groupBox;
    QPushButton *saveDrawing;
    QPushButton *selectImages;
    QPushButton *generateCollage;
    QSlider *brushSizeHorizontalSlider;
    QLabel *label_7;
    QSpinBox *imageHeightSpinBox;
    QLabel *label_2;
    QSlider *collageRandomHorizontalSlider;
    QSpinBox *matrixRowsSpinBox;
    QLabel *label_8;
    QLabel *label;
    QSpinBox *matrixColsSpinBox;
    QLabel *label_6;
    QSpinBox *imageWidthSpinBox;
    QLabel *label_5;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_9;
    QPushButton *selectSingleImage;
    QLabel *label_11;
    QLabel *label_10;
    QSlider *redVerticalSlider;
    QSlider *greenVerticalSlider;
    QSlider *blueVerticalSlider;
    QLabel *label_12;
    QSlider *alphaVerticalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1260, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setAutoFillBackground(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        paintArea = new PaintArea(centralwidget);
        paintArea->setObjectName("paintArea");
        sizePolicy.setHeightForWidth(paintArea->sizePolicy().hasHeightForWidth());
        paintArea->setSizePolicy(sizePolicy);
        paintArea->setMinimumSize(QSize(900, 600));

        gridLayout->addWidget(paintArea, 0, 1, 1, 1);

        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setEnabled(true);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        groupBox->setMinimumSize(QSize(300, 0));
        saveDrawing = new QPushButton(groupBox);
        saveDrawing->setObjectName("saveDrawing");
        saveDrawing->setGeometry(QRect(30, 460, 101, 23));
        selectImages = new QPushButton(groupBox);
        selectImages->setObjectName("selectImages");
        selectImages->setGeometry(QRect(30, 490, 101, 23));
        generateCollage = new QPushButton(groupBox);
        generateCollage->setObjectName("generateCollage");
        generateCollage->setGeometry(QRect(30, 520, 101, 23));
        brushSizeHorizontalSlider = new QSlider(groupBox);
        brushSizeHorizontalSlider->setObjectName("brushSizeHorizontalSlider");
        brushSizeHorizontalSlider->setGeometry(QRect(30, 230, 160, 16));
        brushSizeHorizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 160, 171, 16));
        label_7->setTextFormat(Qt::TextFormat::PlainText);
        label_7->setAlignment(Qt::AlignmentFlag::AlignCenter);
        imageHeightSpinBox = new QSpinBox(groupBox);
        imageHeightSpinBox->setObjectName("imageHeightSpinBox");
        imageHeightSpinBox->setGeometry(QRect(120, 60, 71, 23));
        imageHeightSpinBox->setMinimum(600);
        imageHeightSpinBox->setMaximum(99999);
        imageHeightSpinBox->setValue(1440);
        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 40, 171, 16));
        label_2->setTextFormat(Qt::TextFormat::PlainText);
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        collageRandomHorizontalSlider = new QSlider(groupBox);
        collageRandomHorizontalSlider->setObjectName("collageRandomHorizontalSlider");
        collageRandomHorizontalSlider->setGeometry(QRect(30, 180, 160, 16));
        collageRandomHorizontalSlider->setMaximum(700);
        collageRandomHorizontalSlider->setSingleStep(1);
        collageRandomHorizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        matrixRowsSpinBox = new QSpinBox(groupBox);
        matrixRowsSpinBox->setObjectName("matrixRowsSpinBox");
        matrixRowsSpinBox->setGeometry(QRect(120, 120, 71, 23));
        matrixRowsSpinBox->setMinimum(1);
        matrixRowsSpinBox->setMaximum(200);
        matrixRowsSpinBox->setValue(24);
        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 210, 171, 16));
        label_8->setTextFormat(Qt::TextFormat::PlainText);
        label_8->setAlignment(Qt::AlignmentFlag::AlignCenter);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 60, 21, 20));
        matrixColsSpinBox = new QSpinBox(groupBox);
        matrixColsSpinBox->setObjectName("matrixColsSpinBox");
        matrixColsSpinBox->setGeometry(QRect(20, 120, 71, 23));
        matrixColsSpinBox->setMinimum(1);
        matrixColsSpinBox->setMaximum(200);
        matrixColsSpinBox->setValue(32);
        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 100, 171, 16));
        label_6->setTextFormat(Qt::TextFormat::PlainText);
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);
        imageWidthSpinBox = new QSpinBox(groupBox);
        imageWidthSpinBox->setObjectName("imageWidthSpinBox");
        imageWidthSpinBox->setGeometry(QRect(20, 60, 71, 23));
        imageWidthSpinBox->setMinimum(800);
        imageWidthSpinBox->setMaximum(99999);
        imageWidthSpinBox->setValue(1920);
        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(100, 120, 21, 20));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 460, 16, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 490, 16, 20));
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(10, 520, 16, 20));
        selectSingleImage = new QPushButton(groupBox);
        selectSingleImage->setObjectName("selectSingleImage");
        selectSingleImage->setGeometry(QRect(150, 460, 101, 23));
        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(130, 460, 21, 20));
        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 260, 171, 16));
        label_10->setTextFormat(Qt::TextFormat::PlainText);
        label_10->setAlignment(Qt::AlignmentFlag::AlignCenter);
        redVerticalSlider = new QSlider(groupBox);
        redVerticalSlider->setObjectName("redVerticalSlider");
        redVerticalSlider->setGeometry(QRect(80, 280, 16, 91));
        redVerticalSlider->setMaximum(255);
        redVerticalSlider->setOrientation(Qt::Orientation::Vertical);
        greenVerticalSlider = new QSlider(groupBox);
        greenVerticalSlider->setObjectName("greenVerticalSlider");
        greenVerticalSlider->setGeometry(QRect(130, 280, 16, 91));
        greenVerticalSlider->setMaximum(255);
        greenVerticalSlider->setOrientation(Qt::Orientation::Vertical);
        blueVerticalSlider = new QSlider(groupBox);
        blueVerticalSlider->setObjectName("blueVerticalSlider");
        blueVerticalSlider->setGeometry(QRect(180, 280, 16, 91));
        blueVerticalSlider->setMaximum(255);
        blueVerticalSlider->setOrientation(Qt::Orientation::Vertical);
        label_12 = new QLabel(groupBox);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(20, 370, 181, 16));
        label_12->setTextFormat(Qt::TextFormat::PlainText);
        label_12->setAlignment(Qt::AlignmentFlag::AlignCenter);
        alphaVerticalSlider = new QSlider(groupBox);
        alphaVerticalSlider->setObjectName("alphaVerticalSlider");
        alphaVerticalSlider->setGeometry(QRect(30, 280, 16, 91));
        alphaVerticalSlider->setMaximum(255);
        alphaVerticalSlider->setOrientation(Qt::Orientation::Vertical);

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1260, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Collage Maker", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        saveDrawing->setText(QCoreApplication::translate("MainWindow", "Guardar Dibujo", nullptr));
        selectImages->setText(QCoreApplication::translate("MainWindow", "Seleccionar Img", nullptr));
        generateCollage->setText(QCoreApplication::translate("MainWindow", "Generar Collage", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Collage Homogeneity", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Collage Resolution", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "Brush Size", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", " x", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Collage Divisions", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", " x", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "1.", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "2.", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "3.", nullptr));
        selectSingleImage->setText(QCoreApplication::translate("MainWindow", "Cargar Img", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "  o", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Brush Color", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Alpha     Red     Green     Blue", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
