#include "myview.h"

MyView::MyView() : QGraphicsView()
{

}

MyView::MyView(QGraphicsScene *scene, QWidget *parent) : QGraphicsView(scene,parent)
{

}

void MyView::mouseMoveEvent(QMouseEvent *e)
{
    QGraphicsView::mouseMoveEvent(e);
    this->update();
    this->scene()->update();
}
