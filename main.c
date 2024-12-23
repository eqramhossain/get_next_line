/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 08:32:55 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/23 18:36:45 by ikramhossain     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = 0;
	next_line = "";
	fd = open("file.txt", O_RDONLY);
	while (next_line != NULL)
	{
		next_line = get_next_line(fd);
		printf("get_next_line = %s\n", next_line);
	}
	fd = close(fd);
	return (0);
}
