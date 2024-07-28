
#include "Enemy.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include <stdlib.h> // Incluye función random()
#include "Game.h"
extern Game * game;
Enemy::Enemy() : QObject(), QGraphicsPixmapItem()
{
    //Imagen de enemigo
    setPixmap(QPixmap(":/images/enemy.png"));
    this->setScale(0.05);
    this->setRotation(180);

    //Posición de inicio alatoria
    int random_number = rand() % 600; // No queremos que se generen fuera de la pantalla, por eso 700 es el límite
    setPos(random_number, 0);

    //También empieza con tamaño 0
    // dibuja el rectángulo
    //setRect(0,0, 100,100); --> versión anterior

    //Conectando a slot
    QTimer * timer = new QTimer(); // Ése slot será llamado periódicamente

    // Función connect: connect({objeto cuya señal será conectada, señal a conectar, objeto de destino, función slot miembro})
    // La señal periódica timeout se conecta al slot "move" del objeto bullet. Bullet se mueve periódicamente.
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); // Tiempo del timer a 50ms
    // Cada bala tiene su timer, y se mueve independientemente.
}

void Enemy::move()
{
    // mueve "enemy" hacia abajo
    setPos(x(), y()+5);
    // Destruye "enemy" si sale de pantalla

    if (pos().y() > 600 ){
        qDebug()<<"Enemigo ha impactado";
        game->health->decrease();
        scene()->removeItem(this);
        delete this;
    }

    // reduce health
}
