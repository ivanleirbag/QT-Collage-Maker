#ifndef BRUSHTOOL_H
#define BRUSHTOOL_H

#include <QPoint>
#include <QPainter>
#include "PaintTool.h"

class BrushTool : public PaintTool
{
public:
    const QString toolName() override;
    const QString iconName() override;
    virtual void onMousePress(PaintEvent *event) override;
    virtual void onMouseRelease(PaintEvent *) override;
    virtual void onMouseMove(PaintEvent *event) override;
private:
    void paintLine(PaintEvent *event);
    void paintPoint(PaintEvent *event);
};

#endif // BRUSHTOOL_H
