/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/23 16:04:17 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_a_file(int fd, char *buffer);
char	*set_next_line(char *buffer);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*the_next_line;

	buffer = ft_calloc(1, sizeof(char));
	/* 	the buffer should be NULL or it can caused undefinded behaveior */
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_a_file(fd, buffer);
	if (!buffer)
		return (NULL);
	the_next_line = set_next_line(buffer);
	if (!the_next_line || the_next_line[0] == '\0')
	{
		free(the_next_line);
		the_next_line = NULL;
		return (NULL);
	}
	return (the_next_line);
}

char	*read_a_file(int fd, char *buffer)
{
	ssize_t	bytes_readed;
	char	*tmp_buffer;
	char	*new_buffer;

	bytes_readed = 1;
	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (tmp_buffer == NULL)
		return (NULL);
	while (bytes_readed > 0)
	{
		bytes_readed = read(fd, tmp_buffer, BUFFER_SIZE);
		if (bytes_readed == -1)
		{
			free(buffer);
			free(tmp_buffer);
			tmp_buffer = NULL;
			return (NULL);
		}
		if (bytes_readed == 0)
			break ;
		tmp_buffer[bytes_readed] = 0;
		new_buffer = ft_strjoin(buffer, tmp_buffer);
		free(buffer);
		buffer = new_buffer;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp_buffer);
	tmp_buffer = NULL;
	return (buffer);
}

char	*set_next_line(char *buffer)
{
	int		i;
	char	*tmp_buffer;
	char	*remaining_buffer;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == 0 || buffer[1] == 0)
		return (NULL);
	tmp_buffer = ft_calloc(i + 1, sizeof(char));
	if (buffer[i] == '\n')
		tmp_buffer = ft_substr(buffer, 0, i + 1);
	else
		tmp_buffer = ft_substr(buffer, 0, i);
	if (buffer[i])
		remaining_buffer = ft_strdup(buffer + i + 1);
	else
		remaining_buffer = ft_strdup("");
	return (tmp_buffer);
}

// Now i know that where the `\n` char is
// we will have to copy up to `\n` char and store it to line
// - If (`\n` exists in buffer)
// - extract all characters up to and including the '\n'
// - Splits the content of `buffer` to able copy the string up to the `\n`
// - Update `buffer`:
//
/* 	- If a newline was found in the buffer save the remaining content (after the `\n`) back into `buffer`. */
// - If no content remains, free `buffer`
