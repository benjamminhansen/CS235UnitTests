/*
 * main.cpp
 *
 *  Created on: May 30, 2018
 *      Author: Daniel Hixson
 */

#define UNIT_TESTING

#include <iostream>       // for CIN and COUT
#include <string>
#include <cassert>
#include "list.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

int main(int argc, const char* argv[]){

	List <int> l;
	assert(l.pHead == NULL);
	assert(l.pTail == NULL);
	assert(l.numElements == 0);
	cout << "Default Constructor test passed" << endl;

	l.push_back(4);
	assert(l.numElements == 1);
	assert(l.pHead->data == 4);
	assert(l.pTail->data == 4);
	assert(l.pHead == l.pTail);

	l.push_back(6);
	assert(l.numElements == 2);
	assert(l.pTail->data == 6);
	assert(l.pHead->data == 4);
	assert(l.pHead->pNext == l.pTail);
	assert(l.pTail->pPrev == l.pHead);

	cout << "push_back() tests passed" << endl;
	l.push_front(2);
	assert(l.numElements == 3);
	assert(l.pTail->data == 6);
	assert(l.pHead->data == 2);
	assert(l.pHead->pNext == l.pTail->pPrev);
	assert(l.pTail->pPrev->data == 4);

	l.push_front(0);
	assert(l.numElements == 4);
	assert(l.pTail->data == 6);
	assert(l.pHead->data == 0);
	assert(l.pHead->pNext->pNext->pNext == l.pTail);
	assert(l.pTail->pPrev->pPrev->data == 2);

	cout << "push_front() tests passed" << endl;

	l.pop_front();
	assert(l.numElements == 3);
	assert(l.pTail->data == 6);
	assert(l.pHead->data == 2);
	assert(l.pHead->pNext == l.pTail->pPrev);
	assert(l.pTail->pPrev->data == 4);
	assert(l.pHead->pPrev == NULL);
	assert(l.pTail->pNext == NULL);

	cout << "pop_front() tests passed" << endl;

	l.pop_back();
	assert(l.numElements == 2);
	assert(l.pTail->data == 4);
	assert(l.pHead->data == 2);
	assert(l.pHead->pNext == l.pTail);
	assert(l.pTail->pPrev == l.pHead);
	assert(l.pHead->pPrev == NULL);
	assert(l.pTail->pNext == NULL);

	cout << "pop_back() tests passed" << endl;

	assert(l.size() == 2);
	cout << "size() tests passed" << endl;

	assert(l.empty() == false);
	cout << "empty() tests passed" << endl;

	l.clear();
	assert(l.pHead == NULL);
	assert(l.pHead == NULL);
	assert(l.numElements == 0);
	assert(l.size() == 0);
	assert(l.empty() == true);
	cout << "clear() tests passed" << endl;

	l.push_back(1);
	l.push_front(0);
	assert(l.front() == 0);
	assert(l.back() == 1);
	cout << "front() tests passed" << endl;
	cout << "back() tests passed" << endl;

	List<int>::iterator it = l.find(1);
	assert(*it == 1);

	it = l.find(2);
	assert(it == l.end());

	it = l.begin();
	assert(*it == 0);

	l.insert(it, 2);
	assert(l.numElements == 3);
	assert(l.pTail->data == 1);
	assert(l.pHead->data == 2);
	assert(l.pHead->pNext->data == 0);

	cout << "insert() test passed" << endl;


	it = l.find(2);
	assert(*it == 2);
	cout << "find() test passed" << endl;

	it = l.erase(it);
	assert(it == l.end() );
	assert(l.pHead->data == 0);
	assert(l.pTail->data == 1);
	assert(l.numElements == 2);
	assert(l.pHead->pNext == l.pTail);
	assert(l.pTail->pPrev == l.pHead);
	cout << "erase() test passed" << endl;

	List <int> list2(l);

	assert(list2.pHead->data == 0);
	assert(list2.pTail->data == 1);
	assert(list2.numElements == 2);
	assert(list2.pHead->pNext == list2.pTail);
	assert(list2.pTail->pPrev == list2.pHead);
	cout << "Copy Constructor test passed" << endl;

	return 0;
}
