/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:37 by aklein            #+#    #+#             */
/*   Updated: 2023/11/10 18:40:57 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define MAX_FD 1024

static void* my_malloc(size_t size) {
	// static int counter = 0;
	// counter++;

	// // Fail every Nth allocation for testing
    // if (counter % 20000 == 0) {
	// 	return NULL;
	// }

	return malloc(size);
}

static void* my_calloc(size_t count, size_t size) {
	// static int counter = 0;
	// counter++;

	// // Fail every Nth allocation for testing
    // if (counter % 20000 == 0) {
	// 	return NULL;
	// }

	return calloc(count, size);
}

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
void		myfree(void *str);

#endif
