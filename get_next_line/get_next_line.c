/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:26 by gykoh             #+#    #+#             */
/*   Updated: 2023/07/10 15:49:29 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char *str;
    char *buffer;
    char *line;
    int i;
    int j;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (NULL);
    if (!str)
        str = ft_strdup("");
    while ((i = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[i] = '\0';
        str = ft_strjoin(str, buffer);
        if (ft_strchr(str, '\n'))
            break;
    }
    free(buffer);
    if (i < 0)
        return (NULL);
    i = 0;
    while (str[i] && str[i] != '\n')
        i++;
    if (!(line = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    j = 0;
    while (j < i)
    {
        line[j] = str[j];
        j++;
    }
    line[j] = '\0';
    if (str[i] == '\n')
        i++;
    buffer = ft_strdup(str + i);
    free(str);
    str = buffer;
    if (i == 0 && !str)
        return (NULL);
    return (line);
}