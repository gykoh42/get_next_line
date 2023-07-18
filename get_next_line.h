#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

# include <unistd.h>
# include <stdlib.h>

char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char    *ft_strdup(const char *s1);

#endif