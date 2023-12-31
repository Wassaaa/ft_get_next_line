/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:29:33 by aklein            #+#    #+#             */
/*   Updated: 2023/11/15 15:54:07 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int fd = open("test", O_RDONLY);
	int i = 0;
	char * test;

	while (i++ < 13)
	{
		test = get_next_line(fd);
		printf("%p : %s", test, test);
		free(test);
	}
	// int		fd;
	// int		fd2;

	// fd = open("test", O_RDONLY);
	// fd2 = open("file", O_RDONLY);
	// printf("line: '%s'\n", get_next_line(1001));
	// printf("line: '%s'\n", get_next_line(fd));
	// printf("line: '%s'\n", get_next_line(fd));
	// printf("line: '%s'\n", get_next_line(1002));
	// printf("line: '%s'\n", get_next_line(1003));
	// printf("line: '%s'\n", get_next_line(fd2));
	// printf("line: '%s'\n", get_next_line(fd2));
	// printf("line: '%s'\n", get_next_line(1006));
	// printf("line: '%s'\n", get_next_line(1007));
	// printf("line: '%s'\n", get_next_line(1008));
	// printf("line: '%s'\n", get_next_line(1009));
}
