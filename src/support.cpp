#include "support.h"

using namespace std;

std::string Support::intToString(int input){
	ostringstream o;
	o << input;
	return o.str();
}

std::string Support::doubleToString(double input) {
	ostringstream o;
	o << input;
	return o.str();
}

QByteArray Support::stringToQByteArray(std::string input)
{
	return (QString::fromStdString(input)).toLatin1();
}

QString Support::stringtoQString(std::string input)
{
    return QString(stringToQByteArray(input));
}

std::string Support::booleanToString(bool input)
{
	if (input == true) {
		return "true";
	}
	else {
		return "false";
	}
}

//converts string into int;
int Support::stringToInt(std::string input)
{
	stringstream geek(input);
	int x = 0;
	geek >> x; // stream input string into int
	return x;
}

std::string Support::getDataPath()
{
	QString appdata = QStandardPaths::writableLocation(QStandardPaths::StandardLocation::DataLocation);

	// creates application directory in APPDATA if it doesnt exist
	QDir dir(appdata);
	if (!dir.exists())
		dir.mkpath(appdata);

	return appdata.toStdString();
}

std::string Support::getResourcePath()
{
	return QString_To_String( QDir().currentPath() ) + "/resources/";
}

std::string Support::getDatasetPath(std::string resourceName)
{
	return getResourcePath() + "dataset/" + resourceName;
}

string Support::QString_To_String(QString input_string)
{
    return input_string.toStdString();
}

int Support::getStringIndexOf(std::string item, std::vector<std::string> *str)
{
	for (int i = 0; i < str->size(); i++) {
		if (toLowerCaseString(str->at(i)) == toLowerCaseString(item)) return i;
	}
	return -1;
}

int Support::dateStringToEpochSeconds(std::string input) // WWW MMM DD YYYY
{
	tm tmt = *(new tm()); 
	std::string _days[] = { "Mon","Tue","Wed","Thu","Fri","Sat","Sun" };
	std::string _months[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };

	std::vector<string> days(std::vector<std::string>(_days, _days + sizeof _days / sizeof _days[0]));
	std::vector<string> months(_months, _months + sizeof _months / sizeof _months[0]);

	// get input as chars
	const char * dateString = input.data();

	// split input into tokens;
	std::vector<std::string> tokens;
	std::string currentToken = "";
	
	for (const char * c = dateString; *c; *c++) {
		if (*c == ' ') {
			tokens.push_back(currentToken);
			currentToken = "";
		}
		else {
			currentToken += *c;
		}
	}
	tokens.push_back(currentToken);

	//tmt.tm_wday = getStringIndexOf( tokens.at(0) , &days );  <- Ignore the day
	tmt.tm_mon = getStringIndexOf( tokens.at(1) , &months );
	tmt.tm_mday = stringToInt(tokens.at(2));
	tmt.tm_year = stringToInt(tokens.at(3)) - 1900;

	return mktime(&tmt); // returns time to epoch
}

int Support::dateStringToEpochMilliseconds(std::string input)
{
	return dateStringToEpochSeconds(input) * 1000;
}
vector<string> Support::splitString(string str, string delim)
{
    char* currentString =const_cast<char*>(str.c_str());
    char* current;

    vector<string> stringArray;
    current=strtok(currentString,delim.c_str());

    while(current!=NULL)
    {
        stringArray.push_back(current);
        current=strtok(NULL,delim.c_str());
    }

    return stringArray;
}

string Support::toLowerCaseString(string stringToLower)
{
    string returnString = stringToLower;
    for (auto i=0; i < returnString.length(); ++i)
    {
        returnString[i] = tolower(returnString[i]);
    }
    return returnString;
}
