#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

/**
 * @brief 	Calling in a loop will then allow you to read the text available on
 *			the file descriptor one line at a time until the end of it.
 * @param 1
 * @return	The line that has just been read. If there is nothing else to read
 *			or if an error has occurred it should return NULL.
**/
char	*get_next_line(int fd);

#endif
