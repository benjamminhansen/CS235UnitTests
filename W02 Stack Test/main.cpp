/*
 * main.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: Daniel Hixson
 */
#define UNIT_TESTING

#include <iostream>       // for CIN and COUT
#include <string>
#include <cassert>
#include "stack.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;
//using namespace std;



int main(int argc, const char* argv[]) {

	stack <int> s;
	assert(s.numElements == 0);
	assert(s.numCapacity == 0);
	assert(s.buffer == NULL);

	cout << "Default Constructor Test Passed" << endl;
	stack <int> s2(4);
	assert(s2.numElements == 0);
	assert(s2.numCapacity == 4);
	assert(s2.buffer != NULL);

	cout << "Non-Default Capacity Constructor Test Passed" << endl;
	stack <int> s3(s2);
	assert(s3.numElements == s2.numElements);
	assert(s3.numCapacity != s2.numCapacity);
	assert(s3.buffer != s2.buffer);

	cout << "Copy Constructor Test Passed" << endl;
	stack <int> s4;
	s4.push(1);
	assert(s4.numCapacity == 1);
	assert(s4.numElements == 1);
	assert(s4.buffer[0] == 1);

	cout << "push() Test Passed" << endl;
	s4.push(5);
	assert(s4.numCapacity == 2);
	assert(s4.numElements == 2);
	assert(s4.buffer[1] == 5);

	s4.push(10);
	assert(s4.numCapacity == 4);
	assert(s4.numElements == 3);
	assert(s4.buffer[2] == 10);

	s4.pop();
	assert(s4.numCapacity == 4);
	assert(s4.numElements == 2);
	//assert(s4.buffer[2] == NULL); //Is there a way to assert this?

	cout << "pop() Test Passed" << endl;
	s4.pop();
	assert(s4.numCapacity == 4);
	assert(s4.numElements == 1);
	//buffer code here.

	stack <int> s5;

	s5.push(3);
	assert(s5.numCapacity == 1);
	assert(s5.numElements == 1);
	assert(s5.buffer[0] == 3);

	s5.top() = 5; //Why not put s5.top(5); ?
	assert(s5.numCapacity == 1);
	assert(s5.numElements == 1);
	assert(s5.buffer[0] == 5); //Correct notation?

	cout << "top() Test Passed" << endl;

	stack <int> sCopy(4);

	sCopy.push(2);

	stack <int> sCopy2;

	sCopy2 = sCopy;
	assert(sCopy2.numElements == sCopy.numElements);
	assert(sCopy2.numCapacity == 1);
	assert(sCopy.numCapacity == 4);
	assert(sCopy2.buffer[0] == 2);
	assert(sCopy2.numCapacity != sCopy.numCapacity);

	cout << "= Operator Test Passed" << endl;

	stack <int> sSizeTest;

	sSizeTest.push(1);
	assert(sSizeTest.size() == 1);
	assert(!sSizeTest.empty());

	sSizeTest.push(2);
	assert(sSizeTest.size() == 2);
	assert(!sSizeTest.empty());

	sSizeTest.pop();
	assert(sSizeTest.size() == 1);
	assert(!sSizeTest.empty());

	sSizeTest.clear();
	assert(sSizeTest.size() == 0);
	assert(sSizeTest.empty());

	cout << "size() and empty() Tests Passed" << endl;

	stack <string> sString;

	sString.push("Hello");
	sString.push("It's me");
	sString.push("I was wondering");
	assert(sString.buffer[0] == "Hello");
	assert(sString.buffer[1] == "It's me");
	assert(sString.buffer[2] == "I was wondering");
	assert(sString.numCapacity == 4);
	assert(sString.numElements == 3);

	cout << "This stack can hold a string!!!!" << endl;

	return 0;
}
