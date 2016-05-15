#define GAME_H

#include<QGraphicsView>
#include<QGraphicsScene>
#include<QWidget>
#include"score.h"
#include"Time.h"

class Game:public QGraphicsView{
    Q_OBJECT
public:
    //constructor
    Game(QWidget*parent=NULL);

    //public methods
    void displayMainMenu();


    //public attribute
    QGraphicsScene * scene;
    Score * score;
    Time * time;

public slots:
    void start();
    void timecount();
    void endwindow(QWidget*parent=NULL);
};

#endif // GAME_H
