#include "platform.h"

Platform::Platform() : QObject(), QGraphicsItem()
{
 //   setFlag(ItemIsMovable);
    setFlag(ItemIsFocusable);
    setFocus(Qt::OtherFocusReason);
}

void Platform::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
//   / this->setPos(event->pos());

    qDebug() << this->pos();
    QGraphicsItem::mouseMoveEvent(event);
}

void Platform::keyPressEvent(QKeyEvent *key)
{
    switch(key->key())
    {
    //case Qt::Key_W : this->setPos(this->x(), this->y() - 7.5+countKeyPressedInARow);break;
    //case Qt::Key_S : this->setPos(this->x(), this->y() + 7.5+countKeyPressedInARow);break;
    case Qt::Key_A : this->setPos(this->x() - 7.5+countKeyPressedInARow, this->y());break;
    case Qt::Key_D : this->setPos(this->x() + 7.5+countKeyPressedInARow, this->y());break;
    default : break;
    }
    countKeyPressedInARow += 0.25;
    qDebug() << "PRESSED";
}

void Platform::keyReleaseEvent(QKeyEvent *prost)
{
    countKeyPressedInARow = 0;
    qDebug() << "UNPRESSED";
}
