/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/03 15:38:08 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/libft.h"
#include "get_next_line.h"

static char	*ft_copy_after_n(char *str) //// !!!!!!!!!!!!!
{
	int			i;
	int			len;
	char	*cpy;

	len = ft_strlen(&str[i]);
	if (!str)
		return (NULL);
	cpy = malloc((len + 1) * sizeof(char));
	i = 0;
	while (str[i] != '\n')
		i++;
	ft_strlcpy(cpy, &str[i], len);
	cpy[len] = '\0';
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
		//si after != NULL
		///cpy jusqu'au 
		
		//lis le fichier si aftern est vide
		///>>
		ret = read(fd, buf, BUFFER_SIZE);
		buf[ret] = '\0';
		//after_n = ft_copy_after_n(buf); //
		// parcourir le buf et cherche un \n
		////ft_bufchr << buf   >> return 0 si pas de \n ou return la position du \n
		// si 0 : on join buf + tmp et reboucle
		// si >1 :
		//// on save dans une static le restant
		////on join jusqu au \n
		//// return tmp
		//
	}

	tmp = ft_strjoin_gnl(tmp, buf, i);
	return (tmp);
}
