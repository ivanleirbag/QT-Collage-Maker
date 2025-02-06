#include "Layer.h"

Layer::Layer()
    :m_image(QImage())
    ,m_visible(false)
{}

Layer::Layer(const QImage &image, bool visible)
    :m_image(image),
    m_visible(visible)
{}

bool Layer::isVisible() const
{
    return m_visible;
}

void Layer::setVisible(bool value)
{
    m_visible = value;
}

QImage *Layer::getImage()
{
    return &m_image;
}

void Layer::setImage(const QImage &image)
{
    m_image = image;
}
