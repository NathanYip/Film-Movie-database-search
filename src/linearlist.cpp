#include "linearlist.h"

Storage::LinearList::LinearList()
{
	head = NULL;
	tail = NULL;
	itemCount = 0;
}

Storage::LinearList::~LinearList()
{
	int count = length();
	while (count > 0) {
		removeAt(0);
		count = length();
	}
}

void Storage::LinearList::add(InfoContainer * value)
{
	lnode *temp = new lnode();
	temp->data = value;
	temp->next = NULL;
	if (head == NULL) {
		//nothing is currently in the list
		head = temp;
		tail = temp;
		temp = NULL;
	}
	else {
		//add to the end of list
		tail->next = temp;
		tail = temp;
	}
	itemCount++;
}

void Storage::LinearList::insertAt(int position, InfoContainer * value)
{
	if (position == length()) {
		LinearList::add(value); //add to the end
	}
	else if (position == 0) {
		//add tp start
		lnode *newHead = new lnode();
		newHead->data = value;
		newHead->next = head;
		head = newHead;
	}
	else {
		lnode *previous = new lnode();
		lnode *temp = new lnode();
		lnode *current = new lnode();
		previous = getNode(position - 1);
		current = getNode(position);
		temp->data = value;
		temp->next = current;
		previous->next = temp;
	}
}

void Storage::LinearList::removeAt(int position)
{
	lnode *previous = new lnode();
	lnode *current = new lnode();
	current = head;
	for (int i = 0; i < position; i++) {
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	delete current;
}

InfoContainer * Storage::LinearList::getAt(int position)
{
	return getNode(position)->data;
}

Storage::lnode * Storage::LinearList::getNode(int position)
{
	lnode *previous = new lnode();
	lnode *current = new lnode();
	current = head;
	for (int i = 0; i < position; i++) {
		previous = current;
		current = current->next;
	}
	return current;
}