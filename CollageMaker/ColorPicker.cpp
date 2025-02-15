#include "ColorPicker.h"
#include "qevent.h"

ColorPicker::ColorPicker(QWidget *parent, const QColor &color, bool clickable)
    : QLabel(parent)
    , m_dialog(new QColorDialog)
    , m_clickable(clickable)
{
    connect(m_dialog, &QColorDialog::colorSelected, this, &ColorPicker::setColor);
    setColor(color);
    setText(QStringLiteral("         "));
}

ColorPicker::~ColorPicker()
{
    delete m_dialog;
}


QColor ColorPicker::getColor() const
{
    return m_color;
}

void ColorPicker::openPickerDialog()
{
    m_dialog->setOption(QColorDialog::ShowAlphaChannel);
    m_dialog->setCurrentColor(m_color);
    m_dialog->show();
}


QColorDialog *ColorPicker::dialog() const
{
    return m_dialog;
}

void ColorPicker::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton && m_clickable){
        openPickerDialog();
    }
}

void ColorPicker::setColor(const QColor &color)
{
    m_color = color;
    setStyleSheet(QStringLiteral("border-style:inset;border-width:1px;border-color:#7A7A7A;")
                  + QStringLiteral("background:") + m_color.name());
    setWindowOpacity(m_color.alpha() / 255);
}
