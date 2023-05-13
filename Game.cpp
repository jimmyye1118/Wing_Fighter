#include"Game.h"
#include<QTimer>
#include<QGraphicsTextItem>
#include<QFont>
#include"Enemy.h"
#include<QMediaPlayer>
#include<QBrush>
#include<QImage>

Game::Game(QWidget *parent){
    //create a scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600);
    setBackgroundBrush(QBrush(QImage(":/images/bg.jpg")));

    //make the newly created scene the scene to visualize
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    //create the player
    player = new Player();
    player->setPos(400,475);//make middle bottom
    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
        //add the player to the scene
    scene->addItem(player);

    //create the score/health
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    //spawm enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(2000);

    //play background music
    QMediaPlayer * music =new QMediaPlayer();
    music->setMedia(QUrl("qrc:/sound/bgsound.mp3"));
    music->play();
    show();

}
