#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    int win_W = 1440;
    int win_H = 960;
    setFixedSize(win_W,win_H);

    createControls();
    connectControls();

    battlefield = new RenderArea();
    battlefield->setFixedSize(600,600);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(controls);
    layout->addWidget(battlefield);
    layout->addStretch();
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

    datshape = new polygon(shape_sides->value());
    weights = vector<int>();
    updateShape();
    updateSides();
    updateSpeed();
    updateWeights();
    cout << "current sides " << currentSides << endl
         << "current speed " <<currentSpeed << endl
         << "current regularity " <<regPolygon << endl;
}

void Window::createControls()
{
    controls = new QGroupBox(tr("Controls:"));
    buffer = new QLabel("");

    start = new QPushButton("Start", this);

    shape_label = new QLabel(tr("Shape:"));
    shape_regpoly = new QRadioButton(tr("Regular Polygon"));
    shape_regpoly->setChecked(true);
    shape_sides = new QSpinBox();
    shape_sides->setRange(3,12);
    shape_sides->setSingleStep(1);
    shape_sides->setValue(4);
    shape_star = new QRadioButton(tr("Star"));
    shape_diamond = new QRadioButton(tr("Rhombic blob"));

    speed_label = new QLabel(tr("Speed:"));
    speed = new QSlider(Qt::Horizontal, this);
    speed->setTickPosition(QSlider::TicksBothSides);
    speed->setRange(50,2000);
    speed->setTickInterval(50);
    speed->setSingleStep(1);
    speed->setValue(500);

    weights_label = new QLabel(tr("Weights:"));
    weights_textbox = new QLineEdit();
    weights_textbox->setText("1 1");

    reset = new QPushButton("Reset", this);



    QGridLayout *controlLayout = new QGridLayout;
    controlLayout->addWidget(buffer, 0,0);
    controlLayout->addWidget(start, 1,0);
    controlLayout->addWidget(buffer, 2,0);
    controlLayout->addWidget(shape_label, 3,0);
    controlLayout->addWidget(shape_regpoly, 4,0);
    controlLayout->addWidget(shape_sides, 4,1);
    controlLayout->addWidget(shape_star, 5,0);
    controlLayout->addWidget(shape_diamond, 6,0);
    controlLayout->addWidget(buffer, 7,0);
    controlLayout->addWidget(speed_label, 8,0);
    controlLayout->addWidget(speed, 9,0);
    controlLayout->addWidget(buffer, 10,0);
    controlLayout->addWidget(weights_label, 11,0);
    controlLayout->addWidget(weights_textbox, 12,0);
    controlLayout->addWidget(buffer, 13,0);
    controlLayout->addWidget(reset, 14,0);
    controlLayout->addWidget(buffer, 15,0);
    controls->setLayout(controlLayout);
    controls->setMaximumWidth(400);
}

void Window::connectControls()
{
    connect(start, SIGNAL(clicked(bool)),
            this, SLOT(startRunning()));
    connect(shape_regpoly, SIGNAL(toggled(bool)),
            this, SLOT(updateShape()));
    connect(shape_sides, SIGNAL(valueChanged(int)),
            this, SLOT(updateSides()));
    connect(shape_star, SIGNAL(toggled(bool)),
            this, SLOT(updateShape()));
    connect(shape_diamond, SIGNAL(toggled(bool)),
            this, SLOT(updateShape()));
    connect(speed, SIGNAL(valueChanged(int)),
            this, SLOT(updateSpeed()));
    connect(weights_textbox, SIGNAL(textChanged(QString)),
            this, SLOT(updateWeights()));
    connect(reset, SIGNAL(clicked(bool)),
            this, SLOT(resetControls()));
}

void Window::startRunning()
{
    running = true;
    int everyother = 0;
    int mySides = currentSides;
    int myNumweights = numweights;
    vector<int> myWeights = weights;
    cout << "MY SIDES: " << mySides << endl;

    //for (int i=0; i<4; i++) {
    while(running == true) {
        cout << everyother << endl;

        everyother % 2 ? datshape->do_average(myNumweights, myWeights) : datshape->do_split();
        if(!(everyother % 2)) mySides *= 2;
        battlefield->setShape(datshape, mySides);
        everyother++;

        delay(currentSpeed);
        if(mySides > 9000) running = false;
    }
}

void Window::updateShape()
{
    if(shape_regpoly->isChecked()) {
        regPolygon = true;
        currentSides = shape_sides->value();
        datshape = new polygon(currentSides);
    }
    else {
        regPolygon = false;
        if(shape_star) {
            otherShape = star;
            currentSides = 10;
        }
        else if(shape_diamond) {
            otherShape = rhombus;
            currentSides = 4;
        }
        datshape = new polygon(otherShape);
    }
    battlefield->setShape(datshape, currentSides);
}

void Window::updateSides()
{
    currentSides = shape_sides->value();
    if(regPolygon) {
        datshape = new polygon(currentSides);
        battlefield->setShape(datshape, currentSides);
    }
}

void Window::updateWeights()
{
    QStringList myWeights = weights_textbox->text().split(" ");

    weights.clear();

    numweights = myWeights.size();
    for(int i=0; i<numweights; i++) {
        weights.push_back(myWeights.at(i).toInt());
    }
}

void Window::updateSpeed()
{
    currentSpeed = speed->value();
}

void Window::resetControls()
{
    running = false;
    shape_regpoly->setChecked(true);
    shape_sides->setValue(4);
    speed->setValue(500);
    weights_textbox->setText("1 1");
    currentSides = 4;
    datshape = new polygon(currentSides);
    battlefield->setShape(datshape, currentSides);
}

void Window::delay(int waitTime)
{
    QTime dieTime = QTime::currentTime().addMSecs( waitTime );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
