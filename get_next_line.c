/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synoshah <synoshah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 14:18:16 by synoshah          #+#    #+#             */
/*   Updated: 2025/08/28 20:43:41 by synoshah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_stash(int fd, char *stash)
{
    char buf[BUFFER_SIZE];

    BUFFER_SIZE + 1;
}

char	*get_next_line(int fd)
{
	static char *stash[1024];
	char *line;

	// [BLOCK 1: Validate inputs and BUFFER_SIZE]
	// [BLOCK 2: Call helper to read into stash[fd] until '\n' or EOF]
	// [BLOCK 3: Call helper to extract one line from stash[fd] into `line`]
	// [BLOCK 4: Call helper to trim stash[fd] to leftovers after the line]
	// [BLOCK 5: Handle NULL/empty results: return NULL when appropriate]
	return (line);
}