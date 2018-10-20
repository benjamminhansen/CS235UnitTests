//
//  node_delete.h
//  junk
//
//  Created by Lee Barney on 10/20/18.
//  Copyright © 2018 Lee Barney. All rights reserved.
//

#ifndef unit_testing_delete_h
#define unit_testing_delete_h

#ifdef UNIT_TESTING

int unit_testing_delete_call_counter = 0;
void operator delete(void * p)
{
    free(p);
    unit_testing_delete_call_counter++;
}
#endif

#endif /* unit_testing_delete_h */
