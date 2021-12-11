/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:33:21 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/10 23:35:30 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int buf_end)
{
	long	i;
	long	j;
	char	*str;
	long	len_s2;

	i = 0;
	while (*s2 == '\0' && i < BUFFER_SIZE)
	{
		s2++;
		i++;
	}
	if (buf_end != BUFFER_SIZE)
		len_s2 = i;
	len_s2 = buf_end - i;
	i = 0;
	str = ft_calloc((ft_strlen(s1) + (len_s2) + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (i <= len_s2)
		str[j++] = s2[i++];
	str[j] = '\0';
	free(s1);
	return (str);
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
	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
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
