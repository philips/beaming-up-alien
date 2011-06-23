#include <stdio.h>

static int times(int argc, char **argv)
{
	if (argc < 1 || argc > 2) {
		printf("usage: %s count\n", argv[0]);
		return -1;
	}
	return 1 << atoi(argv[1]);
}
