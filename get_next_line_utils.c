/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 15:00:30 by gykoh             #+#    #+#             */
/*   Updated: 2023/07/12 22:51:04 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t  ft_strlen(const char *str)
{
    size_t  i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

char	*ft_strchr(const char *s, int c)
{
    size_t  i;

    i = 0;
    while (*s && *s != (char)c)
        i++;
    if (s[i] == (char)c)
        return ((char *)(s + i));
    return (0);
}

char    *ft_strjoin(const char *s1, const char *s2)
{
    size_t  i;
    size_t  total_size;
    char    *rtn;

    i = 0;
    total_size = ft_strlen(s1) + ft_strlen(s2);
    if (!(rtn = (char *)malloc(sizeof(char) * (total_size + 1))))
        return (0);
    while (*s1)
    {
        rtn[i] = *s1;
        s1++;
        i++;
    }
    while (*s2)
    {
        rtn[i] = *s2;
        s2++;
        i++;
    }
    rtn[i] = '\0';
    return (rtn);
}

// #include <stdio.h>
// int main()
// {
//     char *s1 = "hello ";
//     char *s2 = "im gyeonga!";

//     char *s3 = ft_strjoin(s1, s2);
//     printf("%s\n", s3);
//  }