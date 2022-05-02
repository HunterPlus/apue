#include "lib.h"

int main()
{
	int	n;
	char	buf[BUFSIZ];
	
	while ((n = read(0, buf, sizeof (buf))) > 0)
		if (write(1, buf, n) != n)
			err_sys("write error");
	if (n < 0)
		err_sys("read error");
	exit(0);	/* return 0;	*/
}
