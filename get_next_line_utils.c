/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:18:19 by synoshah          #+#    #+#             */
/*   Updated: 2025/09/13 19:19:46 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	char	*dup;
	size_t	index;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	index = 0;
	while (index < len)
	{
		dup[index] = s[index];
		index++;
	}
	dup[index] = '\0';
	return (dup);
}

char	*ft_strchr(const char *str, char c)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return ((char *)str);
		str++;
	}
	if (c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;

	index = 0;
	if (!dst || !src)
		return (0);
	if (size > 0)
	{
		while (src[index] && index + 1 < size)
		{
			dst[index] = src[index];
			index++;
		}
		dst[index] = '\0';
	}
	return (index);
}

char	*alt_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i1;
	size_t	i2;
	char	*new_string;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_string = malloc(len1 + len2 + 1);
	if (!new_string)
		return (NULL);
	i1 = 0;
	while (i1 < len1)
	{
		new_string[i1] = s1[i1];
		i1++;
	}
	i2 = 0;
	while (i2 < len2)
		new_string[i1++] = s2[i2++];
	new_string[i1] = '\0';
	return (new_string);
}
