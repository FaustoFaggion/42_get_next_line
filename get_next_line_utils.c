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
