#include<fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char	*read_buff;

	read_buff = (char *)malloc(BUFFER_SIZE + 1);

	read(fd, read_buff, BUFFER_SIZE);
	return (read_buff);
}



int	main(void)
{
	int		fd;
	char	*ret;

	fd = open("test.txt", O_RDONLY);
	ret = get_next_line(fd);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = get_next_line(fd);
	}
	free(ret);
	return (0);
}
