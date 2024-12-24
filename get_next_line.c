/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehossain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:32:36 by ehossain          #+#    #+#             */
/*   Updated: 2024/12/24 15:50:42 by ehossain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd);
char	*ft_read_file(int fd, char *buffer);
char	*ft_set_line(char *buffer);
char	*ft_set_remaining(char *buffer);

int	main(void)
{
	int		fd;
	char	*next_line;

	fd = 0;
	next_line = "";
	fd = open("file.txt", O_RDONLY);
	// while (next_line != NULL)
	// {
	next_line = get_next_line(fd);
	printf("---------------------------------\n");
	printf("get_next_line = %s\n", next_line);
	printf("---------------------------------\n");
	next_line = get_next_line(fd);
	printf("---------------------------------\n");
	printf("get_next_line = %s\n", next_line);
	printf("---------------------------------\n");
	next_line = get_next_line(fd);
	printf("---------------------------------\n");
	printf("get_next_line = %s\n", next_line);
	printf("---------------------------------\n");
	// }
	fd = close(fd);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*read_file;
	char		*new_line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	read_file = ft_read_file(fd, read_file);
	printf("---------------------------------\n");
	printf("read_file = %s\n", read_file);
	printf("---------------------------------\n");
	if (!read_file)
		return (NULL);
	new_line = ft_set_line(read_file);
	printf("---------------------------------\n");
	printf("new_line = %s\n", new_line);
	printf("---------------------------------\n");
	read_file = ft_set_remaining(read_file);
	printf("---------------------------------\n");
	printf("read_file = %s\n", read_file);
	printf("---------------------------------\n");
	return (new_line);
}

char	*ft_read_file(int fd, char *buffer)
{
	int		read_bytes;
	char	*tmp_buffer;

	read_bytes = 1;
	if (!buffer)
		buffer = ft_calloc(1, 1);
	tmp_buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (read_bytes > 0)
	{
		read_bytes = read(fd, tmp_buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(tmp_buffer);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		tmp_buffer[read_bytes] = '\0';
		buffer = ft_str_free_join(buffer, tmp_buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(tmp_buffer);
	return (buffer);
}

char	*ft_set_line(char *buffer)
{
	int		i;
	int		j;
	char	*tmp_buffer;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp_buffer = ft_calloc(i + 2, sizeof(char));
	while (j < i)
	{
		tmp_buffer[j] = buffer[j];
		j++;
	}
	printf("i = [%d]\nj = [%d]\n", i, j);
	if (buffer[i] && buffer[i] == '\n')
	{
		tmp_buffer[i] = '\n';
		i++;
	}
	tmp_buffer[i] = '\0';
	printf("---------------------------------\n");
	printf("tmp_buffer = %s\n", tmp_buffer);
	printf("---------------------------------\n");
	return (tmp_buffer);
}

char	*ft_set_remaining(char *buffer)
{
	int		i;
	int		j;
	int		tmp;
	char	*tmp_buffer;

	i = 0;
	j = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	tmp = i;
	tmp_buffer = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
	while (buffer[i + 1] != 0)
	{
		tmp_buffer[j] = buffer[i + 1];
		i++;
		j++;
	}
	tmp_buffer[i] = '\0';
	printf("---------------------------------\n");
	printf("tmp_buffer = %s\n", tmp_buffer);
	printf("---------------------------------\n");
	free(buffer);
	return (tmp_buffer);
}
//
// remaining = ft_calloc(ft_strlen(buffer) - i + 1, sizeof(char));
// remaining = ft_substr(buffer, i, ft_strlen(buffer) - i);
// printf("---------------------------------\n");
// printf("remaining = %s\n", remaining);
// printf("---------------------------------\n");
// free(buffer);
// buffer = ft_calloc(ft_strlen(remaining) + 1, sizeof(char));
// buffer = ft_strdup(remaining);
// printf("---------------------------------\n");
// printf("buffer = %s\n", buffer);
// printf("---------------------------------\n");
//
