/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:33:21 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/28 16:58:58 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t ft_find_start(char *buf2)
{
	int	i;

	i = 0;
	while (buf2[i] == '\0' && i < BUFFER_SIZE)
		i++;
	return(i);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		i++;
	}
	return (i);
}

void	ft_strjoin_gnl(char **dst, char *line2, char *buf2, size_t buf_end)
 {
	size_t	i;
	size_t	j;
	size_t	srcslen;
	size_t	start;

	start = ft_find_start(buf2);
	srcslen = ft_strlen(line2);
	srcslen = srcslen + ((buf_end + 1) - start); //FIXME: bufend +1 DL
	*dst = malloc((sizeof(char) * srcslen) + 1); //TODO: pourquoi +8 sinon free invalid
	if (!dst)
		*dst = NULL;
	j = 0;
	i = 0;
	while (line2[i])
		dst[0][j++] = line2[i++];
	i = start;
	while (buf2[i] && i <= (size_t)buf_end)
		dst[0][j++] = buf2[i++];
	dst[0][j] = '\0';
	if (line2)
		free (line2);
	if (BUFFER_SIZE > 1)
		ft_buf_process(&*buf2);
	else if (BUFFER_SIZE <= 1)
		buf2[0] = '\0';
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

