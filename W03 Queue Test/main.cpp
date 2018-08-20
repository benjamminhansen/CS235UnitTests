/*
 * main.cpp
 *
 *  Created on: May 7, 2018
 *      Author: Daniel Hixson
 */

#define UNIT_TESTING

#include <iostream>       // for CIN and COUT
#include <string>
#include <cassert>
#include "queue.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;


int main(int argc, const char* argv[]){

	queue <int> q;
	assert(q.numCapacity == 0);
	assert(q.numPush == 0);
	assert(q.numPop == 0);
	assert(q.buffer == NULL);
	cout << "Constructor test passed" << endl;

	queue <int> q2(10);
	assert(q2.numCapacity == 10);
	assert(q2.numPush == 0);
	assert(q2.numPop == 0);
	assert(q2.buffer != NULL);
	cout << "Non-Default Constructor test passed" << endl;

	queue <int> q3;
	q3.push(1);
	assert(q3.numCapacity == 1);
	assert(q3.numPop == 0);
	assert(q3.numPush == 1);
	assert(q3.buffer[0] == 1);
	cout << "push() test passed" << endl;

	q3.pop();
	assert(q3.numCapacity == 1);
	assert(q3.numPop == 1);
	assert(q3.numPush == 1);
	assert(q3.buffer != NULL);
	cout << "pop() test passed" << endl;

	q3.push(5);
	q3.push(10);
	assert(q3.numCapacity == 2);
	assert(q3.numPush == 2); //This is because the resizing of the queue.
	assert(q3.numPop == 0);
	assert(q3.buffer[0] == 5);
	assert(q3.buffer[1] == 10);
	cout << "resize() test passed" << endl;

	q3.pop();
	q3.push(17);
	assert(q3.numCapacity == 2);
	assert(q3.numPush == 3);
	assert(q3.numPop == 1);
	assert(q3.buffer[0] == 17);
	assert(q3.buffer[1] == 10);
	cout << "wrapping test passed" << endl;

	assert(q3.front() == 10);
	cout << "front() test passed" << endl;
	assert(q3.back() == 17);
	cout << "back() test passed" << endl;

	queue <int> qCopy(q3);

	assert(qCopy.numCapacity == 2);
	assert(qCopy.numPush == 2);
	assert(qCopy.numPop == 0);
	assert(qCopy.buffer[0] == 10);
	assert(qCopy.buffer[1] == 17);
	cout << "Copy Contructor test passed" << endl;

	queue <int> q6;

	q6.push(5);
	q6.push(4);
	q6.push(9);
	q6.pop();

	queue <int> q7;

	q7 = q6;
	assert(q7.numCapacity == 2);
	assert(q7.numPush == 2);
	assert(q7.numPop == 0);
	assert(q7.buffer[0] == 4);
	assert(q7.buffer[1] == 9);
	cout << "= operator test passed" << endl;

	q7.clear();
	assert(q7.numCapacity == 2);
	assert(q7.numPush == 0);
	assert(q7.numPop == 0);
	assert(q7.size() == 0);
	assert(q7.empty() == true);
	cout << "clear() test passed" << endl;

	return 0;
}
