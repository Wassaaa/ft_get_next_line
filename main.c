/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:29:33 by aklein            #+#    #+#             */
/*   Updated: 2023/11/07 20:44:10 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		fd2;

	fd = open("myfile", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	printf("line: '%s'\n", get_next_line(fd));
	printf("line: '%s'\n", get_next_line(fd));
	printf("line: '%s'\n", get_next_line(1002));
	printf("line: '%s'\n", get_next_line(1003));
	printf("line: '%s'\n", get_next_line(fd2));
	printf("line: '%s'\n", get_next_line(fd2));
	printf("line: '%s'\n", get_next_line(1006));
	printf("line: '%s'\n", get_next_line(1007));
	printf("line: '%s'\n", get_next_line(1008));
	printf("line: '%s'\n", get_next_line(1009));
}
