/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/08 19:06:16 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// TODO: gerer quand memo est finis mais pas le text"
// TODO: gerer la fin du texte \0
// TODO: problem avec memo -->> gerer quand memo na plus de \n pour re read
char	*get_line(char *str)  //copy juska trouver \n ou \0 et return le result
{
	int		i;
	char	*tmp;

	tmp = ft_calloc ((ft_strlen(str)), sizeof(char));
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
	//free(str);
	return (tmp);
}

char	*memory_process(char *str) //met en memoire dans memo tous apres un \n et retourn le result
{
	if (!str)
		return(NULL);
	if (str[0] == '\n')  //FIXME: pas sur cest utile
		return (&str[1]);
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
	static char		memo[BUFFER_SIZE + 1];
	char			*tmp;

	ret = 1;
	tmp = ft_strdup("");
	ft_bzero(buf, BUFFER_SIZE);
	if (read(fd, buf, 0) < 0)
		return (NULL);
	if (memo != NULL && *memo != '\0' && (ft_strchr(memo, '\n')))
	{
		free(tmp);  // forcement deuxieme tour, donc free pour pas leaks ?!
		tmp = ft_strdup(memo);
		memo = memory_process(memo);
		if (ft_strchr(tmp, '\n'))
			return (get_line(tmp)); // return jusqua \n
	}
	if (memo && !(ft_strchr(memo, '\n')))
	{
		free(tmp);
		tmp = ft_strdup(memo);
		//memo[0] = '\0';
		//ft_bzero(memo, ft_strlen(memo));
		//free(memo);
	}
	while (!ft_strchr(tmp, '\n') && ret != 0)	// boucle tant que pas de \n ou ret 0
	{
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (ret <= 0)
			return (0);
		buf[ret] = '\0';
		tmp = ft_strjoin_gnl(tmp, buf, BUFFER_SIZE);
		if (!tmp)
			return (0);
		i++;
	}
	if (ft_strchr(tmp, '\n') && memo == NULL)  // FIXME: memo ne se vide pas 
	{
		memo = (ft_strchr(tmp, '\n') + 1);
	}
	if (!ft_strchr(memo, '\n'))
		memo = memory_process(tmp);
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