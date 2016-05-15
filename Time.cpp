#include"Time.h"
#include"Game.h"
#include"Button.h"
#include<QGraphicsView>
#include<QGraphicsScene>
#include<QFont>
#include<QTimer>
#include<QDebug>
extern Game*game;

Time::Time(QGraphicsTextItem *parent):QGraphicsTextItem(parent){
    time=30;
    //draw the text
    setPlainText(QString("Time : ") + QString::number(time));
    setDefaultTextColor(Qt::blue);
    setFont(QFont("Helvetica",38));
}

int Time::decrease(){
        time--;
        setPlainText(QString("Time: ") + QString::number(time));
        if(time==0){
            game->close();
            game->endwindow();
        }

}

int Time::getTime(){
    return time;
}
