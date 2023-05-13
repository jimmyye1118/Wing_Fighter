
#include<QDebug>
#include<QGraphicsScene>
#include"Bullet.h"
#include "Player.h"
#include"Enemy.h"
Player::Player(QGraphicsItem *parent):QGraphicsPixmapItem(parent){
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sound/bullet.mp3"));

    setPixmap(QPixmap(":/images/player.png"));
}

void Player::keyPressEvent(QKeyEvent *event){
    if(event->key() == Qt::Key_Left){
        if(pos().x() > 0){
            setPos(x()-10,y());
        }
    }else if(event->key() == Qt::Key_Right){
        //pos().x()+100 is upper left corner
        if(pos().x() + 100<800){
            setPos(x()+10,y());
        }
    }
    else if(event->key() == Qt::Key_Space){
        //create a bullet
        Bullet*bullet = new Bullet();
        bullet->setPos(x()+100,y());
        scene()->addItem(bullet);

        //play bulletsound
        if(bulletsound->state()==QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
    }
}

void Player::spawn(){
    //create an enemy
    Enemy*enemy = new Enemy();
    scene()->addItem(enemy);
}
