/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:42 by aklein            #+#    #+#             */
/*   Updated: 2023/11/07 23:10:01 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_and_exit(t_buffer *line_buffer, int handle_err)
{
	char	*final_line;

	if (handle_err && line_buffer)
	{
		final_line = malloc(line_buffer->length + 1);
		if (final_line)
		{
			ft_memmove(final_line, line_buffer->data, line_buffer->length);
			final_line[line_buffer->length] = '\0';
		}
		buffer_free(line_buffer);
		return (final_line);
	}
	if (line_buffer && line_buffer->data)
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

	if (bad_params(fd, buf)) {
		return (NULL);
	}
	line_buffer = buffer_init(BUFFER_SIZE);
	if (!line_buffer)
		return NULL;
	while (1) {
		if (buf[0] == '\0')
		{
			read_len = read(fd, buf, BUFFER_SIZE);
			if (read_len <= 0)
				return (free_and_exit(line_buffer, 0));
			buf[read_len] = '\0';
		}
		nl_ptr = ft_strchr(buf, '\n');
		if (nl_ptr) {
			buffer_append(line_buffer, buf, nl_ptr - buf + 1);
			ft_memmove(buf, nl_ptr + 1, ft_strlen(nl_ptr + 1) + 1);
			break;
		} else {
			buffer_append(line_buffer, buf, ft_strlen(buf));
			buf[0] = '\0';
		}
	}
	return (free_and_exit(line_buffer, 1));
}

