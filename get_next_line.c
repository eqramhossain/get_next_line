/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/23 19:43:28 by ikramhossain     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_a_file(int fd, char *buffer);
char	*ft_set_new_line(char *buffer);
char	*ft_set_next_line(char *buffer);
char	*ft_str_free_join(char *str1, char *str2);

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*the_new_line;

	buffer = ft_calloc(1, sizeof(char));
	/* 	the buffer should be NULL or it can caused undefinded behaveior */
	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read_a_file(fd, buffer);
	if (!buffer)
		return (NULL);
	the_new_line = ft_set_new_line(buffer);
	buffer = ft_set_next_line(buffer);
	// if (!the_new_line || the_new_line[0] == '\0')
	// {
	// 	free(the_new_line);
	// 	the_new_line = NULL;
	// 	return (NULL);
	// }
	return (the_new_line);
}

char	*ft_read_a_file(int fd, char *buffer)
{
	ssize_t	bytes_readed;
	char	*tmp_buffer;

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
		buffer = ft_str_free_join(buffer, tmp_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp_buffer);
	tmp_buffer = NULL;
	return (buffer);
}

// char	*ft_set_next_line(char *buffer)
// {
// 	int		i;
// 	char	*tmp_buffer;
// 	char	*remaining_buffer;
//
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (buffer[i] == 0 || buffer[1] == 0)
// 		return (NULL);
// 	tmp_buffer = ft_calloc(i + 1, sizeof(char));
// 	if (buffer[i] == '\n')
// 		tmp_buffer = ft_substr(buffer, 0, i + 1);
// 	else
// 		tmp_buffer = ft_substr(buffer, 0, i);
// 	if (buffer[i])
// 		remaining_buffer = ft_strdup(buffer + i + 1);
// 	else
// 		remaining_buffer = ft_strdup("");
// 	return (tmp_buffer);
// }

char	*ft_set_new_line(char *buffer)
{
	int		i;
	char	*the_new_line;

	i = 0;
	// if the buffer does not exists return NULL
	if (!buffer)
		return (NULL);
	// look for the `\n` character in the buffer
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// allocate enough memory to stoc the the_new_line
	the_new_line = ft_calloc(i + 2, sizeof(char));
	// cpy till the '\n' characters
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		the_new_line = ft_strcpy(the_new_line, buffer);
	}
	// if buffer[i] == '\n' than the newline will contain the `\n`
	if (buffer[i] && buffer[i] != '\n')
	{
		the_new_line[i] = '\n';
	}
	return (the_new_line);
}

char	*ft_set_next_line(char *buffer)
{
	int		i;
	int		j;
	char	*the_next_line;

	i = 0;
	j = 0;
	// look for the `\n` character
	while (buffer[i] && buffer[i] != '\n')
		i++;
	// if the buffer does not exists
	// free the buffer set buffer to NULL return (NULL);
	if (!buffer)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	// allocate enough memory to stock the_next_line
	the_next_line = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	i++;
	// loop through buffer cpy buffer into the_next_line
	while (buffer[i])
	{
		the_next_line[j] = buffer[i];
		i++;
		j++;
	}
	free(buffer);
	buffer = NULL;
	return (the_next_line);
	// free buffer set buffer to NULL
	// return (the_next_line);
}

char	*ft_str_free_join(char *str1, char *str2)
{
	char	*tmp_buffer;

	tmp_buffer = ft_strjoin(str1, str2);
	free(str1);
	str1 = NULL;
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
