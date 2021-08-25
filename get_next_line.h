/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fagiusep <fagiusep@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 23:38:44 by fagiusep          #+#    #+#             */
/*   Updated: 2021/08/24 23:39:19 by fagiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*ft_strchr(const char *s, int c);

char	*ft_strdup(const char	*str);

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);



/**
 * @brief 	Calling in a loop will then allow you to read the text available on
 *			the file descriptor one line at a time until the end of it.
 * @param 1
 * @return	The line that has just been read. If there is nothing else to read
 *			or if an error has occurred it should return NULL.
**/
char	*get_next_line(int fd);


#endif
