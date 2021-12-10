/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/10 22:57:15 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strichr(const char *s, int c)	// analyse buff qui peut commencer par des 0
{	
	int	i;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	i = 0;
	while (s[i] == '\0')
	{
		if (i == BUFFER_SIZE)
			return(-1);   //si rien dans buf, que des 0, return -1
		i++;
	}
	return (BUFFER_SIZE); // si pas de \n mais char trouvé
}

static size_t	ft_strlen_gnl(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
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

static char	*get_line(char *str)
{

	return (NULL);
}

char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	int				ret;
	int				start;
	int				eol;
	char			*line;

	ret = 1;
	line = ft_strdup("");
	eol = ft_strichr(buf, '\n');
	if (ft_strichr(buf, '\n') != BUFFER_SIZE && eol != -1)
	{
		//eol = ft_strichr(buf, '\n');
		line = ft_strjoin_gnl(line, buf, eol);
	}
	if (eol == BUFFER_SIZE)
	{
		line = ft_strjoin_gnl(line, buf, eol);
		ft_buf_process(buf); // met a zero jusquau \n
	}
	while ((ft_strichr(buf, '\n') == BUFFER_SIZE || ft_strichr(buf, '\n') == -1) && ret != 0)	// boucle tant que pas de \n ou ret 0 
	{
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (ret <= 0)
			return (0);
		buf[ret] = '\0';
		eol = ft_strichr(buf, '\n');
		// if (eol == -1)
		// 	eol = BUFFER_SIZE; 
		line = ft_strjoin_gnl(line, buf, eol); // modifier le joint pour prendre en compte lindex	
		// ft_buf_process(buf); // met a zero jusquau \n
	}
	ft_buf_process(buf); // met a zero jusquau \n
	
	// line = get_line(line); // TODO: ajouter buf en param pour mettre a zero avant \n
	// eol = ft_strichr(buf, '\n');
	
	//ft_strichr lire le buf, index juskau \n return position du n ou -1 
		// if (ft_strichr >= 0)
		// 	ft_strlcpy(line, buf, ft_strichr(buf));
		//si strichr >= 0 copier jusqua la position et remplir de zero
	return(line);
}
