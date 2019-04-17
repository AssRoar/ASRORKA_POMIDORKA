#include "mainwindow.h"
#include "ui_mainwindow.h"

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

}


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_PushButton_clicked()
{
    QString S1 = ui->lineEdit->text();
    N = S1.toInt();
    QString S2 = ui->lineEdit_2->text();
    Fun_Num = S2.toInt();
//    int bin_mas[paw(N)];
    mdnf();
}
