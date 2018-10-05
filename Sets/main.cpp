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
#include "set.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

/*
 * While set can be implemented either sorted
 * or not sorted, for this class, you are
 * required to implement the sorted design.
 */

int main(int argc, const char* argv[])
{
    
    /*
     * Testing default constructor
     */
    set <int> defaultset;
    assert(defaultset.numCapacity == 0);
    assert(defaultset.numElements == 0);
    assert(defaultset.buffer == NULL);
    cout << "Default Constructor Test Passed" << endl;
    
    /*
     * Testing sized set constructor
     */
    try
    {
        set<int> badSizeset(-3);
        assert(false);
    }
    catch(const char* exceptionMessage)
    {
        assert(strcmp(exceptionMessage,"Error: set sizes must be greater than or equal to 0.") == 0);
    }
    
    set <int> sizedset(4);
    assert(sizedset.numCapacity == 4);
    assert(sizedset.numElements == 0);
    assert(sizedset.buffer != NULL);
    cout << "Sized Constructor Test Passed" << endl;
    
    /*
     * Testing Size
     */
    set <int> sizeTestset;
    
    sizeTestset.numCapacity = 8;
    sizeTestset.numElements = 4;
    assert(sizeTestset.size() == 4);
    cout << "Size Tests Passed" << endl;
    
    /*
     * Resetting for further use
     */
    sizeTestset.numCapacity = 8;
    sizeTestset.numElements = 0;
    sizeTestset.buffer = new int[sizeTestset.numCapacity];
    for (int i = 0; i < sizeTestset.numCapacity; i++)
    {
        sizeTestset.buffer[i]=i*i+1;
    }
    //buffer: [1,2,5,10,17,26,50,65]
    /*
     * Testing Clear
     */
    sizeTestset.clear();
    assert(sizeTestset.numCapacity == 8);
    assert(sizeTestset.numElements == 0);
    assert(sizeTestset.buffer != NULL);
    cout << "Clear Test Passed" << endl;
    
    /*
     * Testing Empty
     */
    sizeTestset.numElements = 3;
    assert(!sizeTestset.empty());
    
    sizeTestset.numElements = 0;
    
    assert(sizeTestset.empty());
    cout << "Empty Tests Passed" << endl;
    
    /*
     * Testing resize
     */
    set<int> emptyResizeset;
    emptyResizeset.resize(-1);
    assert(emptyResizeset.numCapacity == 0);
    assert(emptyResizeset.numElements == 0);
    assert(emptyResizeset.buffer == NULL);
    cout<<"Passed negative resize test."<<endl;
    
    emptyResizeset.resize(7);
    assert(emptyResizeset.numCapacity == 7);
    assert(emptyResizeset.numElements == 0);
    assert(emptyResizeset.buffer != NULL);
    cout<<"Passed default set resized test."<<endl;
    
    set <int> resizeset;
    resizeset.buffer = new int[5];
    resizeset.numCapacity = 5;
    resizeset.numElements = 5;
    resizeset.buffer[0] = 7;
    resizeset.buffer[1] = 12;
    resizeset.buffer[2] = 10;
    resizeset.buffer[3] = 9;
    resizeset.buffer[4] = 8;
    //buffer: [7,12,10,9,8]
    
    int *theBuffer = resizeset.buffer;
    resizeset.resize(10);
    //buffer: [7,12,10,9,8,_,_,_,_,_]
    assert(theBuffer != resizeset.buffer);
    assert(resizeset.numCapacity = 10);
    assert(resizeset.numElements = 5);
    assert(resizeset.buffer[0] == 7);
    assert(resizeset.buffer[1] == 12);
    assert(resizeset.buffer[2] == 10);
    assert(resizeset.buffer[3] == 9);
    assert(resizeset.buffer[4] == 8);
    
    theBuffer = resizeset.buffer;
    resizeset.resize(2);
    //buffer: [7,12,10,9,8,_,_,_,_,_]
    assert(theBuffer != resizeset.buffer);
    assert(resizeset.numCapacity == 2);
    assert(resizeset.numElements == 2);
    assert(resizeset.buffer[0] == 7);
    assert(resizeset.buffer[1] == 12);
    
    theBuffer = resizeset.buffer;
    resizeset.resize(0);
    assert(resizeset.numCapacity == 0);
    assert(resizeset.numElements == 0);
    assert(resizeset.buffer == NULL);
    cout << "Resize Test Passed" << endl;
    
    
    /*
     * Testing insert with no resizing
     */
    set <int> insertset(5);
    int * tempBuffer = insertset.buffer;
    insertset.insert(1);
    assert(tempBuffer != insertset.buffer);
    assert(insertset.numCapacity == 10);
    assert(insertset.numElements == 6);
    assert(insertset.buffer[0] == 0);
    assert(insertset.buffer[1] == 0);
    assert(insertset.buffer[2] == 0);
    assert(insertset.buffer[3] == 0);
    assert(insertset.buffer[4] == 0);
    assert(insertset.buffer[5] == 1);
    cout << "Push_back First ElementTest Passed" << endl;
    
    insertset.insert(3);
    assert(insertset.numCapacity == 10);
    assert(insertset.numElements == 7);
    assert(insertset.buffer[0] == 0);
    assert(insertset.buffer[1] == 0);
    assert(insertset.buffer[2] == 0);
    assert(insertset.buffer[3] == 0);
    assert(insertset.buffer[4] == 0);
    assert(insertset.buffer[5] == 1);
    assert(insertset.buffer[6] == 3);
    
    
    
    
    /*
     * Testing Accessor
     */
    set <int> beginEndset;
    beginEndset.buffer = new int[6];
    beginEndset.buffer[0] = -500;
    beginEndset.buffer[1] = 0;
    beginEndset.buffer[2] = 7;
    beginEndset.buffer[3] = 13;
    beginEndset.buffer[4] = 23;
    beginEndset.numCapacity = 6;
    beginEndset.numElements = 5;
    
    //test accessor
    assert(beginEndset[0] == -500);
    //test mutator
    beginEndset[0] = 35;
    assert(beginEndset.buffer[0] == 35);
    
    try {
        beginEndset[-1];
        assert(false);
    }
    catch (const char * message)
    {
        assert(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    
    try
    {
        beginEndset[6];
        assert(false);
    }
    catch (const char * message) {
        assert(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    
    set <int> emptyset;
    try
    {
        emptyset[0];
        assert(false);
    }
    catch (const char* message) {
        assert(strcmp(message, "Error: indices must be greater than zero and less than size().") == 0);
    }
    
    cout << "Accessor tests passed"<<endl;
    
    
    
    /*
     * Testing = operator and copy constructor
     */
    set <int> setToCopy;
    setToCopy.numCapacity = 8;
    setToCopy.numElements = 8;
    setToCopy.buffer = new int[setToCopy.numCapacity];
    for (int i = 0; i < setToCopy.numCapacity; i++)
    {
        setToCopy.buffer[i]=i*i+1;
    }
    set <int> setAssignedCopy;
    setAssignedCopy = setToCopy;
    assert(setAssignedCopy.numCapacity == 8);
    assert(setAssignedCopy.numElements == 8);
    assert(setAssignedCopy.buffer != setToCopy.buffer);
    assert(setAssignedCopy.buffer[0] == 1);
    assert(setAssignedCopy.buffer[1] == 2);
    assert(setAssignedCopy.buffer[2] == 5);
    assert(setAssignedCopy.buffer[3] == 10);
    assert(setAssignedCopy.buffer[4] == 17);
    assert(setAssignedCopy.buffer[5] == 26);
    assert(setAssignedCopy.buffer[6] == 37);
    assert(setAssignedCopy.buffer[7] == 50);
    cout << "(full) = Operator Test Passed" << endl;
    
    set <int> setCopy(setToCopy);
    assert(setCopy.numCapacity == 8);
    assert(setCopy.numElements == 8);
    assert(setCopy.buffer != setToCopy.buffer);
    assert(setCopy.numCapacity == 8);
    assert(setCopy.buffer[0] == 1);
    assert(setCopy.buffer[1] == 2);
    assert(setCopy.buffer[2] == 5);
    assert(setCopy.buffer[3] == 10);
    assert(setCopy.buffer[4] == 17);
    assert(setCopy.buffer[5] == 26);
    assert(setCopy.buffer[6] == 37);
    assert(setCopy.buffer[7] == 50);
    cout << "(Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Resetting to not full set
     */
    
    setToCopy.numElements = 3;
    
    set <int> notFullsetAssignedCopy;
    notFullsetAssignedCopy = setToCopy;
    assert(notFullsetAssignedCopy.numCapacity == 3);
    assert(notFullsetAssignedCopy.numElements == 3);
    assert(notFullsetAssignedCopy.buffer != setToCopy.buffer);
    assert(notFullsetAssignedCopy.buffer[0] == 1);
    assert(notFullsetAssignedCopy.buffer[1] == 2);
    assert(notFullsetAssignedCopy.buffer[2] == 5);
    cout << "(Not full) = Operator Test Passed" << endl;
    
    set <int> notFullsetCopy(setToCopy);
    assert(notFullsetCopy.numCapacity == 3);
    assert(notFullsetCopy.numElements == 3);
    assert(notFullsetCopy.buffer != setToCopy.buffer);
    assert(notFullsetCopy.buffer[0] == 1);
    assert(notFullsetCopy.buffer[1] == 2);
    assert(notFullsetCopy.buffer[2] == 5);
    cout << "(Not Full) Copy Constructor Test Passed" << endl;
    
    /*
     * Testing Raw Iterators
     */
    set<int>::iterator nullIt = set<int>::iterator();
    assert(nullIt.ptr == NULL);
    int someInt = 3;
    int *someIntPtr = &someInt;
    set<int>::iterator intPtr = set<int>::iterator(&someInt);
    assert(intPtr.ptr == someIntPtr);
    
    cout<<"Passed Raw Iterator Test."<<endl;
    
    /*
     * Testing begin and end
     */
    set<int>::iterator emptysetBeginIt = emptyset.begin();
    assert(emptysetBeginIt.ptr == NULL);
    
    
    set<int>::iterator emptysetEndIt = emptyset.end();
    assert(emptysetEndIt.ptr == NULL);
    
    set<int>::iterator notFullsetBeginIt = notFullsetCopy.begin();
    assert(notFullsetCopy.buffer == notFullsetBeginIt.ptr);
    
    
    set<int>::iterator notFullsetEndIt = notFullsetCopy.end();
    assert(notFullsetCopy.buffer+notFullsetCopy.numElements == notFullsetEndIt.ptr);
    cout<<"Passed iterator begin and end test."<<endl;
    
    /*
     * Testing Iterator Assignment Operator
     */
    set<int>::iterator iteratorToAssign;
    iteratorToAssign.ptr = someIntPtr;
    set<int>::iterator assignedToIterator;
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
    set<int>::iterator fakeBeginIt = set<int>::iterator();
    fakeBeginIt.ptr = notFullsetCopy.buffer;
    
    assert((fakeBeginIt++).ptr == notFullsetCopy.buffer);
    //reset
    fakeBeginIt.ptr = notFullsetCopy.buffer;
    assert((++fakeBeginIt).ptr == notFullsetCopy.buffer+1);
    
    cout<<"Passed pre and post-increment ++ test."<<endl;
    
    //setting to the end of buffer
    set<int>::iterator fakeEndIt = set<int>::iterator();
    fakeEndIt.ptr = notFullsetCopy.buffer+notFullsetCopy.numElements;
    assert((fakeEndIt--).ptr == notFullsetCopy.buffer+notFullsetCopy.numElements);
    //reset
    fakeEndIt.ptr = notFullsetCopy.buffer+notFullsetCopy.numElements;
    assert((--fakeEndIt).ptr == notFullsetCopy.buffer+notFullsetCopy.numElements - 1);
    
    cout<<"Passed pre and post-increment -- test."<<endl;
    
    
    
    
    
    /*
     * Testing insert for Non-Integer set Behavior (Just to Make Sure set Works For Other Types)
     */
    set <string> stringset;
    
    stringset.insert("Hello");
    stringset.insert("It's me");
    stringset.insert("I was wondering");
    assert(stringset.numCapacity == 4);
    assert(stringset.buffer[0] == "Hello");
    assert(stringset.buffer[1] == "It's me");
    assert(stringset.buffer[2] == "I was wondering");
    
    cout << "This set can hold strings!!!!" << endl;
    
    
    
    return 0;
}
