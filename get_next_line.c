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

int	ft_strichr(char *s, int c)	// analyse buff qui peut commencer par des 0
{	
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == c)
			return (i);
		else if ( s[i] == '\0')
			return(-1);
		i++;
	}
	return (BUFFER_SIZE); // si pas de \n mais char trouvé
}

int	ft_buf_process(char *bufp, int *ret) // met des zero jusquau \n
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
	return (ft_strichr(bufp, '\n'));
}

void	ft_read(int	*fd, int *ret, char **buf)
{
	while (1)	// boucle tant que pas de \n ou ret 0 FIXME: ret buff attention
	{
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		while (ret != BUFFER_SIZE)
		{
			buf[ret] = '\0'; // TODO: mettre a zero jusqua buffer size
			ret++;
		}
	}

}
char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	int				*ret;
	int				eol;
	char			**line;

	*line = ft_strdup("");
	while ((eol == BUFFER_SIZE || eol != -1))	// boucle tant que pas de \n ou ret 0 FIXME: ret buff attention
	{
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (ret <= 0)
			return (NULL);
		while (ret != BUFFER_SIZE)
		{
			buf[ret] = '\0'; // TODO: mettre a zero jusqua buffer size
			ret++;
		}
		eol = ft_strichr(buf, '\n');
		ft_strjoin_gnl(&line, buf, eol);
		// if (ret < BUFFER_SIZE)
		// 	return(line); // modifier le joint pour prendre en compte lindex
	}
	ft_buf_process(buf, ret); // met a zero jusquau \n
	// if (ret < BUFFER_SIZE) // FIXME:
	// 	line = ft_strjoin_gnl(line, buf, eol);
	return(line);
}
