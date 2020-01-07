#include "Player.h"
#include "Bullet.h"
#include <QGraphicsScene>
#include "Enemy.h"
#include <QMediaPlayer>
#include <QPixmap>


Player::Player()
{
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/bullet.wav"));
    setPixmap(QPixmap(":/sounds/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event)
{
    if(event->key()==Qt::Key_Left){
        if(this->pos().x()>0)
        setPos(x()-10,y());
    }
    if(event->key()==Qt::Key_Right){
        if(this->pos().x()<700)
        setPos(x()+10,y());
    }
    if(event->key()==Qt::Key_Space){
        Bullet *bullet = new Bullet();
        bullet->setPos(x()+48,y()-30);
        scene()->addItem(bullet);

        if(bulletsound->state() == QMediaPlayer::PlayingState)
        {
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState)
        {
            bulletsound->play();
        }

    }
}

void Player::spawn()
{
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
