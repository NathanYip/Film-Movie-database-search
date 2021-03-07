#include "logger.h"

Logger::Logger()
{
	//gather the current time
	time_t getCurrentTime = time(NULL);

	string timeString = std::ctime(&getCurrentTime);

	Logger::fileName = Support::getDataPath() + timeString + ".log";

	//Create a file with it log information
	ofstream fileWriter(Logger::fileName);
	if (fileWriter.is_open())
	{
		fileWriter << "Log created at time: " << timeString << "\n";
		fileWriter.close();
	}
	else
	{
		cout << "Failed to create file" << endl;
	}
}

void Logger::writeToLog(string input)
{

    //Get the current time
	time_t getCurrentTime = time(NULL);

    //Remote the \n from the string
    string timeString = std::ctime(&getCurrentTime);
    timeString.erase(timeString.end()-2,timeString.end());

    //Open the file in append mode and write
    ofstream fileWriter(Logger::fileName, std::ios::app);
    if (fileWriter.is_open())
    {
        fileWriter <<timeString << " - " << input << "\n";
    }
    else
    {
        cout << "Filed to write to file" << endl;
    }
	fileWriter.close();
}

