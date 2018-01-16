TEMPLATE = app
TARGET = polygonal

QT = core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    main.cpp \
    window.cpp \
    polygonal.cpp \
    renderarea.cpp

HEADERS += \
    window.h \
    polygonal.h \
    renderarea.h
