/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:18:16 by synoshah          #+#    #+#             */
/*   Updated: 2025/09/13 19:20:08 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*append_buffer_and_free(char *saved_text, char *buffer)
{
	char	*combined_text;

	if (!buffer || !*buffer)
		return (saved_text);
	if (!saved_text)
		return (ft_strdup(buffer));
	combined_text = alt_strjoin(saved_text, buffer);
	free(saved_text);
	return (combined_text);
}

static char	*extract_line_from_saved_text(char *saved_text)
{
	char	*newline_position;
	char	*line;
	size_t	line_length;

	if (!saved_text || !*saved_text)
		return (NULL);
	newline_position = ft_strchr(saved_text, '\n');
	if (newline_position)
		line_length = newline_position - saved_text + 1;
	else
		line_length = ft_strlen(saved_text);
	line = malloc(line_length + 1);
	if (!line)
		return (NULL);
	ft_strlcpy(line, saved_text, line_length + 1);
	return (line);
}

static void	update_saved_text(char **saved_text)
{
	char	*newline_position;
	char	*remaining_text;

	if (!*saved_text)
		return ;
	newline_position = ft_strchr(*saved_text, '\n');
	if (!newline_position || !*(newline_position + 1))
		remaining_text = NULL;
	else
		remaining_text = ft_strdup(newline_position + 1);
	free(*saved_text);
	*saved_text = remaining_text;
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
			saved_text = append_buffer_and_free(saved_text, buffer);
			if (!saved_text)
				return (NULL);
		}
	}
	return (saved_text);
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
	line = extract_line_from_saved_text(saved_text);
	if (!line)
	{
		free(saved_text);
		saved_text = NULL;
		return (NULL);
	}
	update_saved_text(&saved_text);
	return (line);
}
