
#include "Bullet.h"
#include <QTimer>
#include <QDebug>
#include <QGraphicsScene>
#include "Enemy.h"
#include "Game.h"

extern Game* game;  // Instrucciones de compilador: hay un objeto "game" externo al archivo tipo Game*.

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
    //También empieza con tamaño 0
    // dibuja el rectángulo
    // setRect(0,0, 10,50) -- versión anterior;

    setPixmap(QPixmap(":/images/bullet.png"));
    //Conectando a slot
    QTimer * timer = new QTimer(); // Ése slot será llamado periódicamente

    // Función connect: connect({objeto cuya señal será conectada, señal a conectar, objeto de destino, función slot miembro})
    // La señal periódica timeout se conecta al slot "move" del objeto bullet. Bullet se mueve periódicamente.
    connect(timer,SIGNAL(timeout()), this, SLOT(move()));

    timer->start(50); // Tiempo del timer a 50ms
    // Cada bala tiene su timer, y se mueve independientemente.
}

void Bullet::move()
{
    // Si la bala colisiona con el enemigo, destruye ambos.
    // todos los QObject tienen una función para "colliding"
    QList<QGraphicsItem* >colliding_items = collidingItems(); // Devuelve todos los punteros de objetos que están colisionando con el objeto
    for (int i=0 , n =colliding_items.size(); i<n; ++i ){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            // Aumentar puntuación
            game->score->increase();

            //Se destruyen ambos
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            // Borrar del heap
            delete colliding_items[i];
            delete this; // No tiene sentido, dará error porque aún hay código moviendo el objeto bullet. Por éso añadimos return
            return;
        }
    }
    // mueve "bullet" hacia arriba
    setPos(x(), y()-10);
    if (pos().y() < 0 ){
        scene()->removeItem(this);
        delete this;
        //qDebug()<<"bullet deleted";
    }
}
