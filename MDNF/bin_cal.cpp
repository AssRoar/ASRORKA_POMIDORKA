#include "mainwindow.h"
#include <algorithm>

QString MainWindow::bin_cal(int a)
{
    QString s, e;
    std::vector <int> eyey;
    int S=paw(N);
    while (S!=0)
    {
        S--;
        eyey.push_back(a%2);
        e.setNum(a%2);
        s+=e;
        a=a/2;
    }
    QString answ;
    for (int i=paw(N)-1;i>=0;i--)
    {
        int_curr_fun.push_back(eyey[i]);
        answ+=s[i];
    }

    return answ;
}
