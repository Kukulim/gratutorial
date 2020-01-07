#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <QObject>
#include <QMediaPlayer>


class Player:public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player();
    void keyPressEvent(QKeyEvent *event);
public slots:
    void spawn();
private:
    QMediaPlayer *bulletsound;


};
#endif // MYRECT_H
