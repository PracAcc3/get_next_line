/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:18:16 by synoshah          #+#    #+#             */
/*   Updated: 2025/09/13 17:34:04 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*join_and_free(char *stash, char *buf)
{
	char	*tmp;

	if (!stash)
		return (ft_strdup(buf));
	tmp = alt_strjoin(stash, buf);
	free(stash);
	return (tmp);
}

/* Helper function: extract one line from stash */
static char	*extract_line(char **stash)
{
	char	*line;
	char	*nl;
	size_t	len;
	char	*tmp;

	if (!*stash || !**stash)
		return (NULL);
	nl = ft_strchr(*stash, '\n');
	len = nl ? nl - *stash + 1 : ft_strlen(*stash);
	line = (char *)malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, *stash, len + 1);
	/* Update stash */
	if (nl)
	{
		tmp = ft_strdup(nl + 1);
		free(*stash);
		*stash = tmp;
	}
	else
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

/* Helper function: read from fd and join to stash */
static char	*read_and_join(int fd, char *stash)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	r;

	while (!ft_strchr(stash, '\n'))
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r <= 0)
			break ;
		buf[r] = '\0';
		stash = join_and_free(stash, buf);
		if (!stash)
			return (NULL);
	}
	return (stash);
}

/* Main function */
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_join(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(&stash);
	return (line);
}
