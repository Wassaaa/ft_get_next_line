#include "get_next_line.h"
#include <stdio.h>
int main(void)
{
	char filename[] = "testingasdwad";
	int i = 0;
	int j = 0;
	int fd;
	while (++i)
	{
		j = 0;
		while (++j < 255)
		{
		filename[i] += 1;
		fd = open(filename, O_CREAT, O_RDONLY);
		printf("%d\n", i * j);
		if (j * i == 2000)
			printf("here");
		}
	}
}