/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:26 by gykoh             #+#    #+#             */
/*   Updated: 2023/07/18 17:08:24 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read_line(int fd, char *storage)
{
    ssize_t read_size;
    char    buff[BUFFER_SIZE + 1];
    char    *tmp;

    read_size = 1;
    while (read_size > 0)
    {
        read_size = read(fd, buff, BUFFER_SIZE);
        if (read_size < 0)
        {
            free(storage);
            return (NULL);
        }
        buff[read_size] = '\0';
        tmp = storage;
        if (!tmp)
            tmp = ft_strdup("");
        if (!tmp)
            return (0);
        storage = ft_strjoin(tmp, buff);
        free(tmp);
        if (ft_strchr(buff, '\n'))
            break;
    }
    return (storage);
}

static char *ft_extract_line(char **storage)
{
    char *line;
    char *newline_pos;
    char    *temp;
    size_t line_len;

    temp = *storage;
    newline_pos = ft_strchr(*storage, '\n');
    line_len = ft_strlen(*storage);
    if (newline_pos)
        line_len = newline_pos - *storage + 1;
    line = (char *)malloc(sizeof(char) * (line_len + 1));
    if (!line)
    {
        free(*storage);
        *storage = NULL;
        return (NULL);
    }
    ft_strlcpy(line, *storage, line_len + 1);
    *storage = NULL;
    if (newline_pos)
        *storage = ft_strdup(newline_pos + 1);
    free(temp);
    return (line);
}

char *get_next_line(int fd)
{
    static char *storage;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    storage = ft_read_line(fd, storage);
    if (storage == NULL || *storage == 0)
	{
		free(storage);
		storage = 0;
		return (NULL);
	}
	return (ft_extract_line(&storage));
}

// #include <stdio.h>
// #include <fcntl.h>

// int main(int argc, char **argv)
// {
//     int fd;
//     char *str;

//     if (argc != 2)
//         return (0);
//     fd = open(argv[1], O_RDONLY);
//     while ((str = get_next_line(fd)))
//     {
//         printf("|%s|\n", str);
//         free(str);
//     }
//     return (0);
// }