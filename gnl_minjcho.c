/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line (1).c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:26 by gykoh             #+#    #+#             */
/*   Updated: 2023/07/16 16:35:37 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read_line(int fd, char *storage)
{
	ssize_t read_size;
	char    buff[BUFFER_SIZE + 1];
	char    *tmp;

	while (1)
	{
		read_size = read(fd, buff, BUFFER_SIZE);
		if (read_size < 0)
		{
			free(storage);
			return (NULL);
		}
		buff[read_size] = '\0';
		tmp = storage;
		storage = ft_strjoin(tmp, buff);
		if (storage == NULL)
		{
			free(tmp);
			return (NULL);
		}
		free(tmp);
		if (ft_strchr(storage, '\n'))
			break ;
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
        if (line == NULL)
            return (NULL);
        ft_strncpy(line, *storage, line_len);
        line[line_len] = '\0';
        *storage = ft_strdup(newline_pos + 1);
        if (*storage == NULL)
        {
            free(line);
            return (NULL);
        }
    }
    else
    {
        line_len = ft_strlen(*storage);
        line = (char *)malloc(sizeof(char) * (line_len + 1));
        if (line == NULL)
            return (NULL);
        ft_strncpy(line, *storage, line_len);
        line[line_len] = '\0';
        free(*storage);
        *storage = NULL;
    }
    return (line);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*storage = NULL;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = ft_read_line(fd, storage);
	if (!storage)
		return (NULL);
	line = ft_extract_line(&storage);
	return (line);
}
