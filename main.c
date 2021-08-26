#include <stdio.h>
#include "get_next_line.h"

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
