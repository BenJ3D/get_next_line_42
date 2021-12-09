/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 18:33:21 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/09 17:17:25 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
#include "get_next_line.h"

char	*get_line(char *str)  //copy juska trouver \n ou \0 et return le result
{
	int		i;
	char	*tmp;

	tmp = ft_calloc((ft_strlen(str)), sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	ft_memcpy(tmp, str, ft_strlen(str));
	if (tmp[0] == '\n')
	{
		tmp[1] = '\0';
		free(str);
		return (tmp);
	}
	while (tmp[i++])
	{
		if (tmp[i] == '\n')
		{
			tmp[i + 1] = '\0';
			break;
		}
	}
	return (tmp);
}