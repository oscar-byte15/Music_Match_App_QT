#include "musicmatch.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    musicmatch w;
    w.show();
    return a.exec();
}
