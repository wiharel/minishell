/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <wiharel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 13:11:39 by wiharel           #+#    #+#             */
/*   Updated: 2022/01/05 13:23:26 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *string_left, char *buffer)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	if (!string_left)
	{
		string_left = malloc(sizeof(char) * 1);
		string_left[0] = '\0';
	}
	if (!buffer || !string_left)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(buffer) + 1)
				+ ft_strlen(string_left)));
	if (str == 0)
		return (NULL);
	if (string_left)
		while (string_left[++i] != '\0')
			str[i] = string_left[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_strlen(string_left) + ft_strlen(buffer)] = '\0';
	free(string_left);
	return (str);
}

char	*ft_new_string_left(char *string_left)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (string_left[i] != '\n' && string_left[i])
		i++;
	if (!string_left[i])
	{
		free(string_left);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(string_left) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (string_left[i])
		str[j++] = string_left[i++];
	str[j] = '\0';
	free(string_left);
	return (str);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_get_line(char *string_left)
{
	char	*str;
	int		i;

	i = 0;
	if (!string_left[i])
		return (NULL);
	while (string_left[i] != '\n' && string_left[i])
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (string_left[i] != '\n' && string_left[i])
	{
		str[i] = string_left[i];
		i++;
	}
	if (string_left[i] == '\n')
	{
		str[i] = string_left[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}	
