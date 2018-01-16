#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    QPushButton button("mothefug", &w);
    QFont font("Courier");
    button.setFont(font);
    button.setText("REPLACED");
    button.setToolTip("just the tip");
    button.setGeometry(10,10, 90, 90);
    button.show();

    return a.exec();
}
