#include "get_next_line.h"

extern int	errno;

int	main(void)
{
	int		fd;
	char	*next_line;
	int		i;

	fd = 0;
	next_line = "";
	fd = open("file.txt", O_RDONLY);
	i = 0;
	next_line = get_next_line(fd);
	printf("get_next_line = %s\n", next_line);
	free(next_line);
	i++;
	fd = close(fd);
	return (0);
}
