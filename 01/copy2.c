#include "lib.h"

int main()
{
	int	c;
	
	while ((c = getc(stdin)) != EOF)
		putc(c, stdout);
	exit(0);	/* return 0;	*/
}
