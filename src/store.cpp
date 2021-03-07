#include "store.h"

using namespace std;
using namespace Storage;

//HACK changed Support::getDataPath() to Support::getDatasetPath()

Store::Store(string storageName)
{
	//set filename for access when writing listStore to file
	storageFileName = storageName;

	if (storageFileName.at(0) == '@') {
		string p = storageFileName.substr(1, storageFileName.length() - 1);
		storageFilePath = Support::getDatasetPath(p);
		storageFilePathWritable = Support::getDataPath() + "/" + p;
	}
	else {
		storageFilePath = Support::getDataPath() + "/TrekStar/" + storageFileName + ".txt";
		storageFilePathWritable = Support::getDataPath() + "/TrekStar/" + storageFileName + ".txt";
	}

	// initialize the list
	listStore = new LinearList();
	//read and populate listStore with file contents
	load();
}

Store::~Store()
{
	//write changes
	flush();

	qDebug("Deleting Store");
	//clean up
	delete &listStore;
}

// adds item to list. Item must be an object that extends the InfoContainer class and MUST implement the toString() method
void Store::add(InfoContainer * value)
{
	// add item to the list
	listStore->add(value);
}

void Store::removeAt(int position) {
    // remove item at index position
	listStore->removeAt(position);
}

InfoContainer * Store::getAt(int position) {
	// get item at index position
	return listStore->getAt(position);
}

void Store::load()
{
	std::ifstream input( storageFilePath );

	if (!input) {
		// file doesnt exist
		flush();// create
		load(); // re run this function
		return; // cancel current function
	}
	for (std::string line; getline(input, line); )
	{
		//TODO need to find a way to create an instance from a pre-existing instance of a class
		if (storageFileName == "movies" || storageFileName.at(0) == '@' ) {
			Film * f = new Film();
			f->fromString(line);
			qDebug("read line from file: " + Support::stringToQByteArray( line ));
			add(f);
		}
	}
	input.close();
}

void Store::flush()
{
	// write all changes to file
	ofstream myfile( storageFilePathWritable );

	//write items to file
	for (int i = 0; i < listStore->length(); i++) {
		// serializes the object and writes as new line
		myfile << listStore->getAt(i)->toString() << endl;
	}

	//DEBUG
	qDebug("Saved at " + Support::stringToQByteArray(storageFilePathWritable) );

	// closes file stream
	myfile.close();
}

int Store::length()
{
	return listStore->length();
}