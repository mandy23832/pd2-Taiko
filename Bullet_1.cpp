#include"Bullet_1.h"
#include<QTimer>
#include<QGraphicsScene>
#include<QKeyEvent>
#include<typeinfo>
#include"MyRect.h"
#include<QList>
#include"Check.h"
#include<QKeyEvent>
#include<QElapsedTimer>
#include"Game.h"
#include<QCoreApplication>

#include<QDebug>
extern Game * game;

Bullet_1::Bullet_1(QGraphicsItem *parent):QObject(),QGraphicsPixmapItem(parent){
    getscoresound = new QMediaPlayer();
    getscoresound->setMedia(QUrl("qrc:/sounds/sound.mp3"));
    //set bullet_1
    setPixmap(QPixmap(":/pics/2.png"));//draw graphics
    //bullet move
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));
    timer->start(40);
    setFlag(QGraphicsItem::ItemIsFocusable);
}

void Bullet_1::move(){
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

void Bullet_1::keyPressEvent(QKeyEvent*event){
    if(event->key() == Qt::Key_Q){
        getscoresound->play();
        scene()->removeItem(this);
        game->score->increase();
        delete this;
        return;
    }
}
