#ifndef MYRECT_H
#define MYRECT_H

#include <QGraphicsRectItem>
#include<QObject>

class MyRect: public QObject, public QGraphicsRectItem{
    Q_OBJECT
public slots:
    void spawn_l();
};

#endif // MYRECT_H
