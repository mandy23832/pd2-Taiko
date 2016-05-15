#include"GamePlay.h"
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QGraphicsTextItem>
#include<QGraphicsProxyWidget>
#include<QTimer>
#include<stdlib.h>
#include<QMovie>
#include<QLabel>
#include<QFont>
#include<QString>
#include<QTextEdit>
#include<QObject>
#include"MyRect.h"
#include"Score.h"
#include"Bullet_1.h"
#include"Game.h"
#include"Time.h"
#include"Check.h"
#include<QPlainTextEdit>
#include<QWidget>

#include<QDebug>
extern Game*game;

//GamePlay::GamePlay(){}

void GamePlay::create(){
    //create items to the scene
    QGraphicsPixmapItem *checkbox = new QGraphicsPixmapItem();
    checkbox->setPixmap(QPixmap(":/pics/target.png"));
    game->scene->addItem(checkbox);//checkbox
    checkbox->setPos(158,155);

    MyRect * startbox = new MyRect();
    startbox->setRect(0,0,50,50);
    game->scene->addItem(startbox);//startbox

    QGraphicsPixmapItem * pic1 = new QGraphicsPixmapItem();
    pic1->setPixmap(QPixmap(":/pics/12.png"));
    game->scene->addItem(pic1);
    pic1->setPos(400,0);//decorate picture

    QGraphicsPixmapItem * pic_b1 = new QGraphicsPixmapItem();
    pic_b1->setPixmap(QPixmap(":/pics/2.png"));
    game->scene->addItem(pic_b1);
    pic_b1->setPos(630,400);//decorate picture

    QGraphicsTextItem * text_b1 = new QGraphicsTextItem();
    text_b1->setPlainText(QString("Q"));
    text_b1->setDefaultTextColor(Qt::blue);
    text_b1->setFont(QFont("Helvetica",34));
    text_b1->setPos(700,420);
    game->scene->addItem(text_b1);

    QGraphicsPixmapItem * pic_b2 = new QGraphicsPixmapItem();
    pic_b2->setPixmap(QPixmap(":/pics/bullet_2.png"));
    game->scene->addItem(pic_b2);
    pic_b2->setPos(630,500);//decorate picture

    QGraphicsTextItem * text_b2 = new QGraphicsTextItem();
    text_b2->setPlainText(QString("W"));
    text_b2->setDefaultTextColor(Qt::blue);
    text_b2->setFont(QFont("Helvetica",34));
    text_b2->setPos(700,520);
    game->scene->addItem(text_b2);

    QGraphicsPixmapItem*pic_out=new QGraphicsPixmapItem();
    pic_out->setPixmap(QPixmap(":/pics/32.png"));
    pic_out->setPos(0,136);
    game->scene->addItem(pic_out);//decorate picture

    QLabel *label =new QLabel();
    QMovie * movie = new QMovie(":/pics/25.gif");
    label->setMovie(movie);
    QGraphicsProxyWidget *proxy = game->scene->addWidget(label);
    game->scene->addItem(proxy);
    proxy->setPos(105,333);
    movie->start();//decorate picture gif

    QGraphicsView * view = new QGraphicsView(game->scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setFixedSize(1024,660);//create the view

    startbox->setPos(view->width() - startbox->rect().width(),142);//set startbox position

    //create drum every 1 sec
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),startbox,SLOT(spawn_l()));
    timer->start(1000);

}


