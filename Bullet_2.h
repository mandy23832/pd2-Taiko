#ifndef BULLET_2_H
#define BULLET_2_H

#include<QGraphicsPixmapItem>
#include<QObject>
#include<QKeyEvent>
#include"Score.h"
#include<QMediaPlayer>

class Bullet_2: public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Bullet_2(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent*event);
    Score * score;
public slots:
    void move();
private:
    QMediaPlayer*getscoresound;

};

#endif // BULLET_2_H
