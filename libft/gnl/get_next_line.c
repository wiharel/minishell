/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:11:14 by wiharel           #+#    #+#             */
/*   Updated: 2022/01/05 13:16:45 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_string_left(int fd, char *string_left)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (i != 0 && !ft_strchr(string_left, '\n'))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		string_left = ft_strjoin(string_left, buffer);
	}
	free(buffer);
	return (string_left);
}

char	*get_next_line(int fd)
{
	static char	*string_left;
	char		*l;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	string_left = ft_string_left(fd, string_left);
	if (!string_left)
		return (NULL);
	l = ft_get_line(string_left);
	string_left = ft_new_string_left(string_left);
	return (l);
}
