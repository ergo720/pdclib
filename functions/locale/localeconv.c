/* localeconv( void )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <locale.h>

#ifndef REGTEST

struct lconv * localeconv( void )
{
    return _PDCLIB_lc_numeric_monetary.lconv;
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    struct lconv * lconv;
    TESTCASE( ( lconv = localeconv() ) != NULL );
    TESTCASE( strcmp_( lconv->decimal_point, "." ) == 0 );
    TESTCASE( strcmp_( lconv->thousands_sep, "" ) == 0 );
    TESTCASE( ( strcmp_( lconv->grouping, "" ) == 0 ) || ( strcmp_( lconv->grouping, "\x7f" ) == 0 ) );
    return TEST_RESULTS;
}

#endif
