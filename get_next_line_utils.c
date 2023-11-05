/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aklein <aklein@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 00:03:40 by aklein            #+#    #+#             */
/*   Updated: 2023/11/05 02:33:38 by aklein           ###   ########.fr       */
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

char *append_str_to_str(char *str, char *src, int len)
{
	char	*new_str;
	int		i;

	new_str = malloc(len + ft_strlen(str) + 1);
	if (!new_str)
	{
		free(str);
		return (NULL);
	}
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
