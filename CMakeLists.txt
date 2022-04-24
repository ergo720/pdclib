cmake_minimum_required(VERSION 3.1.3 FATAL_ERROR)

project(pdclib)

set(CMAKE_SUPPRESS_REGENERATION true)

set(CMAKE_C_STANDARD_LIBRARIES "")
foreach(flag_var
    CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
    CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)
  string(REGEX REPLACE "/RTC(su|[1su])" "" ${flag_var} "${${flag_var}}")
endforeach(flag_var)

set(PDCLIB_ROOT_DIR ${CMAKE_CURRENT_LIST_DIR})

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_compile_definitions(
 _PDCLIB_STATIC_DEFINE
 __STDC_NO_THREADS__
)

add_compile_options(
 /GS-
 /GR-
 /sdl-
 /X
 /Zc:preprocessor
 /Za
)

file (GLOB HEADERS
 "include/assert.h"
 "include/ctype.h"
 "include/errno.h"
 "include/inttypes.h"
 "include/iso646.h"
 "include/limits.h"
 "include/locale.h"
 "include/stdalign.h"
 "include/stdarg.h"
 "include/stdbool.h"
 "include/stddef.h"
 "include/stdint.h"
 "include/stdio.h"
 "include/stdlib.h"
 "include/stdnoreturn.h"
 "include/string.h"
 "include/time.h"
 "include/wctype.h"

 "platform/xbox/include/float.h"
 "platform/xbox/include/signal.h"

 "include/pdclib/_PDCLIB_glue.h"
 "include/pdclib/_PDCLIB_internal.h"
 "include/pdclib/_PDCLIB_lib_ext1.h"
 "platform/xbox/include/pdclib/_PDCLIB_config.h"
)

file (GLOB SOURCES
 "functions/ctype/isalnum.c"
 "functions/ctype/isalpha.c"
 "functions/ctype/isblank.c"
 "functions/ctype/iscntrl.c"
 "functions/ctype/isdigit.c"
 "functions/ctype/isgraph.c"
 "functions/ctype/islower.c"
 "functions/ctype/isprint.c"
 "functions/ctype/ispunct.c"
 "functions/ctype/isspace.c"
 "functions/ctype/isupper.c"
 "functions/ctype/isxdigit.c"
 "functions/ctype/tolower.c"
 "functions/ctype/toupper.c"

 "functions/inttypes/imaxabs.c"
 "functions/inttypes/imaxdiv.c"
 "functions/inttypes/strtoimax.c"
 "functions/inttypes/strtoumax.c"

 "functions/locale/localeconv.c"
 "functions/locale/setlocale.c"

 "platform/xbox/functions/signal/raise.c"
 "platform/xbox/functions/signal/signal.c"

 "functions/stdio/clearerr.c"
 "functions/stdio/fclose.c"
 "functions/stdio/feof.c"
 "functions/stdio/ferror.c"
 "functions/stdio/fflush.c"
 "functions/stdio/fgetc.c"
 "functions/stdio/fgetpos.c"
 "functions/stdio/fgets.c"
 "functions/stdio/fopen.c"
 "functions/stdio/fopen_s.c"
 "functions/stdio/fprintf.c"
 "functions/stdio/fputc.c"
 "functions/stdio/fputs.c"
 "functions/stdio/fread.c"
 "functions/stdio/freopen.c"
 "functions/stdio/freopen_s.c"
 "functions/stdio/fscanf.c"
 "functions/stdio/fseek.c"
 "functions/stdio/fsetpos.c"
 "functions/stdio/ftell.c"
 "functions/stdio/fwrite.c"
 "functions/stdio/getc.c"
 "functions/stdio/getchar.c"
 "functions/stdio/perror.c"
 "functions/stdio/printf.c"
 "functions/stdio/putc.c"
 "functions/stdio/putchar.c"
 "functions/stdio/puts.c"
 "functions/stdio/remove.c"
 "functions/stdio/rename.c"
 "functions/stdio/rewind.c"
 "functions/stdio/scanf.c"
 "functions/stdio/setbuf.c"
 "functions/stdio/setvbuf.c"
 "functions/stdio/snprintf.c"
 "functions/stdio/sprintf.c"
 "functions/stdio/sscanf.c"
 "functions/stdio/tmpfile_s.c"
 "functions/stdio/tmpnam.c"
 "functions/stdio/ungetc.c"
 "functions/stdio/vfprintf.c"
 "functions/stdio/vfscanf.c"
 "functions/stdio/vprintf.c"
 "functions/stdio/vscanf.c"
 "functions/stdio/vsnprintf.c"
 "functions/stdio/vsprintf.c"
 "functions/stdio/vsscanf.c"
 "platform/xbox/functions/stdio/tmpfile.c"

 "functions/stdlib/abort.c"
 "functions/stdlib/abort_handler_s.c"
 "functions/stdlib/abs.c"
 "functions/stdlib/at_quick_exit.c"
 "functions/stdlib/atexit.c"
 "functions/stdlib/atoi.c"
 "functions/stdlib/atol.c"
 "functions/stdlib/atoll.c"
 "functions/stdlib/bsearch.c"
 "functions/stdlib/bsearch_s.c"
 "functions/stdlib/div.c"
 "functions/stdlib/exit.c"
 "functions/stdlib/_Exit.c"
 "functions/stdlib/ignore_handler_s.c"
 "functions/stdlib/labs.c"
 "functions/stdlib/ldiv.c"
 "functions/stdlib/llabs.c"
 "functions/stdlib/lldiv.c"
 "functions/stdlib/qsort.c"
 "functions/stdlib/qsort_s.c"
 "functions/stdlib/quick_exit.c"
 "functions/stdlib/rand.c"
 "functions/stdlib/set_constraint_handler_s.c"
 "functions/stdlib/srand.c"
 "functions/stdlib/strtol.c"
 "functions/stdlib/strtoll.c"
 "functions/stdlib/strtoul.c"
 "functions/stdlib/strtoull.c"
 "platform/xbox/functions/stdlib/getenv.c"
 "platform/xbox/functions/stdlib/getenv_s.c"
 "platform/xbox/functions/stdlib/system.c"

 "functions/string/memchr.c"
 "functions/string/memcmp.c"
 "functions/string/memcpy.c"
 "functions/string/memmove.c"
 "functions/string/memset.c"
 "functions/string/strcat.c"
 "functions/string/strchr.c"
 "functions/string/strcmp.c"
 "functions/string/strcoll.c"
 "functions/string/strcpy.c"
 "functions/string/strcspn.c"
 "functions/string/strerror.c"
 "functions/string/strlen.c"
 "functions/string/strncat.c"
 "functions/string/strncmp.c"
 "functions/string/strncpy.c"
 "functions/string/strpbrk.c"
 "functions/string/strrchr.c"
 "functions/string/strspn.c"
 "functions/string/strstr.c"
 "functions/string/strtok.c"
 "functions/string/strtok_s.c"
 "functions/string/strxfrm.c"
 "functions/string/memcpy_s.c"
 "functions/string/memmove_s.c"
 "functions/string/memset_s.c"
 "functions/string/strcat_s.c"
 "functions/string/strcpy_s.c"
 "functions/string/strerror_s.c"
 "functions/string/strerrorlen_s.c"
 "functions/string/strncat_s.c"
 "functions/string/strncpy_s.c"

 "functions/time/asctime.c"
 "functions/time/asctime_s.c"
 "functions/time/ctime.c"
 "functions/time/ctime_s.c"
 "functions/time/difftime.c"
 "functions/time/gmtime.c"
 "functions/time/gmtime_s.c"
 "functions/time/localtime.c"
 "functions/time/localtime_s.c"
 "functions/time/mktime.c"
 "functions/time/strftime.c"
 "platform/xbox/functions/time/clock.c"
 "platform/xbox/functions/time/time.c"
 "platform/xbox/functions/time/timespec_get.c"

 "functions/_tzcode/_PDCLIB_gmtcheck.c"
 "functions/_tzcode/_PDCLIB_gmtsub.c"
 "functions/_tzcode/_PDCLIB_increment_overflow.c"
 "functions/_tzcode/_PDCLIB_init_ttinfo.c"
 "functions/_tzcode/_PDCLIB_localsub.c"
 "functions/_tzcode/_PDCLIB_localtime_tzset.c"
 "functions/_tzcode/_PDCLIB_mktime_tzname.c"
 "functions/_tzcode/_PDCLIB_timesub.c"
 "functions/_tzcode/_PDCLIB_tzload.c"
 "functions/_tzcode/_PDCLIB_tzparse.c"
 "functions/_tzcode/_PDCLIB_tzset_unlocked.c"
 "functions/_tzcode/_PDCLIB_update_tzname_etc.c"

 "functions/_PDCLIB/assert.c"
 "functions/_PDCLIB/errno.c"
 "functions/_PDCLIB/_PDCLIB_atomax.c"
 "functions/_PDCLIB/_PDCLIB_bigint.c"
 "functions/_PDCLIB/_PDCLIB_bigint2.c"
 "functions/_PDCLIB/_PDCLIB_bigint10.c"
 "functions/_PDCLIB/_PDCLIB_bigint32.c"
 "functions/_PDCLIB/_PDCLIB_bigint64.c"
 "functions/_PDCLIB/_PDCLIB_bigint_add.c"
 "functions/_PDCLIB/_PDCLIB_bigint_sub.c"
 "functions/_PDCLIB/_PDCLIB_bigint_cmp.c"
 "functions/_PDCLIB/_PDCLIB_bigint_invlog2.c"
 "functions/_PDCLIB/_PDCLIB_bigint_log2.c"
 "functions/_PDCLIB/_PDCLIB_bigint_mant.c"
 "functions/_PDCLIB/_PDCLIB_bigint_mul.c"
 "functions/_PDCLIB/_PDCLIB_bigint_mul_dig.c"
 "functions/_PDCLIB/_PDCLIB_bigint_div.c"
 "functions/_PDCLIB/_PDCLIB_bigint_div_dig.c"
 "functions/_PDCLIB/_PDCLIB_bigint_shl.c"
 "functions/_PDCLIB/_PDCLIB_bigint_tostring.c"
 "functions/_PDCLIB/_PDCLIB_closeall.c"
 "functions/_PDCLIB/_PDCLIB_digits.c"
 "functions/_PDCLIB/_PDCLIB_filemode.c"
 "functions/_PDCLIB/_PDCLIB_getstream.c"
 "functions/_PDCLIB/_PDCLIB_init_file_t.c"
 "functions/_PDCLIB/_PDCLIB_is_leap.c"
 "functions/_PDCLIB/_PDCLIB_isstream.c"
 "functions/_PDCLIB/_PDCLIB_load_lc_collate.c"
 "functions/_PDCLIB/_PDCLIB_load_lc_ctype.c"
 "functions/_PDCLIB/_PDCLIB_load_lc_messages.c"
 "functions/_PDCLIB/_PDCLIB_load_lc_monetary.c"
 "functions/_PDCLIB/_PDCLIB_load_lc_numeric.c"
 "functions/_PDCLIB/_PDCLIB_load_lc_time.c"
 "functions/_PDCLIB/_PDCLIB_load_lines.c"
 "functions/_PDCLIB/_PDCLIB_prepread.c"
 "functions/_PDCLIB/_PDCLIB_prepwrite.c"
 "functions/_PDCLIB/_PDCLIB_print.c"
 "functions/_PDCLIB/_PDCLIB_print_fp.c"
 "functions/_PDCLIB/_PDCLIB_print_integer.c"
 "functions/_PDCLIB/_PDCLIB_print_string.c"
 "functions/_PDCLIB/_PDCLIB_scan.c"
 "functions/_PDCLIB/_PDCLIB_seed.c"
 "functions/_PDCLIB/_PDCLIB_strtod_main.c"
 "functions/_PDCLIB/_PDCLIB_strtod_scan.c"
 "functions/_PDCLIB/_PDCLIB_strtok.c"
 "functions/_PDCLIB/_PDCLIB_strtox_main.c"
 "functions/_PDCLIB/_PDCLIB_strtox_prelim.c"
 "functions/_PDCLIB/stdarg.c"

 "platform/xbox/functions/_PDCLIB/_PDCLIB_changemode.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_close.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_Exit.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_fillbuffer.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_flushbuffer.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_open.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_realpath.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_rename.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_remove.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_seek.c"
 "platform/xbox/functions/_PDCLIB/_PDCLIB_stdinit.c"
)

source_group(TREE ${PDCLIB_ROOT_DIR} PREFIX header FILES ${HEADERS})
source_group(TREE ${PDCLIB_ROOT_DIR} PREFIX source FILES ${SOURCES})

add_library(pdclib STATIC ${HEADERS} ${SOURCES})

target_include_directories(pdclib BEFORE PRIVATE
 ${PDCLIB_ROOT_DIR}/include
 ${PDCLIB_ROOT_DIR}/platform/xbox/include
)

set_target_properties(pdclib PROPERTIES
 STATIC_LIBRARY_OPTIONS "
 /NODEFAULTLIB \
 /LTCG \
 "
)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} \
 /MTd \
 "
)

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} \
 /O2 \
 /GL \
 /MT \
 "
)
