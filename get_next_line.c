/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/02 19:04:20 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/libft.h"
#include "get_next_line.h"

static char	*ft_copy_after_n(char *str)
{
	int			i;
	static char	cpy[BUFFER_SIZE];

	//cpy = ft_strdup("");
	if (!str)
		return (cpy);
	i = 0;
	while (str[i] != '\n' || i < ft_strlen(str))
		i++;
	ft_memcpy(cpy, &str[i], ft_strlen(&str[i]));
	return (cpy);
}

char	*get_next_line(int fd)
{	
	size_t			ret;
	char			buf[BUFFER_SIZE + 1];
	size_t			i;
	char			*tmp;
	int				bool;
	static char		*after_n = NULL;

	i = 0;
	bool = 0;
	tmp = ft_strdup("");
	ft_bzero(buf, BUFFER_SIZE);
	printf ("buf init: %s\n", buf);
	if (after_n != NULL)
	{
		tmp = ft_strjoin_gnl(tmp, after_n, i);
		after_n = ft_copy_after_n(tmp);
		printf("\nRESTANT after1:%s\n", after_n);
		return (tmp);
	}
	
	while (1)   // boucle principale, decoupe au premier \n
	{
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		after_n = ft_copy_after_n(buf);
		printf("\nRESTANT :%s\n", after_n);
		printf ("\nBUFFER :%s\n", buf);
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
