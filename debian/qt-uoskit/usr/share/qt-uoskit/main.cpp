#include "uoskitgui.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UoskitGui w;
    w.show();

    return a.exec();
}
