#include<QGraphicsScene>
#include "Enemy.h"
#include<QTimer>
#include<QDebug>
#include<stdlib.h>
#include<Game.h>
#include"Health.h"
extern Game * game;//there is an exernal global object

Enemy::Enemy(QGraphicsItem * parent):QObject(),QGraphicsPixmapItem(parent){
    //set random position
    int random_number = rand()%700;
    setPos(random_number,0);


    //drew the rect
    setPixmap(QPixmap(":/images/enemy.png"));
    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Enemy::move(){
    // move enemy down;
    setPos(x(),y()+5);
    if(pos().y() >600){
        //decrease health
        game->health->decrease();

        scene()->removeItem(this);
        delete this;
    }

}


