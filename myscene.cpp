#include "myscene.h"



MyScene::MyScene() :QGraphicsScene()
{

}

MyScene::MyScene(QObject *parent) :QGraphicsScene(parent)
{
    QImage back("/opt/qtdisk/newGame/background.png");
    this->setBackgroundBrush(back);
}

void MyScene::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    QGraphicsScene::mouseMoveEvent(e);
}

void MyScene::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_Escape)
        emit escPressed();
    QGraphicsScene::keyPressEvent(e);
}
