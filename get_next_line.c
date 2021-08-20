//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <unistd.h>
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

		if (flag == 1)
		{
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
	}
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
	char	*read_buff;
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
char	*get_line(int fd, int BUFFER_SIZE)
{
	char			*read_buff;
	char			*line;
	static char		*line_y;
	int				flag;
	int				i;
	int				j;
	char			*swap;

	if (fd < 0) //OPEN_MAX
		return (NULL);

	read_buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buff)
		return (NULL);
	line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (0);

	flag = 0;
	i = 0;
	j = 0;

	if (line_y)
	{
		while (line_y[i] != '\0')
		{
			if (line_y[i] == '\n')
			{
				line[i] = line_y[i];
				while (line_y[i] != '\0')
				{
					line_y[j] = line_y[i +1];
					i++;
					j++;
				}
				line_y[j] = '\0';
				return (line);
			}
			line[i] = line_y[i];
			i++;
		}
	}

	while (flag == 0)
	{
		if (!read(fd, read_buff, BUFFER_SIZE))
			return (NULL); //(void *)0
		i  = 0;
		while(i < BUFFER_SIZE)
		{
			if(read_buff[i] == '\n')
			{
				flag = 1;
				break;
			}
			i++;
		}
		if (flag == 0)
		{
			swap = line;
			line = ft_strjoin(line, read_buff);
			free(swap);
		}

		if (flag == 1)
		{
			line_y = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			if (!line_y)
				return (0);
			j = 0;
			while ( j <= i)
			{
				line_y[j] = read_buff[j];
				j++;
			}

			swap = line;
			line = ft_strjoin(line, line_y);
			free(swap);

			j = 0;
			i = i + 1;
			while (i < BUFFER_SIZE)
			{
				line_y[j] = read_buff[i];
				i++;
				j++;
			}
			line_y[j] = '\0';

			return (line);
		}

	}

}
*/

/*
//s1 = &malloc
//*s1 = conteudo malloc

char	*gnl_line(char *s1, char *s2)
{
	char	*swap;

	swap = s1;
	s1 = ft_strjoin(s1, s2);
	free(swap);
	return (s1);
}


char	*get_line(int fd, int BUFFER_SIZE)
{
	char			*read_buff;
	char			*line;
	static char		*line_y;
	int				flag;
	int				i;
	int				j;
	char			*swap;

	if (fd < 0) //OPEN_MAX
		return (NULL);

	read_buff = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buff)
		return (NULL);
	line = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!line)
		return (0);

	flag = 0;
	i = 0;
	j = 0;

	if (line_y)
	{
		while (line_y[i] != '\0')
		{
			if (line_y[i] == '\n')
			{
				line[i] = line_y[i];
				while (line_y[i] != '\0')
				{
					line_y[j] = line_y[i +1];
					i++;
					j++;
				}
				line_y[j] = '\0';
				return (line);
			}
			line[i] = line_y[i];
			i++;
		}
	}

	while (!flag)
	{
		if (!read(fd, read_buff, BUFFER_SIZE))
			return (NULL); //(void *)0
		i  = 0;
		while(i++ < BUFFER_SIZE)
		{
			if(read_buff[i] == '\n')
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			line = gnl_line(&(line), read_buff);
		}

		if (flag == 1)
		{
			line_y = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
			if (!line_y)
				return (0);
			j = 0;
			while ( j <= i)
			{
				line_y[j] = read_buff[j];
				j++;
			}
			line = gnl_line(&(*line), line_y);

			j = 0;
			i = i + 1;
			while (i < BUFFER_SIZE)
			{
				line_y[j] = read_buff[i];
				i++;
				j++;
			}
			line_y[j] = '\0';

			return (line);
		}

	}

}
*/
