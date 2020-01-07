#ifndef HEALTH_H
#define HEALTH_H

#include <QGraphicsTextItem>

class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem *parent=nullptr);

    void decrese();
    int getHealth() const;

private:
    int health=3;
};

#endif // HEALTH_H
