#include "BrushTool.h"

const QString BrushTool::toolName()
{
    static const QString brushName = QStringLiteral("Brush");
    return brushName;
}

const QString BrushTool::iconName()
{
    static const QString brushIcon = QStringLiteral("Brush");
    return brushIcon;
}

void BrushTool::onMousePress(PaintEvent *event)
{
    paintPoint(event);
}

void BrushTool::onMouseRelease(PaintEvent *)
{

}

void BrushTool::onMouseMove(PaintEvent *event)
{
    paintLine(event);
}

void BrushTool::paintLine(PaintEvent *event)
{
    QPainter painter(event->selectedLayer);
    painter.setPen(event->pen);
    painter.drawLine(event->previousPoint, event->currentPoint);
}

void BrushTool::paintPoint(PaintEvent *event)
{
    QPainter painter(event->selectedLayer);
    painter.setPen(event->pen);
    painter.drawPoint(event->currentPoint);
}
