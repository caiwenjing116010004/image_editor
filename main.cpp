#include "hellowindow.h"
#include "developwindow.h"
#include <QApplication>
#include "iostream"
using namespace std;

/*
 * This is the final project of CSC3002
 * This project is an image editor
 * Team members are
 * 叶成葳 116010265
 * 兰一帆 116010103
 * 蔡文婧 116010004
 */

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    HelloWindow h;
    h.show();
    return a.exec();
}
