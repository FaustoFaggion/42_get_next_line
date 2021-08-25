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

size_t	ft_strlen(const char *s);

char	*ft_strjoin(char const *s1, char const *s2);

char    *ft_substr(char const *s, unsigned int start, size_t len);



/**
 * @brief 	Calling in a loop will then allow you to read the text available on
 *			the file descriptor one line at a time until the end of it.
 * @param 1
 * @return	The line that has just been read. If there is nothing else to read
 *			or if an error has occurred it should return NULL.
**/
char	*get_next_line(int fd);


#endif
