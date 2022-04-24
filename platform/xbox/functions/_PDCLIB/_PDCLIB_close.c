/* _PDCLIB_close( _PDCLIB_fd_t )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an example implementation of _PDCLIB_close() fit for use with POSIX
   kernels.
*/

#include <stdio.h>
#include <assert.h>

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int close( int fd );

#ifdef __cplusplus
}
#endif

int _PDCLIB_close( int fd )
{
    _PDCLIB_assert89(__func__);
    return -1;
    //return close( fd );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    /* No testdriver; tested in driver for _PDCLIB_open(). */
    return TEST_RESULTS;
}

#endif
