#include "mainwindow.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
//    w.setFocusPolicy(Qt::StrongFocus );
//    w.show();

    w.setWindowFlags(w.windowFlags() | Qt::WindowStaysOnTopHint);
    w.showNormal();



    return a.exec();
}
