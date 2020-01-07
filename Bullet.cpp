#include "Bullet.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include "Enemy.h"
#include <QList>
#include <typeinfo>
#include "Game.h"

extern Game * game;

Bullet::Bullet(QGraphicsItem *parent):  QObject(), QGraphicsPixmapItem(parent){

    setPixmap(QPixmap(":/sounds/bullet.png"));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Bullet::move()
{
    QList <QGraphicsItem*> collidingItems = this->collidingItems();
    for(int i =0, n=collidingItems.size() ; i < n ; i++)
    {
        if (typeid(*(collidingItems[i]))==typeid (Enemy))
        {
            game->score->incrase();
              scene()->removeItem(collidingItems[i]);
              scene()->removeItem(this);
                delete collidingItems[i];
                delete this;
                return;
        }
    }
    setPos(x(),y()-10);
    if(pos().y() < 0)
    {
        scene()->removeItem(this);
        delete this;
    }
}
