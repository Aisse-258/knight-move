#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "knight.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QPixmap>
#include <QVBoxLayout>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene;
    ui->chess_board->setScene(scene);

    background = new QGraphicsPixmapItem(QPixmap(":/img/img/chessboard.jpg"));
    scene->addItem(background);
    background->setPos(0, 0);
    background->setScale(0.54);
    background->setZValue(-0.1);

    knight_figure = new QGraphicsPixmapItem(QPixmap(":/img/img/knight-icon.png"));
    scene->addItem(knight_figure);
    knight_figure->setScale(0.15);
    knight_figure->hide();
    timer = new QTimer();
    timer->setInterval(500);

    connect(timer, SIGNAL(timeout()), this, SLOT(timeToStep()));
    connect(ui->StartButton, &QPushButton::clicked, this, &MainWindow::OnStart);
}

void MainWindow::OnStart() {
    stepsRequired = knight(ui->position1_input->text(),ui->position2_input->text());
    currentStep = 0;
    timer->start();
}

void MainWindow::timeToStep() {
    ui->statusBar->showMessage("Необходимо шагов: "+QString::number(stepsRequired)+"; Шаг: "+QString::number(currentStep));
    knight_figure->show();
    knight_figure->setPos(stepPositions[currentStep][1].toInt(), stepPositions[currentStep][2].toInt());
    currentStep++;
    if (currentStep == stepsRequired+1) {
        timer->stop();
    }
}

}

MainWindow::~MainWindow()
{
    delete ui;
    delete scene;
    delete chess_board;
    delete background;
    delete knight_figure;
    delete timer;
}
