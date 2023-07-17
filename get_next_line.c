/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:26 by gykoh             #+#    #+#             */
/*   Updated: 2023/07/17 15:14:47 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read_line(int fd, char *storage)
{
    size_t read_size;
    char buff[BUFFER_SIZE + 1];
    char *tmp;

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
        if (!storage)
            storage = ft_strdup(buff);
        else
        {
            tmp = ft_strjoin(storage, buff);
            free(storage);
            storage = tmp;
        }
        if (ft_strchr(buff, '\n'))
            break;
    }
    return (storage);
}

static char *ft_extract_line(char **storage)
{
    char *line;
    char *newline_pos;
    size_t line_len;

    newline_pos = ft_strchr(*storage, '\n');
    if (newline_pos)
    {
        line_len = newline_pos - *storage;
        line = (char *)malloc(sizeof(char) * (line_len + 1));
        ft_strlcpy(line, *storage, line_len + 1);
        line[line_len] = '\0';
        *storage = ft_strdup(newline_pos + 1);
    }
    else
    {
        line_len = ft_strlen(*storage);
        line = (char *)malloc(sizeof(char) * (line_len + 1));
        ft_strlcpy(line, *storage, line_len + 1);
        line[line_len] = '\0';
        free(*storage);
        *storage = NULL;
    }
    return (line);
}

char *get_next_line(int fd)
{
    static char *line;
    char *storage = NULL;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    storage = ft_read_line(fd, storage);
    if (!storage)
        return (NULL);
    free(line);
    line = ft_extract_line(&storage);
    return (line);
}