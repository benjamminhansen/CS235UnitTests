/*
 * main.cpp
 *
 *  Created on: Jun 26, 2018
 *      Author: Daniel Hixson
 */

#define UNIT_TESTING

#include <iostream>
#include <string>
#include <cassert>
#include "map.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

int main(int argc, const char* argv[]){

	//Need to write tests for map data structure

	custom::Map<string, int> m;

	assert(m.bst.numElements == 0);
	assert(m.bst.root == NULL);

	cout << "Default Constructor Test Passed" << endl;

	m["a"] = 100;
	assert(m.bst.numElements == 1);
	assert(m.bst.root->data.key == "a");
	assert(m.bst.root->data.value == 100);

	m["b"];
	assert(m.bst.numElements == 2);
	assert(m.bst.root->data.key == "a");
	assert(m.bst.root->data.value == 100);
	//Done with previous tests
	assert(m.bst.root->pRight->data.key == "b");
	assert(m.bst.root->pRight->data.value == m["b"]);
	//Done with the right node tests.

	cout << "[] operator tests passed" << endl;

	m.insert("`", 17);
	assert(m.bst.numElements == 3);
	assert(m.bst.root->data.key == "a");
	assert(m.bst.root->data.value == 100);
	//Done with previous tests
	assert(m.bst.root->pRight->data.key == "b");
	assert(m.bst.root->pRight->data.value == m["b"]);
	//Done with right node tests.
	assert(m.bst.root->pLeft->data.key == "`");
	assert(m.bst.root->pLeft->data.value == 17);
	//Done with left node tests.

	cout << "insert() tests passed" << endl;

	custom::Map<string, int>::iterator it = m.find("b");

	assert(*it == m["b"]);

	it = m.find("...");

	assert(it == m.end());

	cout << "find() tests passed" << endl;

	custom::Map<string, int> m1(m);

	assert(m1.bst.numElements == 3);
	assert(m1.bst.root->data.key == "a");
	assert(m1.bst.root->data.value == 100);
	//Done with previous tests
	assert(m1.bst.root->pRight->data.key == "b");
	assert(m1.bst.root->pRight->data.value == m1["b"]);
	//Done with right node tests.
	assert(m1.bst.root->pLeft->data.key == "`");
	assert(m1.bst.root->pLeft->data.value == 17);

	cout << "Copy Constructor Test Passed" << endl;

	cout << "Congrats! You reached the end of testing!" << endl;

	return 0;
}





