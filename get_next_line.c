/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/15 19:11:55 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strichr_nl(char *str)	// analyse buff qui peut commencer par des 0
{	
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] == '\n')		//renvoi i si nl trouvé
			return (i);
		i++;
	}
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (str[i] != '\0')		//renvoi -1 si char trouvé
			return (-1);
		i++;
	}
	return (-2); // renvoi -1 si completement vide
}

int	ft_check_is_empty(char *str) //renvoi 1 si non vide
{
	int	i;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		if (str[i] != '\0')
			return (0);
	}
	return(1);
}

int	ft_buf_process(char *bufp, int ret) // met des zero jusquau \n
{
	int	i;

	i = 0;
	if (ret < BUFFER_SIZE)
	{
		

	}
	while (*bufp != '\n')
	{
		if (i == BUFFER_SIZE)//FIXME: attention
			break ;
		*bufp = '\0';
		bufp++;
		i++;
	}
	*bufp = '\0';
	ret = ret + 1;  // POUR TRIPUIOLLE FLAG
	return (ft_strichr_nl(bufp));
}

int	ft_read(int	fd, int ret, char *buf, char **line)
{
	int	chr_result;

	chr_result = -1;
	while(chr_result < 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		chr_result = ft_strichr_nl(buf);		// return >= 0 pour position \n // -1 si char trouvé sans nl // -2 si vide
		if (ret < BUFFER_SIZE) // moins de char lu que buffer_size donc fin de fichier
		{
			*line = ft_strdup("ret est inférieur à buf size, fin de fichier a gerer");
			break ;
		}
		if (chr_result >= 0) // nl trouvé
			*line = ft_strdup("buf contient une nl");
		if (chr_result == -1) // char trouvé
			*line = ft_strdup("Buff contient un ou plusieurs char");
		if (chr_result == -2) // chaine vide
			*line = ft_strdup("buf est NULL");
	}
	//printf("%d", chr_result);
	return(ret);
}

char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	int				ret;
	char			*line;

	while(1)
	{
		ret = ft_read(fd, ret, buf, &line);
		break;
	}

	return(line);
}
