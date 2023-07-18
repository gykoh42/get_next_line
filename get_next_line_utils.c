/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:30 by gykoh             #+#    #+#             */
/*   Updated: 2023/07/18 17:01:16 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	tmp_c;

	i = 0;
	tmp_c = (char)c;
	while (s[i] != '\0' && s[i] != tmp_c)
		i++;
	if (s[i] == tmp_c)
		return ((char *)(s + i));
	return (0);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t s1_len;
	size_t s2_len;
	size_t total_size;
	
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	total_size = s1_len + s2_len + 1;
	if (s1 == 0 || s2 == 0)
		return (0);
	char *answer = (char *)malloc(sizeof(char) * total_size);
	if (!answer)
		return (0);
	ft_strlcpy(answer, s1, total_size);
	ft_strlcpy(answer + s1_len, s2, total_size - s1_len);
	return (answer);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*answer;

	i = 0;
	size = ft_strlen(s1);
	answer = malloc(sizeof(char) * (size + 1));
	if (!answer)
		return (0);
	while (s1[i] != '\0')
	{
		answer[i] = s1[i];
		i++;
	}
	answer[i] = '\0';
	return (answer);
}