#ifndef SOMEKINDATHING_H
#define SOMEKINDATHING_H

#include <QMainWindow>

namespace Ui {
class Somekindathing;
}

class Somekindathing : public QMainWindow
{
    Q_OBJECT

public:
    explicit Somekindathing(QWidget *parent = 0);
    ~Somekindathing();

private:
    Ui::Somekindathing *ui;
};

#endif // SOMEKINDATHING_H
