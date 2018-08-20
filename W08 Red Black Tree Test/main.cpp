/*
 * main.cpp
 *
 *  Created on: Jun 19, 2018
 *      Author: Daniel Hixson
 */



#define UNIT_TESTING

#include <iostream>       // for CIN and COUT
#include <string>
#include <cassert>
#include "BST.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

int main(int argc, const char* argv[]){

	BST<int> t;
	assert(t.root == NULL);
	assert(t.numElements == 0);

	cout << "Default Constructor Test Passed" << endl;

	t.insert(5);
	assert(t.numElements == 1);
	assert(t.root != NULL);
	assert(t.root->data == 5);
	assert(t.root->pParent == NULL);
	assert(t.root->pRight == NULL);
	assert(t.root->pLeft == NULL);
	assert(t.root->isRed == false);

	t.insert(3);
	assert(t.numElements == 2);
	assert(t.root != NULL);
	assert(t.root->isRed == false);
	assert(t.root->data == 5);
	assert(t.root->pParent == NULL);
	assert(t.root->pRight == NULL);
	assert(t.root->pLeft != NULL);
	assert(t.root->pLeft->data == 3);
	assert(t.root->pLeft->pParent == t.root);
	assert(t.root->pLeft->pRight == NULL);
	assert(t.root->pLeft->pLeft == NULL);
	assert(t.root->pLeft->isRed == true);

	t.insert(9);
	assert(t.numElements == 3);
	assert(t.root != NULL);
	assert(t.root->isRed == false);
	assert(t.root->data == 5);
	assert(t.root->pParent == NULL);
	assert(t.root->pRight != NULL);
	assert(t.root->pRight->data == 9);
	assert(t.root->pRight->pParent == t.root);
	assert(t.root->pRight->pRight == NULL);
	assert(t.root->pRight->pLeft == NULL);
	assert(t.root->pRight->isRed == true);

	assert(t.root->pLeft != NULL);
	assert(t.root->pLeft->data == 3);
	assert(t.root->pLeft->pParent == t.root);
	assert(t.root->pLeft->pRight == NULL);
	assert(t.root->pLeft->pLeft == NULL);
	assert(t.root->pLeft->isRed == true);

	assert(t.root->pRight->getSibling() == t.root->pLeft);
	assert(t.root->pLeft->getSibling() == t.root->pRight);

	cout << "getSibling() test passed" << endl;

	t.insert(4);
	assert(t.numElements == 4);
	assert(t.root->pLeft->pRight != NULL);
	assert(t.root->pLeft->pRight->data == 4);
	assert(t.root->pLeft->pRight->pParent == t.root->pLeft);
	assert(t.root->pLeft->pRight->pRight == NULL);
	assert(t.root->pLeft->pRight->pLeft == NULL);
	assert(t.root->isRed == false);
	assert(t.root->pRight->isRed == false);
	assert(t.root->pLeft->isRed == false);
	assert(t.root->pLeft->pRight->isRed == true);



	t.insert(7);
	assert(t.numElements == 5);
	assert(t.root->pRight->pLeft != NULL);
	assert(t.root->pRight->pLeft->data == 7);
	assert(t.root->pRight->pLeft->pParent == t.root->pRight);
	assert(t.root->pRight->pLeft->pRight == NULL);
	assert(t.root->pRight->pLeft->pLeft == NULL);
	assert(t.root->isRed == false);
	assert(t.root->pRight->isRed == false);
	assert(t.root->pLeft->isRed == false);
	assert(t.root->pLeft->pRight->isRed == true);
	assert(t.root->pRight->pLeft->isRed == true);


	cout << "insert() tests passed" << endl;

	BST<int> t2;
	t2.insert(1);
	t2.insert(2);

	assert(t2.root->getSibling() == NULL);

	t2.insert(3);
	assert(t2.numElements == 3);
	assert(t2.root != NULL);
	assert(t2.root->pParent == NULL);
	assert(t2.root->isRed == false);


	assert(t2.root->data == 2);
	assert(t2.root->pLeft != NULL);
	assert(t2.root->pLeft->data == 1);
	assert(t2.root->pRight != NULL);
	assert(t2.root->pRight->data == 3);

	cout << "left re-balancing test passed" << endl;

	BST<int> t3;
	t3.insert(9);
	t3.insert(8);
	t3.insert(7);

	assert(t3.numElements == 3);
	assert(t3.root != NULL);
	assert(t3.root->pParent == NULL);
	assert(t3.root->data == 8);
	assert(t3.root->isRed == false);

	assert(t3.root->pLeft->data == 7);
	assert(t3.root->pLeft->pLeft == NULL);
	assert(t3.root->pLeft->pRight == NULL);
	assert(t3.root->pLeft->isRed == true);


	assert(t3.root->pRight->data == 9);
	assert(t3.root->pRight->pLeft == NULL);
	assert(t3.root->pRight->pRight == NULL);
	assert(t3.root->pRight->isRed == true);


	cout << "right rebalancing test passed" << endl;

	BST<int> t4;
	t4.insert(5);
	t4.insert(3);
	t4.insert(4);

	assert(t4.numElements == 3);
	assert(t4.root->data == 4);
	assert(t4.root->pLeft->pParent == t4.root);
	assert(t4.root->pRight->pParent == t4.root);

	assert(t4.root->isRed == false);
	assert(t4.root->pLeft->data == 3);
	assert(t4.root->pLeft->pRight == NULL);
	assert(t4.root->pLeft->pLeft == NULL);
	assert(t4.root->pLeft->isRed == true);
	assert(t4.root->pRight->data == 5);
	assert(t4.root->pRight->pRight == NULL);
	assert(t4.root->pRight->pLeft == NULL);
	assert(t4.root->pRight->isRed == true);

	cout << "bottom-to-top left re-balancing test passed" << endl;

	BST<int> t5;
	t5.insert(5);
	t5.insert(7);
	t5.insert(6);

	assert(t5.numElements == 3);
	assert(t5.root->data == 6);
	assert(t5.root->pLeft->pParent == t5.root);
	assert(t5.root->pRight->pParent == t5.root);

	assert(t5.root->isRed == false);
	assert(t5.root->pLeft->data == 5);
	assert(t5.root->pLeft->pRight == NULL);
	assert(t5.root->pLeft->pLeft == NULL);
	assert(t5.root->pLeft->isRed == true);

	assert(t5.root->pRight->data == 7);
	assert(t5.root->pRight->pRight == NULL);
	assert(t5.root->pRight->pLeft == NULL);
	assert(t5.root->pRight->isRed == true);

	cout << "bottom-to-top right re-balancing test passed" << endl;

	BST<int> t6;
	t6.insert(4);
	t6.insert(2);
	t6.insert(6);
	t6.insert(1);
	t6.insert(3);
	t6.insert(5);
	t6.insert(7);

	BST<int>::iterator it = t6.find(2);
	assert(it.p->data == 2);
	assert(it.p->pParent == t6.root);

	cout << "find() test passed" << endl;

	t6.erase(it);

	assert(t6.numElements == 6);
	assert(t6.root->pLeft->data == 3);
	assert(t6.root->pLeft->pLeft->data == 1);
	assert(t6.root->pLeft->pRight == NULL);

	cout << "erase() case with two children without grand-children test passed" << endl;

	it = t6.find(4);

	t6.erase(it);

	assert(t6.numElements == 5);
	assert(t6.root->data == 5);
	assert(t6.root->pRight->data == 6);
	assert(t6.root->pRight->pLeft == NULL);
	assert(t6.root->pRight->pRight->data == 7);
	assert(t6.root->pLeft->data == 3);
	assert(t6.root->pLeft->pLeft->data == 1);
	assert(t6.root->pLeft->pRight == NULL);

	cout << "erase(root) test passed" << endl;

	it = t6.find(6);

	t6.erase(it);

	assert(t6.numElements == 4);
	assert(t6.root->data == 5);
	assert(t6.root->pRight->data == 7);
	assert(t6.root->pRight->pParent == t6.root);
	assert(t6.root->pRight->pRight == NULL);
	assert(t6.root->pRight->pLeft == NULL);

	cout << "erase() of a right side node with one right side child test complete" << endl;

	BST<int> t7(t);
	assert(t7.numElements == 5);
	assert(t7.root->pRight->pLeft != NULL);
	assert(t7.root->pRight->pLeft->data == 7);
	assert(t7.root->pRight->pLeft->pParent == t7.root->pRight);
	assert(t7.root->pRight->pLeft->pRight == NULL);
	assert(t7.root->pRight->pLeft->pLeft == NULL);
	assert(t7.root->isRed == false);
	assert(t7.root->pRight->isRed == false);
	assert(t7.root->pLeft->isRed == false);
	assert(t7.root->pLeft->pRight->isRed == true);
	assert(t7.root->pRight->pLeft->isRed == true);

	cout << "Copy Constructor test passed" << endl;



	return 0;
}


