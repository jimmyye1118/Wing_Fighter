
#ifndef Player_H
#define Player_H
#include<QGraphicsItem>
#include<QGraphicsPixmapItem>
#include<QKeyEvent>
#include<QObject>
#include<QMediaPlayer>

class Player:public QObject,public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Player(QGraphicsItem * parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
private:
    QMediaPlayer * bulletsound;
};

#endif // Player_H
