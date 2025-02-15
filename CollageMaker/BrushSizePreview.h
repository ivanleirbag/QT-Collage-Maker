#ifndef BRUSHSIZEPREVIEW_H
#define BRUSHSIZEPREVIEW_H

#include <QWidget>
#include <QColor>
#include <QPainter>

class BrushSizePreview : public QWidget
{
    Q_OBJECT

public:
    explicit BrushSizePreview(QWidget *parent = nullptr);
    ~BrushSizePreview();

    void setBrushSize(int size);
    int getBrushSize() const;

    void setBrushColor(const QColor &color);
    QColor getBrushColor() const;

private:
    void paintEvent(QPaintEvent *event) override;
    int m_brushSize;
    QColor m_brushColor;
};

#endif // BRUSHSIZEPREVIEW_H
