/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/05 02:53:52 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*next_line;
	static int	bytes_read = 0;
	static int	len = 0;
	static char	*line_start;
	int			nl;

	nl = 0;
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	next_line = NULL;
	while (1)
	{
		if (!bytes_read)
		{
			buffer = malloc(BUFFER_SIZE + 1);
			if (!buffer)
				return (NULL);
			line_start = buffer;
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			buffer[bytes_read] = '\0';
			len = 0;
		}
		if (bytes_read == 0 && len == 0)
			break ;
		while (bytes_read)
		{
			--bytes_read;
			if (*buffer == '\n' || !bytes_read)
			{
				if (*buffer == '\n')
					nl = 1;
				len++;
				next_line = append_str_to_str(next_line, line_start, len);
				if (!next_line)
				{
					free(buffer);
					return (NULL);
				}
				len = 0;
				line_start = ++buffer;
				if (nl)
					return (next_line);
				continue ;
			}
			buffer++;
			len++;
		}
		next_line = append_str_to_str(next_line, buffer, len);
		free(buffer);
	}
	return (next_line);
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
