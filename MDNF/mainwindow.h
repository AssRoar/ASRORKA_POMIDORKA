#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMainWindow>
#include <QPainter>
#include <QString>
#include <iostream>
#include <qDebug>
#include <QTableWidget>
#include <vector>
#include <ui_mainwindow.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void buildTable();
    void updateVarCount(int x);
    QStringList getColumn(QString s);
    QStringList getSimpleColumn(QString s);
    QString bin_cal(int a);
    void formula(int y);
//    int mas_bin[2];
    void paintEvent(QPaintEvent *event);
    int N;
    std::vector<QString> Answ();
    unsigned long long int Fun_Num;
    void mdnf();
    int paw(int k);
    bool busy();
    QTableWidget * table;
    std::vector <int> int_curr_fun;


private slots:
    void on_PushButton_clicked();

private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
