/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:33:21 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/20 21:02:20 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_strjoin_gnl(char **dst, char *line2, char *buf2, int buf_end)
 {
	size_t	i;
	size_t	j;
	size_t	srcslen;

	i = 0;
	while (*buf2 == '\0' && i < BUFFER_SIZE)
	{
		*buf2++;
		i++;
	}
	srcslen = ft_strlen(line2);
	srcslen = srcslen + ft_strlen(buf2);
	*dst = malloc(sizeof(char) * srcslen + 1);
	j = 0;
	i = 0;
	while (line2[i])
		dst[0][j++] = line2[i++];
	i = 0;
	while (buf2[i] && i <= buf_end)
		dst[0][j++] = buf2[i++];
	dst[0][j] = '\0';
	free(line2);
 }

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (ptr == NULL)
		return (ptr);
	//ft_bzero(ptr, size * count);
	ft_memset(ptr, 0, size * count);
	return (ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(sizeof(char) * (ft_strlen((char *)s1) + 1));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
		((char *)b)[i++] = c;
	return (b);
}
