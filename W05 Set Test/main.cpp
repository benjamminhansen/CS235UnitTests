/*
 * main.cpp
 *
 *  Created on: May 18, 2018
 *      Author: Daniel Hixson
 */

#define UNIT_TESTING

#include <iostream>       // for CIN and COUT
#include <string>
#include <cassert>
#include "set.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

int main(int argc, const char* argv[]){

	set <int> s;
	assert(s.numCapacity == 0);
	assert(s.numElements == 0);
	assert(s.buffer == NULL);
	cout << "Default Constructor test passed" << endl;

	set <int> s2(5);
	assert(s2.numCapacity == 5);
	assert(s2.numElements == 0);
	assert(s2.buffer != NULL);
	cout << "Non-Default Constructor test passed" << endl;

	set <int> s3(s2);
	assert(s3.numCapacity == 5);
	assert(s3.numElements == 0);
	assert(s3.buffer != NULL);
	cout << "Copy Constructor test passed" << endl;

	set <int> s4;
	s4 = s3;
	assert(s4.numCapacity == 5);
	assert(s4.numElements == 0);
	assert(s4.buffer != NULL);
	cout << "Assignment operator test passed" << endl;

	s4.buffer[0] = 1;
	s4.buffer[1] = 3;
	s4.buffer[2] = 4;
	s4.buffer[3] = 7;
	s4.buffer[4] = 10;
	s4.numElements = 5;

	assert(s4.find(2) == s4.end());
	assert(s4.find(5) == s4.end());
	assert(s4.find(0) == s4.end());
	assert(s4.find(9) == s4.end());
	assert(s4.find(11) == s4.end());
	cout << "not find() test passed" << endl;

	set <int> :: iterator it;
	it = s4.begin();
	assert(s4.find(1) == it);
	assert(s4.find(3) == ++it);
	assert(s4.find(4) == ++it);
	assert(s4.find(7) == ++it);
	assert(s4.find(10) == ++it);
	cout << "find() test passed" << endl;

	set <int> s5;

	s5.insert(1); // Working right here.
	assert(s5.numCapacity == 1);
	assert(s5.numElements == 1);
	assert(s5.buffer[0] == 1);

	s5.insert(5);
	assert(s5.numCapacity == 2);
	assert(s5.numElements == 2);
	assert(s5.buffer[0] == 1);
	assert(s5.buffer[1] == 5);

	s5.insert(3);
	assert(s5.numCapacity == 4);
	assert(s5.numElements == 3);
	assert(s5.buffer[0] == 1);
	assert(s5.buffer[1] == 3);
	assert(s5.buffer[2] == 5);

	cout << "insert() test passed" << endl;

	it = s5.find(3);
	s5.erase(it);
	assert(s5.numCapacity == 4);
	assert(s5.numElements == 2);
	assert(s5.buffer[0] == 1);
	assert(s5.buffer[1] == 5);
	cout << "erase() test passed" << endl;

	it = s5.find(9);
	s5.erase(it);
	assert(s5.numCapacity == 4);
	assert(s5.numElements == 2);
	assert(s5.buffer[0] == 1);
	assert(s5.buffer[1] == 5);
	cout << "non existing item erase() test passed" << endl;

	set <int> s6;
	s6.buffer = new int[8];
	s6.buffer[0] = 1;
	s6.buffer[1] = 2;
	s6.buffer[2] = 3;
	s6.buffer[3] = 4;
	s6.buffer[4] = 5;
	s6.numElements = 5;
	s6.numCapacity = 8;

	set <int> s7;
	s7.buffer = new int[8];
	s7.buffer[0] = 1;
	s7.buffer[1] = 3;
	s7.buffer[2] = 5;
	s7.buffer[3] = 7;
	s7.buffer[4] = 9;
	s7.numElements = 5;
	s7.numCapacity = 8;

	set <int> s8 = s6 || s7;
	assert(s8.numCapacity == 8);
	assert(s8.numElements == 7);
	assert(s8.buffer[0] == 1);
	assert(s8.buffer[1] == 2);
	assert(s8.buffer[2] == 3);
	assert(s8.buffer[3] == 4);
	assert(s8.buffer[4] == 5);
	assert(s8.buffer[5] == 7);
	assert(s8.buffer[6] == 9);
	cout << "Union test passed" << endl;

	set <int> s9 = s6 && s7;
	assert(s9.numCapacity == 4);
	assert(s9.numElements == 3);
	assert(s9.buffer[0] == 1);
	assert(s9.buffer[1] == 3);
	assert(s9.buffer[2] == 5);
	cout << "Intersection test passed" << endl;

	set <int> s10 = s6 - s7;
	assert(s10.numCapacity == 2);
	assert(s10.numElements == 2);
	assert(s10.buffer[0] == 2);
	assert(s10.buffer[1] == 4);
	cout << "Difference test passed" << endl;

	set <int> s11(s10);
	assert(s11.numCapacity == 2);
	assert(s11.numElements == 2);
	assert(s11.buffer[0] == 2);
	assert(s11.buffer[1] == 4);
	cout << "Copy Constructor test passed" << endl;

	return 0;
}

