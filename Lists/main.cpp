/*
 * main.cpp
 *
 *  Created by Lee Barney on 09/20/18.
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
#include "unit_testing_delete.h"
#include "list.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;


int main(int argc, const char* argv[])
{
    
    /*
     * Testing default node constructor
     */
    list<int>::node defaultNode;
    assert(defaultNode.data == NULL);
    assert(defaultNode.pNext == NULL);
    assert(defaultNode.pPrev == NULL);
    cout << "Default Node Constructor Test Passed" << endl;
    
    /*
     * Testing Node constructor with data
     */
    list<int>::node dataNode(4);
    assert(*(dataNode.data) == 4);
    assert(dataNode.pNext == NULL);
    assert(dataNode.pPrev == NULL);
    
    cout<<"Constructor with Data Test Passed"<<endl;
    
    /*
     * Testing Node Destructor
     */
    list<int>::node* nodeToDelete = new list<int>::node();
    delete nodeToDelete;
    assert(unit_testing_delete_call_counter = 1);
    //When done with a pointer set it to NULL so you don't create a zombie pointer.
    nodeToDelete = NULL;
    
    //resetting deletion counter
    unit_testing_delete_call_counter = 0;
    nodeToDelete = new list<int>::node(5);
    delete nodeToDelete;
    assert(unit_testing_delete_call_counter == 2);
    //killing potential zombie
    nodeToDelete = NULL;
    cout<<"Passed Node Destructor Test"<<endl;
    
    /*
     * Testing default list constructor
     */
    list <int> defaultList;
    assert(defaultList.pHead == NULL);
    assert(defaultList.pTail == NULL);
    assert(defaultList.numElements == 0);
    cout << "Default List Constructor Test Passed" << endl;
    
    
    /*
     * Testing copy constructor
     */
    list<int> listToCopy;
    listToCopy.numElements = 0;
    listToCopy.pHead = NULL;
    listToCopy.pTail = NULL;
    
    //testing copy of empty list
    list<int>emptyListCopy(listToCopy);
    assert(emptyListCopy.numElements == 0);
    assert(emptyListCopy.pHead == NULL);
    assert(emptyListCopy.pTail == NULL);
    
    //Generating small doubly linked list with the ordered list of values 5<->6<->7<->9<->9<->10. The character set <-> indicates doubly linked lists.
    listToCopy.numElements = 6;
    listToCopy.pHead = new list<int>::node(5);
    list<int>::node* currentNodePtr = listToCopy.pHead;
    currentNodePtr->pNext = new list<int>::node(6);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(7);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(9);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(9);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(10);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    listToCopy.pTail = currentNodePtr;
    //reset currentNodePtr to be NULL so it can't be a zombie pointer
    currentNodePtr = NULL;
    
    //testing copy of non-empty list
    list<int> listCopy(listToCopy);
    assert(listCopy.numElements == 6);
    //These two pointers are here to get rid of the chain of pointers that yout saw in the LinkedList tests.
    list<int>::node* toCopyCurrentNode = listToCopy.pHead;
    list<int>::node* copyCurrentNode = listCopy.pHead;
    
    assert(toCopyCurrentNode != copyCurrentNode);
    assert(toCopyCurrentNode->data == copyCurrentNode->data);
    assert(toCopyCurrentNode->pNext != copyCurrentNode->pNext);
    assert(toCopyCurrentNode->pPrev == NULL);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assert(toCopyCurrentNode != copyCurrentNode);
    assert(toCopyCurrentNode->data == copyCurrentNode->data);
    assert(toCopyCurrentNode->pNext != copyCurrentNode->pNext);
    assert(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assert(toCopyCurrentNode != copyCurrentNode);
    assert(toCopyCurrentNode->data == copyCurrentNode->data);
    assert(toCopyCurrentNode->pNext != copyCurrentNode->pNext);
    assert(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assert(toCopyCurrentNode != copyCurrentNode);
    assert(toCopyCurrentNode->data == copyCurrentNode->data);
    assert(toCopyCurrentNode->pNext != copyCurrentNode->pNext);
    assert(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assert(toCopyCurrentNode != copyCurrentNode);
    assert(toCopyCurrentNode->data == copyCurrentNode->data);
    assert(toCopyCurrentNode->pNext != copyCurrentNode->pNext);
    assert(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev);
    
    toCopyCurrentNode = toCopyCurrentNode->pNext;
    copyCurrentNode = copyCurrentNode->pNext;
    
    assert(toCopyCurrentNode != copyCurrentNode);
    assert(toCopyCurrentNode->data == copyCurrentNode->data);
    assert(toCopyCurrentNode->pNext == NULL);
    assert(toCopyCurrentNode->pPrev != copyCurrentNode->pPrev);
   
    cout<<"Passed List Copy Constructor Test"<<endl;
    
    
    /*
     * Testing list destructor
     */
    
    unit_testing_delete_call_counter = 0;
    list<int>* listToDelete = new list<int>();
    delete listToDelete;
    assert(unit_testing_delete_call_counter == 1);
    
    //killing potential zombie
    listToDelete = NULL;
    
    //reset deletion counter
    unit_testing_delete_call_counter = 0;
    //resetting listToDelete to: 5<=>6<=>7<=>9
    listToDelete->numElements = 4;
    listToDelete->pHead = new list<int>::node(5);
    //reusing currentNodePtr variable
    currentNodePtr = listToDelete->pHead;
    currentNodePtr->pNext = new list<int>::node(6);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(7);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    currentNodePtr->pNext = new list<int>::node(9);
    currentNodePtr->pNext->pPrev = currentNodePtr;
    
    //kill potential zombie
    currentNodePtr = NULL;
    
    delete listToDelete;
    assert(unit_testing_delete_call_counter == 9);
    //kill potential zombie
    listToDelete = NULL;
    
    /*
     * Testing size
     */
    list<int>emptyList;
    //building emptyList
    emptyList.numElements = 0;
    emptyList.pHead = NULL;
    emptyList.pTail = NULL;
    
    list<int>listWithStuffInIt;
    //building listWithStuffInIt: 5<=>6<=>7<=>9
    listWithStuffInIt.numElements = 4;
    list<int>::node* firstNode = new list<int>::node(5);
    listWithStuffInIt.pHead = firstNode;
    //reusing currentNodePtr variable
    currentNodePtr = listWithStuffInIt.pHead;
    list<int>::node* secondNode = new list<int>::node(6);
    currentNodePtr->pNext = secondNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    list<int>::node* thirdNode = new list<int>::node(7);
    currentNodePtr->pNext = thirdNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    currentNodePtr = currentNodePtr->pNext;
    
    list<int>::node* fourthNode = new list<int>::node(9);
    currentNodePtr->pNext = secondNode;
    currentNodePtr->pNext->pPrev = currentNodePtr;
    
    //testing empty list
    assert(emptyList.size() == 0);
    assert(emptyList.numElements == 0);
    assert(emptyList.pHead == NULL);
    assert(emptyList.pTail == NULL);
    //testing non-empty list
    assert(listWithStuffInIt.size() == 4);
    //make sure nothing changed in the list
    assert(listWithStuffInIt.numElements == 4);
    assert(listWithStuffInIt.pHead == firstNode);
    assert(listWithStuffInIt.pTail == fourthNode);
    assert(listWithStuffInIt.pHead->pNext = secondNode);
    assert(secondNode->pPrev = firstNode);
    assert(listWithStuffInIt.pHead->pNext->pNext = thirdNode);
    assert(thirdNode->pPrev = secondNode);
    assert(listWithStuffInIt.pHead->pNext->pNext->pNext = fourthNode);
    assert(fourthNode->pPrev = thirdNode);
    
    /*
     * Testing empty
     */
    //testing empty list
    assert(emptyList.empty() == true);
    assert(emptyList.numElements == 0);
    assert(emptyList.pHead == NULL);
    assert(emptyList.pTail == NULL);
    
    //testing non-empty list
    assert(listWithStuffInIt.empty() == false);
    //make sure nothing changed in the list
    assert(listWithStuffInIt.numElements == 4);
    assert(listWithStuffInIt.pHead == firstNode);
    assert(listWithStuffInIt.pTail == fourthNode);
    assert(listWithStuffInIt.pHead->pNext = secondNode);
    assert(secondNode->pPrev = firstNode);
    assert(listWithStuffInIt.pHead->pNext->pNext = thirdNode);
    assert(thirdNode->pPrev = secondNode);
    assert(listWithStuffInIt.pHead->pNext->pNext->pNext = fourthNode);
    assert(fourthNode->pPrev = thirdNode);
    
    /*
     * Testing front
     */
    //testing empty list front getter
    try {
        emptyList.front();
        assert(false);
    } catch (const char* message) {
        assert(strcmp(message, "Error: calling front on empty list."));
    }
    assert(emptyList.numElements == 0);
    assert(emptyList.pHead == NULL);
    assert(emptyList.pTail == NULL);
    
    //testing empty list front setter
    try {
        emptyList.front() = 7;
        assert(false);
        
    } catch (const char* message) {
        assert(strcmp(message, "Error: calling front on empty list."));
    }
    assert(emptyList.numElements == 0);
    assert(emptyList.pHead == NULL);
    assert(emptyList.pTail == NULL);
    
    //testing non-empty list front getter:5<=>6<=>7<=>9
    assert(listWithStuffInIt.front() == 5);
    //make sure nothing changed in the list
    assert(listWithStuffInIt.numElements == 4);
    assert(listWithStuffInIt.pHead == firstNode);
    assert(listWithStuffInIt.pTail == fourthNode);
    assert(listWithStuffInIt.pHead->pNext = secondNode);
    assert(secondNode->pPrev = firstNode);
    assert(listWithStuffInIt.pHead->pNext->pNext = thirdNode);
    assert(thirdNode->pPrev = secondNode);
    assert(listWithStuffInIt.pHead->pNext->pNext->pNext = fourthNode);
    assert(fourthNode->pPrev = thirdNode);
    
    //testing non-empty lists front setter:5<=>6<=>7<=>9 becomes 7<=>6<=>7<=>9
    listWithStuffInIt.front() = 7;
    //make sure the first node's data changed
    assert(*(listWithStuffInIt.pHead->data) == 7);
    //make sure no nodes were changed in the list
    assert(listWithStuffInIt.numElements == 4);
    assert(listWithStuffInIt.pHead == firstNode);
    assert(listWithStuffInIt.pTail == fourthNode);
    assert(listWithStuffInIt.pHead->pNext = secondNode);
    assert(secondNode->pPrev = firstNode);
    assert(listWithStuffInIt.pHead->pNext->pNext = thirdNode);
    assert(thirdNode->pPrev = secondNode);
    assert(listWithStuffInIt.pHead->pNext->pNext->pNext = fourthNode);
    assert(fourthNode->pPrev = thirdNode);
    
    /*
     * Testing back
     */
    //testing empty list back getter
    try {
        emptyList.back();
        assert(false);
    } catch (const char* message) {
        assert(strcmp(message, "Error: calling front on empty list."));
    }
    assert(emptyList.numElements == 0);
    assert(emptyList.pHead == NULL);
    assert(emptyList.pTail == NULL);
    
    //testing empty list back setter
    try {
        emptyList.back() = 7;
        assert(false);
        
    } catch (const char* message) {
        assert(strcmp(message, "Error: calling front on empty list."));
    }
    //testing non-empty list back getter:7<=>6<=>7<=>9
    assert(listWithStuffInIt.back() == 9);
    //make sure nothing changed in the list
    assert(listWithStuffInIt.numElements == 4);
    assert(listWithStuffInIt.pHead == firstNode);
    assert(listWithStuffInIt.pTail == fourthNode);
    assert(listWithStuffInIt.pHead->pNext = secondNode);
    assert(secondNode->pPrev = firstNode);
    assert(listWithStuffInIt.pHead->pNext->pNext = thirdNode);
    assert(thirdNode->pPrev = secondNode);
    assert(listWithStuffInIt.pHead->pNext->pNext->pNext = fourthNode);
    assert(fourthNode->pPrev = thirdNode);
    
    //testing non-empty list back setter: 7<=>6<=>7<=>9 becomes 7<=>6<=>7<=>1
    listWithStuffInIt.back() = 1;
    //make sure the first node's data changed
    assert(*(listWithStuffInIt.pTail->data) == 1);
    //make sure no nodes were changed in the list
    assert(listWithStuffInIt.numElements == 4);
    assert(listWithStuffInIt.pHead == firstNode);
    assert(listWithStuffInIt.pTail == fourthNode);
    assert(listWithStuffInIt.pHead->pNext = secondNode);
    assert(secondNode->pPrev = firstNode);
    assert(listWithStuffInIt.pHead->pNext->pNext = thirdNode);
    assert(thirdNode->pPrev = secondNode);
    assert(listWithStuffInIt.pHead->pNext->pNext->pNext = fourthNode);
    assert(fourthNode->pPrev = thirdNode);
    
    /*
     * Testing pop_back
     */
    //testing pop_back for empty list
    try {
        emptyList.pop_back();
    } catch (const char* message) {
        assert(false);
    }
    assert(emptyList.numElements == 0);
    assert(emptyList.pHead == NULL);
    assert(emptyList.pTail == NULL);
    
    //testing pop_back for non-empty list:7<=>6<=>7<=>1 becomes 7<=>6<=>7
    listWithStuffInIt.pop_back();
    assert(listWithStuffInIt.numElements == 3);
    assert(listWithStuffInIt.pHead == firstNode);
    assert(listWithStuffInIt.pTail == thirdNode);
    assert(listWithStuffInIt.pHead->pNext = secondNode);
    assert(secondNode->pPrev = firstNode);
    assert(listWithStuffInIt.pHead->pNext->pNext = thirdNode);
    assert(thirdNode->pPrev = secondNode);
    
    /*
     * Testing pop_front
     */
    //testing pop_front for empty list
    try {
        emptyList.pop_front();
    } catch (const char* message) {
        assert(false);
    }
    assert(emptyList.numElements == 0);
    assert(emptyList.pHead == NULL);
    assert(emptyList.pTail == NULL);
    
    //testing pop_front for non-empty list:7<=>6<=>7 becomes 6<=>7
    listWithStuffInIt.pop_front();
    assert(listWithStuffInIt.numElements == 2);
    assert(listWithStuffInIt.pHead == firstNode);
    assert(listWithStuffInIt.pTail == secondNode);
    assert(listWithStuffInIt.pHead->pNext = secondNode);
    assert(secondNode->pPrev = firstNode);
    
    /*
     * Testing clear
     */
    //resetting delete counter
    unit_testing_delete_call_counter = 0;
    //testing empty list
    emptyList.clear();
    assert(unit_testing_delete_call_counter == 0);
    assert(emptyList.numElements == 0);
    assert(emptyList.pHead == NULL);
    assert(emptyList.pTail == NULL);
    //testing non-empty list
    unit_testing_delete_call_counter = 0;
    listWithStuffInIt.clear();
    assert(unit_testing_delete_call_counter == 4);
    assert(listWithStuffInIt.numElements == 0);
    assert(listWithStuffInIt.pHead == NULL);
    assert(listWithStuffInIt.pTail == NULL);
    
    /*
     * Testing push_front
     */
    list<int> pushTestingList;
    pushTestingList.numElements = 0;
    pushTestingList.pHead = NULL;
    pushTestingList.pTail = NULL;
    
    //testing push_front on an empty list
    try {
        pushTestingList.push_front(3);
    } catch (const char* message) {
        assert(false);
    }
    assert(pushTestingList.numElements == 1);
    assert(pushTestingList.pHead != NULL);
    assert(pushTestingList.pTail == pushTestingList.pHead);
    assert(pushTestingList.pHead->pNext == NULL);
    assert(pushTestingList.pTail->pPrev == NULL);
    assert(*(pushTestingList.pHead->data) == 3);
    
    //testing push_front on a list with one node: 3 becomes 5<=>3
    pushTestingList.push_front(5);
    assert(pushTestingList.numElements == 2);
    assert(pushTestingList.pHead != NULL);
    assert(pushTestingList.pTail != NULL);
    assert(pushTestingList.pHead != pushTestingList.pTail);
    assert(pushTestingList.pHead->pNext == pushTestingList.pTail);
    assert(pushTestingList.pTail->pPrev == pushTestingList.pHead);
    assert(*(pushTestingList.pHead->data) == 5);
    assert(*(pushTestingList.pHead->pNext->data) == 3);
    
    //testing push_front on a list with multiple nodes: 5<=>3 becomes -2<=>5<=>3
    list<int>::node* previousHead = pushTestingList.pHead;
    pushTestingList.push_front(5);
    assert(pushTestingList.numElements == 3);
    //making sure the pointers all got set correctly
    assert(pushTestingList.pHead != NULL);
    assert(pushTestingList.pTail != NULL);
    assert(pushTestingList.pHead != pushTestingList.pTail);
    assert(pushTestingList.pHead->pNext == previousHead);
    assert(pushTestingList.pHead->pPrev == NULL);
    assert(pushTestingList.pTail->pPrev == previousHead);
    assert(pushTestingList.pTail->pNext == NULL);
    assert(previousHead->pPrev == pushTestingList.pHead);
    assert(previousHead->pNext == pushTestingList.pTail);
    //making sure the data didn't get messed up
    assert(*(pushTestingList.pHead->data) == -2);
    assert(*(pushTestingList.pTail->data) == 3);
    assert(*(previousHead->data) == 5);
    
    
    /*
     * Testing push_back
     */
    list<int>pushBackTestingList;
    pushBackTestingList.numElements = 0;
    pushBackTestingList.pHead = NULL;
    pushBackTestingList.pTail = NULL;
    
    //testing push_back on an empty list
    pushBackTestingList.push_back(20);
    assert(pushBackTestingList.numElements = 1);
    assert(pushBackTestingList.pHead != NULL);
    assert(pushBackTestingList.pTail == emptyList.pHead);
    assert(pushBackTestingList.pHead->pNext == NULL);
    assert(pushBackTestingList.pTail->pPrev == NULL);
    assert(*(pushBackTestingList.pTail->data) == 20);
    
    //testing push_back on a list with one node: 20 becomes 20<=>0
    pushBackTestingList.push_back(0);
    assert(pushBackTestingList.numElements = 2);
    assert(pushBackTestingList.pHead != NULL);
    assert(pushBackTestingList.pTail != NULL);
    assert(pushBackTestingList.pHead != pushBackTestingList.pTail);
    assert(pushBackTestingList.pHead->pNext == pushBackTestingList.pTail);
    assert(pushBackTestingList.pTail->pPrev == pushBackTestingList.pHead);
    assert(*(pushBackTestingList.pTail->data) == 0);
    assert(*(pushBackTestingList.pHead->data) == 20);
    
    //testing push_back on a list with multiple nodes: 20<=>0 becomes 20<=>0<=>32
    list<int>::node* previousTail = pushTestingList.pTail;
    pushTestingList.push_back(32);
    assert(pushBackTestingList.numElements = 3);
    //making sure the pointers all got set correctly
    assert(pushBackTestingList.pHead != NULL);
    assert(pushBackTestingList.pTail != NULL);
    assert(pushBackTestingList.pHead != pushBackTestingList.pTail);
    assert(pushBackTestingList.pHead->pNext == previousTail);
    assert(pushBackTestingList.pHead->pPrev == NULL);
    assert(pushBackTestingList.pTail->pPrev == previousTail);
    assert(pushBackTestingList.pTail->pNext == NULL);
    assert(previousTail->pPrev == pushBackTestingList.pHead);
    assert(previousTail->pNext == pushTestingList.pTail);
    //making sure the data didn't get messed up
    assert(*(pushBackTestingList.pHead->data) == 20);
    assert(*(previousTail->data) == 0);
    assert(*(pushBackTestingList.pTail->data) == 32);
    
    
    
    /*
     * Testing iterator Constructors
     */
    
    //testing default constructor
    list<int>::iterator emptyIterator;
    assert(emptyIterator.ptr == NULL);
    
    //testing non-default constructor with node that has a null data pointer
    int leftDataValue = 5;
    list<int>::node* leftNode = new list<int>::node();
    leftNode->data = &leftDataValue;
    
    int rightDataValue = -76;
    list<int>::node* rightNode = new list<int>::node();
    rightNode->data = &rightDataValue;
    
    list<int>::node* nullDataNode;
    nullDataNode->data = NULL;
    //set up the pointers correctly
    nullDataNode->pNext = rightNode;
    rightNode->pPrev = nullDataNode;
    nullDataNode->pPrev = leftNode;
    leftNode->pNext = nullDataNode;
    
    list<int>::iterator nullDataNodeIterator(nullDataNode);
    assert(nullDataNodeIterator.ptr == nullDataNode);
    
    
    //make sure the pointers didn't get messed up
    assert(nullDataNode->pNext == rightNode);
    assert(rightNode->pPrev == nullDataNode);
    assert(nullDataNode->pPrev == leftNode);
    assert(leftNode->pNext == nullDataNode);
    
    //make sure the values didn't get messed up
    assert(nullDataNode->data == NULL);
    assert(*(leftNode->data) == 5);
    assert(*(rightNode->data) == -76);
    
    //testing non-default constructor with node that has a non-null data pointer
    int middleNodeDataValue = 512;
    list<int>::node* nonNullDataNode;
    nonNullDataNode->data = &middleNodeDataValue;
    //set up the pointers correctly
    nonNullDataNode->pNext = rightNode;
    rightNode->pPrev = nonNullDataNode;
    nonNullDataNode->pPrev = leftNode;
    leftNode->pNext = nonNullDataNode;
    
    list<int>::iterator nonNullDataNodeIterator(nonNullDataNode);
    assert(nonNullDataNodeIterator.ptr == nonNullDataNode);
    
    //make sure the pointers didn't get messed up
    assert(nonNullDataNode->pNext == rightNode);
    assert(rightNode->pPrev == nonNullDataNode);
    assert(nonNullDataNode->pPrev == leftNode);
    assert(leftNode->pNext == nonNullDataNode);
    
    //make sure the values didn't get messed up
    assert(*(nonNullDataNode->data) == 512);
    assert(*(leftNode->data) == 5);
    assert(*(rightNode->data) == -76);
    
    //copies of iterators are shallow copies
    
    //Testing copy constructor with null data node
    list<int>::iterator nullDataCopiedIterator(nullDataNodeIterator);
    assert(nullDataCopiedIterator.ptr == nullDataNodeIterator.ptr);
    assert(nullDataCopiedIterator.ptr->pNext == rightNode);
    assert(nullDataCopiedIterator.ptr->pPrev == leftNode);
    //make sure the values didn't get messed up
    assert(nullDataCopiedIterator.ptr->data == NULL);
    assert(*(leftNode->data) == 5);
    assert(*(rightNode->data) == -76);
    
    //Testing copy constructor with non-null data node
    list<int>::iterator nonNullDataCopiedIterator(nonNullDataNodeIterator);
    assert(nonNullDataCopiedIterator.ptr == nonNullDataNodeIterator.ptr);
    assert(nonNullDataCopiedIterator.ptr->pNext == rightNode);
    assert(nonNullDataCopiedIterator.ptr->pPrev == leftNode);
    //make sure the values didn't get messed up
    assert(*(nonNullDataNode->data) == 512);
    assert(*(leftNode->data) == 5);
    assert(*(rightNode->data) == -76);
    
    cout<<"Passed Copy Constructor Tests"<<endl;
    
    
    
    /*
     * Testing push_back for Non-Integer list Behavior (Just to Make Sure set Works For Other Types)
     */
    
    list<string>stringList;
    assert(stringList.pHead == NULL);
    assert(stringList.pTail == NULL);
    assert(stringList.numElements == 0);
    stringList.push_back("Hello");
    
    assert(stringList.pHead == stringList.pTail);
    assert(stringList.pHead->data->compare("Hello") == 0);
    
    cout << "This list can hold strings!!!!" << endl;
     
    return 0;
}
