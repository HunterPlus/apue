#include "lib.h"

/* error ***********************************************************************************************
 * <stdarg.h> <errorno.h> <string.h>
 */
static void 
err_doit(int errnoflag, const char *fmt, va_list ap)
{
        int     errno_save, n;
        char    buf[MAXLINE];

        errno_save = errno;     /* value caller might want printed */
        vsnprintf(buf, sizeof(buf), fmt, ap);
        n = strlen(buf);
        if (errnoflag)
                snprintf(buf + n, sizeof(buf) - n, ": %s", strerror(errno_save));
        strcat(buf, "\n");

        fflush(stdout);
        fputs(buf, stderr);
        fflush(stderr);
        
        return ;
}
void 
err_ret(const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_doit(1, fmt, ap);
        va_end(ap);
        return ;
}
void 
err_sys(const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_doit(1, fmt, ap);
        va_end(ap);
        exit(1);
}
void 
err_dump(const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_doit(1, fmt, ap);
        va_end(ap);
        abort();        /* dump core and terminate */
        exit(1);        /* shouldn't get here */
}
void 
err_msg(const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_doit(0, fmt, ap);
        va_end(ap);
        return ;
}
void 
err_quit(const char *fmt, ...)
{
        va_list ap;

        va_start(ap, fmt);
        err_doit(0, fmt, ap);
        va_end(ap);
        exit(1);
}

