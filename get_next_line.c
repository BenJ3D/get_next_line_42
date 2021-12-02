/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benasusmac <benasusmac@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/02 00:33:55 by benasusmac       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/libft.h"
#include "get_next_line.h"

static int	ft_copy_after_n(char *str)
{
	static char	*cpy;
	
	//if ()
	return (0);
}

char	*get_next_line(int fd)
{	
	size_t		ret;
	char		buf[BUFFER_SIZE + 1];
	size_t		i;
	char		*tmp;
	int			bool;

	i = 0;
	bool = 0;
	tmp = ft_strdup("");
	ft_bzero(buf, BUFFER_SIZE);
	printf ("buf init: %s\n", buf);
	while (1)   // boucle principale, decoupe au premier \n
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		printf ("buf : %s\n", buf);
		i = 0;
		while (i <= ret)
		{
			if (buf[i] == '\n')
			{
				bool = 1;
				tmp = ft_strjoin_gnl(tmp, buf, i);
				printf("tmp = %s\n", tmp);
				return (tmp);
				break ;
			}
			if (i == ret)
			{
				tmp = ft_strjoin_gnl(tmp, buf, i);
				printf("tmp = %s\n", tmp);
				return (tmp);
				break ;
			}
			i++;
		}
		if (bool == 1) // si \n trouvé
		{
			printf("tmp = %s\n", tmp);
			tmp = ft_strjoin_gnl(tmp, buf, i);
			printf("tmp = %s\n", tmp);
			ft_copy_after_n(tmp);
			return (tmp);
			i = 0;
		}
		
		tmp = ft_strjoin_gnl(tmp, buf, i);
		bool = 0;
	}


	tmp = ft_strjoin_gnl(tmp, buf, i);
	return (tmp);
}
