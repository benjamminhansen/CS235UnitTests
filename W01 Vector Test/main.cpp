/*
 * main.cpp
 *
 *  Created on: Aug 20, 2018
 *      Author: Lee Barney
 */
#define UNIT_TESTING

#include <iostream>
#include <string>
#include <cassert>
#include "vector.hpp"

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
    vector <int> defaultVector;
    assert(defaultVector.numElements == 0);
    assert(defaultVector.numCapacity == 0);
    assert(defaultVector.buffer == NULL);
    cout << "Default Constructor Test Passed" << endl;
   
    /*
     * Testing sized vector constructor
     */
    try{
        vector<int> badSizeVector(-3);
        assert(false);
    }
    catch(const char* exceptionMessage){
        assert(strcmp(exceptionMessage,"Error: vector sizes must be greater than or equal to 0.") == 0);
    }
    vector <int> sizedVector(4);
    assert(sizedVector.numElements == 4);
    assert(sizedVector.numCapacity == 4);
    assert(sizedVector.buffer != NULL);
    cout << "Sized Constructor Test Passed" << endl;
    
    /*
     * Testing sized filled vector constructor
     */
    try{
        vector<int> badSizeVector(-3,0);
        assert(false);
    }
    catch(const char* exceptionMessage){
        assert(strcmp(exceptionMessage,"Error: vector sizes must be greater than or equal to 0.") == 0);
    }
    
    vector <int> sizedFilledVector(5,7);
    assert(sizedFilledVector.numElements == 5);
    assert(sizedFilledVector.numCapacity == 5);
    assert(sizedFilledVector.buffer[0] == 7);
    assert(sizedFilledVector.buffer[1] == 7);
    assert(sizedFilledVector.buffer[2] == 7);
    assert(sizedFilledVector.buffer[3] == 7);
    assert(sizedFilledVector.buffer[4] == 7);
    cout << "Sized Filled Constructor Test Passed" << endl;
    /*
     * Testing copy constructor
     */
    sizedFilledVector.numElements = 3;//as if something had been removed.
    vector <int> vectorCopy(sizedFilledVector);
    assert(vectorCopy.numElements == sizedFilledVector.numElements);
    assert(vectorCopy.numCapacity != sizedFilledVector.numCapacity);
    assert(vectorCopy.buffer != sizedVector.buffer);
    cout << "Copy Constructor Test Passed" << endl;
    /*
     * Testing resize
     */
    vector <int> resizeVector;
    resizeVector.buffer = new int[5];
    resizeVector.numElements = 5;
    resizeVector.numCapacity = 5;
    resizeVector.buffer[0] = 7;
    resizeVector.buffer[1] = 7;
    resizeVector.buffer[2] = 7;
    resizeVector.buffer[3] = 7;
    resizeVector.buffer[4] = 7;
    int *theBuffer = resizeVector.buffer;
    resizeVector.resize(10);
    assert(theBuffer != resizeVector.buffer);
    assert(resizeVector.numElements == 5);
    assert(resizeVector.numCapacity == 10);
    assert(resizeVector.buffer[0] == 7);
    assert(resizeVector.buffer[1] == 7);
    assert(resizeVector.buffer[2] == 7);
    assert(resizeVector.buffer[3] == 7);
    assert(resizeVector.buffer[4] == 7);
    
    resizeVector.resize(2);
    assert(theBuffer != resizeVector.buffer);
    assert(resizeVector.numElements == 2);
    assert(resizeVector.numCapacity == 2);
    assert(resizeVector.buffer[0] == 7);
    assert(resizeVector.buffer[1] == 7);
    
    
    resizeVector.resize(0);
    assert(theBuffer != resizeVector.buffer);
    assert(resizeVector.numElements == 0);
    assert(resizeVector.numCapacity == 0);
    assert(resizeVector.buffer == NULL);
    
    cout << "Resize Test Passed" << endl;
    /*
     * Testing push_back
     */
    vector <int> pushVector;
    pushVector.push_back(1);
    assert(pushVector.numCapacity == 1);
    assert(pushVector.numElements == 1);
    assert(pushVector.buffer[0] == 1);
    cout << "Push_back First ElementTest Passed" << endl;
    
    pushVector.push_back(5);
    assert(pushVector.numCapacity == 2);
    assert(pushVector.numElements == 2);
    assert(pushVector.buffer[0] == 1);
    assert(pushVector.buffer[1] == 5);
    cout << "Push_back Second ElementTest Passed" << endl;
    
    pushVector.push_back(10);
    assert(pushVector.numCapacity == 4);
    assert(pushVector.numElements == 3);
    assert(pushVector.buffer[0] == 1);
    assert(pushVector.buffer[1] == 5);
    assert(pushVector.buffer[2] == 10);
    cout << "Push_back Second ElementTest Passed" << endl;
    /*
     * Testing Access and Update
     */
    
    vector <int> accessVector;
    try{
        accessVector[-1];
        assert(false);
    }
    catch(const char* exceptionMessage){
        assert(strcmp(exceptionMessage,"Error: invalid index.") == 0);
    }
    cout << "Accessed Bad Index Test Passed" << endl;
    
    accessVector.numCapacity = 4;
    accessVector.numElements = 3;
    accessVector.buffer = new int[4];
    accessVector.buffer[0] = -2;
    accessVector.buffer[1] = 17;
    accessVector.buffer[2] = 0;
    
    assert(accessVector[0] == -2);
    assert(accessVector[1] == 17);
    assert(accessVector[2] == 0);
    
    try{
        accessVector[5];
        assert(false);
    }
    catch(const char* exceptionMessage){
        assert(strcmp(exceptionMessage,"Error: invalid index.") == 0);
    }
    cout << "Access Test Passed" << endl;
    
    accessVector[0] = 1;
    accessVector[1] = 2;
    accessVector[2] = 3;
    accessVector[3] = 4;
    try{
        accessVector[5] = 35;
        assert(false);
    }
    catch(const char* exceptionMessage){
        assert(strcmp(exceptionMessage,"Error: invalid index.") == 0);
    }
    cout << "Update Test Passed" << endl;
    
    /*
     * Testing = operator and copy constructor
     */
    vector <int> vectorToCopy;
    vectorToCopy.numCapacity = 8;
    vectorToCopy.numElements = 5;
    vectorToCopy.buffer = new int[vectorToCopy.numCapacity];
    for (int i = 0; i < vectorToCopy.numElements; i++) {
        vectorToCopy.buffer[i]=i*i+1;
    }
    
    vector <int> vectorCopiedTo = vectorToCopy;
    assert(vectorCopiedTo.numElements == vectorToCopy.numElements);
    assert(vectorCopiedTo.numCapacity == 5);
    assert(vectorCopiedTo.numElements == 5);
    assert(vectorCopiedTo.buffer[0] == 1);
    assert(vectorCopiedTo.buffer[1] == 2);
    assert(vectorCopiedTo.buffer[2] == 5);
    assert(vectorCopiedTo.buffer[3] == 10);
    assert(vectorCopiedTo.buffer[4] == 17);
    cout << "= Operator and Copy Constructor Test Passed" << endl;
    
    /*
     * Testing Size
     */
    vector <int> sizeTestVector;
    
    
    sizeTestVector.numCapacity = 8;
    sizeTestVector.numElements = 5;
    sizeTestVector.buffer = new int[sizeTestVector.numCapacity];
    for (int i = 0; i < sizeTestVector.numElements; i++) {
        sizeTestVector.buffer[i]=i*i+1;
    }
    
    assert(sizeTestVector.size() == 5);
    
    sizeTestVector.numElements = 0;
    assert(sizeTestVector.size() == 0);
    cout << "Size Tests Passed" << endl;
    /*
     * Testing Capacity
     */
    assert(sizeTestVector.capacity() == 8);
    sizeTestVector.numCapacity = 0;
    assert(sizeTestVector.capacity() == 0);
    cout << "Capacity Tests Passed" << endl;
    /*
     * Resetting for further use
     */
    sizeTestVector.numCapacity = 8;
    sizeTestVector.numElements = 5;
    sizeTestVector.buffer = new int[vectorToCopy.numCapacity];
    for (int i = 0; i < vectorToCopy.numElements; i++) {
        sizeTestVector.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    sizeTestVector.clear();
    assert(sizeTestVector.numElements == 0);
    assert(sizeTestVector.numCapacity == 8);
    cout << "Clear Test Passed" << endl;
    /*
     * Testing Empty
     */
    sizeTestVector.numCapacity = 8;
    sizeTestVector.numElements = 5;
    sizeTestVector.buffer = new int[sizeTestVector.numCapacity];
    for (int i = 0; i < sizeTestVector.numElements; i++) {
        sizeTestVector.buffer[i]=i*i+1;
    }
    assert(!sizeTestVector.empty());
    
    sizeTestVector.numElements = 0;
    
    assert(sizeTestVector.empty());
    cout << "Empty Tests Passed" << endl;
    /*
     * Iterator Tests
     */
    
    /*
     * Testing Iterator Default Constructor
     */
    vector<int>::iterator defaultIterator;
    assert(defaultIterator.valuePtr == NULL);
    cout << "Default Iterator Constructor Test Passed" << endl;
    
    /*
     * Testing Iterator Defined Value Constructor
     */
    int someInt = 9;
    vector<int>::iterator defindedIterator(&someInt);
    assert(defindedIterator.valuePtr == &someInt);
    cout << "Defined Iterator Constructor Test Passed" << endl;
    /*
     * Testing Iterator Copy Constructor
     */
    vector<int>::iterator anIteratorCopy = vector<int>::iterator(defindedIterator);
    assert(defindedIterator.valuePtr = anIteratorCopy.valuePtr);
    cout << "Iterator Copy Constructor Test Passed" << endl;
    
    
    vector <int> iteratorVector;
    iteratorVector.numCapacity = 8;
    iteratorVector.numElements = 5;
    iteratorVector.buffer = new int[iteratorVector.numCapacity];
    for (int i = 0; i < iteratorVector.numElements; i++) {
        iteratorVector.buffer[i]=i*i+1;
    }
    
    /*
     * Testing Begin Iterator Generation
     */
    vector<int>::iterator beginIterator = iteratorVector.begin();
    assert(beginIterator.valuePtr == iteratorVector.buffer);
    assert(*beginIterator.valuePtr == 1);
    cout << "Begin Iterator Generation Test Passed" << endl;
    /*
     * Testing End Iterator Generation
     */
    vector<int>::iterator endIterator = iteratorVector.end();
    assert(endIterator.valuePtr == iteratorVector.buffer+iteratorVector.numElements);
    cout << "End Iterator Generation Test Passed" << endl;
    /*
     * Testing ++ and -- Operators
     */
    assert(++beginIterator.valuePtr == iteratorVector.buffer + 1);
    assert(beginIterator++.valuePtr == iteratorVector.buffer + 1);
    assert(beginIterator.valuePtr == iteratorVector.buffer + 2);
    assert(beginIterator--.valuePtr == iteratorVector.buffer + 2);
    assert(beginIterator.valuePtr == iteratorVector.buffer + 1);
    assert(--beginIterator.valuePtr == iteratorVector.buffer);
    cout << "Iterator Increment and Decrement Operator Test Passed" << endl;
    
    /*
     * Testing Iterator = (Assignment) operator
     */
    //reset beginIterator for further use.
    beginIterator.valuePtr = iteratorVector.buffer;
    vector<int>::iterator anIterator = beginIterator;
    assert(anIterator.valuePtr == beginIterator.valuePtr);
    cout << "Iterator assignment Operator Test Passed" << endl;
    /*
     * Testing Iterator != Operator
     */
    int fiveValue = 5;
    int sevenValue = 7;
    vector<int>::iterator anotherVectorIterator;
    anIterator.valuePtr = &fiveValue;
    anotherVectorIterator.valuePtr = &sevenValue;
    assert(anotherVectorIterator != anIterator);
    assert(anotherVectorIterator.valuePtr != anIterator.valuePtr);
    cout << "Iterator Not Equal Operator Test Passed" << endl;
    /*
     * Testing Iterator == Operator
     */
    anIterator.valuePtr = &fiveValue;
    beginIterator.valuePtr = &fiveValue;
    assert(anIterator == beginIterator);
    cout << "Iterator Equal Operator Test Passed" << endl;
    /*
     * Reset anIterator for further use
     */
    anIterator.valuePtr = &fiveValue;
    assert(*anIterator == 5);
    cout<< "Iterator Dereference Operator Test Passed" << endl;
    
    /*
     * Testing Push for Non-Integer Stack Behavior (Just to Make Sure vector Works For Other Types)
     */
    vector <string> sString;
    
    sString.push_back("Hello");
    sString.push_back("It's me");
    sString.push_back("I was wondering");
    assert(sString.numCapacity == 4);
    assert(sString.numElements == 3);
    assert(sString.buffer[0] == "Hello");
    assert(sString.buffer[1] == "It's me");
    assert(sString.buffer[2] == "I was wondering");
    
    cout << "This vector can hold strings!!!!" << endl;
    
    return 0;
}
