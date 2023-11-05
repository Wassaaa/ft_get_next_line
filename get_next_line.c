/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/05 07:59:37 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_exit(char *next_line)
{
	if (next_line)
		free(next_line);
	return (NULL);
}

static char	*handle_error(char *next_line)
{
	if (next_line && *next_line)
		return (next_line);
	else
		return (free_and_exit(next_line));
}

static int	bad_params(int fd, char *buffer)
{
	if (fd < 0 || read(fd, 0, 0) == -1 || fd > MAX_FD || BUFFER_SIZE <= 0)
	{
		buffer[0] = '\0';
		return (1);
	}
	return (0);
}

static char	*build_line(char *next_line, char *buffer, char *newline_ptr)
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
	if (bad_params(fd, buffer))
		return (NULL);
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
