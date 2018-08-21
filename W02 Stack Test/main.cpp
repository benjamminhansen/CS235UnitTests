/*
 * main.cpp
 *
 *  Created on: Apr 30, 2018
 *      Author: Daniel Hixson
 *  Modified on: Aug 20, 2018
 *      Author: Lee Barney
 */
#define UNIT_TESTING

#include <iostream>       // for CIN and COUT
#include <string>
#include <cassert>
#include "stack.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;
//using namespace std;



int main(int argc, const char* argv[]) {
    /*
     * Testing default constructor
     */
	stack <int> s;
	assert(s.numElements == 0);
	assert(s.numCapacity == 0);
	assert(s.buffer == NULL);
	cout << "Default Constructor Test Passed" << endl;
    /*
     * Testing sizing constructor
     */
	stack <int> s2(4);
	assert(s2.numElements == 0);
	assert(s2.numCapacity == 4);
	assert(s2.buffer != NULL);
	cout << "Sizing Non-Default Capacity Constructor Test Passed" << endl;
    /*
     * Testing copy constructor
     */
	stack <int> s3(s2);
	assert(s3.numElements == s2.numElements);
	assert(s3.numCapacity != s2.numCapacity);
	assert(s3.buffer != s2.buffer);
	cout << "Copy Constructor Test Passed" << endl;
    /*
     * Testing push method
     */
	stack <int> s4;
	s4.push(1);
	assert(s4.numCapacity == 1);
	assert(s4.numElements == 1);
	assert(s4.buffer[0] == 1);
	cout << "Push First ElementTest Passed" << endl;
    
	s4.push(5);
	assert(s4.numCapacity == 2);
    assert(s4.numElements == 2);
    assert(s4.buffer[0] == 1);
    assert(s4.buffer[1] == 5);
    cout << "Push Second ElementTest Passed" << endl;

	s4.push(10);
	assert(s4.numCapacity == 4);
	assert(s4.numElements == 3);
    assert(s4.buffer[0] == 1);
    assert(s4.buffer[1] == 5);
	assert(s4.buffer[2] == 10);
    cout << "Push Second ElementTest Passed" << endl;
    /*
     * Testing Pop
     */
    
    stack <int> s5;
    
    s5.pop();
    assert(s5.numCapacity == 0);
    assert(s5.numElements == 0);
    cout << "Pop Empty Stack Test Passed" << endl;
    
    s5.numCapacity = 4;
    s5.numElements = 3;
    s5.buffer = new int[4];
    s5.buffer[0] = -2;
    s5.buffer[1] = 17;
    s5.buffer[2] = 0;
    
	s5.pop();
	assert(s5.numCapacity == 4);
	assert(s5.numElements == 2);
    assert(s5.buffer[0] == -2);
    assert(s5.buffer[1] == 17);
	cout << "Pop Latest Element Test Passed" << endl;
    
	s5.pop();
    assert(s5.buffer[0] == -2);
	assert(s5.numCapacity == 4);
	assert(s5.numElements == 1);
    cout << "Pop Middle Element Test Passed" << endl;
    
    s5.pop();
    assert(s5.numCapacity == 4);
    assert(s5.numElements == 0);
    cout << "Pop Earliest Element Test Passed" << endl;
    

	stack <int> s6;
	s6.numCapacity = 1;
    s6.numElements = 1;
    s6.buffer = new int[1];
    s6.buffer[0] = 3;
    /*
     * Testing top method as getter
     */
    assert(s6.numCapacity == 1);
    assert(s6.numElements == 1);
    assert(s6.top() == 3);
    cout<<"Top as Setter passed."<<endl;
    /*
     * Testing top method as setter
     */
	s6.top() = 5;
	assert(s6.numCapacity == 1);
	assert(s6.numElements == 1);
	assert(s6.buffer[0] == 5); //Correct notation?

	cout << "Top as Getter Passed" << endl;

    /*
     * Testing = operator and copy constructor
     */
	stack <int> stackToCopy;
    stackToCopy.numCapacity = 8;
    stackToCopy.numElements = 5;
    stackToCopy.buffer = new int[stackToCopy.numCapacity];
    for (int i = 0; i < stackToCopy.numElements; i++) {
        stackToCopy.buffer[i]=i*i+1;
    }

	stack <int> stackCopiedTo;
	stackCopiedTo = stackToCopy;
	assert(stackCopiedTo.numElements == stackToCopy.numElements);
	assert(stackCopiedTo.numCapacity == 5);
	assert(stackCopiedTo.numElements == 5);
    assert(stackCopiedTo.buffer[0] == 1);
    assert(stackCopiedTo.buffer[1] == 2);
    assert(stackCopiedTo.buffer[2] == 5);
    assert(stackCopiedTo.buffer[3] == 10);
    assert(stackCopiedTo.buffer[4] == 17);

	cout << "= Operator and Copy Constructor Test Passed" << endl;


    /*
     * Testing Size
     */
    stack <int> sSizeTest;
    
    
    sSizeTest.numCapacity = 8;
    sSizeTest.numElements = 5;
    sSizeTest.buffer = new int[stackToCopy.numCapacity];
    for (int i = 0; i < stackToCopy.numElements; i++) {
        sSizeTest.buffer[i]=i*i+1;
    }
    
	assert(sSizeTest.size() == 5);
    
    sSizeTest.numElements = 0;
    assert(sSizeTest.size() == 0);
    cout << "Size Tests Passed" << endl;
    /*
     * Testing Capacity
     */
    assert(sSizeTest.capacity() == 8);
    sSizeTest.numCapacity = 0;
    assert(sSizeTest.capacity() == 0);
    
    cout << "Capacity Tests Passed" << endl;
    /*
     * Resetting stack
     */
    
    sSizeTest.numCapacity = 8;
    sSizeTest.numElements = 5;
    sSizeTest.buffer = new int[stackToCopy.numCapacity];
    for (int i = 0; i < stackToCopy.numElements; i++) {
        sSizeTest.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
	sSizeTest.clear();
    assert(sSizeTest.numElements == 0);
    assert(sSizeTest.numCapacity == 8);
    
    cout << "Clear Test Passed" << endl;
    /*
     * Testing Empty
     */
    sSizeTest.numCapacity = 8;
    sSizeTest.numElements = 5;
    sSizeTest.buffer = new int[stackToCopy.numCapacity];
    for (int i = 0; i < stackToCopy.numElements; i++) {
        sSizeTest.buffer[i]=i*i+1;
    }
	assert(!sSizeTest.empty());
    
    sSizeTest.numElements = 0;
    
    assert(sSizeTest.empty());

	cout << "Empty Tests Passed" << endl;

    /*
     * Testing Push for Non-Integer Stack Behavior
     */
	stack <string> sString;

	sString.push("Hello");
	sString.push("It's me");
    sString.push("I was wondering");
    assert(sString.numCapacity == 4);
    assert(sString.numElements == 3);
	assert(sString.buffer[0] == "Hello");
	assert(sString.buffer[1] == "It's me");
	assert(sString.buffer[2] == "I was wondering");

	cout << "This stack can hold a string!!!!" << endl;

	return 0;
}
