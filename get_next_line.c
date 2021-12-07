/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/07 13:21:04 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*memory_process(char *str)
{
	if (!str)
		return(NULL);
	if (ft_strchr(str, '\n'))
		printf ("memory_process =|| %s ||\n", str);
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
	if (memo != NULL && (!ft_strchr(memo, '\n')))   // TODO:  FIXME: reprendre ICI poru gerer 
	{
		memo = memory_process(memo);
		return	
	}
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
	if (ft_strchr(tmp, '\n'))
	{
		memo = malloc(sizeof(char) * ((ft_strlen(tmp) + 1)));
		memo = ft_strchr(tmp, '\n');
		printf("memo = %s\n",  memo);
	}
	return(tmp);
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