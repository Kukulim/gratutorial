#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    setPlainText("Score:" + QString::number(score));
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16));
}

void Score::incrase()
{
    score++;
    setPlainText("Score: " + QString::number(score));
}

int Score::getScore() const
{
    return score;
}
