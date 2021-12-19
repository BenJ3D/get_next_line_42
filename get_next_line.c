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

	if (BUFFER_SIZE == 1 && str[i] != '\n')		//renvoi -3 si nl trouvé avec buffsize a 1
		return (-3);
	i = 0;
	while (i <= BUFFER_SIZE)  // FIXME:
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
	return (-2); // renvoi -2 si completement vide
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
	return (0);
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
			ft_strjoin_gnl(&*line, *line, buf, BUFFER_SIZE);
			break ;
		}
		if (chr_result >= 0 && ret >= BUFFER_SIZE)
		{
			//*line = ft_strdup("buf contient une nl");
			break ;
		} // nl trouvé
		if (chr_result == -1 || chr_result == -3 && (ret >= BUFFER_SIZE)) // char trouvé sans nl
		{
			ft_strjoin_gnl(&*line, *line, buf, BUFFER_SIZE); // FIXME:
			ft_buf_process(buf, ret);
		}
		if (chr_result == -2 && ret >= BUFFER_SIZE) // chaine vide
			*line = ft_strdup("buf est NULL");
		//ft_strjoin_gnl(&*line, *line, buf, BUFFER_SIZE); //TODO: pour la norme supr if au dessus
	}
	return(ret);
}

char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	int				ret;
	char			*line;

	line = ft_strdup("");
	printf("%s\n", line);
	
	while(1)
	{
		ret = ft_read(fd, ret, buf, &line);
		break;
	}

	return(line);
}
