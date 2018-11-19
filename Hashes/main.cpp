/*
 * main.cpp
 *
 *  Created by Lee Barney on 11/1/18.
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
 * Hashing Functions to Use
 */
int hashInt(const int& aValue, int theBucketCount){
    return abs(aValue) % theBucketCount;
}
int hashString(const string& aValue, int theBucketCount){
    const char* str = aValue.c_str();
    unsigned long hash = 5381;//seed value
    int accumulator;
    
    while ((accumulator = *str++))
        hash = ((hash << 5) + hash) + accumulator; /* hash * 32 + accumulator */
    
    return hash % theBucketCount;
}

int main(int argc, const char * argv[]) {
    Hash<int> aHash(10);
    aHash.insert(4, hashInt);
    
}
