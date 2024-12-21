/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/21 19:10:27 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_line_buffer(int fd, char *lft_char, char *buffer);
char	*set_line(char *line_buffer);

char	*get_next_line(int fd)
{
	static char	*lft_char;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line_buffer(fd, lft_char, buffer);
	printf("line = %s\n", line);
	printf("lft_char = %s\n", lft_char);
	return (line);
}

char	*fill_line_buffer(int fd, char *lft_char, char *buffer)
{
	ssize_t	bytes_readen;
	char	*tmp;

	bytes_readen = read(fd, buffer, BUFFER_SIZE);
	lft_char = buffer;
	return (tmp);
}

char	*set_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;
}
