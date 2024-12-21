/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:20:20 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/21 11:05:40 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

extern int	errno;

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = 0;
	next_line = "";
	fd = open("file.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error number: %d\nError Cause: %s\n", fd, strerror(errno));
		return (0);
	}
	else
		printf("Open Successful!!\nfd = %d\n", fd);
	for (int i = 0; i < 3; i++)
	{
		next_line = get_next_line(fd);
		printf("Line Readed = %s\n", next_line);
		free(next_line);
	}
	fd = close(fd);
	if (fd == -1)
	{
		printf("Error number: %d\nError Cause: %s\n", fd, strerror(errno));
		return (0);
	}
	else
		printf("Close Successful!!\nfd = %d\n", fd);
	return (0);
}
