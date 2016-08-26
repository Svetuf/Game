#include "ball.h"

Ball::Ball() : QObject(), QGraphicsItem()
{
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerIsTimeout()));
    timer.start(2000);
    srand(time(NULL));
    xAvverage = 4;
    yAvverage = 4;
}

Ball::Ball(MyScene* scene) : QObject(), QGraphicsItem()
{
    myScene = scene;
    connect(&timer, SIGNAL(timeout()), this, SLOT(timerIsTimeout()));
    timer.start(2000);
    srand(time(NULL));
    xAvverage = 4;
    yAvverage = 4;
}

void Ball::timerIsTimeout()
{
    this->setPos(this->scenePos().x() + xAvverage, this->scenePos().y() + yAvverage);
    if(this->scenePos().x() >= (myScene->width() - 5) || this->scenePos().x() <= 5)
        xAvverage *= -1;
    if(this->scenePos().y() <= 5)
        yAvverage *= -1;
    if(this->scenePos().y() >= (myScene->height())){
        deleteLater();
        emit imDead();
    }
//    if(this->collidesWithItem(myScene->bottomPlatform,Qt::IntersectsItemShape))
//        yAvverage *= -1;

    int itemsSize = myScene->items().size();

    for(int i = 0; i < itemsSize; i++)
    {
        if(collidesWithItem(myScene->items()[i], Qt::IntersectsItemShape) && ( myScene->items()[i] != dynamic_cast<QGraphicsItem*>(this))  )
        {
            // TODO: сделат разрешение столкновения по сумме импульсов
            yAvverage *= -1;
            emit collized(this);
            break;
        }
    }

    timer.start(25);
}
