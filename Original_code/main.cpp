
#include "Game.h"
#include <QApplication>
/*Topics:
 *
 * - QGraphicsScene
 * - QGraphicsItem(QGraphicsrectItem)
 * - QGraphicsView -> Usado para visualizar la escena
 * - KeyPressEvent and QKeyEvent
 * - QDebug
 *
 * -- Tuto 3
 *
 * Hacer que l rectángulo dispare otros rectángulos
 *
 *-- Tuto 4
 *
 *Hay distintos sistemas de coordenadas en Qt
 *  - QGraphicsScene
 *  - QGraphicsView
 *  - MyRect
 *
 *  -- Tuto 5
 *  Creaciónd e clase "enemy"
 *
 * -- Tuto 6
 *Vida y Score
 *
 *-- Tuto 7
 *sonido
 *
 *-- Tuto 8
 *Gráficos
 *QGraphicsPixmapItem, QPixmap, QImage
 *Pixmap permite manegar pixeles individuales.

 */

Game * game; // Se trata de un objeto global, accesible para el resto de objetos.

int Main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();

    return a.exec();
}
