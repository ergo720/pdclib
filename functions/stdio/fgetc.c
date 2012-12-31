/* $Id$ */

/* fgetc( FILE * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#include <stdio.h>

#ifndef REGTEST
#include <_PDCLIB_io.h>

int fgetc_unlocked( FILE * stream )
{
    if ( _PDCLIB_prepread( stream ) == EOF )
    {
        return EOF;
    }

    char c;

    size_t n = _PDCLIB_getchars( &c, 1, EOF, stream );

    return n == 0 ? EOF : (unsigned char) c;
}

int fgetc( FILE * stream )
{
    flockfile( stream );
    int c = fgetc_unlocked( stream );
    funlockfile( stream );
    return c;
}

#endif

#ifdef TEST
#include <_PDCLIB_test.h>

int main( void )
{
    /* Testing covered by ftell.c */
    return TEST_RESULTS;
}

#endif
