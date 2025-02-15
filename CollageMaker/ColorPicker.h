#ifndef COLORPICKER_H
#define COLORPICKER_H

#include <QColorDialog>
#include <QLabel>

class ColorPicker : public QLabel
{
    Q_OBJECT
public:
    ColorPicker(QWidget *parent = nullptr,
                const QColor &color = QColor(Qt::white),
                bool clickable = true);

    QColor getColor() const;
    void openPickerDialog();
    ~ColorPicker();
    QColorDialog *dialog()const;

private:
    QColorDialog *m_dialog;
    QColor m_color;
    bool m_clickable;
    void mouseReleaseEvent(QMouseEvent *event) override;

public slots:
    void setColor(const QColor &color);
};

#endif // COLORPICKER_H
