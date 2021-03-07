#pragma once

#include <sstream>
#include <string>
#include <locale>
#include <algorithm>
#include <ctime>
#include <QDir>

#include "qbytearray.h"
#include "qstring.h"
#include "qdir.h"
#include "qdesktopservices.h"
#include "qstandardpaths.h"

// c++11 shims
class Support {
public:
	static std::string intToString(int);
	static std::string doubleToString(double);
	static std::string booleanToString(bool);
	static int stringToInt(std::string);
	static QByteArray stringToQByteArray(std::string);
	static std::string getDataPath();
	static std::string getResourcePath();
	static std::string getDatasetPath(std::string);
	static int getStringIndexOf(std::string, std::vector<std::string> *);
	static int dateStringToEpochSeconds(std::string);
	static int dateStringToEpochMilliseconds(std::string);
    static QString stringtoQString(std::string);
    /**
     * @brief QString_To_String
     * This will convert QStrings to string specifying the codec to convert to
     * which is UTF8
     * @param string The QString that will be converted
     * @return the converted string
     */
    static std::string QString_To_String(QString);
    /**
     * @brief splitString
     * This function splits the string based on the delimeter
     * @param str the string that is going to be split
     * @param delim the delimeter by which to split the string
     * @return returns the splitted string
     */
    static std::vector<std::string> splitString(std::string, std::string);
    static std::string toLowerCaseString(std::string);
};
