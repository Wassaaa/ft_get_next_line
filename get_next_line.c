/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/04 03:06:13 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char *append_str_to_str(char *str, char *src, int len)
{
	char	*new_str;
	int		i;

	new_str = malloc(1 + len + ft_strlen(str));
	if (!new_str)
		return (NULL);
	i = 0;
	while (str != NULL && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	while (*src && len--)
	{
		new_str[i] = *src;
		src++;
		i++;
	}
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*get_next_line(int fd)
{
	int			line_size;
	int			bytes_read;
	char		buffer[BUFFER_SIZE];
	char		curr_char;
	char		*next_line;

	// next_line = malloc(1);
	// if (!next_line)
	// 	return (NULL);
	// next_line[0] = '\0';
	next_line = NULL;
	read(fd, &curr_char, 1);
	line_size = 0;
	while (curr_char != '\n')
	{
		buffer[line_size] = curr_char;
		bytes_read = read(fd, &curr_char, 1);
		if (!bytes_read && !line_size)
			break ;
		line_size++;
		if (line_size == BUFFER_SIZE || bytes_read <= 0 || curr_char == '\n')
		{
			if (curr_char == '\n')
				buffer[line_size++] = '\n';
			next_line = append_str_to_str(next_line, buffer, line_size);
			if (!next_line)
				return (NULL);
			line_size = 0;
		}
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