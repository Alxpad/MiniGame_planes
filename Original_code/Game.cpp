
#include "Game.h"
#include <QApplication>
#include <QGraphicsScene>
//#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QTimer>
#include <QMediaPlayer>
#include <QAudioOutput>
#include <QImage>

Game::Game(QWidget * parent){
    //Crear scene
    QGraphicsScene * scene = new QGraphicsScene();
    //setBackgroundBrush(QBrush(QImage(":/images/background.jpg")));
    scene->setBackgroundBrush(QBrush(QImage(":/images/background.png")));


    // Creación del jugador
    Player * player = new Player(); // Por defecto, width & height = 0
    //player->setRect(0,0, 100, 100); --> Versión anterior
    player->setPos(400,500);
    player->setScale(0.2);

    // Hacer al item "focusable"
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus(); // será el que reciba los eventos

    //Añadir item a la escena
    scene->addItem(player); //La escena es "invisible"

    // Creación de puntuación/salud
    score = new Score();
    scene->addItem(score);

    health = new Health();
    health->setPos(health->x(), health->y()+25);
    scene->addItem(health);
    //health->setPos(health->x(), health->y(+25);
    //scene->addItem(health);


    //add a view
    QGraphicsView * view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //view->setScene(scene); Otra forma de inicializar
    view->show();
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);

    // Creación de enemigos
    QTimer * timer = new QTimer();
    QObject::connect(timer, SIGNAL(timeout()), player, SLOT(spawn()));
    timer->start(2000); // Contador para generar enemigos

    // Play música background
    QMediaPlayer * music = new QMediaPlayer();
    QAudioOutput * audioOutput = new QAudioOutput();
    music->setSource(QUrl("qrc:/sounds/BgMusic.mp3"));
    music->setAudioOutput(audioOutput);
    audioOutput->setVolume(0.5);
    music->play();
}
