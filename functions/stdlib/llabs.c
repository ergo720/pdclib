/* llabs_( long int )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdlib.h>

#ifndef REGTEST

long long int llabs_( long long int j )
{
    return ( j >= 0 ) ? j : -j;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

#include <limits.h>

int main( void )
{
    TESTCASE( llabs_( 0ll ) == 0 );
    TESTCASE( llabs_( LLONG_MAX ) == LLONG_MAX );
    TESTCASE( llabs_( LLONG_MIN + 1 ) == -( LLONG_MIN + 1 ) );
    return TEST_RESULTS;
}

#endif
