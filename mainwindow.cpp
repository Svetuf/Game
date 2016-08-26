#include "mainwindow.h"
#include "ui_mainwindow.h"

// ИТЕМЫ ДВИГАЛИСЬ ТК РАСШИРЯЛАСЬ СЦЕНА !!!

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setFixedSize(540,420);
    //this->setFixedSize(mySize);
    act = false;
    createMenu();
}

MainWindow::~MainWindow()
{

}

void MainWindow::createMenu()
{
    wi = new QWidget(this);
    wi->setFixedSize(this->size());
    QImage planet("/opt/qtdisk/newGame/earth.png");

    MyScene* scene1 = new MyScene(wi);
    scene1->setSceneRect(0,0, wi->width(), wi->height());
    scene1->setBackgroundBrush(planet);
    MyView* view1 = new MyView(scene1,wi);
    //setCentralWidget(view1);
    view1->show();

    int h = 40, w = 80;
    for(int i = 0; i < 4; i++)
    {
        QPushButton* r = new QPushButton(wi);
        r->setGeometry(30, 15 + i*h, w, h);
        buttons.push_back(r);
    }
    buttons[0]->setText("Start game");
    buttons[1]->setText("Settings");
    buttons[2]->setText("Help");
    buttons[3]->setText("About");
    connect(buttons[0], SIGNAL(pressed()), this, SLOT(startGameButtonPressed()));
    connect(buttons[1], SIGNAL(pressed()), this, SLOT(settings()));
    setCentralWidget(wi);
    return;
}

void MainWindow::createGame()
{
    buttons.clear();
    // all about scene
    scene = new MyScene(this);
    scene->setSceneRect(0,0, this->width() - 20, this->height() - 20);

    // all about items
    Platform* fp = new Platform();
    scene->bottomPlatform = fp;
    scene->addItem(fp);
    fp->setPos(this->width() / 2, this->height() - 35);
    Ball* testBall = new Ball(scene);
    scene->addItem(testBall);
    testBall->setPos(this->width() / 2, this->height() / 2);
    connect(scene, &MyScene::escPressed, this, &MainWindow::gameExit);
    connect(testBall, &Ball::imDead, this, &MainWindow::gameOver);
    //add tiles
    for(int j = 0; j < 5; j++)
    for(int i = 0; i < (this->width() / 60); i++)
    {
        Tile *t = new Tile();
        scene->addItem(t);
        t->setPos(20 + i*60, j*16);
        connect(testBall, SIGNAL(collized(Ball*)), t, SLOT(collizingWithBall(Ball*)));
    }
    TILE_I_HAD = 5*(this->width() / 60);
    // all about view
    // ne work ((
//    scene->setFocus(Qt::OtherFocusReason);
//    scene->clearFocus();
//    scene->setFocusItem(fp,Qt::OtherFocusReason);

    view = new MyView(scene,this);
    setCentralWidget(view);
    scene->setFocusItem(fp, Qt::OtherFocusReason);
    view->show();
}

void MainWindow::startGameButtonPressed()
{
    wi->deleteLater();
    createGame();
}

void MainWindow::settings()
{
    wi->deleteLater();

    settingsWidget = new QWidget(this);
    settingsWidget->setFixedSize(this->size());
    QImage planet("/opt/qtdisk/newGame/earth.png");

    MyScene* scene1 = new MyScene(settingsWidget);
    scene1->setSceneRect(0,0, settingsWidget->width(), settingsWidget->height());
    scene1->setBackgroundBrush(planet);
    MyView* view1 = new MyView(scene1,settingsWidget);
    view1->show();
    setCentralWidget(settingsWidget);

    QPushButton* back = new QPushButton(settingsWidget);
    back->setGeometry(10,5,100,50);
    back->setText("Back");
    connect(back, SIGNAL(clicked(bool)), this, SLOT(settingsEnd()));
    buttons.clear();
}

void MainWindow::settingsEnd()
{
    settingsWidget->deleteLater();
    wi = NULL;
    createMenu();
}

void MainWindow::gameExit()
{

//    view = NULL;
//    scene = NULL;
    if(act)
        return;
    wi = NULL;
    view->deleteLater();
    scene->deleteLater();
    createMenu();
    act = true;
    return;
}

void MainWindow::gameOver()
{
    QImage words("/opt/qtdisk/newGame/gameover2.png");
 //   words.scaled(QSize(this->width()*0.6,this->height() / 3));
    GraphicsItemDrawImage* i = new GraphicsItemDrawImage(words);
    scene->addItem(i);
    i->setPos(scene->width() / 2, scene->height() / 2);
    QTimer *timer = new QTimer;
    timer->start(2000);
    connect(timer, &QTimer::timeout, this, &MainWindow::gameExit);
}
