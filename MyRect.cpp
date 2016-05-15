#include"MyRect.h"
#include<QGraphicsScene>
#include<QKeyEvent>
#include"Bullet_1.h"
#include"Bullet_2.h"
#include<QList>
#include<typeinfo>

#include<QDebug>


void MyRect::spawn_l(){
    int randnum = rand()%2;
    if(randnum==0){
       Bullet_1 * bullet_1 = new Bullet_1();
       bullet_1->setPos(x(),y());
       scene()->addItem(bullet_1);
    }
    if(randnum==1){
        Bullet_2 * bullet_2 = new Bullet_2();
        bullet_2->setPos(x(),y());
        scene()->addItem(bullet_2);
    }

}
