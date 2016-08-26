#include "tile.h"

Tile::Tile() : QObject(), QGraphicsItem()
{

}

void Tile::collizingWithBall(Ball *ball)
{
    if(collidesWithItem(ball, Qt::IntersectsItemShape))
        deleteLater();
}
