
#include "Player.h"
#include "Enemy.h"
#include <QDebug>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QDebug>
#include "Bullet.h"
#include <QAudioOutput>

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent){
    //Se define el sonido usado para el disparo. Se usará cada vez que se cre aun objeto "bullet"
    bulletSound = new QMediaPlayer();
    QAudioOutput * audioOutput = new QAudioOutput();
    bulletSound->setSource(QUrl("qrc:/sounds/BulletSound.mp3"));
    bulletSound->setAudioOutput(audioOutput);
    audioOutput->setVolume(25);

    // Imagen de jugador
    setPixmap(QPixmap(":/images/player.png"));

}

void Player::keyPressEvent(QKeyEvent *event)

// Todo lo que pasa con tecla pulsada
{
    // Event guarda la información del evento
    qDebug()<<"Player knows you pressed a key";

    if (event->key() == Qt::Key_Left){ //Movimiento izquierda
        if (pos().x() > 0){
            setPos(x()-10, y());
        }
    }

    else if (event->key() == Qt::Key_Right){ //Movimiento derecha
        if (pos().x() + 100 < 800){
            setPos(x()+10, y());
        }
    }

    // El punto de origen está en la esquina superior izquierda

    else if(event->key() == Qt::Key_Space){// Disparo
        //Crea una bullet
        Bullet * bullet = new Bullet();
        bullet->setScale(0.05);
        bullet->setRotation(-90);
        bullet->setPos(x()+50,y());
        scene()->addItem(bullet);

        // Sonido disparo

        bulletSound->setSource(QUrl("qrc:/sounds/BulletSound.mp3"));
        bulletSound->play(); // Si se deja así, sólo se escuchará una vez. Hay que hacer un check de su estado para reiniciar el sonido
        if(bulletSound->mediaStatus() == QMediaPlayer::PlayingState){ // Si el objeto ha sido ya reproducido...
            bulletSound->setPosition(25);
        }
        else if(bulletSound->mediaStatus() == QMediaPlayer::StoppedState){
            bulletSound->play();
        }

    }
}

void Player::spawn(){
    // Genera enemigo
    Enemy * enemy = new Enemy();
    scene()->addItem(enemy);
}

