#ifndef LOGGER_H
#define LOGGER_H
/* This is a class which logs all user interactions with the
 * @author Alex McBean
 * */

#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <fstream>

#include "support.h"

using std::cout;
using std::endl;
using std::string;
using std::ofstream;

//TODO make it handle more data and look nicer
class Logger
{
    private:
        std::string fileName;

    public:
        
         /*
         * Main Constructor
         * This creates a new file for the class to log to
         * as-well as assigning the fileName to be used
         * */
        Logger();

        /*
         * This writes to the previously created log file
         * whatever the input is with the current
         * date and time */
        void writeToLog(string);

};

#endif // LOGGER_H
