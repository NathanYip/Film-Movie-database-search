#include <QApplication>
#include <iostream>

#include "mainwindow.h"
#include "logger.h"
#include "mastercontroller.h"
#include "store.h"

using namespace Storage;

int main(int argc, char *argv[])
{
	//MUST BE FIRST TO RUN TO SET APPLICATION NAME FOLDER
	QApplication app(argc, argv);
	app.setApplicationName("TrekStar"); //needed for store to be able write to disk

    MasterController * masterController = MasterController::getInstance(); // initializes storage items

	qDebug( Support::stringToQByteArray( "TASBDAS" ) );

    MainWindow w;
    w.show();

    return app.exec();
}
