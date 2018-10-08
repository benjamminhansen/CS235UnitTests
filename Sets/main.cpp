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
     * Testing insert with no resizing
     */
    set <int> insertset(5);
    int * tempBuffer = insertset.buffer;
    insertset.insert(3);
    assert(tempBuffer != insertset.buffer);
    assert(insertset.numCapacity == 10);
    assert(insertset.numElements == 1);
    assert(insertset.buffer[0] == 3);
    cout << "Insert First ElementTest Passed" << endl;
    
    insertset.insert(3);
    assert(insertset.numCapacity == 10);
    assert(insertset.numElements == 2);
    assert(insertset.buffer[0] == 1);
    assert(insertset.buffer[1] == 3);
    
    
    insertset.insert(7);
    assert(insertset.numCapacity == 10);
    assert(insertset.numElements == 2);
    assert(insertset.buffer[0] == 1);
    assert(insertset.buffer[1] == 3);
    assert(insertset.buffer[2] == 7);
    
    
    insertset.insert(-5);
    assert(insertset.numCapacity == 10);
    assert(insertset.numElements == 4);
    assert(insertset.buffer[0] == -5);
    assert(insertset.buffer[1] == 1);
    assert(insertset.buffer[2] == 3);
    assert(insertset.buffer[3] == 7);
    
    cout<<"Passed insert no-resize Tests"<<endl;
    
    
    /*
     * Testing Find
     */
    set<int> findSet;
    //testing find with empty set
    findSet.numElements = 0;
    findSet.numCapacity = 0;
    findSet.buffer = NULL;
    assert(findSet.findIndex(35) == 0);
    
    //resetting
    findSet.numElements = 3;
    findSet.numCapacity = 4;
    findSet.buffer = new int[4];
    findSet.buffer[0] = 8;
    findSet.buffer[1] = 4;
    findSet.buffer[2] = 2;
    //buffer - [8,4,2]
    //Testing happy paths
    assert(findSet.findIndex(8) == 0);
    assert(findSet.findIndex(2) == 1);
    assert(findSet.findIndex(4) == 1);
    //Testing not found and boundary conditions
    assert(findSet.findIndex(27) == 3);
    assert(findSet.findIndex(0) == 3);
    assert(findSet.findIndex(-100) == 3);
    
    
    
    
    
    
    
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
    
    //reset
    int someOtherInt = 4;
    int* someOtherIntPtr = &someOtherInt;
    assignedToIterator.ptr = someOtherIntPtr;
    
    
    assert(iteratorToAssign == assignedToIterator);
    assert(!(assignedToIterator == iteratorToAssign));
    
    cout<<"Passed operator == test."<<endl;
    
    assert(iteratorToAssign != assignedToIterator);
    assert(!(assignedToIterator != assignedToIterator));
    cout<<"Passed operator != test."<<endl;
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
    
    set<int> incrementTesterSet;
    //setting to the beginning of buffer
    set<int>::iterator fakeBeginIt = set<int>::iterator();
    fakeBeginIt.ptr = incrementTesterSet.buffer;
    
    assert((fakeBeginIt++).ptr == incrementTesterSet.buffer);
    //reset
    fakeBeginIt.ptr = incrementTesterSet.buffer;
    assert((++fakeBeginIt).ptr == incrementTesterSet.buffer+1);
    
    cout<<"Passed pre and post-increment ++ test."<<endl;
    
    incrementTesterSet.buffer = new int[8];
    incrementTesterSet.numCapacity = 8;
    incrementTesterSet.numElements = 5;
    incrementTesterSet.buffer[0] = 6;
    incrementTesterSet.buffer[1] = 4;
    incrementTesterSet.buffer[2] = -3;
    incrementTesterSet.buffer[3] = 2;
    incrementTesterSet.buffer[4] = 0;
    //buffer: [6,4,-3,2,0]
    //setting to the end of buffer
    set<int>::iterator fakeEndIt = set<int>::iterator();
    fakeEndIt.ptr = incrementTesterSet.buffer+incrementTesterSet.numElements;
    assert((fakeEndIt--).ptr == incrementTesterSet.buffer+incrementTesterSet.numElements);
    //reset
    fakeEndIt.ptr = incrementTesterSet.buffer+incrementTesterSet.numElements;
    assert((--fakeEndIt).ptr == incrementTesterSet.buffer+incrementTesterSet.numElements - 1);
    cout<<"Passed pre and post-increment -- test."<<endl;
    
    
    /*
     * Testing Erase
     */
    set <int> eraseSet;
    eraseSet.buffer = new int[6];
    eraseSet.numCapacity = 6;
    eraseSet.numElements = 5;
    eraseSet.buffer[0] = -500;
    eraseSet.buffer[1] = 0;
    eraseSet.buffer[2] = 7;
    eraseSet.buffer[3] = 13;
    eraseSet.buffer[4] = 23;
    
    eraseSet.erase(nullIt);
    assert(eraseSet.numCapacity == 6);
    assert(eraseSet.numElements == 5);
    assert(eraseSet.buffer[0] == -500);
    assert(eraseSet.buffer[1] == 0);
    assert(eraseSet.buffer[2] == 7);
    assert(eraseSet.buffer[3] == 13);
    assert(eraseSet.buffer[4] == 23);
    
    
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
    
    set <int> resizeSet;
    resizeSet.buffer = new int[5];
    resizeSet.numCapacity = 5;
    resizeSet.numElements = 5;
    resizeSet.buffer[0] = 7;
    resizeSet.buffer[1] = 12;
    resizeSet.buffer[2] = 10;
    resizeSet.buffer[3] = 9;
    resizeSet.buffer[4] = 8;
    //buffer: [7,12,10,9,8]
    
    int *theBuffer = resizeSet.buffer;
    resizeSet.resize(10);
    //buffer: [7,12,10,9,8,_,_,_,_,_]
    assert(theBuffer != resizeSet.buffer);
    assert(resizeSet.numCapacity = 10);
    assert(resizeSet.numElements = 5);
    assert(resizeSet.buffer[0] == 7);
    assert(resizeSet.buffer[1] == 12);
    assert(resizeSet.buffer[2] == 10);
    assert(resizeSet.buffer[3] == 9);
    assert(resizeSet.buffer[4] == 8);
    
    theBuffer = resizeSet.buffer;
    resizeSet.resize(2);
    //buffer: [7,12,10,9,8,_,_,_,_,_]
    assert(theBuffer != resizeSet.buffer);
    assert(resizeSet.numCapacity == 2);
    assert(resizeSet.numElements == 2);
    assert(resizeSet.buffer[0] == 7);
    assert(resizeSet.buffer[1] == 12);
    
    theBuffer = resizeSet.buffer;
    resizeSet.resize(0);
    assert(resizeSet.numCapacity == 0);
    assert(resizeSet.numElements == 0);
    assert(resizeSet.buffer == NULL);
    cout << "Resize Test Passed" << endl;
    
    
    
    
    
    
    
    
    
    
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
    
    set <int> notFullSetCopy(setToCopy);
    assert(notFullSetCopy.numCapacity == 3);
    assert(notFullSetCopy.numElements == 3);
    assert(notFullSetCopy.buffer != setToCopy.buffer);
    assert(notFullSetCopy.buffer[0] == 1);
    assert(notFullSetCopy.buffer[1] == 2);
    assert(notFullSetCopy.buffer[2] == 5);
    cout << "(Not Full) Copy Constructor Test Passed" << endl;
    
    
    
    //silly comment
    
    
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
