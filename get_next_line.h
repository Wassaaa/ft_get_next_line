/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:37 by aklein            #+#    #+#             */
/*   Updated: 2023/11/08 17:47:02 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

# define MAX_FD 1024

typedef struct s_buffer {
	char	*data;
	size_t	capacity;
	size_t	length;
}			t_buffer;

int			ft_strlen(const char *str);
char		*get_next_line(int fd);
char		*append_str_to_str(char *str, char *src, int len);
char		*ft_strchr(const char *s, int c);
void		*ft_memmove(void *dst, const void *src, size_t len);
t_buffer	*buffer_init(size_t initial_capacity);
int			buffer_append(t_buffer *buf, const char *src, size_t len);
void		buffer_free(t_buffer *buf);

#endif
