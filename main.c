/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:20:20 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/18 14:15:57 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

extern int	errno;

int	main(void)
{
	int		fd;
	char	*next_line;
	int		cl;
	int		count;

	count = 0;
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error number: %d\nError Cause: %s\n", fd, strerror(errno));
		return (0);
	}
	else
		printf("Open Success!!\nfd = %d\n", fd);
	while (1)
	{
		printf("Line count = [%d] // in main\n", count);
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		printf("char next_line = %s // in main\n", next_line);
		free(next_line);
		count++;
	}
	cl = close(fd);
	if (cl == -1)
	{
		printf("Error number: %d\nError Cause: %s\n", cl, strerror(errno));
		return (0);
	}
	else
		printf("Close Success!!\ncl = %d\n", cl);
	return (0);
}
