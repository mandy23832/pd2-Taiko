#ifndef TIME_H
#define TIME_H

#include<QGraphicsTextItem>
#include"Score.h"

class Time:public QGraphicsTextItem{
public:
    Time(QGraphicsTextItem * parent = 0);
    int getTime();
    int time;
    int decrease();
    Score * score;
};

#endif // TIME_H
