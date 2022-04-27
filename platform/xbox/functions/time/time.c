/* time( time_t * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <time.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_defguard.h"

//#include "sys/time.h"

/* See comments in _PDCLIB_config.h on the semantics of time_t. */

// Defined in cxbxrkrnl
extern void __stdcall KeBugCheckEx(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

time_t time( time_t * timer )
{
    KeBugCheckEx(0xFFFF, (unsigned int)__func__, 0, 0, 0);
#if 0
    struct timeval tv;

    if ( gettimeofday( &tv, NULL ) == 0 )
    {
        if ( timer != NULL )
        {
            *timer = tv.tv_sec;
        }

        return tv.tv_sec;
    }
#endif
    return -1;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    time_t t = time( NULL );
    printf( "%d\n", (int)t );
    TESTCASE( NO_TESTDRIVER );
    return TEST_RESULTS;
}

#endif
