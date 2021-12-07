/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/07 12:15:19 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//int	

char	*get_next_line(int fd)
{	
	char			buf[BUFFER_SIZE + 1];
	size_t			i;
	size_t			ret;
	static char		*memory= NULL;
	char			*tmp;

	tmp = ft_strdup("");
	if (read(fd, buf, 0) < 0)
		return (NULL);
	while (!ft_strchr(tmp, '\n') && ret != 0)// boucle tant que pas de \n ou ret 0
	{
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (ret < 0)
			return (0);
		buf[ret] = '\0';
		tmp = ft_strjoin_gnl(tmp, buf, BUFFER_SIZE);
		if (!tmp)
			return (0);
		i++;
	}
	
	return(tmp);
}

