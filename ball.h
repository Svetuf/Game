#ifndef BALL_H
#define BALL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPen>
#include <QPainter>
#include <QGraphicsScene>
#include <QTimer>
#include <random>
#include <time.h>
#include "myscene.h"

#define RATIO_SIZE 2

class Ball : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    Ball();
    Ball(MyScene *scene);

    QRectF boundingRect() const
    {
        return QRectF(-5*RATIO_SIZE,-5*RATIO_SIZE,10*RATIO_SIZE,10*RATIO_SIZE);
    }

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
    {
        QImage ballTexture("/opt/qtdisk/newGame/ball2.png");
        painter->drawImage(boundingRect(), ballTexture);
    }

private:
    MyScene* myScene;
    int xAvverage;
    int yAvverage;
    QTimer timer;
public slots:
    void timerIsTimeout();
signals:
    void collized(Ball* b);
    void imDead();
};

#endif // BALL_H
