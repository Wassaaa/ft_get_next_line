/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/10 17:47:38 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_exit(t_buffer *line_buffer)
{
	char	*final_line;

	final_line = NULL;
	if (line_buffer && line_buffer->data && *line_buffer->data)
	{
		final_line = my_malloc(line_buffer->length + 1);
		if (!final_line)
		{
			buffer_free(line_buffer);
			return (NULL);
		}
		ft_memmove(final_line, line_buffer->data, line_buffer->length);
		final_line[line_buffer->length] = '\0';
		buffer_free(line_buffer);
		return (final_line);
	}
	if (final_line)
		free(final_line);
	buffer_free(line_buffer);
	return (NULL);
}

static int	bad_params(int fd, char *buffer)
{
	if (fd < 0 || read(fd, 0, 0) < 0 || fd > MAX_FD || BUFFER_SIZE <= 0)
	{
		buffer[0] = '\0';
		return (1);
	}
	return (0);
}

char	*get_next_line(int fd)
{
	static char	buf[BUFFER_SIZE + 1];
	int			read_len;
	char		*nl_ptr;
	t_buffer	*line_buffer;

	if (bad_params(fd, buf))
	{
		return (NULL);
	}
	line_buffer = buffer_init(BUFFER_SIZE);
	if (!line_buffer)
		return (free_and_exit(line_buffer));
	while (1) {
		if (buf[0] == '\0')
		{
			read_len = read(fd, buf, BUFFER_SIZE);
			if (read_len <= 0)
				return (free_and_exit(line_buffer));
			buf[read_len] = '\0';
		}
		nl_ptr = ft_strchr(buf, '\n');
		if (nl_ptr) {
			if (buffer_append(line_buffer, buf, nl_ptr - buf + 1) == -1)
				return (free_and_exit(line_buffer));
			ft_memmove(buf, nl_ptr + 1, ft_strlen(nl_ptr + 1) + 1);
			break;
		} else {
			if (buffer_append(line_buffer, buf, ft_strlen(buf)) == -1)
				return (free_and_exit(line_buffer));
			buf[0] = '\0';
		}
	}
	return (free_and_exit(line_buffer));
}
