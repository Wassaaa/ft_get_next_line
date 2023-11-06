/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 00:29:33 by aklein            #+#    #+#             */
/*   Updated: 2023/11/07 00:31:32 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(void)
{
	int		fd;
	int		i;
	char	*test;

	fd = open("myfile", O_RDONLY);
	i = 0;
	while (i++ < 4)
	{
		test = get_next_line(fd);
		printf("line: '%s'\n", test);
		free(test);
	}
	close(fd);
}
