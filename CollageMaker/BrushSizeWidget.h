#ifndef BRUSHSIZEWIDGET_H
#define BRUSHSIZEWIDGET_H

#include <QWidget>
#include "BrushSizePopUp.h"

namespace Ui {
class BrushSizeWidget;
}

class BrushSizeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit BrushSizeWidget(QWidget *parent = nullptr);
    ~BrushSizeWidget();
    void changeToolName(QString tool);
    void setPopupSliderValue(int size);
    QSlider *getSlider() const;
    void setBrushColor(const QColor &color);

public slots:
    void setBrushSize();

private slots:
    void showPopup();

private:
    int m_brushSize;
    BrushSizePopUp *popup;
    QString m_toolName;
    Ui::BrushSizeWidget *ui;
};

#endif // BRUSHSIZEWIDGET_H
