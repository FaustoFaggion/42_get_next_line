/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 15:43:26 by edpaulin          #+#    #+#             */
/*   Updated: 2021/08/24 23:38:31 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char	*str)
{
	size_t	len;

	len = 0;
	while (str[len])
		++len;
	return (len);
}

char	*ft_strdup(const char *s)
{
	size_t	len;
	size_t	i;
	char	*mem;

	i = 0;
	len = ft_strlen(s);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	while (s[i] != '\0')
	{
		mem[i] = s[i];
		++i;
	}
	mem[i] = '\0';
	return (mem);
}


size_t	ft_strlcpy(char	*dest, const char	*src, size_t	dest_size)
{
	size_t	src_len;

	if (!src)
		return (0);
	src_len = ft_strlen(src);
	if (dest_size)
	{
		while (--dest_size && *src)
			*(dest++) = *(src++);
		*dest = '\0';
	}
	return (src_len);
}


char	*ft_strjoin(const char	*str1, const char	*str2)
{
	size_t	str1_len;
	size_t	str2_len;
	char	*new_str;

	if (!str1 && !str2)
		return (NULL);
	str1_len = ft_strlen(str1);
	str2_len = ft_strlen(str2);
	new_str = (char *)malloc((str1_len + str2_len + 1) * sizeof(*new_str));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, str1, (str1_len + 1));
	ft_strlcpy((new_str + str1_len), str2, (str2_len + 1));
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*(char *)s != '\0')
	{
		if (*(char *)s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*(char *)s == (char)c)
		return ((char *)s);
	return (NULL);
}
