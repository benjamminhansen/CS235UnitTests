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
    //resetting lesser and greater pairs
    lesserPair.first = ' ';
    greaterPair.second = 18;
    //testing comparing to self
    assert(!(greaterPair > greaterPair));
    assert(!(defaultPair > defaultPair));
    
    cout<<"Passed > Operator Tests"<<endl;
    
    /*
     * Testing < operator
     */
    
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
    
    
    /*
     * Testing Map Constructors
     */
    map<char,int> aMap;
    assert(aMap.bst.numElements == 0);
    assert(aMap.bst.root == NULL);
}
