/* _PDCLIB_remove( const char * )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

/* This is an example implementation of _PDCLIB_remove() fit for use with
   POSIX kernels.
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#ifdef __cplusplus
extern "C" {
#endif

extern int unlink( const char * );

#ifdef __cplusplus
}
#endif

// Defined in cxbxrkrnl
extern void __stdcall KeBugCheckEx(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

int _PDCLIB_remove( const char * pathname )
{
    KeBugCheckEx(0x01, (unsigned int)__func__, 0, 0, 0);
    return -1;
    //return unlink( pathname );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    /* Testing covered by ftell.c (and several others) */
    return TEST_RESULTS;
}

#endif
