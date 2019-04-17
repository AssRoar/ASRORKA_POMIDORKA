#include <mainwindow.h>
#include "ui_mainwindow.h"
//#include "widget.h"
//#include "ui_widget.h"


int pow(int k)
{
    int answ=1;
    for (int i=0;i<k;i++) answ*=2;
    return answ;
}

QMap <int, QStringList> headMap;
int varCount = 3;
QString varLbl[6] = {"a","b","c","d","e","f"};
QMap <QString, int> assoc;
QString currentFunction;
int varCountp2 = pow(varCount);
std::vector <int> bin_mas;
bool FLAG=1;
QString str_answ, h_answ;
QString fun_of_ver;
//std::vector <int> Qbin_mas;


//Widget::Widget(QWidget *parent) :
//    QWidget(parent),
//    ui2(new  Ui::Widget)
//{
//    ui2->setupUi(this);
//}

//Widget::~Widget()
//{
//    delete ui2;
//}


std::vector <QString> lists_answ;
void MainWindow::mdnf()
{
    table = new QTableWidget();
//    ui->setupUi(this);
//    table->horizontalHeader()->setDefaultSectionSize(70);
//    table->verticalHeader()->setDefaultSectionSize(20);
    table->setGeometry(4840, 321, 73, 1) ;
    updateVarCount(N);
//    int bin_mas[varCountp2];


 QStringList tmpList;

    if (N==1)
        lists_answ.push_back("a");
    else if (N==2)
    {
        lists_answ={"a", "b",  "ab"};
    }
    else if (N==3)
    {
        lists_answ={"a" ,  "b" ,  "c" ,  "ab" ,  "ac" ,  "bc" ,  "abc"};
    }
    else if (N==4)
    {
        lists_answ={"a" ,  "b" ,  "c" ,  "d" ,  "ab" ,  "ac" ,  "ad" , "bc" , "bd" ,  "cd" ,  "abc", "abd", "acd", "bcd", "abcd"};
    }
    else if (N==5)
    {
        lists_answ={"a" ,  "b" ,  "c" ,  "d" ,  "e" ,  "ab" ,  "ac" ,  "ad" ,  "ae" ,  "bc" ,  "bd" ,  "be" ,  "cd" ,  "ce" ,  "de" ,  "abc" ,  "abd" ,  "abe" ,  "acd" ,  "ace" ,  "ade" , "bcd" ,  "bce" , "bde" ,  "cde" ,  "abcd" , "abce" ,  "abde" ,  "acde" ,  "bcde" ,  "abcde"};
    }
    else if (N==6)
    {
        lists_answ={"a" ,  "b" ,  "c" ,  "d" ,  "e" ,  "f" ,  "ab" ,  "ac" ,  "ad" , "ae" ,  "af" ,  "bc" , "bd" ,  "be" ,  "bf" ,  "cd" ,  "ce" ,  "cf" ,  "de" ,  "df" ,  "ef"/**/ ,  "abc" ,  "abd" ,  "abe" ,  "abf" ,  "acd" ,  "ace" ,  "acf" ,  "ade" ,  "adf" ,  "aef" ,  "bcd" ,  "bce" ,  "bcf" ,  "bde" ,  "bdf" ,  "bef" ,  "cde" ,  "cdf" ,  "cef" ,  "def"/**/ ,  "abcd" ,  "abce" ,  "abcf" , "abde" ,  "abdf" ,  "abef" ,  "acde" , "acdf" ,  "acef" ,  "adef" ,  "bcde" ,  "bcdf" ,  "bcef" ,  "bdef" ,  "cdef" ,  "abcde" ,  "abcdf" ,  "abcef" ,  "abdef" ,  "acdef" ,  "bcdef" ,  "abcdef"};
    }

    tmpList <<  "a";
    headMap[1] = tmpList;
    tmpList.clear();


    tmpList << "a" << "b" << "ab";
    headMap[2] = tmpList;
    tmpList.clear();


    tmpList << "a" << "b" << "c" << "ab" << "ac" << "bc" << "abc";
    headMap[3] = tmpList;
    tmpList.clear();


    tmpList << "a" << "b" << "c" << "d" << "ab" << "ac" << "ad" <<"bc" <<"bd" << "cd" << "abc"<<"abd"<<"acd"<<"bcd"<<"abcd";
    headMap[4] = tmpList;
    tmpList.clear();


    tmpList << "a" << "b" << "c" << "d" << "e" << "ab" << "ac" << "ad" << "ae" << "bc" << "bd" << "be" << "cd" << "ce" << "de" << "abc" << "abd" << "abe" << "acd" << "ace" << "ade" <<"bcd" << "bce" <<"bde" << "cde" << "abcd" <<"abce" << "abde" << "acde" << "bcde" << "abcde";
    headMap[5] = tmpList;
    tmpList.clear();


    tmpList << "a" << "b" << "c" << "d" << "e" << "f" << "ab" << "ac" << "ad" <<"ae" << "af" << "bc" <<"bd" << "be" << "bf" << "cd" << "ce" << "cf" << "de" << "df" << "ef"/**/ << "abc" << "abd" << "abe" << "abf" << "acd" << "ace" << "acf" << "ade" << "adf" << "aef" << "bcd" << "bce" << "bcf" << "bde" << "bdf" << "bef" << "cde" << "cdf" << "cef" << "def"/**/ << "abcd" << "abce" << "abcf" <<"abde" << "abdf" << "abef" << "acde" <<"acdf" << "acef" << "adef" << "bcde" << "bcdf" << "bcef" << "bdef" << "cdef" << "abcde" << "abcdf" << "abcef" << "abdef" << "acdef" << "bcdef" << "abcdef";
    headMap[6] = tmpList;
    tmpList.clear();

    currentFunction=bin_cal(Fun_Num);

    buildTable();
    busy();
//    table->showFullScreen();
    table->show();
    bin_mas.resize(varCountp2, 0);
    QString stri;
//    qDebug() << 1;
    formula(0);
//    qDebug() << int_curr_fun;
}


//__________________________________________________________________________________________
//   int y =0;

//void MainWindow::formula(int y)                                                        //
//{
////    qDebug()<<2;
//    for (int x=0;x<varCountp2;x++)
//    {
////        qDebug()<<3;
//        if (table->item(x, y)->backgroundColor()!=QColor(255, 0, 0, 140)&&table->item(x, y)->backgroundColor()!=QColor(255, 0, 0, 70))
//        {
////            qDebug()<<4;
//            for (int i=0;i<varCountp2;i++)
//            {
////                qDebug()<<5;
//                if (table->item(i, y)->text()==table->item(x, y)->text())
//                {
////                    qDebug()<<6;
//                    if (bin_mas[i]==0)
//                    {
//                      bin_mas[i]++;
//                      FLAG=0;
//                    }
//                }
//            }
//            if (FLAG == 0)
//            {
////              qDebug()<<bin_mas;
//              qDebug()<<table->item(x, y)->text()<<x << y;
////              table->item(x, y)->
//              FLAG = 1;
//              formula(y);
////              return
//              ;
//            }
//            else continue;

//        }
////        qDebug()<<7;
//        FLAG=1;
//    }
////    if (bin_mas==int_curr_fun) {qDebug()<<bin_mas << int_curr_fun; return;}
//    if (bin_mas!=int_curr_fun&&y<varCountp2-1)
//    {
////        qDebug()<<2984248;
//        formula(y+1);
//    }
//}



void MainWindow::formula(int x)
{
    if (x==varCountp2)
    {
        int f=str_answ.size()-1;
        str_answ[f]=' ';
        if (str_answ!="")
        qDebug() << str_answ;
        while (str_answ[f]!='+')
        {
            str_answ[f]=' ';
            f--;
        }
        return;
    }
    for (int y=1;y<varCountp2;y++)
    {
        if (table->item(x, y)->backgroundColor()!=QColor(255, 0, 0, 140)&&table->item(x, y)->backgroundColor()!=QColor(255, 0, 0, 70)&&bin_mas[x]==0)
        {
            bin_mas[x]=1;
//            std::string st_answ="str_answ";

            str_answ+=table->item(x, y)->text();
            str_answ+="+";
            fun_of_ver=table->item(x, y)->text();
            for (int i=0;i<varCountp2;i++)
            {
                if (fun_of_ver==table->item(i, y)->text()) bin_mas[i]=1;
            }
            formula(x+1);
        }
        for (int i=0;i<varCountp2;i++)
        {
            if (fun_of_ver==table->item(i, y)->text()) bin_mas[i]=0;
        }
        bin_mas[x]=0;
    }
    formula(x+1);
}



                                                                                         //
QStringList MainWindow::getSimpleColumn(QString s)                                      //
{
    int x = assoc[s];
    QStringList ans;
   while(ans.length() < varCountp2){
       for (int i = 0; i < pow(x); ++i){
           ans<<"0";
       }
       for(int i = 0; i < pow(x); ++i){
           ans<<"1";
       }
   }
   return ans;
}
                                                                                       //
void MainWindow::updateVarCount(int x)                                                //
{
    varCount = x;
    varCountp2 = pow(x);
    for(int i = 0; i < x; ++i){
        assoc[varLbl[i]] = x-i-1;
    }
}
                                                                                     //                   ВСПОМОГАТЕЛЬНЫЕ
QStringList MainWindow::getColumn(QString s)                                        //
{
    QStringList ans;
    for (int i = 0; i < varCountp2; ++i)
    {
        ans << "";
    }
    for(int i = 0; i < s.length(); ++i)
    {
        QStringList tmpColumn = getSimpleColumn(QString(s[i]));
        for (int j = 0; j < varCountp2; ++j)
        {
            ans[j]+=tmpColumn[j];
        }
    }
    return ans;
}
                                                                                   //                     ФУНКЦИИ
void MainWindow::buildTable()                                                     //
{

    int tmpColumnCount = table->columnCount();

    for(int i = 0; i < tmpColumnCount; ++i){
        table->removeColumn(0);
        table->removeRow(0);
    }


    for (int i = 0; i < varCountp2; ++i){
        table->insertRow(i);
        table->insertColumn(i);
    }

    QTableWidgetItem * item = new QTableWidgetItem();
    item->setText("f(x)");
    table->setHorizontalHeaderItem(0,item);



    for(int i = 0; i < varCountp2; ++i){
        QTableWidgetItem * itm = new QTableWidgetItem();
        itm->setText(QString(currentFunction[i]));
        itm->setFlags(Qt::ItemIsEnabled);
        itm->setTextAlignment(Qt::AlignCenter);
        table->setItem(i,0,itm);
    }

    for (int i = 1; i < varCountp2; ++i){
        QTableWidgetItem * itm = new QTableWidgetItem();
        itm->setText(headMap[varCount][i-1]);
        table->setHorizontalHeaderItem(i,itm);
    }

    for (int j = 1; j < varCountp2; ++j){
        QString hed = headMap[varCount][j-1];
        QStringList column = getColumn(hed);
        for (int i = 0; i < column.length(); ++i){
          //  QCoreApplication::processEvents();
            QTableWidgetItem * itm = new QTableWidgetItem();
            itm->setText(column[i]);
            itm->setFlags(Qt::ItemIsEnabled);
            itm->setTextAlignment(Qt::AlignCenter);
            table->setItem(i,j,itm);
        }
    }


    for (int i =0 ; i <varCountp2; ++i){
        QTableWidgetItem * itm = table->item(i,0);
        if (itm->text() == "0"){
            for (int j = 1; j < varCountp2; ++j){
               QTableWidgetItem * tmpItm = table->item(i,j);
               tmpItm->setBackgroundColor(QColor(255, 0, 0, 140));       //ИЗМЕНЕНИЕ ЦВЕТА
               //cохранение значения j-й колонки
            }
        }
    }

    for (int i =0 ; i <varCountp2; ++i){
        QTableWidgetItem * itm = table->item(i,0);
        if (itm->text() == "1"){
            for (int j = 1; j < varCountp2; ++j){
               QTableWidgetItem * tmpItm = table->item(i,j);
//               if(){
//                   tmpItm->setBackgroundColor(QColor(0,0,225,127));
//               } else {
//                   tmpItm->setBackgroundColor(QColor(0,225,0,127));
//               }
            }
        }
    }
}
                                                                                 //
bool MainWindow::busy()                                                         //
{
    QTableWidgetItem *itm, *itm2;
    for (int i=1;i<varCountp2;i++)
        for (int j=0;j<varCountp2;j++)
        {
            itm=table->item(j, i);
            if ((itm->backgroundColor()!=QColor(255, 0, 0, 140))&&(itm->backgroundColor()!=QColor(255, 0, 0, 70)))
            {
            for (int v=0;v<j;v++)
            {
                itm2=table->item(v, i);
                if (itm2->backgroundColor()==QColor(255, 0, 0, 140) && itm2->text()==itm->text()) itm->setBackgroundColor(QColor(255, 0, 0, 70));
            }
            for (int v=j+1;v<varCountp2;v++)
            {
                itm2=table->item(v, i);
                if (itm2->backgroundColor()==QColor(255, 0, 0, 140) && itm2->text()==itm->text()) itm->setBackgroundColor(QColor(255, 0, 0, 70));
            }
            }
        }
}
                                                                               //
//____________________________________________________________________________//
