/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/11 15:10:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strichr(char *s, int c)	// analyse buff qui peut commencer par des 0
{	
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	i = 0;
	while (s[i] == '\0')  // FIXME: changer c en 0 , erreure ?
	{
		if (i == BUFFER_SIZE)
			return(-1);   //si rien dans buf, que des 0, return -1
		i++;
	}
	return (BUFFER_SIZE); // si pas de \n mais char trouvé
}

int	ft_buf_process(char *bufp)
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
	return (ft_strichr(bufp, '\n'));
}

char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	int				ret;
	int				eol;
	char			*line;

	ret = 1;
	line = ft_strdup("");
	eol = ft_strichr(buf, '\n');
	if (ft_strichr(buf, '\n') != BUFFER_SIZE && eol != -1)
		line = ft_strjoin_gnl(line, buf, eol);
	if (eol == BUFFER_SIZE)
	{
		line = ft_strjoin_gnl(line, buf, eol);
		ft_buf_process(buf); // met a zero jusquau \n
	}
	while ((ft_strichr(buf, '\n') == BUFFER_SIZE || ft_strichr(buf, '\n') == -1) && ret != 0)	// boucle tant que pas de \n ou ret 0 
	{
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (ret <= 0)
			return (NULL);
		buf[ret] = '\0';
		eol = ft_strichr(buf, '\n');
		line = ft_strjoin_gnl(line, buf, eol); // modifier le joint pour prendre en compte lindex	
	}
	ft_buf_process(buf); // met a zero jusquau \n
	return(line);
}
