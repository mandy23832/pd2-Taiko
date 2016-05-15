#ifndef BULLET_1_H
#define BULLET_1_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QKeyEvent>
#include"Score.h"
#include<QMediaPlayer>

class Bullet_1: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet_1(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent*event);
    Score * score;
public slots:
    void move();
private:
    QMediaPlayer*getscoresound;

};

#endif // BULLET_1_H
