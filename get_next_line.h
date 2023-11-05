/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:37 by aklein            #+#    #+#             */
/*   Updated: 2023/11/05 07:33:18 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/resource.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif

# define MAX_FD RLIMIT_NOFILE

int		ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*append_str_to_str(char *str, char *src, int len);
char	*ft_strchr(const char *s, int c);
void	*ft_memmove(void *dst, const void *src, size_t len);
char	*free_and_exit(char *next_line);
char	*handle_error(char *next_line);

#endif
