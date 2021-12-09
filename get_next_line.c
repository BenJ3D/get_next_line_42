/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/09 18:01:36 by bducrocq         ###   ########.fr       */
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
		if (s[i] != '\n')
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

char	*ft_strjoin_gnl(char *s1_line, char *s2_buf, int buf_end, int start_join)
{
	size_t	i;
	size_t	j;
	int		len_s1;
	int		len_s2;
	char	*str;

	len_s1 = ft_strlen(s1_line);
	len_s2 = ft_strlen(s2_buf);
	// TODO: gerer le joint si s1_line ou s2_buf sont vide -->> strdup ?
	if (!s1_line)
		s1_line = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!s2_buf)
		s2_buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	str = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1_line[i])
		str[j++] = s1_line[i++];
	i = 0;
	while (start_join != 0)
	{
		str[j++] = s2_buf[i++];
		start_join--;
	}
	str[j] = '\0';
	free(s1_line);
	//free(s2_buf);
	return (str);
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
while (!(ft_strichr(line, '\n') == -1) && ret != 0)	// boucle tant que pas de \n ou ret 0 
	{
		eol = ft_strichr(buf, '\n');
		if (eol == -1)
			eol = BUFFER_SIZE; 
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (ret <= 0)
			return (0);
		buf[ret] = '\0';
		line = ft_strjoin_gnl(line, buf, BUFFER_SIZE, ft_strichr(buf, '\n')); // modifier le joint pour prendre en compte lindex	
	}
	//ft_strichr lire le buf, index juskau \n return position du n ou -1 
		// if (ft_strichr >= 0)
		// 	ft_strlcpy(line, buf, ft_strichr(buf));
		//si strichr >= 0 copier jusqua la position et remplir de zero
	return(line);
}
