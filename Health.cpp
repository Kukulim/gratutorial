#include "Health.h"
#include <QFont>


Health::Health(QGraphicsItem *parent)
{
    setPlainText("Health:" + QString::number(health));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16));
}

void Health::decrese()
{
    health--;
    setPlainText("Health: " + QString::number(health));
}

int Health::getHealth() const
{
    return health;
}
