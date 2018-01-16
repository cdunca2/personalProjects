#include "window.h"

Window::Window(QWidget *parent) : QWidget(parent)
{
    createControls();
    connectControls();

    createControls2();
    connectControls2();

    battlefield = new RenderArea(this);
    battlefield->setFixedSize(600,600);
    battlefield2 = new RenderArea(this);
    battlefield2->setFixedSize(600,600);

    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(controls);
    layout->addWidget(battlefield);
    layout->addWidget(controls2);
    layout->addWidget(battlefield2);
    layout->addStretch();
    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

    datshape = new polygon(shape_sides->value());
    weights = vector<int>();
    everyother = 0;
    updateShape();
    updateSides();
    updateSpeed();
    updateWeights();

    datshape2 = new polygon(shape_sides->value());
    weights2 = vector<int>();
    everyother2 = 0;
    updateShape2();
    updateSides2();
    updateSpeed2();
    updateWeights2();
}

void Window::createControls()
{
    controls = new QGroupBox(tr("Controls:"), this);
    buffer = new QLabel("", this);

    start = new QPushButton("Start", this);
    pause = new QPushButton("Pause", this);

    shape_label = new QLabel(tr("Shape:"), this);
    shape_regpoly = new QRadioButton(tr("Regular Polygon"), this);
    shape_regpoly->setChecked(true);
    shape_sides = new QSpinBox(this);
    shape_sides->setRange(3,12);
    shape_sides->setSingleStep(1);
    shape_sides->setValue(4);
    shape_star = new QRadioButton(tr("Star"), this);
    shape_diamond = new QRadioButton(tr("Rhombic blob"), this);

    speed_label = new QLabel(tr("Speed:"), this);
    speed = new QSlider(Qt::Horizontal, this);
    speed->setTickPosition(QSlider::TicksBothSides);
    speed->setRange(50,2000);
    speed->setTickInterval(50);
    speed->setSingleStep(1);
    speed->setValue(500);

    weights_label = new QLabel(tr("Weights:"), this);
    weights_textbox = new QLineEdit(this);
    weights_textbox->setText("1 1");

    reset = new QPushButton("Reset", this);



    QGridLayout *controlLayout = new QGridLayout;
    controlLayout->addWidget(buffer, 0,0);
    controlLayout->addWidget(start, 1,0);
    controlLayout->addWidget(pause, 2,0);
    controlLayout->addWidget(buffer, 3,0);
    controlLayout->addWidget(shape_label, 4,0);
    controlLayout->addWidget(shape_regpoly, 5,0);
    controlLayout->addWidget(shape_sides, 5,1);
    controlLayout->addWidget(shape_star, 6,0);
    controlLayout->addWidget(shape_diamond, 7,0);
    controlLayout->addWidget(buffer, 8,0);
    controlLayout->addWidget(speed_label, 9,0);
    controlLayout->addWidget(speed, 10,0);
    controlLayout->addWidget(buffer, 11,0);
    controlLayout->addWidget(weights_label, 12,0);
    controlLayout->addWidget(weights_textbox, 13,0);
    controlLayout->addWidget(buffer, 14,0);
    controlLayout->addWidget(reset, 15,0);
    controlLayout->addWidget(buffer, 16,0);
    controls->setLayout(controlLayout);
    controls->setMaximumWidth(400);
}

void Window::connectControls()
{
    connect(start, SIGNAL(clicked(bool)),
            this, SLOT(startRunning()));
    connect(pause, SIGNAL(clicked(bool)),
            this, SLOT(pauseRunning()));
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
    QtConcurrent::run(this, &Window::parallelRunning);
}

void Window::parallelRunning()
{
    running = true;
    //int mySides = currentSides;
    int myNumweights = numweights;
    vector<int> myWeights = weights;

    //for (int i=0; i<4; i++) {
    while(running == true) {everyother % 2 ? datshape->do_average(myNumweights, myWeights) : datshape->do_split();
        if(!(everyother % 2)) currentSides *= 2;
        battlefield->setShape(datshape, currentSides);
        everyother++;

        delay(currentSpeed);
        if(currentSides > 9000) running = false;
    }
}

void Window::pauseRunning()
{
    running = false;
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
        if(shape_star->isChecked()) {
            otherShape = star;
            currentSides = 10;
        }
        else if(shape_diamond->isChecked()) {
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
    everyother = 0;
}

void Window::createControls2()
{
    controls2 = new QGroupBox(tr("Controls:"), this);
    buffer2 = new QLabel("", this);

    start2 = new QPushButton("Start", this);
    pause2 = new QPushButton("Pause", this);

    shape_label2 = new QLabel(tr("Shape:"), this);
    shape_regpoly2 = new QRadioButton(tr("Regular Polygon"), this);
    shape_regpoly2->setChecked(true);
    shape_sides2 = new QSpinBox(this);
    shape_sides2->setRange(3,12);
    shape_sides2->setSingleStep(1);
    shape_sides2->setValue(4);
    shape_star2 = new QRadioButton(tr("Star"), this);
    shape_diamond2 = new QRadioButton(tr("Rhombic blob"), this);

    speed_label2 = new QLabel(tr("Speed:"), this);
    speed2 = new QSlider(Qt::Horizontal, this);
    speed2->setTickPosition(QSlider::TicksBothSides);
    speed2->setRange(50,2000);
    speed2->setTickInterval(50);
    speed2->setSingleStep(1);
    speed2->setValue(500);

    weights_label2 = new QLabel(tr("Weights:"), this);
    weights_textbox2 = new QLineEdit(this);
    weights_textbox2->setText("1 1");

    reset2 = new QPushButton("Reset", this);



    QGridLayout *controlLayout = new QGridLayout;
    controlLayout->addWidget(buffer2, 0,0);
    controlLayout->addWidget(start2, 1,0);
    controlLayout->addWidget(pause2, 2,0);
    controlLayout->addWidget(buffer2, 3,0);
    controlLayout->addWidget(shape_label2, 4,0);
    controlLayout->addWidget(shape_regpoly2, 5,0);
    controlLayout->addWidget(shape_sides2, 5,1);
    controlLayout->addWidget(shape_star2, 6,0);
    controlLayout->addWidget(shape_diamond2, 7,0);
    controlLayout->addWidget(buffer2, 8,0);
    controlLayout->addWidget(speed_label2, 9,0);
    controlLayout->addWidget(speed2, 10,0);
    controlLayout->addWidget(buffer2, 12,0);
    controlLayout->addWidget(weights_label2, 12,0);
    controlLayout->addWidget(weights_textbox2, 13,0);
    controlLayout->addWidget(buffer2, 14,0);
    controlLayout->addWidget(reset2, 15,0);
    controlLayout->addWidget(buffer2, 16,0);
    controls2->setLayout(controlLayout);
    controls2->setMaximumWidth(400);
}

void Window::connectControls2()
{
    connect(start2, SIGNAL(clicked(bool)),
            this, SLOT(startRunning2()));
    connect(pause2, SIGNAL(clicked(bool)),
            this, SLOT(pauseRunning2()));
    connect(shape_regpoly2, SIGNAL(toggled(bool)),
            this, SLOT(updateShape2()));
    connect(shape_sides2, SIGNAL(valueChanged(int)),
            this, SLOT(updateSides2()));
    connect(shape_star2, SIGNAL(toggled(bool)),
            this, SLOT(updateShape2()));
    connect(shape_diamond2, SIGNAL(toggled(bool)),
            this, SLOT(updateShape2()));
    connect(speed2, SIGNAL(valueChanged(int)),
            this, SLOT(updateSpeed2()));
    connect(weights_textbox2, SIGNAL(textChanged(QString)),
            this, SLOT(updateWeights2()));
    connect(reset2, SIGNAL(clicked(bool)),
            this, SLOT(resetControls2()));
}

void Window::startRunning2()
{
    QtConcurrent::run(this, &Window::parallelRunning2);
}

void Window::parallelRunning2()
{
    running2 = true;
    //int mySides = currentSides2;
    int myNumweights = numweights2;
    vector<int> myWeights = weights2;

    //for (int i=0; i<4; i++) {
    while(running2 == true) {everyother2 % 2 ? datshape2->do_average(myNumweights, myWeights) : datshape2->do_split();
        if(!(everyother2 % 2)) currentSides2 *= 2;
        battlefield2->setShape(datshape2, currentSides2);
        everyother2++;

        delay(currentSpeed2);
        if(currentSides2 > 9000) running2 = false;
    }
}

void Window::pauseRunning2()
{
    running2 = false;
}

void Window::updateShape2()
{
    if(shape_regpoly2->isChecked()) {
        regPolygon2 = true;
        currentSides2 = shape_sides2->value();
        datshape2 = new polygon(currentSides2);
    }
    else {
        regPolygon2 = false;
        if(shape_star2->isChecked()) {
            otherShape2 = star;
            currentSides2 = 10;
        }
        else if(shape_diamond2->isChecked()) {
            otherShape2 = rhombus;
            currentSides2 = 4;
        }
        datshape2 = new polygon(otherShape2);
    }
    battlefield2->setShape(datshape2, currentSides2);
}

void Window::updateSides2()
{
    currentSides2 = shape_sides2->value();
    if(regPolygon) {
        datshape2 = new polygon(currentSides2);
        battlefield2->setShape(datshape2, currentSides2);
    }
}

void Window::updateWeights2()
{
    QStringList myWeights = weights_textbox2->text().split(" ");

    weights2.clear();

    numweights2 = myWeights.size();
    for(int i=0; i<numweights2; i++) {
        weights2.push_back(myWeights.at(i).toInt());
    }
}

void Window::updateSpeed2()
{
    currentSpeed2 = speed2->value();
}

void Window::resetControls2()
{
    running2 = false;
    shape_regpoly2->setChecked(true);
    shape_sides2->setValue(4);
    speed2->setValue(500);
    weights_textbox2->setText("1 1");
    currentSides2 = 4;
    datshape2 = new polygon(currentSides2);
    battlefield2->setShape(datshape2, currentSides2);
    everyother2 = 0;
}

void Window::delay(int waitTime)
{
    QTime dieTime = QTime::currentTime().addMSecs( waitTime );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}
