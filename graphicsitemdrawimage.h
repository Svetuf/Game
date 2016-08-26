#ifndef GRAPHICSITEMDRAWIMAGE_H
#define GRAPHICSITEMDRAWIMAGE_H

#include <QGraphicsItem>
#include <QImage>
#include <QPainter>

class GraphicsItemDrawImage : public QGraphicsItem
{
public:
    GraphicsItemDrawImage();
    GraphicsItemDrawImage(QImage image);

    QRectF boundingRect() const
    {
        return QRectF(QPointF(-160,-120), QPointF(160,120));
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        painter->drawImage(boundingRect(), myPicture);
    }

private:
    QImage myPicture;
};

#endif // GRAPHICSITEMDRAWIMAGE_H
