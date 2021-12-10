/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/10 15:38:47 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
// TODO: gerer quand memo est finis mais pas le text"
// TODO: gerer la fin du texte \0
// TODO: problem avec memo -->> gerer quand memo na plus de \n pour re read

int	ft_strichr(const char *s, int c)   // analyse buff qui peut commencer par des 0
{	
	int	i;

	i = 0;

	while (i <= BUFFER_SIZE)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);  // si pas de \n et que s[i] finis, pas de \n donc renvoi -1
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
	while (*bufp != '\n')
	{
		*bufp = '\0';
		bufp++;
	}
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
while ((eol = ft_strichr(buf, '\n') == -1) && ret != 0)	// boucle tant que pas de \n ou ret 0 
	{
		//eol = ft_strichr(buf, '\n');
		if (eol == -1)
			eol = BUFFER_SIZE; 
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (ret <= 0)
			return (0);
		buf[ret] = '\0';
		line = ft_strjoin_gnl(line, buf, BUFFER_SIZE); // modifier le joint pour prendre en compte lindex	
	}
	if (ft_strichr(buf, '\n'))
	{
		eol = ft_buf_process(buf); // met a zero jusquau \n
		line = ft_strjoin_gnl(line, buf, BUFFER_SIZE);
	}
	line = get_line(line); // TODO: ajouter buf en param pour mettre a zero avant \n
	eol = ft_strichr(buf, '\n');
	
	//ft_strichr lire le buf, index juskau \n return position du n ou -1 
		// if (ft_strichr >= 0)
		// 	ft_strlcpy(line, buf, ft_strichr(buf));
		//si strichr >= 0 copier jusqua la position et remplir de zero
	return(line);
}
