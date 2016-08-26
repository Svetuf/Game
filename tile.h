#ifndef TILE_H
#define TILE_H

#include <QGraphicsItem>
#include <QPainter>
#include <QObject>
#include "ball.h"

class Tile : public QObject, public QGraphicsItem
{
public:

    Tile();

    Q_OBJECT



    QRectF boundingRect() const
    {
        return QRectF(-30,-8,60,16);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QImage tile("/opt/qtdisk/newGame/tile.png");
        painter->drawImage(boundingRect(), tile);
    }
public slots:
   void collizingWithBall(Ball* ball);

};

#endif // TILE_H
