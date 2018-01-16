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
#include <QtConcurrent/QtConcurrent>
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
    int currentSides;
    int currentSpeed;
    bool regPolygon;
    SHAPE otherShape;
    int everyother;

    polygon *datshape2;
    int numweights2;
    vector<int> weights2;
    bool running2;
    int currentSides2;
    int currentSpeed2;
    bool regPolygon2;
    SHAPE otherShape2;
    int everyother2;

    void createControls();
    void connectControls();

    void createControls2();
    void connectControls2();

    RenderArea *battlefield;
    RenderArea *battlefield2;

    QGroupBox *controls;
    QLabel *buffer;
    QPushButton *start;
    QPushButton *pause;
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

    QGroupBox *controls2;
    QLabel *buffer2;
    QPushButton *start2;
    QPushButton *pause2;
    QLabel *shape_label2;
    QRadioButton *shape_regpoly2;
    QSpinBox *shape_sides2;
    QRadioButton *shape_star2;
    QRadioButton *shape_diamond2;
    QLabel *speed_label2;
    QSlider *speed2;
    QLabel *weights_label2;
    QLineEdit *weights_textbox2;
    QPushButton *reset2;

    void delay(int);

signals:

public slots:
    void startRunning();
    void parallelRunning();
    void pauseRunning();
    void updateShape();
    void updateSides();
    void updateSpeed();
    void updateWeights();
    void resetControls();

    void startRunning2();
    void parallelRunning2();
    void pauseRunning2();
    void updateShape2();
    void updateSides2();
    void updateSpeed2();
    void updateWeights2();
    void resetControls2();
};

#endif // WINDOW_H
