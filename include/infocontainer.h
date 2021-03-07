#pragma once
#include <string>

using namespace std;

// abstract class
// To use Storage objects, the information to be stored (strings or classes) need to extend this class
// The *String() method needs to be implemented in the child class for Storage::Store to read/write proper values to file
class InfoContainer {
public:
	virtual string toString();
	virtual void fromString(string);
};