#include "somekindathing.h"
#include "ui_somekindathing.h"

Somekindathing::Somekindathing(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Somekindathing)
{
    ui->setupUi(this);
}

Somekindathing::~Somekindathing()
{
    delete ui;
}
