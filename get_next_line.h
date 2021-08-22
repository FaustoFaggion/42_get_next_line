#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//# ifndef BUFFER_SIZE
//#  define BUFFER_SIZE 42
//# endif

# include <unistd.h>
# include <stdlib.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

char	*get_line(int fd, int BUFFER_SIZE);


/**
 * @brief 	Calling in a loop will then allow you to read the text available on
 *			the file descriptor one line at a time until the end of it.
 * @param 1
 * @return	The line that has just been read. If there is nothing else to read
 *			or if an error has occurred it should return NULL.
**/
char	*get_next_line(int fd);


#endif
