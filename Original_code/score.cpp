#include <QFont>
#include "score.h"

Score::Score(QGraphicsItem *parent): QGraphicsTextItem(parent){
    // Inicializar puntuación a 0
    score=0;

    //Mostrar score
    setPlainText("Score: " + QString::number(score)); // Convierte int a string
    setDefaultTextColor(Qt::blue);
    setFont(QFont("times",16)); // Fuente, tamano de fuente
}

void Score::increase(){
    score++;
    // Actualizamos el valor, y volvemos a imprimir
    setPlainText("Score: " + QString::number(score)); // Convierte int a string
    setDefaultTextColor(Qt::blue);

}

int Score::getScore(){
    return score;
}
