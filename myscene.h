#ifndef MYSCENE_H
#define MYSCENE_H

#include <QGraphicsScene>
#include <QMouseEvent>
#include <QObject>
#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include "platform.h"

class MyScene : public QGraphicsScene
{
    Q_OBJECT

public:
    MyScene();
    MyScene(QObject* parent);
    Platform *bottomPlatform;
protected:
    void mouseMoveEvent(QGraphicsSceneMouseEvent* event);
    void keyPressEvent(QKeyEvent* e);
signals:
    void escPressed();
};

#endif // MYSCENE_H
