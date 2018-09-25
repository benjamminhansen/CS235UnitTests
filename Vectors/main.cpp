/*
 * main.cpp
 *
 *  Created by Lee Barney on 09/15/18.
 *  Copyright (c) 2018 Lee Barney
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 
 *  The above copyright notice and this permission notice shall be
 *  included in all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 */

/* !!!!GRADING INSTRUCTIONS!!!!
 *
 * When you report your score for this test set, report
 * the percentage of asserts found in this test code that
 * your data structure code passed.
 */
#define UNIT_TESTING

#include <iostream>
#include <cstring>
#include <cassert>
#include "vector.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;



int main(int argc, const char* argv[]) {
    
    /*
     * Testing default constructor
     */
    vector <int> defaultVector;
    assert(defaultVector.numCapacity == 0);
    assert(defaultVector.numElements == 0);
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
    assert(sizedVector.numCapacity == 4);
    assert(sizedVector.numElements == 4);
    assert(sizedVector.buffer != NULL);
    assert(sizedVector.buffer[0] == 0);
    assert(sizedVector.buffer[1] == 0);
    assert(sizedVector.buffer[2] == 0);
    assert(sizedVector.buffer[3] == 0);
    cout << "Sized Constructor Test Passed" << endl;
    
    /*
     * Testing Size
     */
    vector <int> sizeTestVector;
    
    sizeTestVector.numCapacity = 8;
    sizeTestVector.numElements = 4;
    assert(sizeTestVector.size() == 4);
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
    sizeTestVector.numElements = 0;
    sizeTestVector.buffer = new int[sizeTestVector.numCapacity];
    for (int i = 0; i < sizeTestVector.numCapacity; i++) {
        sizeTestVector.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    sizeTestVector.clear();
    assert(sizeTestVector.numCapacity == 8);
    assert(sizeTestVector.numElements == 0);
    assert(sizeTestVector.buffer != NULL);
    cout << "Clear Test Passed" << endl;
    
    /*
     * Testing Empty
     */
    sizeTestVector.numElements = 3;
    assert(!sizeTestVector.empty());
    
    sizeTestVector.numElements = 0;
    
    assert(sizeTestVector.empty());
    cout << "Empty Tests Passed" << endl;
    
    /*
     * Testing resize
     */
    vector<int> emptyResizeVector;
    emptyResizeVector.resize(-1);
    assert(emptyResizeVector.numCapacity == 0);
    assert(emptyResizeVector.numElements == 0);
    assert(emptyResizeVector.buffer == NULL);
    cout<<"Passed negative resize test."<<endl;
    
    emptyResizeVector.resize(7);
    assert(emptyResizeVector.numCapacity == 7);
    assert(emptyResizeVector.numElements == 0);
    assert(emptyResizeVector.buffer != NULL);
    cout<<"Passed default vector resized test."<<endl;
    
    vector <int> resizeVector;
    resizeVector.buffer = new int[5];
    resizeVector.numCapacity = 5;
    resizeVector.numElements = 5;
    resizeVector.buffer[0] = 7;
    resizeVector.buffer[1] = 12;
    resizeVector.buffer[2] = 10;
    resizeVector.buffer[3] = 9;
    resizeVector.buffer[4] = 8;
    
    int *theBuffer = resizeVector.buffer;
    resizeVector.resize(10);
    assert(theBuffer != resizeVector.buffer);
    assert(resizeVector.numCapacity = 10);
    assert(resizeVector.numElements = 5);
    assert(resizeVector.buffer[0] == 7);
    assert(resizeVector.buffer[1] == 12);
    assert(resizeVector.buffer[2] == 10);
    assert(resizeVector.buffer[3] == 9);
    assert(resizeVector.buffer[4] == 8);
    
    theBuffer = resizeVector.buffer;
    resizeVector.resize(2);
    assert(theBuffer != resizeVector.buffer);
    assert(resizeVector.numCapacity == 2);
    assert(resizeVector.numElements == 2);
    assert(resizeVector.buffer[0] == 7);
    assert(resizeVector.buffer[1] == 12);
    
    theBuffer = resizeVector.buffer;
    resizeVector.resize(0);
    assert(resizeVector.numCapacity == 0);
    assert(resizeVector.numElements == 0);
    assert(resizeVector.buffer == NULL);
    cout << "Resize Test Passed" << endl;
    
    
    /*
     * Testing push_back with no resizing
     */
    vector <int> pushBackVector(5);
    int * tempBuffer = pushBackVector.buffer;
    pushBackVector.push_back(1);
    assert(tempBuffer != pushBackVector.buffer);
    assert(pushBackVector.numCapacity == 10);
    assert(pushBackVector.numElements == 6);
    assert(pushBackVector.buffer[0] == 0);
    assert(pushBackVector.buffer[1] == 0);
    assert(pushBackVector.buffer[2] == 0);
    assert(pushBackVector.buffer[3] == 0);
    assert(pushBackVector.buffer[4] == 0);
    assert(pushBackVector.buffer[5] == 1);
    cout << "Push_back First ElementTest Passed" << endl;
    
    pushBackVector.push_back(3);
    assert(pushBackVector.numCapacity == 10);
    assert(pushBackVector.numElements == 7);
    assert(pushBackVector.buffer[0] == 0);
    assert(pushBackVector.buffer[1] == 0);
    assert(pushBackVector.buffer[2] == 0);
    assert(pushBackVector.buffer[3] == 0);
    assert(pushBackVector.buffer[4] == 0);
    assert(pushBackVector.buffer[5] == 1);
    assert(pushBackVector.buffer[6] == 3);
    
    
    
    
    /*
     * Testing Accessor
     */
    vector <int> beginEndVector;
    beginEndVector.buffer = new int[6];
    beginEndVector.buffer[0] = -500;
    beginEndVector.buffer[1] = 0;
    beginEndVector.buffer[2] = 7;
    beginEndVector.buffer[3] = 13;
    beginEndVector.buffer[4] = 23;
    beginEndVector.numCapacity = 6;
    beginEndVector.numElements = 5;
    
    //test accessor
    assert(beginEndVector[0] == -500);
    //test mutator
    beginEndVector[0] = 35;
    assert(beginEndVector.buffer[0] == 35);
    
    try {
        beginEndVector[-1];
        assert(false);
    } catch (const char * message) {
        assert(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    
    try {
        beginEndVector[6];
        assert(false);
    } catch (const char * message) {
        assert(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    
    vector <int> emptyVector;
    try {
        emptyVector[0];
        assert(false);
    } catch (const char* message) {
        assert(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    cout << "Accessor tests passed"<<endl;
    
    
    
    /*
     * Testing = operator and copy constructor
     */
    vector <int> vectorToCopy;
    vectorToCopy.numCapacity = 8;
    vectorToCopy.numElements = 8;
    vectorToCopy.buffer = new int[vectorToCopy.numCapacity];
    for (int i = 0; i < vectorToCopy.numCapacity; i++) {
        vectorToCopy.buffer[i]=i*i+1;
    }
    vector <int> vectorAssignedCopy;
    vectorAssignedCopy = vectorToCopy;
    assert(vectorAssignedCopy.numCapacity == 8);
    assert(vectorAssignedCopy.numElements == 8);
    assert(vectorAssignedCopy.buffer != vectorToCopy.buffer);
    assert(vectorAssignedCopy.buffer[0] == 1);
    assert(vectorAssignedCopy.buffer[1] == 2);
    assert(vectorAssignedCopy.buffer[2] == 5);
    assert(vectorAssignedCopy.buffer[3] == 10);
    assert(vectorAssignedCopy.buffer[4] == 17);
    assert(vectorAssignedCopy.buffer[5] == 26);
    assert(vectorAssignedCopy.buffer[6] == 37);
    assert(vectorAssignedCopy.buffer[7] == 50);
    cout << "(full) = Operator Test Passed" << endl;
    
    vector <int> vectorCopy(vectorToCopy);
    assert(vectorCopy.numCapacity == 8);
    assert(vectorCopy.numElements == 8);
    assert(vectorCopy.buffer != vectorToCopy.buffer);
    assert(vectorCopy.numCapacity == 8);
    assert(vectorCopy.buffer[0] == 1);
    assert(vectorCopy.buffer[1] == 2);
    assert(vectorCopy.buffer[2] == 5);
    assert(vectorCopy.buffer[3] == 10);
    assert(vectorCopy.buffer[4] == 17);
    assert(vectorCopy.buffer[5] == 26);
    assert(vectorCopy.buffer[6] == 37);
    assert(vectorCopy.buffer[7] == 50);
    cout << "(Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Resetting to not full vector
     */
    
    vectorToCopy.numElements = 3;
    
    vector <int> notFullVectorAssignedCopy;
    notFullVectorAssignedCopy = vectorToCopy;
    assert(notFullVectorAssignedCopy.numCapacity == 3);
    assert(notFullVectorAssignedCopy.numElements == 3);
    assert(notFullVectorAssignedCopy.buffer != vectorToCopy.buffer);
    assert(notFullVectorAssignedCopy.buffer[0] == 1);
    assert(notFullVectorAssignedCopy.buffer[1] == 2);
    assert(notFullVectorAssignedCopy.buffer[2] == 5);
    cout << "(Not full) = Operator Test Passed" << endl;
    
    vector <int> notFullVectorCopy(vectorToCopy);
    assert(notFullVectorCopy.numCapacity == 3);
    assert(notFullVectorCopy.numElements == 3);
    assert(notFullVectorCopy.buffer != vectorToCopy.buffer);
    assert(notFullVectorCopy.buffer[0] == 1);
    assert(notFullVectorCopy.buffer[1] == 2);
    assert(notFullVectorCopy.buffer[2] == 5);
    cout << "(Not Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Testing Raw Iterators
     */
    vector<int>::iterator nullIt = vector<int>::iterator();
    assert(nullIt.ptr == NULL);
    int someInt = 3;
    int *someIntPtr = &someInt;
    vector<int>::iterator intPtr = vector<int>::iterator(&someInt);
    assert(intPtr.ptr == someIntPtr);
    
    cout<<"Passed Raw Iterator Test."<<endl;
    
    /*
     * Testing begin and end
     */
    vector<int>::iterator emptyVectorBeginIt = emptyVector.begin();
    assert(emptyVectorBeginIt.ptr == NULL);
    
    
    vector<int>::iterator emptyVectorEndIt = emptyVector.end();
    assert(emptyVectorEndIt.ptr == NULL);
    
    vector<int>::iterator notFullVectorBeginIt = notFullVectorCopy.begin();
    assert(notFullVectorCopy.buffer == notFullVectorBeginIt.ptr);
    
    
    vector<int>::iterator notFullVectorEndIt = notFullVectorCopy.end();
    assert(notFullVectorCopy.buffer+notFullVectorCopy.numElements == notFullVectorEndIt.ptr);
    cout<<"Passed iterator begin and end test."<<endl;
    
    /*
     * Testing Iterator Assignment Operator
     */
    vector<int>::iterator iteratorToAssign;
    iteratorToAssign.ptr = someIntPtr;
    vector<int>::iterator assignedToIterator;
    assignedToIterator = iteratorToAssign;
    assert(assignedToIterator.ptr == someIntPtr);
    cout<<"Passed iterator assignment test."<<endl;
    
    /*
     * Testing Iterator Comparison Operators
     */
    assert(iteratorToAssign == assignedToIterator);
    //reset
    int someOtherInt = 4;
    int* someOtherIntPtr = &someOtherInt;
    assignedToIterator.ptr = someOtherIntPtr;
    assert(iteratorToAssign != assignedToIterator);
    cout<<"Passed comparison operators test."<<endl;
    /*
     * Testing Dereference Operator
     */
    assert(*assignedToIterator == 4);
    cout<<"Passed dereference operator test."<<endl;
    /*
     * Testing iterator incrementor
     */
    assert((nullIt++).ptr == NULL);
    assert((++nullIt).ptr == NULL);
    
    //setting to the beginning of buffer
    vector<int>::iterator fakeBeginIt = vector<int>::iterator();
    fakeBeginIt.ptr = notFullVectorCopy.buffer;
    
    assert((fakeBeginIt++).ptr == notFullVectorCopy.buffer);
    //reset
    fakeBeginIt.ptr = notFullVectorCopy.buffer;
    assert((++fakeBeginIt).ptr == notFullVectorCopy.buffer+1);
    
    cout<<"Passed pre and post-increment ++ test."<<endl;
    
    //setting to the end of buffer
    vector<int>::iterator fakeEndIt = vector<int>::iterator();
    fakeEndIt.ptr = notFullVectorCopy.buffer+notFullVectorCopy.numElements;
    assert((fakeEndIt--).ptr == notFullVectorCopy.buffer+notFullVectorCopy.numElements);
    //reset
    fakeEndIt.ptr = notFullVectorCopy.buffer+notFullVectorCopy.numElements;
    assert((--fakeEndIt).ptr == notFullVectorCopy.buffer+notFullVectorCopy.numElements - 1);
    
    cout<<"Passed pre and post-increment -- test."<<endl;
    
    
    
    
    
    /*
     * Testing push_back for Non-Integer Vector Behavior (Just to Make Sure vector Works For Other Types)
     */
    vector <string> stringVector;
    
    stringVector.push_back("Hello");
    stringVector.push_back("It's me");
    stringVector.push_back("I was wondering");
    assert(stringVector.numCapacity == 4);
    assert(stringVector.buffer[0] == "Hello");
    assert(stringVector.buffer[1] == "It's me");
    assert(stringVector.buffer[2] == "I was wondering");
    
    cout << "This vector can hold strings!!!!" << endl;
    
    
    
    return 0;
}
