#include"Game.h"
#include"button.h"
#include"GamePlay.h"
#include"Time.h"
#include<QGraphicsTextItem>
#include<QGraphicsPixmapItem>
#include<QObjectCleanupHandler>
#include<QImage>
#include<QFont>
#include<QTimer>
#include<QMediaPlayer>
#include <QQueue>
#include<QDebug>

Game::Game(QWidget *parent){
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    QPixmap pim(":/pics/bgh.png");
    scene->setBackgroundBrush(pim.scaled(800,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    setScene(scene);

    //decorate pictures
    QGraphicsPixmapItem * pic0 = new QGraphicsPixmapItem();
    pic0->setPixmap(QPixmap(":/pics/20.png"));
    scene->addItem(pic0);

    //decorate pictures
    QGraphicsPixmapItem * pic2 = new QGraphicsPixmapItem();
    pic2->setPixmap(QPixmap(":/pics/19.png"));
    scene->addItem(pic2);
    pic2->setPos(600,200);

    //play background music
    QMediaPlayer* music=new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sounds/bgmusic.mp3"));
    music->play();
    connect(music,SIGNAL(mediaStatusChanged(QMediaPlayer::MediaStatus)),music,SLOT(play()));
}
void Game::displayMainMenu(){
    //create the play Button
    Button* playButton = new Button(QString("Play"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 250;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //create the quit Button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);
}

void Game::endwindow(QWidget*parent){
    //set up the screen
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //set up the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    QPixmap pim(":/pics/proj.2pic/bg_miss_p2.png");
    scene->setBackgroundBrush(pim.scaled(800,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    setScene(scene);
    show();

    //create the restart Button
    Button* playButton = new Button(QString("ReStart"));
    int bxPos = this->width()/2 - playButton->boundingRect().width()/2;
    int byPos = 250;
    playButton->setPos(bxPos,byPos);
    connect(playButton,SIGNAL(clicked()),this,SLOT(start()));
    scene->addItem(playButton);

    //create the quit Button
    Button* quitButton = new Button(QString("Quit"));
    int qxPos = this->width()/2 - quitButton->boundingRect().width()/2;
    int qyPos = 350;
    quitButton->setPos(qxPos,qyPos);
    connect(quitButton,SIGNAL(clicked()),this,SLOT(close()));
    scene->addItem(quitButton);

    //create the score
    scene->addItem(score);
    score->setPos(310,150);//create the score
}

void Game::start(){
    scene->clear();
    QPixmap pim(":/pics/bg2.png");
    scene->setBackgroundBrush(pim.scaled(800,600,Qt::IgnoreAspectRatio,Qt::SmoothTransformation));
    GamePlay * gameplay = new GamePlay();
    gameplay->create();

    score = new Score();
    scene->addItem(score);
    score->setPos(0,50);//create the score

    time = new Time();
    scene->addItem(time);//create the time

    QTimer * timer0 = new QTimer();
    connect(timer0,SIGNAL(timeout()),this,SLOT(timecount()));
    timer0->start(1000);

    QTimer * timer1 = new QTimer();
    connect(timer1,SIGNAL(timeout()),timer0,SLOT(stop()));
    timer1->start(31000);
}


void Game::timecount(){
    time->decrease();
}

