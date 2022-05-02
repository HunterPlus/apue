#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <errno.h>
#include <unistd.h>

#define max(a,b)        ((a) > (b) ? (a) : (b))

/* error ****************************************************************
 * <stdarg.h> <errorno.h> <string.h> <stdlib.h>
 */
void err_ret(const char *fmt, ...);
void err_sys(const char *fmt, ...);
void err_dump(const char *fmt, ...);
void err_msg(const char *fmt, ...);
void err_quit(const char *fmt, ...);

