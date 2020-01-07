#ifndef SCORE_H
#define SCORE_H

#include <QGraphicsTextItem>

class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent=nullptr);

    void incrase();
    int getScore() const;

private:
    int score=0;
};

#endif // SCORE_H
