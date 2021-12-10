/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:33:21 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/10 22:38:17 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, char *s2, int buf_end)
{
	size_t	i;
	size_t	j;
	char	*str;
	int		len_s2;

	i = 0;
	while (*s2 == '\0' && i < BUFFER_SIZE)
	{
		s2++;
		i++;
	}
	// if (i == BUFFER_SIZE)
	// {
	// 	free(s1);
	// 	return (NULL);
	// }
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

// char	*get_line(char *str)  //copy juska trouver \n ou \0 et return le result
// {
// 	int		i;
// 	char	*tmp;

// 	tmp = ft_calloc((ft_strlen(str)), sizeof(char));
// 	if (!tmp)
// 		return (NULL);
// 	i = 0;
// 	ft_memcpy(tmp, str, ft_strlen(str));
// 	if (tmp[0] == '\n')
// 	{
// 		tmp[1] = '\0';
// 		free(str);
// 		return (tmp);
// 	}
// 	while (tmp[i++])
// 	{
// 		if (tmp[i] == '\n')
// 		{
// 			tmp[i + 1] = '\0';
// 			break;
// 		}
// 	}
// 	return (tmp);
// }