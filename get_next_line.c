/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/18 14:27:47 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		read_bytes;
	char	*buffer;

	buffer = (char *)malloc(7 + 1 * sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = read(fd, buffer, 7);
	buffer[read_bytes] = '\0';
	printf("int read_bytes = %d // in get_next_line \n", read_bytes);
	printf("char *buffer = %s // in get_next_line.c \n", buffer);
	if (read_bytes <= 0)
	{
		free(buffer);
		return (NULL);
	}
	return (buffer);
}
