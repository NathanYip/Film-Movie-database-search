#pragma once

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <QDesktopServices>
#include <QStandardPaths>
#include <QDir>

#include "linearlist.h"
#include "film.h"

class Store
{
	private:
		Storage::LinearList * listStore;
		string storageFileName;
		string storageFilePath;
		string storageFilePathWritable;
		void load();
	public:
		Store(string);
		~Store();
		void add(InfoContainer*);
		void removeAt(int);
		InfoContainer * getAt(int);
		void flush();
		int length();
};