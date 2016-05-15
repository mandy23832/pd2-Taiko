#include"Bullet_2.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<typeinfo>
#include"MyRect.h"
#include<QList>
#include"Check.h"
#include<QKeyEvent>
#include"Game.h"

#include<QDebug>
extern Game * game;
Bullet_2::Bullet_2(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    getscoresound = new QMediaPlayer();
    getscoresound->setMedia(QUrl("qrc:/sounds/sound.mp3"));
    //set bullet_2
    setPixmap(QPixmap(":/pics/bullet_2.png"));//draw graphics
    //bullet move
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(40);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Bullet_2::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_W){
        getscoresound->play();
        scene()->removeItem(this);
        game->score->increase();
        delete this;
        return;
    }
}

void Bullet_2::move(){
    if(pos().x()<=210)
         setFocus();
    if(pos().x()<=140)
        clearFocus();

    setPos(x()-10,y());
    if(pos().x() < 0){
        scene()->removeItem(this);
        delete this;
        return;
    }
}
