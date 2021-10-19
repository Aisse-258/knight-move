#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>
#include <QWidget>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>

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

private:
    Ui::MainWindow *ui;
    QGraphicsView *chess_board;
    QGraphicsScene *scene;
    QGraphicsPixmapItem *knight_figure;
    QGraphicsPixmapItem *background;
};

#endif // MAINWINDOW_H
