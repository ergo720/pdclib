/* labs_( long int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdlib.h>

#ifndef REGTEST

long int labs_( long int j )
{
    return ( j >= 0 ) ? j : -j;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <limits.h>

int main( void )
{
    TESTCASE( labs_( 0 ) == 0 );
    TESTCASE( labs_( LONG_MAX ) == LONG_MAX );
    TESTCASE( labs_( LONG_MIN + 1 ) == -( LONG_MIN + 1 ) );
    return TEST_RESULTS;
}

#endif
