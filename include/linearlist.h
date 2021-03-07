#pragma once

#include "enumerable_list.h"

namespace Storage {

	struct lnode : enode {
		InfoContainer * data;
		lnode *next;
	};

	class LinearList : public EnumerableList {

	private:
		lnode * head;
		lnode * tail;
		lnode * getNode(int);
	public:
		LinearList();
		~LinearList();
		void add(InfoContainer*);
		void insertAt(int, InfoContainer*);
		void removeAt(int);
		InfoContainer * getAt(int);
	};

}
