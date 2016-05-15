#include <QApplication>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QGraphicsRectItem>
#include<QTimer>
#include<QTime>
#include<stdlib.h>
#include"MyRect.h"
#include"Bullet_1.h"
#include<QDebug>
#include"Game.h"

Game * game;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    game = new Game();
    game->show();
    game->displayMainMenu();

    return a.exec();
}
