/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:18:16 by synoshah          #+#    #+#             */
/*   Updated: 2025/09/13 19:40:26 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	get_line_length(char *saved_text)
{
	char	*newline_pos;

	newline_pos = ft_strchr(saved_text, '\n');
	if (newline_pos)
		return (newline_pos - saved_text + 1);
	return (ft_strlen(saved_text));
}

static char	*append_saved_text(char *saved_text, char *buffer)
{
	char	*temp;

	if (!saved_text)
		temp = ft_strdup(buffer);
	else
		temp = alt_strjoin(saved_text, buffer);
	free(saved_text);
	return (temp);
}

static char	*read_file_and_append(int fd, char *saved_text)
{
	char	buffer[BUFFER_SIZE + 1];
	ssize_t	bytes_read;

	bytes_read = 1;
	while (!ft_strchr(saved_text, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(saved_text);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		if (bytes_read > 0)
		{
			saved_text = append_saved_text(saved_text, buffer);
			if (!saved_text)
				return (NULL);
		}
	}
	return (saved_text);
}

static char	*get_line_and_update_saved(char **saved_text)
{
	char	*newline_pos;
	char	*line;
	size_t	line_len;
	char	*rest;

	if (!*saved_text || !**saved_text)
		return (NULL);
	line_len = get_line_length(*saved_text);
	line = malloc(line_len + 1);
	if (!line)
	{
		free(*saved_text);
		*saved_text = NULL;
		return (NULL);
	}
	ft_strlcpy(line, *saved_text, line_len + 1);
	newline_pos = ft_strchr(*saved_text, '\n');
	if (newline_pos && *(newline_pos + 1))
		rest = ft_strdup(newline_pos + 1);
	else
		rest = NULL;
	free(*saved_text);
	*saved_text = rest;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved_text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	saved_text = read_file_and_append(fd, saved_text);
	if (!saved_text || !*saved_text)
	{
		free(saved_text);
		saved_text = NULL;
		return (NULL);
	}
	line = get_line_and_update_saved(&saved_text);
	return (line);
}
