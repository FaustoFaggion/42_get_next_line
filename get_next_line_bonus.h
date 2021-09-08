#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <limits.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif


/**
 * @brief	returns a pointer to the first occurrence of the character c in
 * 			the string s.
 * @param 1 pointer to the string
 * @param 2 character c
 * @return  return a pointer to the matched character or NULL if the
 * 			character is not found.
			The terminating null byte is considered part of the string, so
			that if c is
			specified as '\0', these functions return a pointer to the terminator.
**/
char	*ft_strchr(const char *s, int c);

/**
 * @brief 	duplicates the string s. Memory for the new string is obteined
 * 			with malloc, and can
			be freed with free. the NUll character is added to the end.
 * @param 1 string s
 * @return  a pointer to the new string.
**/
char	*ft_strdup(const char	*str);

/**
 * @brief 	Allocates (with malloc(3)) and returns a new string, which is
 * 			the result of the
 * 			concatenation of ’s1’ and ’s2’.
 * @param 1 the prefix string
 * @param 2 the sufix string
 * @return  returns a new string, which is the result of the concatenation
 * 			of ’s1’ and ’s2’.
**/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief	calculates the length of the string pointed to by s, excluding
 * 			the terminating null.
 * 			byte ('\0').
 * @param 1 String to be counted the characters.
 * @return  the number of bytes in the string pointed to by s.
 * 			If parameters are NUll segmentfault returns.
**/
size_t	ft_strlen(const char *s);

/**
 * @brief 	Allocates (with malloc(3)) and returns a substring from the
 * 			string ’s’.	The substring begins at index ’start’ and is of
 * 			maximum size ’len’.
 * @param 1 The string from which to create the substring.
 * @param 2 The start index of the substring in the string ’s’.
 * @param 3	The maximum length of the substring.
 * @return  The substring. NULL if the allocation fails.
**/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief 	Calling in a loop will then allow you to read the text available on
 *			the file descriptor one line at a time until the end of it.
 * @param 1
 * @return	The line that has just been read. If there is nothing else to read
 *			or if an error has occurred it should return NULL.
**/
char	*get_next_line(int fd);

#endif
