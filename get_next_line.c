/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/18 21:50:12 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_from_file(int fd)
{
	int			read_bytes;
	static char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = read(fd, buffer, BUFFER_SIZE);
	buffer[read_bytes] = '\0';
	printf("int read_bytes = %d // in get_next_line \n", read_bytes);
	if (read_bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}

char	*get_next_line(int fd)
{
	char	*buffer;

	buffer = read_from_file(fd);
	printf("char *buffer = %s // in get_next_line.c \n", buffer);
	return (buffer);
}
