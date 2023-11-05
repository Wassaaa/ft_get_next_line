/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/05 07:36:48 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *build_line(char *next_line, char *buffer, char *newline_ptr)
{
	next_line = append_str_to_str(next_line, buffer, newline_ptr - buffer + 1);
	ft_memmove(buffer, newline_ptr + 1, ft_strlen(buffer));
	if (!next_line)
		return (free_and_exit(next_line));
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_len;
	char		*next_line;
	char		*newline_ptr;

	next_line = NULL;
	if (fd < 0 || read(fd, 0, 0) == -1 || fd > MAX_FD || BUFFER_SIZE <= 0)
		return (free_and_exit(next_line));
	while (1)
	{
		if (buffer[0] == '\0')
		{
			read_len = read(fd, buffer, BUFFER_SIZE);
			if (read_len <= 0)
			{
				buffer[0] = '\0';
				return (handle_error(next_line));
			}
			buffer[read_len] = '\0';
		}
		newline_ptr = ft_strchr(buffer, '\n');
		if (newline_ptr)
			return (build_line(next_line, buffer, newline_ptr));
		next_line = build_line(next_line, buffer, ft_strchr(buffer, '\0'));
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
