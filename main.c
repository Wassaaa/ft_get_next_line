#include <stdio.h>
#include "get_next_line.h"

int	main(void)
{
	int fd = open("myfile", O_RDONLY);
	int i = 0;

	while (i++ < 4)
	{
		char *test = get_next_line(fd);
		printf("line: '%s'\n", test);
		free(test);
	}
	close(fd);
}