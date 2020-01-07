#include "Game.h"
#include <QMediaPlayer>
#include <QBrush>
#include <QImage>


Game::Game(QWidget * parent)
{

    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setScene(scene);
    setFixedSize(800,600);
    setBackgroundBrush(QBrush(QImage(":/sounds/sky.jpeg")));

    player = new Player();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    scene->addItem(player);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);


    player->setPos(width()/2,500);

    score = new Score();
    scene->addItem(score);
    health = new Health();
    scene->addItem(health);
    health->setPos(health->x(),health->y()+25);

    QTimer *timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    QMediaPlayer *musik = new QMediaPlayer();
    musik->setMedia(QUrl("qrc:/sounds/musik.mp3"));
    musik->play();


    show();
}
