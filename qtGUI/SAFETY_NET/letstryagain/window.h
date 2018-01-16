#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QLabel>
#include <QGroupBox>
#include <QComboBox>
#include <QRadioButton>
#include <QSlider>
#include <QPainter>
#include <QLineEdit>
#include <QSpinBox>
#include <QTime>
#include <QCoreApplication>
#include <QEventLoop>
#include "renderarea.h"
#include "polygonal.h"

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);

private:
    polygon *datshape;
    int numweights;
    vector<int> weights;

    bool running;

    int win_H, win_X;
    int currentSides;
    int currentSpeed;
    bool regPolygon;
    SHAPE otherShape;

    void createControls();
    void connectControls();

    RenderArea *battlefield;

    QGroupBox *controls;
    QLabel *buffer;
    QPushButton *start;
    QLabel *shape_label;
    QRadioButton *shape_regpoly;
    QSpinBox *shape_sides;
    QRadioButton *shape_star;
    QRadioButton *shape_diamond;
    QLabel *speed_label;
    QSlider *speed;
    QLabel *weights_label;
    QLineEdit *weights_textbox;
    QPushButton *reset;

    void delay(int);

signals:

public slots:
    void startRunning();
    void updateShape();
    void updateSides();
    void updateSpeed();
    void updateWeights();
    void resetControls();
};

#endif // WINDOW_H
