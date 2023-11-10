/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:40 by aklein            #+#    #+#             */
/*   Updated: 2023/11/10 18:44:35 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void myfree(void *str)
{
	if (str)
	{
		free(str);
	}
}

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

t_buffer	*buffer_init(size_t initial_capacity)
{
	t_buffer *buf = my_malloc(sizeof(t_buffer));
	if (!buf)
		return (NULL);
	buf->data = my_calloc(1, initial_capacity);
	if (!buf->data)
	{
		myfree(buf);
		return (NULL);
	}
	buf->capacity = initial_capacity;
	buf->length = 0;
	return (buf);
}

int	buffer_append(t_buffer *buf, const char *src, size_t len)
{
	size_t new_capacity;
	char *new_data;

	new_capacity = buf->capacity;

	if (buf->length + len > buf->capacity) {
		while (buf->length + len > new_capacity) {
			new_capacity *= 2;
		}
		new_data = my_calloc(1, new_capacity);
		if (!new_data)
		{
			buffer_free(buf);
			return (-1);
		}
		ft_memmove(new_data, buf->data, buf->length);
		myfree(buf->data);
		buf->data = new_data;
		buf->capacity = new_capacity;
	}
	ft_memmove(buf->data + buf->length, src, len);
	buf->length += len;
	return (0);
}

void	buffer_free(t_buffer *buf)
{

	if (buf)
	{
		if (buf->data)
		{
			myfree(buf->data);
			myfree(buf);
			buf->data = NULL;
		}
		buf = NULL;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (unsigned char)c)
		s++;
	if (*s == 0 && (unsigned char)c != 0)
		return (NULL);
	return ((char *)s);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*temp;

	if ((!dst && !src) && len != 0)
		return (NULL);
	temp = dst;
	if (dst <= src)
		while (len--)
			*temp++ = *(char *)src++;
	else
	{
		temp += len;
		src += len;
		while (len--)
			*(--temp) = *(char *)(--src);
	}
	return (dst);
}
