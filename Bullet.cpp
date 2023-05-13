#include<QGraphicsScene>
#include "Bullet.h"
#include<QTimer>
#include<QDebug>
#include<QList>
#include"Enemy.h"
#include"Score.h"
#include"Game.h"

extern Game * game;//there is an exernal global object

Bullet::Bullet():QObject(),QGraphicsPixmapItem(){
    //draw the rect
    setPixmap(QPixmap(":/images/bullet.png"));

    //connect
    QTimer *timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move(){
    //if bullect collides with enemy,destroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0,n = colliding_items.size();i<n;++i){
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            game->score->increase();

            //remove the both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //delete them both
            delete colliding_items[i];
            delete this;
            return;
        }
    }

    // move bullet up
    setPos(x(),y()-10);
    if(pos().y() + 50 <0){
        scene()->removeItem(this);
        delete this;
    }

}

