#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "knight.h"
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QGridLayout>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap knight_img(":/img/img/knight-icon.png");
    ui->knight_picture->setPixmap(knight_img.scaled(26,26, Qt::KeepAspectRatio));
    connect(ui->StartButton, &QPushButton::clicked, this, &MainWindow::OnStart);
}

void MainWindow::OnStart() {

  int val = knight(ui->position1_input->text(),ui->position2_input->text());
  ui->lbl->setText(QString::number(val));
}

MainWindow::~MainWindow()
{
    delete ui;
}
