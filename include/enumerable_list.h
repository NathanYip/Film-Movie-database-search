#pragma once
#include <utility>
#include <string>
#include <iostream>

#include "infocontainer.h"

using std::string;
using std::pair;

namespace Storage {

	struct enode {
		pair<string, InfoContainer> data;
		enode *next;
	};

	class EnumerableList {

	protected:
		enode * head;
		enode * tail;
		int itemCount;
		enode * getNode(int);
	public:
		EnumerableList();
		~EnumerableList();
		void add(string,InfoContainer);
		void insertAt(int, string, InfoContainer);
		void remove(string);
		void removeAt(int);
		InfoContainer get(string);
		pair<string,InfoContainer> getAt(int);
		int length();
	};

}
