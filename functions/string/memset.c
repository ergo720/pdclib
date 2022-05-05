/* memset_( void *, int, size_t )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <string.h>

#ifndef REGTEST

// Disable global optimizations. This is necessary because here, msvc decides to replace this function with a call to its intrinsic version,
// which can't work because of the /NODEFAULTLIB option and it will cause a linking error
#pragma optimize("g", off)
void * memset_( void * s, int c, size_t n )
{
    unsigned char * p = ( unsigned char * ) s;

    while ( n-- )
    {
        *p++ = ( unsigned char ) c;
    }

    return s;
}
#pragma optimize("g", on)
#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    char s[] = "xxxxxxxxx";
    TESTCASE( memset_( s, 'o', 10 ) == s );
    TESTCASE( s[9] == 'o' );
    TESTCASE( memset_( s, '_', ( 0 ) ) == s );
    TESTCASE( s[0] == 'o' );
    TESTCASE( memset_( s, '_', 1 ) == s );
    TESTCASE( s[0] == '_' );
    TESTCASE( s[1] == 'o' );
    return TEST_RESULTS;
}

#endif
