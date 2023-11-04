/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/04 20:01:03 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*next_line;
	static int	bytes_read = 0;
	static int	len = 0;
	static int	start = 0;
	int			found_nl;

	found_nl = 0;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	next_line = NULL;
	while (bytes_read == 0 || start == 0)
	{
		if (!bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			start = 0;
			len = 0;
		}
		if (bytes_read == 0 && len == 0)
			break ;
		while (bytes_read)
		{
			if (buffer[start + len] == '\n' || !bytes_read)
			{
				if (buffer[start + len] == '\n')
					len++;
				next_line = append_str_to_str(next_line, (char *)(buffer + start), len + 1);
				if (!next_line)
					return (NULL);
				start += len;
				len = 0;
			}
			len++;
			bytes_read--;
		}
		next_line = append_str_to_str(next_line, buffer, len);
	}
	return (next_line);
}

#include <stdio.h>

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
