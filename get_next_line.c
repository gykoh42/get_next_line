/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:26 by gykoh             #+#    #+#             */
/*   Updated: 2023/07/12 22:52:09 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *ft_store_line(int fd, char *storage)
{
	size_t  read_size;
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
		if (read_size == 0)
			break ;
		buff[read_size] = '\0';
		tmp = storage;
		storage = ft_strjoin(tmp, buff);
		free(tmp);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (storage);
}

// 한줄 뽑고 storage 개행 전까지로 비우기
static char *ft_extract_line(char **storage)
{
	char	*line;
}


char *get_next_line(int fd)
{
	static char *storage;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	storage = ft_store_line(fd, storage);
}