#ifndef PAINTTOOL_H
#define PAINTTOOL_H

#include "PaintEvent.h"

class PaintTool
{
public:
    virtual const QString toolName() = 0;
    virtual const QString iconName() = 0;
    virtual void onMousePress(PaintEvent*) = 0;
    virtual void onMouseRelease(PaintEvent*) = 0;
    virtual void onMouseMove(PaintEvent*) = 0;
};

#endif // PAINTTOOL_H
