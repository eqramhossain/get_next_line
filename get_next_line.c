/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/22 11:36:30 by ikramhossain     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*fill_line_buffer(int fd, char *lft_char, char *buffer);
// char	*set_line(char *line_buffer);

char	*read_a_line(int fd, char *buffer);

char	*get_next_line(int fd)
{
	static char	*lft_char;
	char		*new_line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	new_line = read_a_line(fd, buffer);
	return (new_line);
}

char	*read_a_line(int fd, char *buffer)
{
	ssize_t	bytes_read;
	char	*tmp;

	tmp = "";
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		tmp = ft_strjoin(tmp, buffer);
		printf("tmp = %s\n", tmp);
		if (ft_strchr(tmp, '\n'))
			break ;
	}
	return (tmp);
}
