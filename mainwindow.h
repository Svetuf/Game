#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsScene>
#include <QSize>
#include <QGraphicsView>
#include <vector>
#include <QTimer>
#include "platform.h"
#include "myscene.h"
#include "myview.h"
#include "ball.h"
#include "tile.h"
#include "graphicsitemdrawimage.h"

using namespace std;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QSize mySize = QSize(120,720);
    int DIFICULT_RATIO = 0;
    int TILE_I_HAD = 0;
    MyView* view;
    MyScene* scene;
    QWidget* wi;
    QWidget* settingsWidget;
    vector<QPushButton*>buttons;
    void createGame();

public slots:
    void startGameButtonPressed();
    void settings();
    void createMenu();
    void settingsEnd();
    void gameExit();
    void gameOver();
};

#endif // MAINWINDOW_H
