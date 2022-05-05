/* _PDCLIB_realpath( const char * path )

   This file is part of the Public Domain C Library (PDCLib).
   Permission is granted to use, modify, and / or redistribute at will.
*/

#ifndef REGTEST

#include "pdclib/_PDCLIB_glue.h"

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

extern char * realpath( const char * file_name, char * resolved_name );

#ifdef __cplusplus
}
#endif

// Defined in cxbxrkrnl
extern void __stdcall KeBugCheckEx(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int);

char * _PDCLIB_realpath( const char * path )
{
    KeBugCheckEx(0x01, (unsigned int)__func__, 0, 0, 0);
    return NULL;
    //return realpath( path, NULL );
}

#endif

#ifdef TEST

#include "_PDCLIB_test.h"

int main( void )
{
    /* No test drivers. */
    return TEST_RESULTS;
}

#endif
