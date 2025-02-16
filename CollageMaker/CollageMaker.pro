QT       += core gui opengl widgets openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AvgColorMatrix.cpp \
    BrushSizePopUp.cpp \
    BrushSizePreview.cpp \
    BrushSizeWidget.cpp \
    BrushTool.cpp \
    CollageGenerator.cpp \
    CollageImagesPreviewWidget.cpp \
    CollageResolutionDialog.cpp \
    CollageSubdivisionsDialog.cpp \
    ColorPicker.cpp \
    ImagePreview.cpp \
    ImageProcessor.cpp \
    Layer.cpp \
    PaintArea.cpp \
    PaintWidget.cpp \
    RandomPickDialog.cpp \
    ZoomSlider.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    AvgColorMatrix.h \
    BrushSizePopUp.h \
    BrushSizePreview.h \
    BrushSizeWidget.h \
    BrushTool.h \
    CollageGenerator.h \
    CollageImagesPreviewWidget.h \
    CollageResolutionDialog.h \
    CollageSubdivisionsDialog.h \
    ColorPicker.h \
    ImageData.h \
    ImagePreview.h \
    ImageProcessor.h \
    Layer.h \
    PaintArea.h \
    PaintEvent.h \
    PaintTool.h \
    PaintWidget.h \
    RandomPickDialog.h \
    ZoomSlider.h \
    mainwindow.h

FORMS += \
    BrushSizePopUp.ui \
    BrushSizeWidget.ui \
    CollageImagesPreviewWidget.ui \
    CollageResolutionDialog.ui \
    CollageSubdivisionsDialog.ui \
    RandomPickDialog.ui \
    ZoomSlider.ui \
    mainwindow.ui

TRANSLATIONS += \
    CollageMaker_es_AR.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
