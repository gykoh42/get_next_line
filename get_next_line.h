#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdlib.h>

char        *get_next_line(int fd);
static char *ft_store_line(int fd, char *storage);
static char *ft_extract_line(char **storage);

size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *s, int c);
char    *ft_strjoin(const char *s1, const char *s2);

#endif