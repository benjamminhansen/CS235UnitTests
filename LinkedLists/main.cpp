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
#include "linked_list.h"

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
    node <int> defaultNode;
    assert(defaultNode.data == NULL);
    assert(defaultNode.pNext == NULL);
    assert(defaultNode.pPrev == NULL);
    cout << "Default Constructor Test Passed" << endl;
    
    /*
     * Testing constructor with data
     */
    node<int> dataNode(4);
    assert(*(dataNode.data) == 4);
    assert(dataNode.pNext == NULL);
    assert(dataNode.pPrev == NULL);
    
    /*
     *  Testing Copy Function
     */
    
    //The Copy function should produce a shallow copy.
    //That means the data doesn't get copied but the nodes do.
    
    //Generating small doubley linked list with the ordered list of values 5<->6<->7<->9<->9<->10. The character set <-> indicates doubley linked nodes.
    node<int>* theHead = new node<int>(5);
    node<int>* currentNodePtr = theHead;
    node<int>* aNode = new node<int>(6);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(7);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(8);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(9);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(10);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
   
    //Copying a null list of nodes.
    node<int>* whereToStartCopy = NULL;
    assert(copy(whereToStartCopy) == NULL);
    
    //Copying an entire list of nodes.
    whereToStartCopy = theHead;
    node<int>* theCopyHead = copy(whereToStartCopy);
    //ensuring each node was copied and pNext pointers were duplicated correctly.
    assert(theCopyHead != theHead);
    assert(theCopyHead->pNext != theHead->pNext);
    assert(theCopyHead->pNext->pNext != theHead->pNext->pNext);
    assert(theCopyHead->pNext->pNext->pNext != theHead->pNext->pNext->pNext);
    assert(theCopyHead->pNext->pNext->pNext->pNext != theHead->pNext->pNext->pNext->pNext);
    assert(theCopyHead->pNext->pNext->pNext->pNext->pNext != theHead->pNext->pNext->pNext->pNext->pNext);
    assert(theCopyHead->pNext->pNext->pNext->pNext->pNext->pNext == NULL);
    //ensuring the pPrev pointers were duplicated correctly.
    assert(theCopyHead->pPrev == NULL);
    assert(theCopyHead->pNext->pPrev == theCopyHead);
    assert(theCopyHead->pNext->pNext->pPrev == theCopyHead->pNext);
    assert(theCopyHead->pNext->pNext->pNext->pPrev == theCopyHead->pNext->pNext);
    assert(theCopyHead->pNext->pNext->pNext->pNext->pPrev == theCopyHead->pNext->pNext->pNext);
    assert(theCopyHead->pNext->pNext->pNext->pNext->pPrev == theCopyHead->pNext->pNext->pNext);
    assert(theCopyHead->pNext->pNext->pNext->pNext->pNext->pPrev == theCopyHead->pNext->pNext->pNext->pNext);
    //ensuring the data pointers were set correctly
    assert(theCopyHead->data == theHead->data);
    assert(theCopyHead->pNext->data == theHead->pNext->data);
    assert(theCopyHead->pNext->pNext->data == theHead->pNext->pNext->data);
    assert(theCopyHead->pNext->pNext->pNext->data == theHead->pNext->pNext->pNext->data);
    assert(theCopyHead->pNext->pNext->pNext->pNext->data == theHead->pNext->pNext->pNext->pNext->data);
    assert(theCopyHead->pNext->pNext->pNext->pNext->pNext->data == theHead->pNext->pNext->pNext->pNext->pNext->data);
    assert(theCopyHead->pNext->pNext->pNext->pNext->pNext->pNext->data == theHead->pNext->pNext->pNext->pNext->pNext->pNext->data);
    assert(theCopyHead->pNext->pNext->pNext->pNext->pNext->pNext->data == theHead->pNext->pNext->pNext->pNext->pNext->pNext->data);
    

    //Copying a subset of nodes.
    whereToStartCopy = theHead->pNext->pNext;
    theCopyHead = copy(whereToStartCopy);
    assert(theCopyHead->pPrev == NULL);
    assert(whereToStartCopy->data == theCopyHead->data);
    assert(whereToStartCopy->pNext->data == theCopyHead->pNext->data);
    assert(whereToStartCopy->pNext->pNext->data == theCopyHead->pNext->pNext->data);
    assert(whereToStartCopy->pNext->pNext->data == theCopyHead->pNext->pNext->data);
    assert(whereToStartCopy->pNext->pNext->pNext->data == theCopyHead->pNext->pNext->pNext->data);
    assert(whereToStartCopy->pNext->pNext->pNext->pNext == NULL);
    
    /*
     * Testing Insert
     */
    
    //Reuse the list of values 5<->6<->7<->9<->9<->10.
    //Testing inserting to NULL list.
    node<int>* nullNode = NULL;
    node<int>* createdNode = NULL;
    try
    {
        createdNode = insert(nullNode, 5);
        assert(false);
    }
    catch(const char* message)
    {
        assert(strcmp(message, "Error: inserting into NULL list."));
    }
    
    //Testing insertion before the head node.
    createdNode = insert(theHead, 3);
    //List of values is now 3<->5<->6<->7<->9<->9<->10.
    assert(*(createdNode->data) == 3);
    assert(createdNode->pPrev == NULL);
    assert(createdNode->pNext == theHead);
    assert(theHead->pPrev == createdNode);
    
    //Testing insertion between two existing nodes after the first.
    //reset theHeadPointer
    theHead = createdNode;//theHead now has value of 3
    node<int>* nodeToBeInsertedBefore = theHead->pNext;
    createdNode = insert(theHead, 4, true);
    //List of values is now 3<->4<->5<->6<->7<->9<->9<->10.
    assert(*(createdNode->data) == 4);
    assert(createdNode->pPrev == theHead);
    assert(createdNode->pNext == nodeToBeInsertedBefore);
    assert(theHead->pNext == createdNode);
    
    //Testing insertion at the end of the list
    node<int>* lastNode = theHead->pNext->pNext->pNext->pNext->pNext->pNext->pNext;
    createdNode = insert(lastNode, 12, true);
    //List of values is now 3<->4<->5<->6<->7<->9<->9<->10<->12.
    assert(*(createdNode->data) == 12);
    assert(createdNode->pPrev == lastNode);
    assert(createdNode->pNext == NULL);
    assert(lastNode->pNext == createdNode);
    
    //test insertion between two existing nodes before the second.
    //reset lastNode
    lastNode = createdNode;
    node<int>* nodeToBeInsertedAfter = lastNode->pPrev;
    createdNode = insert(lastNode, 11);
    //List of values is now 3<->4<->5<->6<->7<->9<->9<->10<->11<->12.
    assert(*(createdNode->data) == 11);
    assert(createdNode->pPrev == nodeToBeInsertedAfter);
    assert(createdNode->pNext == lastNode);
    assert(lastNode->pPrev == createdNode);
    
    /*
     * Testing Find
     */
    
    //New list of values 5<->6<->7<->5.
    node<int>* findHead = new node<int>(5);
    currentNodePtr = findHead;
    aNode = new node<int>(6);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(7);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(5);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    
    
    //Testing searching NULL list
    node<int>* foundNode = find(nullNode, 5);
    assert(foundNode == NULL);
    
    //Testing searching entire list without value
    foundNode = find(findHead,10);
    assert(foundNode = NULL);
    
    //Testing searching sub-list without value
    foundNode = find(findHead->pNext,10);
    assert(foundNode == NULL);
    
    //Testing searching full list for first value
    foundNode = find(findHead,5);
    assert(foundNode == findHead);
    
    /*
     * Testing freeData
     */
    
    //Testing freeing NULL list
    try
    {
        freeData(nullNode);
        assert(false);
    } catch (const char* message) {
        assert(strcmp(message, "Error: freeing NULL list."));
    }
    //Testing freeing list consisting of a single node.
    node<int>* singleNode = new node<int>(3);
    freeData(singleNode);
    assert(singleNode == NULL);//If you don't reset the pointer to the node passed in, you have a zombie pointer.
    
    //Reusing findHead list of values 5<->6<->7<->5.
    
    //testing freeing a sublist
    freeData(findHead->pNext->pNext);
    assert(findHead->pNext == NULL);
    
    //testing freeing an entire list
    freeData(findHead);
    assert(findHead == NULL);
    
    /*
     * Testing Remove
     */
    
    //Building list
    node<int>* removeHead = new node<int>(5);
    currentNodePtr = removeHead;
    aNode = new node<int>(6);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(7);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(5);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    aNode = new node<int>(13);
    currentNodePtr->pNext = aNode;
    aNode->pPrev = currentNodePtr;
    currentNodePtr = aNode;
    
    //testing remove NULL node
    
    node<int>* nodeBefore = remove(nullNode);
    assert(nodeBefore == NULL);
    
    //testing remove malformed node
    node<int>* malformedNode = new node<int>(5);
    malformedNode->pNext = NULL;
    malformedNode->pPrev = NULL;
    nodeBefore = remove(malformedNode);
    assert(malformedNode == NULL);
    assert(nodeBefore == NULL);
    
    //testing remove middle node
    //list is currently 5<->6<->7<->5<->13.
    node<int>* nodeToRemove = removeHead->pNext->pNext;
    node<int>* nodeAfterToRemove = nodeToRemove->pNext;
    nodeBefore = remove(nodeToRemove);
    //list is now 5<->6<->5<->13.
    assert(nodeToRemove == NULL);
    assert(nodeBefore->pNext == nodeAfterToRemove);
    assert(nodeAfterToRemove->pPrev == nodeBefore);
    
    //testing removing headNode
    nodeToRemove = removeHead;
    node<int>* secondNode = removeHead->pNext;
    node<int>* currentFirstNode = remove(removeHead);
    //list is now 6<->5<->13.
    assert(currentFirstNode == secondNode);
    assert(removeHead == NULL);
    
    //testing removing lastNode
    //resetting removeHead
    removeHead = currentFirstNode;
    nodeToRemove = removeHead->pNext->pNext;
    nodeBefore = remove(nodeToRemove);
    assert(nodeBefore == removeHead->pNext);
    assert(nodeToRemove == NULL);
    
    
    
    
    
    
    
    
    
    
    /*
     * Testing insert for Non-Integer set Behavior (Just to Make Sure set Works For Other Types)
     */
    
    node<string>* stringNode = new node<string>("Hello");
    std::string greeting = "Hello";
    
    assert(stringNode->data->compare(greeting) == 0);
    assert(stringNode->pNext == NULL);
    assert(stringNode->pPrev == NULL);
    
    cout << "This node can hold strings!!!!" << endl;
    
    
    
    return 0;
}
