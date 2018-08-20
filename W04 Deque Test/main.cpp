/*
 * main.cpp
 *
 *  Created on: May 14, 2018
 *      Author: Daniel Hixson
 */

#define UNIT_TESTING

#include <iostream>       // for CIN and COUT
#include <string>
#include <cassert>
#include "deque.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;


int main(int argc, const char* argv[]){

	deque<int> d;
	assert(d.iFront == 0);
	assert(d.iBack == -1);
	assert(d.numCapacity == 0);
	assert(d.buffer == NULL);
	cout << "Default Contructor Test Passed" << endl;

	d.push_back(90);
	assert(d.iFront == 0);
	assert(d.iBack == 0);
	assert(d.numCapacity == 1);
	assert(d.buffer[0] == 90);
	cout << "First push_back test passed" << endl;

	d.push_back(93);
	assert(d.iFront == 0);
	assert(d.iBack == 1);
	assert(d.numCapacity == 2);
	assert(d.buffer[1] == 93);

	d.push_back(99);
	assert(d.iFront == 0);
	assert(d.iBack == 2);
	assert(d.numCapacity == 4);
	assert(d.buffer[2] == 99);

	d.push_front(9);
	assert(d.iFront == -1);
	assert(d.iBack == 2);
	assert(d.numCapacity == 4);
	assert(d.buffer[3] == 9);
	assert(d.front() == 9);
	assert(d.back() == 99);

	cout << "front() and back() tests passed" << endl;

	d.pop_back();
	assert(d.iFront == -1);
	assert(d.iBack == 1);
	assert(d.numCapacity == 4);

	d.push_front(38);
	assert(d.iFront == -2);
	assert(d.iBack == 1);
	assert(d.numCapacity == 4);
	assert(d.buffer[2] == 38);

	d.push_back(85);
	assert(d.iFront == 0);
	assert(d.iBack == 4);
	assert(d.numCapacity == 8);
	assert(d.buffer[0] == 38);
	assert(d.buffer[1] == 9);
	assert(d.buffer[2] == 90);
	assert(d.buffer[3] == 93);
	assert(d.buffer[4] == 85);

	cout << "resize() + push_front() + pop_back() tests passed" << endl;

	deque<int> d2(5);
	assert(d2.iFront == 0);
	assert(d2.iBack == -1);
	assert(d2.numCapacity == 5);
	assert(d2.buffer != NULL);
	cout << "Non-Default Constructor test passed" << endl;

	d2.push_front(17);
	assert(d2.iFront == -1);
	assert(d2.iBack == -1);
	assert(d2.numCapacity == 5);
	assert(d2.buffer[4] == 17);

	d2.push_back(18);
	assert(d2.iFront == -1);
	assert(d2.iBack == 0);
	assert(d2.numCapacity == 5);
	assert(d2.buffer[0] == 18);

	deque<int> d3(d2);
	assert(d3.numCapacity == 2);
	assert(d3.iFront == 0);
	assert(d3.iBack == 1);
	assert(d3.buffer[0] == 17);
	assert(d3.buffer[1] == 18);
	cout << "Copy Constructor test passed" << endl;

	d = d3;
	assert(d.numCapacity == 8);
	assert(d.iFront == 0);
	assert(d.iBack == 1);
	assert(d.buffer[0] == 17);
	assert(d.buffer[1] == 18);
	assert(!d.empty());
	cout << "Assignment operator test passed" << endl;

	d.clear();
	assert(d.size() == 0);
	cout << "clear() test passed" << endl;
}


