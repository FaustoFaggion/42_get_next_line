/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:17:40 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/24 23:37:47 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*gnl_join(char **s1, char **s2)
{
	char	*swap;

	swap = *s1;
	*s1 = ft_strjoin(*s1, *s2);
	free(swap);
	return (*s1);
}

char	*gnl_read_buff(int fd, char **backup)
{
	char	*read_buff;
	int		r;
	int		flag;

	flag = 0;
	while (flag == 0)
	{
		read_buff = (char *)malloc(BUFFER_SIZE + 1);
		if (!read_buff)
			return (NULL);
		r = read (fd, read_buff, BUFFER_SIZE);
		read_buff[r] = '\0';
		if (r <= 0)
		{
			free(read_buff);
			return (NULL); //return (line);
		}
		if (ft_strchr(read_buff, '\n'))
			flag = 1;
		*backup = gnl_join(&(*backup), &read_buff);
		free(read_buff);
	}
	return (*backup);
}

void	gnl_prep_line(char **line, char **backup)
{
	int	i;
	int	j;

	i = 0;
	while ((*backup)[i] != '\n')
	{
		(*line)[i] = (*backup)[i];
		i++;
	}
	(*line)[i] = (*backup)[i];
	i++;
	(*line)[i] = '\0';
	j = 0;
	while ((*backup)[i + j] != '\0')
	{
		(*backup)[j] = (*backup)[i + j];
		j++;
	}
	(*backup)[j] = '\0';
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (!backup)
	{
		backup = ft_strdup("");
		if (!backup)
			return (NULL);
	}
	if (ft_strchr(backup, '\n'))
	{
		line = ft_strdup(backup);
		gnl_prep_line(&line, &backup);
		return (line);
	}
	if (!gnl_read_buff(fd, &backup))
		return (NULL);
	line = ft_strdup(backup);
	if (!line)
		return (NULL);
	gnl_prep_line(&line, &backup);
	return (line);
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
