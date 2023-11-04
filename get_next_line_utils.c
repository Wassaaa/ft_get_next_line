/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:40 by aklein            #+#    #+#             */
/*   Updated: 2023/11/04 03:21:07 by aklein           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char *append_str_to_str(char *str, char *src, int len)
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

void	construct_line(char **next_line, char *buffer, int *line_size, char curr_char)
{
	if (curr_char == '\n')
		buffer[*(line_size++)] = '\n';
	*next_line = append_str_to_str(*next_line, buffer, *line_size);
	*line_size = 0;
}