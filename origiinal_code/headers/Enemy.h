#ifndef ENEMY_H
#define ENEMY_H

//#include <QGraphicsRectItem>
#include <QGraphicsPixmapItem>
#include <QObject> // REGLA GENERAL -> Todo objeto que vaya a ser conectado a través de signal/slot
//debe derivar de la clase QObject

// Es otro rectángulo

class Enemy : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT // Permite a una clase soportar signal & slots
public:
    Enemy();
public slots: //Slot significa que es una función miembro conectable a una "signal"
    void move();


};

#endif // ENEMY_H
