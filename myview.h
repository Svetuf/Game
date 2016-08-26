#ifndef MYVIEW_H
#define MYVIEW_H

#include <QGraphicsView>
#include <QMouseEvent>

class MyView : public QGraphicsView
{
public:
    MyView();
    MyView(QGraphicsScene* scene, QWidget* parent);
protected:
    void mouseMoveEvent(QMouseEvent* e);
};

#endif // MYVIEW_H
