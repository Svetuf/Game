#ifndef PLATFORM_H
#define PLATFORM_H

#include <QObject>
#include <QGraphicsItem>
#include <QRectF>
#include <QPen>
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPixmap>
#include <QImage>
#include <QKeyEvent>

#define RATIO_OF_THE_PICTURE_SIZE  2

class Platform : public QObject,  public QGraphicsItem
{
    Q_OBJECT

public:
    Platform();

    QRectF boundingRect() const
    {
        return QRect(QPoint(-10*RATIO_OF_THE_PICTURE_SIZE,-10*RATIO_OF_THE_PICTURE_SIZE),
                     QPoint(40*RATIO_OF_THE_PICTURE_SIZE,10*RATIO_OF_THE_PICTURE_SIZE));
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QPixmap picture;
        picture.load("/opt/qtdisk/newGame/platform.png");
        painter->drawPixmap(boundingRect().toRect(), picture);
    }
private:
    float countKeyPressedInARow = 0;
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void keyPressEvent(QKeyEvent* key);
    void keyReleaseEvent(QKeyEvent* prost);
};

#endif // PLATFORM_H
