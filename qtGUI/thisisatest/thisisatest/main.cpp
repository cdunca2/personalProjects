#include "somekindathing.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Somekindathing w;
    w.show();

    return a.exec();
}
