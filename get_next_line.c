#include<fcntl.h>
#include "get_next_line.h"
#include <stdio.h>

//**ptr -> &line_x
//*ptr -> line_x = &malloc
char	*gnl_line(char **ptr, char *s1, char *s2)
{
	char	*swap;

	swap = *ptr;
	*ptr = ft_strjoin(s1, s2);
	free(swap);
	return (*ptr);
}

char	*gnl_backup_buff(char *backup_buff, char *read_buff, int i, int BUFFER_SIZE)
{
	int	j;

	j = 0;
	i = i + 1;
	while (i < BUFFER_SIZE)
	{
		backup_buff[j] = read_buff[i];
		i++;
		j++;
	}
	backup_buff[j] = '\0';
	return (backup_buff);
}

int	gnl_get_backup_buff(char *backup_buff, char *line)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (backup_buff[i] != '\0')
		{
			if (backup_buff[i] == '\n')
			{
				line[i] = backup_buff[i];
				while (backup_buff[i] != '\0')
				{
					backup_buff[j] = backup_buff[i +1];
					i++;
					j++;
				}
				backup_buff[j] = '\0';
				return (0);
			}
			line[i] = backup_buff[i];
			i++;
		}
		return (1);
}

char	*get_line(int fd, int BUFFER_SIZE)
{
	char			*read_buff;
	char			*line;
	static char		*backup_buff;
	int				flag;
	int				i;
	int				j;

	if (fd < 0) //OPEN_MAX
		return (NULL);
	read_buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buff)
	{
		if(backup_buff)
			free(backup_buff);
		return (NULL);
	}
	line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
	{
		if(backup_buff)
			free(backup_buff);
		free(read_buff);
		return (NULL);
	}


	if (backup_buff)
	{
		if (!gnl_get_backup_buff(backup_buff, line))
		{
			free(read_buff);
			return (line);
		}
	}

	flag = 0;
	while (!flag)
	{
		if (!read(fd, read_buff, BUFFER_SIZE))
		{
			free(read_buff);
			free(line);
			if(backup_buff)
				free(backup_buff);
			return (NULL); //(void *)0
		}
		i = 0;
		while (i++ < BUFFER_SIZE)
		{
			if (read_buff[i] == '\n')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			line = gnl_line(&line, line, read_buff);
		}
	}
			if (!backup_buff)
			{
				backup_buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
				if (!backup_buff)
				{
					free(backup_buff);
					free(line);
					return (0);
				}
			}
			j = 0;
			while ( j <= i)
			{
				backup_buff[j] = read_buff[j];
				j++;
			}
			backup_buff[j] = '\0';
			line = gnl_line(&line, line, backup_buff);
			j = 0;
			i = i + 1;
			while (i < BUFFER_SIZE)
			{
				backup_buff[j] = read_buff[i];
				i++;
				j++;
			}
			backup_buff[j] = '\0';
			free(read_buff);
			return (line);
}
/*
	Steps for processing a file
		Declare a file pointer variable
		Open a file using a open()
		Process the file using the suitable function
		close the file using the close()
**/
//gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 <files>.c
int	main(void)
{
	int		fd;
	char	*ret;

	fd = open("test.txt", O_RDONLY);
	ret = get_line(fd, 3);
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = get_line(fd, 3);
	}
	return (0);
}

/*
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
*/
