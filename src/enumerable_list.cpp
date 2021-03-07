#include "enumerable_list.h"

Storage::EnumerableList::EnumerableList()
{
	head = NULL;
	tail = NULL;
	itemCount = 0;
}

Storage::EnumerableList::~EnumerableList()
{
	// destroy all nodes
	int count = length();
	while (count > 0) {
		removeAt(0);
		count = length();
	}
}

// add item to end
void Storage::EnumerableList::add(string key,InfoContainer value)
{
	enode *temp = new enode();
	temp->data.first = key;
	temp->data.second = value;
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

// insert key value pair at index
void Storage::EnumerableList::insertAt(int position, string key, InfoContainer value)
{
	if (position == length()) {
		add(key, value); //add to the end
	}
	else if (position == 0) {
		//add tp start
		enode *newHead = new enode();
		newHead->data.first = key;
		newHead->data.second = value;
		newHead->next = head;
		head = newHead;
	}
	else {
		enode *previous = new enode();
		enode *temp = new enode();
		enode *current = new enode();
		previous = getNode(position - 1);
		current = getNode(position);
		temp->data.first = key;
		temp->data.second = value;
		temp->next = current;
		previous->next = temp;
	}
}

// remove node by key
void Storage::EnumerableList::remove(string key)
{
	enode *item = new enode();
	int index = 0;
	item = head;
	while (item != NULL) {
		if (item->data.first == key) {
			removeAt(index);
			return;
		}
		index++;
	}
}

// remove item at position
void Storage::EnumerableList::removeAt(int position)
{
	enode *previous = new enode();
	enode *current = new enode();
	current = head;
	for (int i = 0; i < position; i++) {
		previous = current;
		current = current->next;
	}
	previous->next = current->next;
	delete current;
}

// get value by key
InfoContainer Storage::EnumerableList::get(string key)
{
	enode *item = new enode();
	item = head;
	while (item != NULL) {
		if (item->data.first == key) return item->data.second;
		item = item->next;
	}
	return InfoContainer();
}

// get node at index
Storage::enode * Storage::EnumerableList::getNode(int position)
{
	enode *previous = new enode();
	enode *current = new enode();
	current = head;
	for (int i = 0; i < position; i++) {
		previous = current;
		current = current->next;
	}
	return current;
}

// find pair at index
pair<string, InfoContainer> Storage::EnumerableList::getAt(int position)
{
	return getNode(position)->data;
}

//get the size of the list
int Storage::EnumerableList::length()
{
	return itemCount;
}
