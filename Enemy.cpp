#include "Enemy.h"

#include <QTimer>
#include <QGraphicsRectItem>
#include <QObject>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "Game.h"

extern Game *game;

Enemy::Enemy()
{
    int randomNumber = QRandomGenerator::global()->bounded(700);
    this->setPos(randomNumber,0);
    setPixmap(QPixmap(":/sounds/enemy.png"));
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(50);
}

void Enemy::move()
{
    setPos(x(),y()+5);
    if(pos().y() > 600)
    {
        game->health->decrese();
        scene()->removeItem(this);
        delete this;
    }
}
