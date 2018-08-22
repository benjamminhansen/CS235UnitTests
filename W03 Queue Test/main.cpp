/*
 * main.cpp
 *
 *  Created by Lee Barney on 8/22/18.
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



int main(int argc, const char* argv[]) {
    /*
     * Testing default constructor
     */
    queue <int> defaultQueue;
    assert(defaultQueue.numPush == 0);
    assert(defaultQueue.numPop == 0);
    assert(defaultQueue.numCapacity == 0);
    assert(defaultQueue.buffer == NULL);
    cout << "Default Constructor Test Passed" << endl;
    
    /*
     * Testing sized queue constructor
     */
    try{
        queue<int> badSizeQueue(-3);
        assert(false);
    }
    catch(const char* exceptionMessage){
        assert(strcmp(exceptionMessage,"Error: queue sizes must be greater than or equal to 0.") == 0);
    }
    queue <int> sizedQueue(4);
    assert(sizedQueue.numPush == 0);
    assert(defaultQueue.numPop == 0);
    assert(sizedQueue.numCapacity == 4);
    assert(sizedQueue.buffer != NULL);
    cout << "Sized Constructor Test Passed" << endl;
    sizedQueue.buffer[0] = 1;
    sizedQueue.buffer[1] = 5;
    sizedQueue.buffer[2] = 10;
    sizedQueue.buffer[3] = 15;
    /*
     * Testing copy constructor
     */
    sizedQueue.numCapacity = 4;
    sizedQueue.numPop = 1;
    sizedQueue.numPush = 4;//as if something had been popped.
    queue <int> queueCopy(sizedQueue);
    assert(queueCopy.numPop == 0);
    assert(queueCopy.numPush == 3);
    assert(queueCopy.numCapacity == 3);
    assert(queueCopy.buffer != sizedQueue.buffer);
    sizedQueue.buffer[0] = 5;
    sizedQueue.buffer[1] = 10;
    sizedQueue.buffer[2] = 15;
    cout << "Copy Constructor Test Passed" << endl;
    /*
     * Testing resize
     */
    queue <int> resizeQueue;
    resizeQueue.buffer = new int[5];
    resizeQueue.numPop = 0;
    resizeQueue.numPush = 5;
    resizeQueue.numCapacity = 5;
    resizeQueue.buffer[0] = 7;
    resizeQueue.buffer[1] = 7;
    resizeQueue.buffer[2] = 7;
    resizeQueue.buffer[3] = 7;
    resizeQueue.buffer[4] = 7;
    int *theBuffer = resizeQueue.buffer;
    resizeQueue.resize(10);
    assert(theBuffer != resizeQueue.buffer);
    assert(resizeQueue.numPush == 5);
    assert(resizeQueue.numPop == 0);
    assert(resizeQueue.numCapacity == 10);
    assert(resizeQueue.buffer[0] == 7);
    assert(resizeQueue.buffer[1] == 7);
    assert(resizeQueue.buffer[2] == 7);
    assert(resizeQueue.buffer[3] == 7);
    assert(resizeQueue.buffer[4] == 7);
    
    resizeQueue.resize(2);
    assert(theBuffer != resizeQueue.buffer);
    assert(resizeQueue.numPush == 2);
    assert(resizeQueue.numPop == 0);
    assert(resizeQueue.numCapacity == 2);
    assert(resizeQueue.buffer[0] == 7);
    assert(resizeQueue.buffer[1] == 7);
    
    
    resizeQueue.resize(0);
    assert(theBuffer != resizeQueue.buffer);
    assert(resizeQueue.numPop == 0);
    assert(resizeQueue.numPush == 0);
    assert(resizeQueue.numCapacity == 0);
    assert(resizeQueue.buffer == NULL);
    
    cout << "Resize Test Passed" << endl;
    /*
     * Testing push
     */
    queue <int> pushQueue;
    pushQueue.push(1);
    assert(pushQueue.numCapacity == 1);
    assert(pushQueue.numPush == 1);
    assert(resizeQueue.numPop == 0);
    assert(pushQueue.buffer[0] == 1);
    cout << "Push_back First ElementTest Passed" << endl;
    
    pushQueue.push(5);
    assert(pushQueue.numCapacity == 2);
    assert(pushQueue.numPush == 2);
    assert(resizeQueue.numPop == 0);
    assert(pushQueue.buffer[0] == 1);
    assert(pushQueue.buffer[1] == 5);
    cout << "Push_back Second Element Test Passed" << endl;
    
    pushQueue.push(10);
    assert(pushQueue.numCapacity == 4);
    assert(pushQueue.numPush == 3);
    assert(resizeQueue.numPop == 0);
    assert(pushQueue.buffer[0] == 1);
    assert(pushQueue.buffer[1] == 5);
    assert(pushQueue.buffer[2] == 10);
    cout << "Push Third Element Test Passed" << endl;
    /*
     * Testing Pop
     */
    
    queue <int> popQueue;
    popQueue.buffer = new int[6];
    popQueue.buffer[0] = -500;
    popQueue.buffer[1] = 0;
    popQueue.buffer[2] = -100;
    popQueue.buffer[3] = 300;
    popQueue.buffer[4] = 10;
    popQueue.buffer[5] = 0;
    popQueue.numPush = 6;
    popQueue.numPop = 0;
    popQueue.numCapacity = 6;
    
    popQueue.pop();
    assert(popQueue.numPop == 1);
    assert(popQueue.numPush == 6);
    assert(popQueue.numCapacity = 6);
    assert(popQueue.buffer[0] == -500);
    assert(popQueue.buffer[1] == 0);
    assert(popQueue.buffer[2] == -100);
    assert(popQueue.buffer[3] == 300);
    assert(popQueue.buffer[4]== 10);
    assert(popQueue.buffer[5]== 0);
    
    
    popQueue.pop();
    assert(popQueue.numPop == 2);
    assert(popQueue.numPush == 6);
    assert(popQueue.numCapacity = 6);
    assert(popQueue.buffer[0] == -500);
    assert(popQueue.buffer[1] == 0);
    assert(popQueue.buffer[2] == -100);
    assert(popQueue.buffer[3] == 300);
    assert(popQueue.buffer[4]== 10);
    assert(popQueue.buffer[5]== 0);
    
    
    popQueue.pop();
    assert(popQueue.numPop == 3);
    assert(popQueue.numPush == 6);
    assert(popQueue.numCapacity = 6);
    assert(popQueue.buffer[0] == -500);
    assert(popQueue.buffer[1] == 0);
    assert(popQueue.buffer[2] == -100);
    assert(popQueue.buffer[3] == 300);
    assert(popQueue.buffer[4]== 10);
    assert(popQueue.buffer[5]== 0);
    
    
    popQueue.pop();
    assert(popQueue.numPop == 4);
    assert(popQueue.numPush == 6);
    assert(popQueue.numCapacity = 6);
    assert(popQueue.buffer[0] == -500);
    assert(popQueue.buffer[1] == 0);
    assert(popQueue.buffer[2] == -100);
    assert(popQueue.buffer[3] == 300);
    assert(popQueue.buffer[4]== 10);
    assert(popQueue.buffer[5]== 0);
    
    
    popQueue.pop();
    assert(popQueue.numPop == 5);
    assert(popQueue.numPush == 6);
    assert(popQueue.numCapacity = 6);
    assert(popQueue.buffer[0] == -500);
    assert(popQueue.buffer[1] == 0);
    assert(popQueue.buffer[2] == -100);
    assert(popQueue.buffer[3] == 300);
    assert(popQueue.buffer[4]== 10);
    assert(popQueue.buffer[5]== 0);
    
    popQueue.pop();
    assert(popQueue.numPop == 6);
    assert(popQueue.numPush == 6);
    assert(popQueue.numCapacity = 6);
    assert(popQueue.buffer[0] == -500);
    assert(popQueue.buffer[1] == 0);
    assert(popQueue.buffer[2] == -100);
    assert(popQueue.buffer[3] == 300);
    assert(popQueue.buffer[4]== 10);
    assert(popQueue.buffer[5]== 0);
    
    //testing popping an empty queue
    popQueue.pop();
    assert(popQueue.numPop == 6);
    assert(popQueue.numPush == 6);
    assert(popQueue.numCapacity = 6);
    assert(popQueue.buffer[0] == -500);
    assert(popQueue.buffer[1] == 0);
    assert(popQueue.buffer[2] == -100);
    assert(popQueue.buffer[3] == 300);
    assert(popQueue.buffer[4]== 10);
    assert(popQueue.buffer[5]== 0);
    
    cout << "Pop tests passed"<<endl;
    
    /*
     * Testing iHead
     */
    queue <int> headQueue;
    headQueue.numCapacity = 8;
    headQueue.numPop = 3;
    assert(headQueue.iHead() == 3);
    
    headQueue.numPop = 6;
    assert(headQueue.iHead() == 6);
    
    headQueue.numPop = 8;
    assert(headQueue.iHead() == 0);
    
    headQueue.numPop = 10;
    assert(headQueue.iHead() == 2);
    
    /*
     * Testing iTail
     */
    queue <int> tailQueue;
    tailQueue.numCapacity = 8;
    tailQueue.numPush = 3;
    assert(tailQueue.iTail() == 2);
    
    tailQueue.numPush = 6;
    assert(tailQueue.iTail() == 5);
    
    tailQueue.numPush = 8;
    assert(tailQueue.iTail() == 7);
    
    tailQueue.numPush = 9;
    assert(tailQueue.iTail() == 0);
    
    tailQueue.numPush = 10;
    assert(tailQueue.iTail() == 1);
    
    /*
     * Testing Front
     */
    queue <int> frontBackQueue;
    frontBackQueue.buffer = new int[6];
    frontBackQueue.buffer[0] = -500;
    frontBackQueue.buffer[1] = 0;
    frontBackQueue.buffer[2] = 7;
    frontBackQueue.buffer[3] = 13;
    frontBackQueue.buffer[4] = 23;
    frontBackQueue.buffer[5] = -1;
    frontBackQueue.numCapacity = 6;
    frontBackQueue.numPush = 6;
    frontBackQueue.numPop = 0;
    //test accessor
    assert(frontBackQueue.front() == -500);
    //test mutator
    frontBackQueue.front() = 35;
    assert(frontBackQueue.buffer[0] == 35);
    
    //test behavior for multiple simulated pops
    frontBackQueue.numPop = 2;
    assert(frontBackQueue.front() == 7);
    
    frontBackQueue.numPop = 5;
    assert(frontBackQueue.front() == -1);
    
    frontBackQueue.numPop = 7;
    assert(frontBackQueue.front() == 0);
    
    
    queue <int> emptyQueue;
    try {
        emptyQueue.front();
        assert(false);
    } catch (const char* message) {
        assert(strcmp(message, "Error: queue is empty.") == 0);
    }
    
    cout << "Front tests passed"<<endl;
    
    /*
     * Testing Back
     */
    //numCapacity is 6
    frontBackQueue.numPush = 1;
    //test accessor
    assert(frontBackQueue.back() == 35);
    //test mutator
    frontBackQueue.back() = 45;
    assert(frontBackQueue.buffer[0] == 45);
    
    //test behavior for multiple simulated pops
    frontBackQueue.numPush = 2;
    assert(frontBackQueue.back() == 0);
    
    frontBackQueue.numPush = 5;
    assert(frontBackQueue.back() == 23);
    
    frontBackQueue.numPush = 6;
    assert(frontBackQueue.back() == -1);
    
    frontBackQueue.numPush = 8;
    assert(frontBackQueue.back() == 0);
    
    
    try {
        emptyQueue.back();
        assert(false);
    } catch (const char* message) {
        assert(strcmp(message, "Error: queue is empty.") == 0);
    }
    
    cout << "Back tests passed"<<endl;
    
    
    /*
     * Testing = operator and copy constructor
     */
    queue <int> queueToCopy;
    queueToCopy.numCapacity = 8;
    queueToCopy.buffer = new int[queueToCopy.numCapacity];
    for (int i = 0; i < queueToCopy.numCapacity; i++) {
        queueToCopy.buffer[i]=i*i+1;
    }
    queueToCopy.numPush = 21;
    queueToCopy.numPop = 16;
    
    queue <int> queueCopiedTo = queueToCopy;
    assert(queueCopiedTo.numPop == 0);
    assert(queueCopiedTo.numPush == 5);
    assert(queueCopiedTo.numCapacity == 5);
    assert(queueCopiedTo.buffer[0] == 1);
    assert(queueCopiedTo.buffer[1] == 2);
    assert(queueCopiedTo.buffer[2] == 5);
    assert(queueCopiedTo.buffer[3] == 10);
    assert(queueCopiedTo.buffer[4] == 17);
    cout << "= Operator and Copy Constructor Test Passed" << endl;
    
    /*
     * Testing Size
     */
    queue <int> sizeTestQueue;
    
    sizeTestQueue.numCapacity = 8;
    sizeTestQueue.numPush = 37;
    sizeTestQueue.numPop = 30;
    assert(sizeTestQueue.size() == 7);
    sizeTestQueue.numPush = 37;
    sizeTestQueue.numPop = 37;
    assert(sizeTestQueue.size() == 0);
    
    cout << "Size Tests Passed" << endl;
    /*
     * Testing Capacity
     */
    assert(sizeTestQueue.capacity() == 8);
    sizeTestQueue.numCapacity = 0;
    assert(sizeTestQueue.capacity() == 0);
    cout << "Capacity Tests Passed" << endl;
    /*
     * Resetting for further use
     */
    sizeTestQueue.numCapacity = 8;
    sizeTestQueue.numPop = 5;
    sizeTestQueue.numPush = 7;
    sizeTestQueue.buffer = new int[queueToCopy.numCapacity];
    for (int i = 0; i < sizeTestQueue.numCapacity; i++) {
        sizeTestQueue.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    sizeTestQueue.clear();
    assert(sizeTestQueue.numPush == 0);
    assert(sizeTestQueue.numPop == 0);
    assert(sizeTestQueue.numCapacity == 8);
    cout << "Clear Test Passed" << endl;
    /*
     * Testing Empty
     */
    sizeTestQueue.numCapacity = 8;
    sizeTestQueue.numPop = 5;
    sizeTestQueue.numPush = 10;

    assert(!sizeTestQueue.empty());
    
    sizeTestQueue.numPop = 7;
    sizeTestQueue.numPush = 7;
    
    assert(sizeTestQueue.empty());
    cout << "Empty Tests Passed" << endl;
    
    /*
     * Testing Push for Non-Integer Queue Behavior (Just to Make Sure queue Works For Other Types)
     */
    queue <string> sString;
    
    sString.push("Hello");
    sString.push("It's me");
    sString.push("I was wondering");
    assert(sString.numCapacity == 4);
    assert(sString.numPush == 3);
    assert(sString.numPop == 0);
    assert(sString.buffer[0] == "Hello");
    assert(sString.buffer[1] == "It's me");
    assert(sString.buffer[2] == "I was wondering");
    
    cout << "This queue can hold strings!!!!" << endl;
    
    /*
     * For 5 percentage points extra credit you can implement
     * the const_iterator inner class and the const cbegin and
     * cend methods along with the tests for all the operators
     * for the const_iterator and cbegin and cend queue methods.
     */
    
    
    
    return 0;
}
