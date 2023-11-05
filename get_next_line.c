/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/05 05:24:38 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	len = 0;
	char		*next_line;
	char		*newline_ptr;

	next_line = NULL;
	if (fd < 0 || read(fd, 0, 0) == -1)
		return (free_and_exit(&next_line, &len));
	while (1)
	{
		if (len == 0)
		{
			len = read(fd, buffer, BUFFER_SIZE);
			if (len <= 0)
			{
				if (next_line && *next_line)
					return (next_line);
				else
					return (free_and_exit(&next_line, &len));
			}
			else if (len == 0 && !next_line)
				return (free_and_exit(&next_line, &len));
		}
		newline_ptr = ft_strchr(buffer, '\n');
		if (newline_ptr)
		{
			next_line = append_str_to_str(next_line, buffer, newline_ptr - buffer + 1);
			ft_memmove(buffer, newline_ptr + 1, len - (newline_ptr - buffer));
			len -= (newline_ptr - buffer + 1);
			return (next_line);
		}
		else
		{
			next_line = append_str_to_str(next_line, buffer, len);
			len = 0;
		}
	}
}

// #include <stdio.h>

// int	main(void)
// {
// 	int fd = open("myfile", O_RDONLY);
// 	int i = 0;

// 	while (i++ < 4)
// 	{
// 		char *test = get_next_line(fd);
// 		printf("line: '%s'\n", test);
// 		free(test);
// 	}
// 	close(fd);
// }
