/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/07 00:08:17 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_exit(char *next_line, char * buffer, int handle_err)
{
	if (handle_err)
	{
		buffer[0] = '\0';
		if (next_line && *next_line)
			return (next_line);
	}
	if (next_line)
		free(next_line);
	return (NULL);
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

static char	*build_line(char *next_line, char *buffer, char *nl_ptr)
{
	int	bytes_to_move;

	bytes_to_move = 0;
	if (!*nl_ptr)
		next_line = append_str_to_str(next_line, buffer, nl_ptr - buffer);
	else
		next_line = append_str_to_str(next_line, buffer, nl_ptr - buffer + 1);
	if (!*nl_ptr)
		buffer[0] = '\0';
	else
		bytes_to_move = ft_strlen(nl_ptr + 1) + 1;
	ft_memmove(buffer, nl_ptr + 1, bytes_to_move);
	if (!next_line)
		return (free_and_exit(next_line, buffer, 0));
	return (next_line);
}

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	int			read_len;
	char		*next_line;
	char		*nl_ptr;

	next_line = NULL;
	if (bad_params(fd, buffer))
		return (NULL);
	while (1)
	{
		if (buffer[0] == '\0')
		{
			read_len = read(fd, buffer, BUFFER_SIZE);
			if (read_len <= 0)
				return (free_and_exit(next_line, buffer, 1));
			buffer[read_len] = '\0';
		}
		nl_ptr = ft_strchr(buffer, '\n');
		if (nl_ptr)
			return (build_line(next_line, buffer, nl_ptr));
		next_line = build_line(next_line, buffer, ft_strchr(buffer, '\0'));
	}
}
