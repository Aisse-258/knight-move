#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTime>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void OnStart();
    void timeToStep();

private:
    Ui::MainWindow *ui;
    QGraphicsView *chess_board;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *knight_figure;
    QGraphicsPixmapItem *background;
    QTimer *timer;
    int currentStep;
    int stepsRequired;
};

#endif // MAINWINDOW_H
