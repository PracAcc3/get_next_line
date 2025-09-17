/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:26:33 by synoshah          #+#    #+#             */
/*   Updated: 2025/09/17 17:46:48 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (str == NULL)
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

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
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

char	*ft_strchr(const char *s, char c)
{
	if (s == NULL)
		return (NULL);
	while (*s)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (src == NULL)
		return (0);
	if (size > 0)
	{
		while (src[i] && i + 1 < size)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len1;
	size_t	len2;
	size_t	i;
	char	*new_string;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_string = malloc(len1 + len2 + 1);
	if (new_string == NULL)
		return (NULL);
	i = 0;
	while (*s1)
	{
		new_string[i] = *s1++;
		i++;
	}
	while (*s2)
	{
		new_string[i] = *s2++;
		i++;
	}
	new_string[i] = '\0';
	return (new_string);
}
