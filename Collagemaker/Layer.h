#ifndef LAYER_H
#define LAYER_H

#include <QImage>
//#include <QString>


class Layer
{   
public:
    Layer();

    Layer(const QImage &image, bool m_visible = true);

    bool isVisible() const;

    void setVisible(bool value);

    QImage *getImage();

    void setImage(const QImage &image);

private:
    QImage m_image;
    bool m_visible;
};

#endif // LAYER_H
