#ifndef ZOOMSLIDER_H
#define ZOOMSLIDER_H

#include <QSlider>
#include <QWidget>

namespace Ui {
class ZoomSlider;
}

class ZoomSlider : public QWidget
{
    Q_OBJECT

public:
    explicit ZoomSlider(QWidget *parent = nullptr);
    ~ZoomSlider();
    QSlider *slider();

private slots:
    void showZoomValue(int value);

private:
    Ui::ZoomSlider *ui;
};

#endif // ZOOMSLIDER_H
