/* timespec_get( struct timespec *, int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <time.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_defguard.h"

//#include "sys/time.h"

// Defined in nboxkrnl
extern void __stdcall KeBugCheckEx(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

int timespec_get( struct timespec * ts, int base )
{
    KeBugCheckEx(0x01, (unsigned int)__func__, 0, 0, 0);
#if 0
    if ( base == TIME_UTC )
    {
        /* We can make do with a really thin wrapper here. */
        struct timeval tv;

        if ( gettimeofday( &tv, NULL ) == 0 )
        {
            ts->tv_sec = tv.tv_sec;
            ts->tv_nsec = tv.tv_usec * 1000;
            return base;
        }
    }
#endif
    /* Not supporting any other time base than TIME_UTC for now. */
    return 0;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    TESTCASE( NO_TESTDRIVER );
    return TEST_RESULTS;
}

#endif
