/*
 * main.cpp
 *
 *  Created on: May 29, 2018
 *      Author: Daniel Hixson
 */


#define UNIT_TESTING

#include <iostream>       // for CIN and COUT
#include <string>
#include <cassert>
#include "node.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

int main(int argc, const char* argv[]){

	Node <int> * n0 = NULL;
	assert(n0 == NULL);
	cout << "NULL test passed" << endl;

	Node <int> * n1 = new Node<int>();
	assert(n1->pNext == NULL);
	assert(n1->pPrev == NULL);
	cout << "Default Constructor test passed" << endl;

	Node <int> * n2 = new Node<int>(8);
	assert(n2->data == 8);
	assert(n2->pNext == NULL);
	assert(n2->pPrev == NULL);
	cout << "Non-Default Constructor test passed" << endl;

	Node <int> * n3 = NULL;
	n3 = insert((Node<int> *) NULL, 3, false); //casted NULL as Node<T> pointer type.
	assert(n3->data == 3);
	assert(n3->pNext == NULL);
	assert(n3->pPrev == NULL);

	insert(n3, 2, false);
	assert(n3->data == 3);
	assert(n3->pNext == NULL);
	assert(n3->pPrev != NULL);
	assert(n3->pPrev->data == 2);
	assert(n3->pPrev->pPrev == NULL);
	assert(n3->pPrev->pNext == n3);

	insert(n3, 5, true);
	assert(n3->data == 3);
	assert(n3->pNext != NULL);
	assert(n3->pPrev != NULL);
	assert(n3->pPrev->data == 2);
	assert(n3->pPrev->pPrev == NULL);
	assert(n3->pPrev->pNext == n3);
	assert(n3->pNext->data == 5);
	assert(n3->pNext->pPrev == n3);
	assert(n3->pNext->pNext == NULL);
	cout << "insert() tests passed" << endl;

	Node <int> * n4 = new Node<int>(2);
	insert(n4, 4, true);
	insert(n4->pNext, 6, true);

	Node <int> * result;
	result = find(n4, 5);
	assert(result == NULL);
	result = find(n4, 4);
	assert(result == n4->pNext);
	result = find(n4, 2);
	assert(result == n4);
	cout << "find() tests passed" << endl;

	Node <int> * n5 = new Node<int>(2);
	n5->pNext = new Node<int>(1);
	n5->pNext->pPrev = n5;
	n5->pNext->pNext = new Node<int>(0);
	n5->pNext->pNext->pPrev = n5->pNext;

	remove(n5->pNext);
	assert(n5->pNext->data == 0);
	assert(n5->pNext->pNext == NULL);
	assert(n5->pNext->pPrev == n5);

	n5 = remove(n5);
	assert(n5->data == 0);
	assert(n5->pNext == NULL);
	assert(n5->pPrev == NULL);

	n5 = remove(n5);
	assert(n5 == NULL);

	cout << "remove() tests passed" << endl;

	Node <int> * n6 = new Node<int>(2);
	n6->pNext = new Node<int>(1);
	n6->pNext->pPrev = n6;
	n6->pNext->pNext = new Node<int>(0);
	n6->pNext->pNext->pPrev = n6->pNext;

	clear(n6);
	assert(NULL == n6);

	cout << "clear() tests passed" << endl;

	Node <int> * n7 = new Node<int>(2);
	n7->pNext = new Node<int>(1);
	n7->pNext->pPrev = n7;
	n7->pNext->pNext = new Node<int>(0);
	n7->pNext->pNext->pPrev = n7->pNext; //inserted incorrectly??
	assert(n7->pNext->data == 1);
	assert(n7->pNext->pPrev == n7);
	assert(n7->pNext->pNext->data == 0);
	assert(n7->pNext->pNext->pPrev == n7->pNext);
	assert(n7->pNext->pNext->pNext == NULL);
	assert(n7->pPrev == NULL);

	Node <int> * n8;
	n8 = copy(n7);
	assert(n8->data == 2);
	cout << n8->data << endl; //2
	cout << n8->pNext->data << endl; //2
	cout << n8->pNext->pNext->data << endl; //1
	cout << n8->pNext->pNext->pNext->data << endl; //0
	//Above is not working properly...it should just be 2 1 0.
	/*
	assert(n8->pNext->data == 1);
	assert(n8->pNext->pPrev == n8);
	assert(n8->pNext->pNext->data == 0);
	assert(n8->pNext->pNext->pPrev == n8->pNext);
	assert(n8->pNext->pNext->pNext == NULL);
	assert(n8->pPrev == NULL);
	cout << "copy() tests passed" << endl;
	*/
	return 0;
}

