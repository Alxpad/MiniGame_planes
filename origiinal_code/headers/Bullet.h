#ifndef BULLET_H
#define BULLET_H

#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QObject> // REGLA GENERAL -> Todo objeto que vaya a ser conectado a través de signal/slot
//debe derivar de la clase QObject

// Es otro rectángulo

class Bullet : public QObject, /*public QGraphicsRectItem -- Versión anterior*/ public QGraphicsPixmapItem {
    Q_OBJECT // Permite a una clase soportar signal & slots
public:
    Bullet(QGraphicsItem* parent = 0);
public slots: //Slot significa que es una función miembro conectable a una "signal"
    void move();


};

#endif // BULLET_H
