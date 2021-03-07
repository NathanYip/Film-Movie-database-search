#-------------------------------------------------
#
# Project created by QtCreator 2018-03-22T15:59:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TrekStar-2018
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

INCLUDEPATH += include/
INCLUDEPATH += src/
INCLUDEPATH += view/

SOURCES += src/main.cpp\
    src/logger.cpp\
    src/filmSort.cpp \
    src/popupdialog.cpp \
    src/film.cpp \
    src/enumerable_list.cpp \
    src/infocontainer.cpp \
    src/linearlist.cpp \
    src/mastercontroller.cpp \
    src/store.cpp \
    src/support.cpp \
    src/mainwindow.cpp \
    src/projcreationwindow.cpp \
    src/viewprojectswindow.cpp \
    src/filmmaterials.cpp \
    src/addmaterialsdialog.cpp \
    src/viewprojectdialog.cpp

HEADERS  += include/popupdialog.h\
    include/filmSort.h\
    include/logger.h\
    include/film.h \
    include/enumerable_list.h \
    include/infocontainer.h \
    include/linearlist.h \
    include/mastercontroller.h \
    include/resource.h \
    include/store.h \
    include/support.h \
    include/mainwindow.h \
    include/projcreationwindow.h \
    include/viewprojectswindow.h \
    include/filmmaterials.h \
    include/addmaterialsdialog.h \
    include/viewprojectdialog.h

FORMS    += \
            view/popupdialog.ui \
    view/mainwindow.ui \
    view/projcreationwindow.ui \
    view/viewprojectswindow.ui \
    view/addmaterialsdialog.ui \
    view/viewprojectdialog.ui

RESOURCES += \
    resources.qrc
