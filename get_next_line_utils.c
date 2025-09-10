/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:18:19 by synoshah          #+#    #+#             */
/*   Updated: 2025/09/10 18:04:40 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*alt_strjoin(char *s1, char *s2)
{
	char	*new_str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	new_str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new_str)
		return (NULL);
	while (s1[i++])
		new_str[i] = s1[i];
	while (s2[j])
		new_str[i++] = s2[j];
	new_str[i] = '\0';
	return (free(s1), new_str);
}

void	*ft_calloc(size_t num, size_t size)
{
	void			*ptr;
	size_t			i;
	unsigned char	*p;

	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	p = ptr;
	i = 0;
	while (i < num * size)
	{
		p[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}
