/*
 * main.cpp
 *
 *  Created by Lee Barney on 8/21/18.
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
#include "stack.h"

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
    stack <int> defaultStack;
    assert(defaultStack.numElements == 0);
    assert(defaultStack.numCapacity == 0);
    assert(defaultStack.buffer == NULL);
    cout << "Default Constructor Test Passed" << endl;
    
    /*
     * Testing sized stack constructor
     */
    try{
        stack<int> badSizeStack(-3);
        assert(false);
    }
    catch(const char* exceptionMessage){
        assert(strcmp(exceptionMessage,"Error: stack sizes must be greater than or equal to 0.") == 0);
    }
    stack <int> sizedStack(4);
    assert(sizedStack.numElements == 0);
    assert(sizedStack.numCapacity == 4);
    assert(sizedStack.buffer != NULL);
    cout << "Sized Constructor Test Passed" << endl;
    sizedStack.buffer[0] = 1;
    sizedStack.buffer[1] = 5;
    sizedStack.buffer[2] = 10;
    sizedStack.buffer[3] = 15;
    /*
     * Testing copy constructor
     */
    sizedStack.numElements = 3;//as if something had been popped.
    stack <int> stackCopy(sizedStack);
    assert(stackCopy.numElements == sizedStack.numElements);
    assert(stackCopy.numCapacity != sizedStack.numCapacity);
    assert(stackCopy.buffer != sizedStack.buffer);
    cout << "Copy Constructor Test Passed" << endl;
    /*
     * Testing resize
     */
    stack <int> resizeStack;
    resizeStack.buffer = new int[5];
    resizeStack.numElements = 5;
    resizeStack.numCapacity = 5;
    resizeStack.buffer[0] = 7;
    resizeStack.buffer[1] = 7;
    resizeStack.buffer[2] = 7;
    resizeStack.buffer[3] = 7;
    resizeStack.buffer[4] = 7;
    int *theBuffer = resizeStack.buffer;
    resizeStack.resize(10);
    assert(theBuffer != resizeStack.buffer);
    assert(resizeStack.numElements == 5);
    assert(resizeStack.numCapacity == 10);
    assert(resizeStack.buffer[0] == 7);
    assert(resizeStack.buffer[1] == 7);
    assert(resizeStack.buffer[2] == 7);
    assert(resizeStack.buffer[3] == 7);
    assert(resizeStack.buffer[4] == 7);
    
    resizeStack.resize(2);
    assert(theBuffer != resizeStack.buffer);
    assert(resizeStack.numElements == 2);
    assert(resizeStack.numCapacity == 2);
    assert(resizeStack.buffer[0] == 7);
    assert(resizeStack.buffer[1] == 7);
    
    
    resizeStack.resize(0);
    assert(theBuffer != resizeStack.buffer);
    assert(resizeStack.numElements == 0);
    assert(resizeStack.numCapacity == 0);
    assert(resizeStack.buffer == NULL);
    
    cout << "Resize Test Passed" << endl;
    /*
     * Testing push
     */
    stack <int> pushStack;
    pushStack.push(1);
    assert(pushStack.numCapacity == 1);
    assert(pushStack.numElements == 1);
    assert(pushStack.buffer[0] == 1);
    cout << "Push_back First ElementTest Passed" << endl;
    
    pushStack.push(5);
    assert(pushStack.numCapacity == 2);
    assert(pushStack.numElements == 2);
    assert(pushStack.buffer[0] == 1);
    assert(pushStack.buffer[1] == 5);
    cout << "Push_back Second ElementTest Passed" << endl;
    
    pushStack.push(10);
    assert(pushStack.numCapacity == 4);
    assert(pushStack.numElements == 3);
    assert(pushStack.buffer[0] == 1);
    assert(pushStack.buffer[1] == 5);
    assert(pushStack.buffer[2] == 10);
    cout << "Push Second ElementTest Passed" << endl;
    /*
     * Testing Pop
     */
    
    stack <int> popStack;
    popStack.buffer = new int[6];
    popStack.buffer[0] = -500;
    popStack.buffer[1] = 0;
    popStack.buffer[2] = -100;
    popStack.buffer[3] = 300;
    popStack.buffer[4] = 10;
    popStack.buffer[5] = 0;
    popStack.numElements = 6;
    popStack.numCapacity = 6;
    
    popStack.pop();
    assert(popStack.numElements == 5);
    assert(popStack.numCapacity = 6);
    assert(popStack.buffer[0] == -500);
    assert(popStack.buffer[1] == 0);
    assert(popStack.buffer[2] == -100);
    assert(popStack.buffer[3] == 300);
    assert(popStack.buffer[4]== 10);
    
    
    popStack.pop();
    assert(popStack.numElements == 4);
    assert(popStack.numCapacity = 6);
    assert(popStack.buffer[0] == -500);
    assert(popStack.buffer[1] == 0);
    assert(popStack.buffer[2] == -100);
    assert(popStack.buffer[3] == 300);
    
    
    popStack.pop();
    assert(popStack.numElements == 3);
    assert(popStack.numCapacity = 6);
    assert(popStack.buffer[0] == -500);
    assert(popStack.buffer[1] == 0);
    assert(popStack.buffer[2] == -100);
    
    
    popStack.pop();
    assert(popStack.numElements == 2);
    assert(popStack.numCapacity = 6);
    assert(popStack.buffer[0] == -500);
    assert(popStack.buffer[1] == 0);
    
    
    popStack.pop();
    assert(popStack.numElements == 1);
    assert(popStack.numCapacity = 6);
    assert(popStack.buffer[0] == -500);
    
    popStack.pop();
    assert(popStack.numElements == 0);
    assert(popStack.numCapacity = 6);
    
    //testing popping an empty stack
    popStack.pop();
    assert(popStack.numElements == 0);
    assert(popStack.numCapacity = 6);
    
    cout << "Pop tests passed"<<endl;
    
    /*
     * Testing Top
     */
    
    stack <int> topStack;
    topStack.buffer = new int[6];
    topStack.buffer[0] = -500;
    topStack.buffer[1] = 0;
    topStack.numCapacity = 2;
    topStack.numElements = 2;
    //test accessor
    assert(topStack.top() == 0);
    //test mutator
    topStack.top() = 35;
    assert(topStack.buffer[1] == 35);
    
    stack <int> emptyStack;
    try {
        emptyStack.top();
        assert(false);
    } catch (const char* message) {
        assert(strcmp(message, "Error: stack is empty.") == 0);
    }
    
    cout << "Top tests passed"<<endl;
    
    
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
    
    stack <int> stackCopiedTo = stackToCopy;
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
    stack <int> sizeTestStack;
    
    
    sizeTestStack.numCapacity = 8;
    sizeTestStack.numElements = 5;
    sizeTestStack.buffer = new int[sizeTestStack.numCapacity];
    for (int i = 0; i < sizeTestStack.numElements; i++) {
        sizeTestStack.buffer[i]=i*i+1;
    }
    
    assert(sizeTestStack.size() == 5);
    
    sizeTestStack.numElements = 0;
    assert(sizeTestStack.size() == 0);
    cout << "Size Tests Passed" << endl;
    /*
     * Testing Capacity
     */
    assert(sizeTestStack.capacity() == 8);
    sizeTestStack.numCapacity = 0;
    assert(sizeTestStack.capacity() == 0);
    cout << "Capacity Tests Passed" << endl;
    /*
     * Resetting for further use
     */
    sizeTestStack.numCapacity = 8;
    sizeTestStack.numElements = 5;
    sizeTestStack.buffer = new int[stackToCopy.numCapacity];
    for (int i = 0; i < stackToCopy.numElements; i++) {
        sizeTestStack.buffer[i]=i*i+1;
    }
    /*
     * Testing Clear
     */
    sizeTestStack.clear();
    assert(sizeTestStack.numElements == 0);
    assert(sizeTestStack.numCapacity == 8);
    cout << "Clear Test Passed" << endl;
    /*
     * Testing Empty
     */
    sizeTestStack.numCapacity = 8;
    sizeTestStack.numElements = 5;
    sizeTestStack.buffer = new int[sizeTestStack.numCapacity];
    for (int i = 0; i < sizeTestStack.numElements; i++) {
        sizeTestStack.buffer[i]=i*i+1;
    }
    assert(!sizeTestStack.empty());
    
    sizeTestStack.numElements = 0;
    
    assert(sizeTestStack.empty());
    cout << "Empty Tests Passed" << endl;
    
    /*
     * Testing Push for Non-Integer Stack Behavior (Just to Make Sure stack Works For Other Types)
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
    
    cout << "This stack can hold strings!!!!" << endl;
    
    /*
     * For 5 percentage points extra credit you can implement
     * the const_iterator inner class and the const cbegin and
     * cend methods along with the tests for all the operators
     * for the const_iterator and cbegin and cend stack methods.
     */
    
    
    
    return 0;
}
