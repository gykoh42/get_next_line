/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:26 by gykoh             #+#    #+#             */
/*   Updated: 2023/07/16 18:04:42 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_read_line(int fd, char *storage)
{
    size_t read_size;
    char buff[BUFFER_SIZE + 1];
    char *tmp;

    while (1)
    {
        read_size = read(fd, buff, BUFFER_SIZE);
        if (read_size < 0)
        {
            free(storage);
            return (NULL);
        }
        if (read_size == 0 || read_size < BUFFER_SIZE) // 버퍼 오버플로우 수정
            break;
        buff[read_size] = '\0';
        tmp = storage;
        if (!tmp)
            tmp = ft_strdup("");
        storage = ft_strjoin(tmp, buff);
        free(tmp);
        if (ft_strchr(storage, '\n'))
            break;
    }
    return (storage);
}

static char *ft_extract_line(char **storage)
{
    static char *line;
    char *newline_pos;
    size_t line_len;

    newline_pos = ft_strchr(*storage, '\n');
    if (newline_pos)
    {
        line_len = newline_pos - *storage;
        line = (char *)malloc(sizeof(char) * (line_len + 1));
        ft_strlcpy(line, *storage, line_len + 1); // 정의되지 않은 동작 수정
        line[line_len] = '\0';
        *storage = ft_strdup(newline_pos + 1);
    }
    else
    {
        line_len = ft_strlen(*storage);
        line = (char *)malloc(sizeof(char) * (line_len + 1));
        ft_strlcpy(line, *storage, line_len + 1); // 정의되지 않은 동작 수정
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
    free(line); // 메모리 누수 수정
    line = ft_extract_line(&storage);
    return (line);
}

// #include "get_next_line.h"

// static char *ft_read_line(int fd, char *storage)
// {
// 	size_t  read_size;
// 	char    buff[BUFFER_SIZE + 1];
// 	char    *tmp;

// 	while (1)
// 	{
// 		read_size = read(fd, buff, BUFFER_SIZE);
// 		if (read_size < 0)
// 		{
// 			free(storage);
// 			return (NULL);
// 		}
// 		if (read_size == 0)
// 			break ;
// 		buff[read_size] = '\0';
// 		tmp = storage;
// 		if (!tmp)
// 			tmp = ft_strdup("");
// 		storage = ft_strjoin(tmp, buff);
// 		free(tmp);
// 		if (ft_strchr(storage, '\n'))
// 			break ;
// 	}
// 	return (storage);
// }

// static char *ft_extract_line(char **storage)
// {
//     static char *line;
//     char *newline_pos;
//     size_t line_len;

//     newline_pos = ft_strchr(*storage, '\n');
//     if (newline_pos)
//     {
//         line_len = newline_pos - *storage;
//         line = (char *)malloc(sizeof(char) * (line_len + 1));
//         ft_strncpy(line, *storage, line_len);
//         line[line_len] = '\0';
//         *storage = ft_strdup(newline_pos + 1);
//     }
//     else
//     {
//         line_len = ft_strlen(*storage);
//         line = (char *)malloc(sizeof(char) * (line_len + 1));
//         ft_strncpy(line, *storage, line_len);
//         line[line_len] = '\0';
//         free(*storage);
//         *storage = NULL;
//     }
//     return (line);
// }

// char	*get_next_line(int fd)
// {
// 	static char	*line;
// 	char	*storage = NULL;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	storage = ft_read_line(fd, storage);
// 	if (!storage)
// 		return (NULL);
// 	line = ft_extract_line(&storage);
// 	return (line);
// }