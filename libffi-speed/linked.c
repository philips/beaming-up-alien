#include <stdio.h>
#include "times.h"

int main(int argc, char **argv)
{
	int i;
	int c;

	c = times(argc, argv);
	if (c < 0)
		return c;

	for (i = 0; i < c; i++) {
		puts("Hello World!\n");
	}


	return 0;
}
