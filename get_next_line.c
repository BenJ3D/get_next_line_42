/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/07 16:50:03 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*get_line(char *str)  //copy juska trouver \n ou \0 et return le result
{
	int		i;
	char	*tmp;

	tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!tmp)
		return (NULL);
	i = 0;
	ft_memcpy(tmp, str, ft_strlen(str));
	while (tmp[++i])
	{
		if (tmp[i] == '\n')
		{
			tmp[i] = '\0';
			break;
		}
	}
	free(str);
	return (tmp);
}

char	*memory_process(char *str) //met en memoire dans memo tous apres un \n et retourn le result
{
	if (!str)
		return(NULL);
	if (ft_strchr(str, '\n'))
	{
		if (str[ft_strlen(str)] == '\n')
			return (ft_strchr(str, '\n'));
		return (ft_strchr(str, '\n') + 1);
	}
	return (str);
}

char	*get_next_line(int fd)
{	
	char			buf[BUFFER_SIZE + 1];
	size_t			i;
	size_t			ret;
	static char		*memo = NULL;
	char			*tmp;

	ret = 1;
	tmp = ft_strdup("");
	if (read(fd, buf, 0) < 0)
		return (NULL);
	if (memo != NULL && *memo != '\0')
	{
		free(tmp);
		tmp = ft_strdup(memo);
		memo = memory_process(memo);
		return (get_line(tmp)); // return jusqua \n
	}
	while (!ft_strchr(tmp, '\n') && ret != 0)	// boucle tant que pas de \n ou ret 0
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
	if (ft_strchr(tmp, '\n') && memo == NULL)
	{
		memo = malloc(sizeof(char) * ((ft_strlen(tmp) + 1)));
		memo = (ft_strchr(tmp, '\n') + 1);
	}
	return(get_line(tmp));
}


// if (read(fd, buf, 0) < 0)
// 		return (NULL);
// 	while (!ft_strchr(str, '\n') && i != 0)
// 	{
// 		i = read(fd, buf, BUFFER_SIZE);
// 		if (i < 0)
// 			return (0);
// 		buf[i] = '\0';
// 		str = ft_strjoin(str, buf);
// 		if (!str)
// 			return (0);
// 	}
// 	if (ft_strchr(str, '\n'))
// 	