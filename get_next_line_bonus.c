/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 13:26:46 by synoshah          #+#    #+#             */
/*   Updated: 2025/09/17 15:39:29 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_line_length(char *saved)
{
	char	*newline_pos;

	newline_pos = ft_strchr(saved, '\n');
	if (newline_pos)
		return (newline_pos - saved + 1);
	return (ft_strlen(saved));
}

static char	*append_saved(char *saved, char *buf)
{
	char	*temp;

	if (saved == NULL)
		temp = ft_strdup(buf);
	else
		temp = ft_strjoin(saved, buf);
	free(saved);
	return (temp);
}

static char	*read_file_and_append(int fd, char *saved)
{
	char	buf[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (ft_strchr(saved, '\n') == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			if (saved != NULL)
				free(saved);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		if (bytes_read > 0)
			saved = append_saved(saved, buf);
	}
	return (saved);
}

static char	*get_line_and_update_saved(char **saved)
{
	char	*line;
	char	*rest;
	size_t	line_len;
	char	*newline_pos;

	if (*saved == NULL)
		return (NULL);
	line_len = get_line_length(*saved);
	line = malloc(line_len + 1);
	if (line == NULL)
		return (free(*saved), *saved = NULL, NULL);
	ft_strlcpy(line, *saved, line_len + 1);
	newline_pos = ft_strchr(*saved, '\n');
	if (newline_pos != NULL && *(newline_pos + 1) != '\0')
		rest = ft_strdup(newline_pos + 1);
	else
		rest = NULL;
	free(*saved);
	*saved = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved_text[10240];
	char		*line;

	if (fd < 0 || fd >= 10240 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_text[fd] = read_file_and_append(fd, saved_text[fd]);
	if (saved_text[fd] == NULL)
		return (NULL);
	line = get_line_and_update_saved(&saved_text[fd]);
	return (line);
}
