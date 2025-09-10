/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:18:16 by synoshah          #+#    #+#             */
/*   Updated: 2025/09/10 18:36:41 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	*free_n_join(char *buffer, char *new)
{
	char	*temp;

	temp = alt_strjoin(buffer, new);
	free(buffer);
	return (temp);
}

int	find_new_line(char *buf, int fd)
{
	while(*buf)
	{
		ft_strchr(buf, '\n');
		buf++;
	}
	ft_calloc(1, 1);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char buffer[BUFFER_SIZE + 1];
	int bytes_read;


	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		stash = free_n_join(stash, buffer);
	}
}
