/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/20 23:58:42 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strichr_nl(char *str, size_t ret)	// TODO: ajout ret pour cal bufend en eot analyse buff qui peut commencer par des 0
{	
	size_t	i;
	size_t	j;
	
	if (BUFFER_SIZE == 1 && str[0] == '\n')		//renvoi -3 si nl trouvé avec buffsize a 1 // FIXME:
		return (-3);
	i = 0;
	while (i < BUFFER_SIZE)  // FIXME:
	{
		if (str[i] == '\n')		//renvoi i si nl trouvé
			return (i);
		i++;
	}
	j = 0;
	while (j < BUFFER_SIZE)
	{
		if (str[j] != '\0')		//renvoi -1 si char trouvé sans nl
			return (-1);
		j++;
	}
	if (ret != BUFFER_SIZE) //TODO: sortir de la fonction
	{
		i = BUFFER_SIZE;
		while (i-- != 0)
		{
			if (str[i] != '\0')
				return(i);
		}
	}
	return (-2); // renvoi -2 si completement vide
}

int	ft_buf_process(char *bufp) // met des zero jusquau \n
{
	int	i;

	i = 0;
	while (*bufp != '\n')
	{
		if (i == BUFFER_SIZE) //FIXME: attention
			break ;
		*bufp = '\0';
		bufp++;
		i++;
	}
	*bufp = '\0';
	return (0);
}

static int	ft_read(int	fd, int ret2, char *buf, char **line)
{
	int	chr_result;
	int	start_buf;

	chr_result = ft_strichr_nl(buf, ret2); // check etat buf 
	if (chr_result == -2) // si buf vide, on le rempli
		ret2 = read(fd, buf, BUFFER_SIZE);
	start_buf = 0;
	while (*buf == '\0' && start_buf < BUFFER_SIZE)
		start_buf++;
	chr_result = ft_strichr_nl(buf, ret2); // check etat buf 
	while ((chr_result < 0 && chr_result != -3 && ret2 > 0) || chr_result == -1) // si pas de new line, read et joint jusqua new line
	{
		if (chr_result == -1)
			chr_result = BUFFER_SIZE;
		ft_strjoin_gnl(&*line, *line, buf, chr_result);
		ret2 = read(fd, buf, BUFFER_SIZE);
		chr_result = ft_strichr_nl(buf, ret2);
	}
	if (chr_result == -3)
		chr_result = 1;
	if (chr_result == -2)
		chr_result = start_buf;
	ft_strjoin_gnl(&*line, *line, buf, chr_result);
	return(ret2);
}

char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	char			*line;
	int				ret;

	if (BUFFER_SIZE == 0)
		return(NULL);
	line = ft_strdup("");
	ret = 0;
	ft_read(fd, ret, buf, &line);
	ret = ft_strlen(line);
	if (ret == 0)
	{
		if (line)
			free(line);
		return(NULL);
	}
	return(line);
}
//TODO: penser a protege strdup // gerer le segfault de fin, voir malloc dans gnl