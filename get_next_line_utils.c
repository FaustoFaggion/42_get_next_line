#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		*((char *)s) = 0;
		s++;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	*pos;
	size_t	tot_size;

	tot_size = nmemb * size;
	pos = malloc(tot_size);
	if (!pos || (tot_size > 2147483647))
		return (NULL);
	ft_bzero(pos, tot_size);
	return ((void *)pos);
}

size_t	ft_strlen(const char *s)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;

	if (!dest || !src)
		return (0);
	i = 0;
	if (dstsize < 1)
		return (ft_strlen(src));
	while (dstsize > 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		dstsize--;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	tot_size;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	tot_size = (len_s1 + len_s2 + 1);
	new = (char *)malloc(tot_size * sizeof(char));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s1, (len_s1 + 1));
	ft_strlcpy(&new[len_s1], s2, (len_s2 + 1));
	return (new);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 10:17:40 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/24 17:50:38 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"
#include <stdio.h>

char	*gnl_join(char *s1, char *s2)
{
	char	*swap;

	swap = s1;
	s1 = ft_strjoin(s1, s2);
	return (s1);
}
char	*gnl_read_buff(int fd, char *line, char *backup)
{
	char	*read_buff;
	int		r;
	*backup = '\0';
	while (*backup == '\0')
	{
		read_buff = ft_strdup("");
		r = read (fd, read_buff, BUFFER_SIZE);
		read_buff[r] = '\0';
		if(r <= 0)
			return (NULL);
		if (ft_strchr(read_buff, '\n'))
			backup = gnl_join(backup, read_buff);
		else
			line = gnl_join(line, read_buff);
		free(read_buff);
	}
	printf("%s\n", backup);
	return(line);
}


char	*get_next_line(int fd)
{
	char	*line;
	char	*backup;

	line = ft_strdup("");
	*line = '\0';
	backup = ft_strdup("");
	*backup = '\0';

	line = gnl_read_buff(fd, line, backup);
	return (line);
}

int	main(void)
{
	int		fd;
	char	*ret;

	fd = open("test.txt", O_RDONLY);
	ret = get_next_line(fd);
	printf("%s", ret);
	free(ret);

/*
	while (ret != NULL)
	{
		printf("%s", ret);
		free(ret);
		ret = get_next_line(fd);
	}
	free(ret);
*/
	return (0);
}
