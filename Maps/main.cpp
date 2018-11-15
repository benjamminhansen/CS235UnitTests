/*
 * main.cpp
 *
 *  Created by Lee Barney on 11/14/18.
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
#include "map.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using namespace custom;

int main(int argc, const char * argv[]) {
    
    /*------------------------------------------------------------------
     * WARNING: THIS TEST HAS A DEPENDENCY ON THE BST TEST.
     * THE BST TEST MUST PASS WITHOUT FAILURE BEFORE THIS TEST IS RUN.
     *------------------------------------------------------------------
     */
    
    
    
    /*
     * Testing pair constructors
     */
    
    
    map<char,int>::pair<char,int> defaultPair;
    //not really anything that can be tested here. Unset default values could be anything.
    
    map<char,int>::pair<char,int> pairToCopy;
    pairToCopy.first = 'a';
    pairToCopy.second = 97;
    
    map<char,int>::pair<char,int> copiedPair(pairToCopy);
    assert(copiedPair.first == 'a');
    assert(copiedPair.second == 97);
    cout<<"Passed Constructor Tests"<<endl;
    
    /*
     * Testing pair operators
     */
    map<char, int>::pair<char, int> assignedToPair = pairToCopy;
    assert(assignedToPair.first == 'a');
    assert(assignedToPair.second == 97);
    
    
    assignedToPair = defaultPair;
    assert(assignedToPair.first == defaultPair.first);
    assert(assignedToPair.second == defaultPair.second);
    
    cout<<"Passed Assignment Operator Tests"<<endl;
    
    
    //for all comparison operators, only the key is used for the comparison.
    
    
    /*
     * Testing == operator
     */
    
    //testing comparing to self
    assert(defaultPair == defaultPair);
    assert(assignedToPair == assignedToPair);
    //testing comparing to others
    assert(assignedToPair == defaultPair);
    assert(copiedPair == pairToCopy);
    assert(!(assignedToPair == pairToCopy));
    //testing key matches value doesn't
    copiedPair.second = 5;
    assert(copiedPair == pairToCopy);
    //testing key doesn't match, value does
    copiedPair.second = 97;
    copiedPair.first = 'b';
    assert(!(copiedPair == pairToCopy));
    
    cout<<"Passed == Operator Tests"<<endl;
    
    /*
     * Testing > operator
     */
    map<char, int>::pair<char, int> lesserPair;
    lesserPair.first = ' ';//ascii value is 32
    lesserPair.second = 18;
    map<char, int>::pair<char, int> greaterPair;
    greaterPair.first = '~';//ascii value is 176
    greaterPair.second = 18;
    
    //testing key doesn't match, value does
    assert(greaterPair > lesserPair);
    //testing key matches, values don't
    lesserPair.first = '~';
    greaterPair.second = 100;
    assert(!(greaterPair > lesserPair));
    //testing comparing to self
    assert(!(greaterPair > greaterPair));
    assert(!(defaultPair > defaultPair));
    
    cout<<"Passed > Operator Tests"<<endl;
    
    /*
     * Testing < operator
     */
    //resetting lesser and greater pairs
    lesserPair.first = ' ';
    lesserPair.second = 18;
    greaterPair.first = '~';//ascii value is 176
    greaterPair.second = 100;
    
    assert(lesserPair < greaterPair);
    //testing against self
    assert(!(lesserPair < lesserPair));
    assert(!(greaterPair < greaterPair));
    assert(!(defaultPair < defaultPair));
    assert(!(greaterPair < lesserPair));
    //testing keys don't match, values do
    greaterPair.second = lesserPair.second;
    assert(lesserPair < greaterPair);
    //testing keys match values don't
    greaterPair.second = 200;
    lesserPair.first = greaterPair.first;
    assert(!(lesserPair < greaterPair));
    
    cout<<"Passed < Operator Tests"<<endl;
    
    /*
     * Testing >= operator
     */
    
    //resetting lesser and greater pairs
    lesserPair.first = ' ';
    lesserPair.second = 18;
    greaterPair.first = '~';//ascii value is 176
    greaterPair.second = 100;
    
    assert(greaterPair >= lesserPair);
    //testing against self
    assert(lesserPair >= lesserPair);
    assert(greaterPair >= greaterPair);
    assert(defaultPair >= defaultPair);
    assert(!(lesserPair >= greaterPair));
    //testing keys don't match, values do;
    greaterPair.second = lesserPair.second;
    assert(greaterPair >= lesserPair);
    assert(!(lesserPair >= greaterPair));
    //testing keys match values don't
    greaterPair.second = 200;
    lesserPair.first = greaterPair.first;
    assert(greaterPair >= lesserPair);
    assert(lesserPair >= greaterPair);
    
    cout<<"Passed >= Tests"<<endl;
    
    /*
     * Testing <= operator
     */
    
    //resetting lesser and greater pairs
    lesserPair.first = ' ';
    lesserPair.second = 18;
    greaterPair.first = '~';//ascii value is 176
    greaterPair.second = 100;
    
    assert(lesserPair <= greaterPair);
    //testing against self
    assert(lesserPair <= lesserPair);
    assert(greaterPair <= greaterPair);
    assert(defaultPair <= defaultPair);
    //testing keys don't match values do
    greaterPair.second = lesserPair.second;
    assert(lesserPair <= greaterPair);
    assert(!(greaterPair <= lesserPair));
    //testing keys match values don't
    greaterPair.second = 200;
    lesserPair.first = greaterPair.first;
    assert(lesserPair <= greaterPair);
    assert(greaterPair <= lesserPair);
    
    cout<<"Passed <= Operator Tests"<<endl;
    
    /*
     * Testing map constructors
     */
    map<char,int> defaultMap;
    assert(defaultMap.bst.numElements == 0);
    assert(defaultMap.bst.root == NULL);
    
    map<char, int> copiedMap(defaultMap);
    assert(copiedMap.bst.numElements == 0);
    assert(copiedMap.bst.root == NULL);
    
    //Generating small BST with the values                              |
    //                                                            ----<f,7>------
    //                                                            |              |
    //                                                       ---<c,21>--     --<g,10>------
    //                                                       |             |              |
    //                                                     <b,3>         <s,-5>         <z,0>
    
    
    map<char, int> builtMap;
    //BST<map<char,int>::pair<char,int>> builtMap.bst;
    builtMap.bst.numElements = 6;
    builtMap.bst.root = new BST<map<char,int>::pair<char,int>>::BNode();
    map<char,int>::pair<char,int>fPair;
    fPair.first = 'f';
    fPair.second = 7;
    builtMap.bst.root->data = fPair;
    
    
    BST<map<char,int>::pair<char,int>>::BNode* insertRootRight = new BST<map<char,int>::pair<char,int>>::BNode();
    map<char,int>::pair<char,int>gPair;
    gPair.first = 'g';
    gPair.second = 10;
    insertRootRight->data = gPair;
    insertRootRight->pParent = builtMap.bst.root;// <f,7>
    builtMap.bst.root->pRight = insertRootRight;// <g,10>
    
    BST<map<char,int>::pair<char,int>>::BNode* insertRootRightRight = new BST<map<char,int>::pair<char,int>>::BNode();
    map<char,int>::pair<char,int>zPair;
    zPair.first = 'z';
    zPair.second = 0;
    insertRootRight->data = zPair;
    insertRootRightRight->pParent = insertRootRight;// <g,10>
    insertRootRight->pRight = insertRootRightRight;// <z,0>
    
    BST<map<char,int>::pair<char,int>>::BNode* insertRootRightLeft = new BST<map<char,int>::pair<char,int>>::BNode();
    map<char,int>::pair<char,int>sPair;
    sPair.first = 's';
    sPair.second = -5;
    insertRootRight->data = sPair;
    insertRootRightLeft->pParent = insertRootRight;// <g,10>
    insertRootRight->pLeft = insertRootRightLeft;// <s,-5>
    
    BST<map<char,int>::pair<char,int>>::BNode* insertRootLeft = new BST<map<char,int>::pair<char,int>>::BNode();
    map<char,int>::pair<char,int>cPair;
    cPair.first = 'c';
    cPair.second = 21;
    insertRootRight->data = cPair;
    insertRootLeft->pRight = NULL;
    insertRootLeft->pParent = builtMap.bst.root;//(7)
    builtMap.bst.root->pLeft = insertRootLeft;//(6)
    
    
    BST<map<char,int>::pair<char,int>>::BNode* insertRootLeftLeft = new BST<map<char,int>::pair<char,int>>::BNode();
    map<char,int>::pair<char,int>bPair;
    bPair.first = 'b';
    bPair.second = 3;
    insertRootRight->data = cPair;
    insertRootLeftLeft->pRight = NULL;
    insertRootLeftLeft->pLeft = NULL;
    insertRootLeftLeft->pParent = insertRootLeft;// <c,21>
    insertRootLeft->pLeft = insertRootLeftLeft;// <b,3>
    
    
    map<char,int> copiedBuiltMap(builtMap);
    
    //copy should be                                                    |
    //                                                            ----<f,7>------
    //                                                            |              |
    //                                                       ---<c,21>--     --<g,10>------
    //                                                       |             |              |
    //                                                     <b,3>         <s,-5>         <z,0>
    
    assert(copiedBuiltMap.bst.root != NULL);
    assert(copiedBuiltMap.bst.root != builtMap.bst.root);
    assert(copiedBuiltMap.bst.root->data.first == 'f');
    assert(copiedBuiltMap.bst.root->data.second == 7);
    assert(copiedBuiltMap.bst.root->pParent == NULL);
    assert(copiedBuiltMap.bst.root->pRight != NULL);
    assert(copiedBuiltMap.bst.root->pLeft != NULL);
    
    //testing right sub-tree
    assert(copiedBuiltMap.bst.root->pRight != builtMap.bst.root->pRight);
    assert(copiedBuiltMap.bst.root->pRight->data.first == 'g');
    assert(copiedBuiltMap.bst.root->pRight->data.second == 10);
    assert(copiedBuiltMap.bst.root->pRight->pParent == copiedBuiltMap.bst.root);
    assert(copiedBuiltMap.bst.root->pRight != NULL);
    assert(copiedBuiltMap.bst.root->pLeft != NULL);
    
    assert(copiedBuiltMap.bst.root->pRight->pRight != builtMap.bst.root->pRight->pRight);
    assert(copiedBuiltMap.bst.root->pRight->pRight->data.first == 'z');
    assert(copiedBuiltMap.bst.root->pRight->pRight->data.second == 0);
    assert(copiedBuiltMap.bst.root->pRight->pRight->pParent == copiedBuiltMap.bst.root->pRight);
    assert(copiedBuiltMap.bst.root->pRight == NULL);
    assert(copiedBuiltMap.bst.root->pLeft == NULL);
    
    assert(copiedBuiltMap.bst.root->pRight->pLeft != builtMap.bst.root->pRight->pLeft);
    assert(copiedBuiltMap.bst.root->pRight->pLeft->data.first == 's');
    assert(copiedBuiltMap.bst.root->pRight->pLeft->data.second == -5);
    assert(copiedBuiltMap.bst.root->pRight->pLeft->pParent == copiedBuiltMap.bst.root->pLeft);
    assert(copiedBuiltMap.bst.root->pRight == NULL);
    assert(copiedBuiltMap.bst.root->pLeft == NULL);
    
    
    //testing left sub-tree
    assert(copiedBuiltMap.bst.root->pLeft != builtMap.bst.root->pLeft);
    assert(copiedBuiltMap.bst.root->pLeft->data.first == 'c');
    assert(copiedBuiltMap.bst.root->pLeft->data.second == 21);
    assert(copiedBuiltMap.bst.root->pLeft->pParent == copiedBuiltMap.bst.root);
    assert(copiedBuiltMap.bst.root->pLeft->pLeft != NULL);
    assert(copiedBuiltMap.bst.root->pLeft->pRight != NULL);
    
    assert(copiedBuiltMap.bst.root->pLeft->pLeft != builtMap.bst.root->pLeft->pLeft);
    assert(copiedBuiltMap.bst.root->pLeft->pLeft->data.first == 'c');
    assert(copiedBuiltMap.bst.root->pLeft->pLeft->data.second == 21);
    assert(copiedBuiltMap.bst.root->pLeft->pLeft->pParent == copiedBuiltMap.bst.root->pLeft);
    assert(copiedBuiltMap.bst.root->pLeft->pLeft->pLeft == NULL);
    assert(copiedBuiltMap.bst.root->pLeft->pLeft->pRight == NULL);
    
    assert(copiedBuiltMap.bst.root->pLeft->pRight != builtMap.bst.root->pLeft->pRight);
    assert(copiedBuiltMap.bst.root->pLeft->pRight->data.first == 'b');
    assert(copiedBuiltMap.bst.root->pLeft->pRight->data.second == 3);
    assert(copiedBuiltMap.bst.root->pLeft->pRight->pParent == copiedBuiltMap.bst.root->pLeft);
    assert(copiedBuiltMap.bst.root->pLeft->pRight->pRight == NULL);
    assert(copiedBuiltMap.bst.root->pLeft->pRight->pLeft == NULL);
    
    cout<<"Passed Map Constructor Tests"<<endl;
    
    /*
     * Testing map size
     */
    assert(defaultMap.size() == 0);
    assert(builtMap.size() == 6);
    builtMap.bst.numElements = 243;
    assert(builtMap.size() == 243);
    //resetting builtMap
    builtMap.bst.numElements = 6;
    
    cout<<"Passed Size Tests"<<endl;
    
    /*
     * Testing map empty
     */
    assert(defaultMap.empty() == true);
    assert(builtMap.empty() == false);
    builtMap.bst.numElements = 0;
    assert(builtMap.empty() == true);
    //resetting builtMap
    builtMap.bst.numElements = 6;
    
    cout<<"Passed Empty Tests"<<endl;
    
    /*
     * Testing map clear
     */
    unit_testing_delete_call_counter = 0;
    defaultMap.clear();
    assert(defaultMap.bst.numElements == 0);
    assert(defaultMap.bst.root == NULL);
    assert(unit_testing_delete_call_counter == 0);
    
    builtMap.clear();
    assert(builtMap.bst.numElements == 0);
    assert(builtMap.bst.root == NULL);
    assert(unit_testing_delete_call_counter == 6);
    
    cout<<"Passed Clear Tests"<<endl;
    
    
    /*
     * Testing iterator constructors
     */
    
    map<char,int>::iterator emptyIterator;
    
    assert(emptyIterator.it.ptr == NULL);
    
    
}
