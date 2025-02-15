#ifndef BRUSHSIZEPOPUP_H
#define BRUSHSIZEPOPUP_H

#include <QDialog>
#include <QSlider>
#include "BrushSizePreview.h"
#include "ui_BrushSizePopUp.h"

class BrushSizePopUp : public QDialog
{
    Q_OBJECT

public:
    explicit BrushSizePopUp(QWidget *parent = nullptr);
    ~BrushSizePopUp();
    QSlider *getSlider();
    void setColor(const QColor &color);
    void setSliderValue(int size);

private slots:
    void resizeBrushPreview();

private:
    Ui::BrushSizePopUp *ui;
    QSlider *m_slider;
    BrushSizePreview *m_previewWidget;
};

#endif // BRUSHSIZEPOPUP_H
