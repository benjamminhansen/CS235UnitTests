/*
 * main.cpp
 *
 *  Created by Lee Barney on 11/10/18.
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
#include "hash.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::ios;
using std::string;
using namespace custom;

/*
 * What you will be implementing by conforming to these unit
 * tests is a hash set.
 */


/*
 * Hashing Functions to Use
 */
long hashInt(const int& aValue, int theBucketCount)
{
    return abs(aValue) % theBucketCount;
}

//This string hashing function was first reported by Dan Bernstein in the news group comp.lang.c
//this string hashing function is often called djb2.
long hashString(const string& aValue, int theBucketCount)
{
    const char* str = aValue.c_str();
    unsigned long hash = 5381;//seed value
    int accumulator;
    while ((accumulator = *str++))
    {
        hash = ((hash << 5) + hash) + accumulator; /* hash * 32 + accumulator */
    }
    return hash % theBucketCount;
}

int main(int argc, const char * argv[])
{
    /*
     * Testing constructors
     */
    
    try {
        Hash<int> zeroHash(-2);
        assert(false);
    } catch (const char* message) {
        cout<<message<<endl;
        assert(strcmp(message, "Error: Hashes must have at least 1 bucket.") == 0);
    }
    
    try {
        Hash<int> zeroHash(0);
        assert(false);
    } catch (const char* message) {
        assert(strcmp(message, "Error: Hashes must have at least 1 bucket.") == 0);
    }
    
    Hash<int>degenerateHash(1);//same behavior as a list
    assert(degenerateHash.numBuckets == 1);
    assert(degenerateHash.numElements == 0);
    assert(degenerateHash.table != NULL);
    assert(degenerateHash.table[0]->numElements == 0);
    assert(degenerateHash.table[0]->pHead == NULL);
    assert(degenerateHash.table[0]->pTail == NULL);
    
    Hash<int> tenHash(10);
    assert(tenHash.numBuckets == 10);
    assert(tenHash.numElements == 0);
    assert(tenHash.table != NULL);
    assert(tenHash.table[0]->numElements == 0);
    assert(tenHash.table[0]->pHead == NULL);
    assert(tenHash.table[0]->pTail == NULL);
    assert(tenHash.table[1]->numElements == 0);
    assert(tenHash.table[1]->pHead == NULL);
    assert(tenHash.table[1]->pTail == NULL);
    assert(tenHash.table[2]->numElements == 0);
    assert(tenHash.table[2]->pHead == NULL);
    assert(tenHash.table[2]->pTail == NULL);
    assert(tenHash.table[3]->numElements == 0);
    assert(tenHash.table[3]->pHead == NULL);
    assert(tenHash.table[3]->pTail == NULL);
    assert(tenHash.table[4]->numElements == 0);
    assert(tenHash.table[4]->pHead == NULL);
    assert(tenHash.table[4]->pTail == NULL);
    assert(tenHash.table[5]->numElements == 0);
    assert(tenHash.table[5]->pHead == NULL);
    assert(tenHash.table[5]->pTail == NULL);
    assert(tenHash.table[6]->numElements == 0);
    assert(tenHash.table[6]->pHead == NULL);
    assert(tenHash.table[6]->pTail == NULL);
    assert(tenHash.table[7]->numElements == 0);
    assert(tenHash.table[7]->pHead == NULL);
    assert(tenHash.table[7]->pTail == NULL);
    assert(tenHash.table[8]->numElements == 0);
    assert(tenHash.table[8]->pHead == NULL);
    assert(tenHash.table[8]->pTail == NULL);
    assert(tenHash.table[9]->numElements == 0);
    assert(tenHash.table[9]->pHead == NULL);
    assert(tenHash.table[9]->pTail == NULL);
    
    cout<<"Passed Hash Constructor Tests"<<endl;
    
    /*
     * Testing Hash Destructor
     */
    
    Hash<int>* singleBucketNoValuesHash = new Hash<int>(1);
    unit_testing_delete_call_counter = 0;
    delete singleBucketNoValuesHash;
    assert(unit_testing_delete_call_counter == 2);
    
    Hash<int>* multipleBucketsMultipleValuesHash = new Hash<int>(3);
    //simulate inserting 8, 7, 3, 9.
    multipleBucketsMultipleValuesHash->table[2]->pHead= new list<long>::node(8);
    multipleBucketsMultipleValuesHash->table[1]->pHead= new list<long>::node(7);
    multipleBucketsMultipleValuesHash->table[0]->pHead= new list<long>::node(3);
    multipleBucketsMultipleValuesHash->table[0]->pHead= new list<long>::node(9);
    unit_testing_delete_call_counter = 0;
    delete multipleBucketsMultipleValuesHash;
    //The list implementation you did is a shallow copy.
    assert(unit_testing_delete_call_counter == 8);
    
    cout<<"Passed Hash Destructor Tests"<<endl;
    
    /*
     * Testing hash size
     */
    
    Hash<int>simpleHash(1);
    simpleHash.numElements = 15;
    assert(simpleHash.size() == 15);
    
    cout<<"Passed Hash Size Tests"<<endl;
    
    /*
     * Testing hash empty
     */
    assert(simpleHash.empty() == false);
    //resetting simpleHash
    simpleHash.numElements = 0;
    assert(simpleHash.empty() == true);
    
    cout<<"Passed Hash Empty Tests"<<endl;
    
    /*
     * Testing hash capacity
     */
    //resetting simpleHash
    simpleHash.numElements = 0;
    simpleHash.numBuckets = 0;
    assert(simpleHash.capacity() == 0);
    simpleHash.numBuckets = 1000;
    assert(simpleHash.capacity() == 1000);
    
    cout<<"Passed Hash Capacity Tests"<<endl;
    
    /*
     * Testing copy constructor
     */
    
    Hash<int>emptyHashToCopy(1);
    Hash<int>copyOfEmptyHash(emptyHashToCopy);
    assert(copyOfEmptyHash.numElements == 0);
    assert(copyOfEmptyHash.numBuckets == 1);
    assert(copyOfEmptyHash.table[0]->pTail == NULL);
    assert(copyOfEmptyHash.table[0]->pHead == NULL);
    
    Hash<int> hashToCopy(5);
    //simulate inserting 8, 7, 3, 9.
    hashToCopy.numBuckets = 5;
    hashToCopy.numElements = 4;
    hashToCopy.table[3]->pHead = new list<long>::node(8);
    hashToCopy.table[2]->pHead = new list<long>::node(7);
    hashToCopy.table[3]->pHead->pNext = new list<long>::node(3);
    hashToCopy.table[4]->pHead = new list<long>::node(9);
    
    Hash<int> copiedHash(hashToCopy);
    assert(copiedHash.numBuckets == 5);
    assert(copiedHash.numElements == 4);
    assert(copiedHash.table[0]->pHead == NULL);
    assert(copiedHash.table[0]->pTail == NULL);
    assert(copiedHash.table[1]->pHead == NULL);
    assert(copiedHash.table[1]->pTail == NULL);
    assert(*(copiedHash.table[2]->pHead->data) = 7);
    assert(*(copiedHash.table[2]->pTail->data) = 7);
    assert(*(copiedHash.table[3]->pHead->data) = 8);
    assert(*(copiedHash.table[3]->pTail->pNext->data) = 3);
    assert(*(copiedHash.table[4]->pHead->data) = 9);
    assert(*(copiedHash.table[4]->pTail->data) = 9);
    
    cout<<"Passed Copy Constructor Tests"<<endl;
    
    /*
     * Testing assignment operator
     */
    Hash<int> assignFrom(3);
    //simulate inserting 8, 7, 3, 9.
    assignFrom.table[2]->pHead= new list<long>::node(8);
    assignFrom.table[1]->pHead= new list<long>::node(7);
    assignFrom.table[0]->pHead= new list<long>::node(3);
    assignFrom.table[0]->pHead->pNext= new list<long>::node(9);
    
    Hash<int>emptyAssignTo(5);
    unit_testing_delete_call_counter = 0;
    emptyAssignTo = assignFrom;
    assert(unit_testing_delete_call_counter == 5);
    assert(emptyAssignTo.numElements == 4);
    assert(emptyAssignTo.numBuckets == 3);
    assert(emptyAssignTo.table[0] != NULL);
    assert(*(emptyAssignTo.table[0]->pHead->data) == 3);
    assert(emptyAssignTo.table[0]->pHead->pNext != NULL);
    assert(*(emptyAssignTo.table[0]->pHead->pNext->data) == 9);
    
    assert(emptyAssignTo.table[1] != NULL);
    assert(*(emptyAssignTo.table[1]->pHead->data) == 7);
    
    assert(emptyAssignTo.table[2] != NULL);
    assert(*(emptyAssignTo.table[2]->pHead->data) == 8);

    Hash<int>emptyToAssign(1);
    
    Hash<int> filledAssignTo(3);
    //simulate inserting 8, 7, 3, 9.
    filledAssignTo.table[2]->pHead= new list<long>::node(8);
    filledAssignTo.table[1]->pHead= new list<long>::node(7);
    filledAssignTo.table[0]->pHead= new list<long>::node(3);
    filledAssignTo.table[0]->pHead->pNext= new list<long>::node(9);
    
    unit_testing_delete_call_counter = 0;
    filledAssignTo = emptyAssignTo;
    assert(unit_testing_delete_call_counter == 7);
    assert(filledAssignTo.numElements == 0);
    assert(filledAssignTo.numBuckets == 1);
    assert(filledAssignTo.table[0]->pHead == NULL);
    assert(filledAssignTo.table[0]->pTail == NULL);
    
    cout<<"Passed Assignment Operator Tests"<<endl;
    
}
