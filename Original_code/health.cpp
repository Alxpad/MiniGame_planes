#include <QFont>
#include "health.h"
#include <QDebug>

Health::Health(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Inicializar salud a 3
    health=3;

    //Mostrar health
    setPlainText("Health: " + QString::number(health)); // Convierte int a string --> Health: 3
    setDefaultTextColor(Qt::red);
    setFont(QFont("times",16)); // Fuente, tamano de fuente
}

void Health::decrease(){
    health--;
    // Actualizamos el valor, y volvemos a imprimir
    setPlainText("Health: " + QString::number(health)); // Convierte int a string --> Health: 2
}

int Health::getHealth(){
    return health;
}
