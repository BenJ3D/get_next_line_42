/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/09 14:33:22 by bducrocq         ###   ########.fr       */
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
	return (tmp);
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
char	*ft_strjoin_gnl(char *s1, char *s2, int buf_end, int size)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1)
		return (0);
	str = ft_calloc(ft_strlen(s1) + size + 1), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] || size != 0)
	{
		str[j++] = s2[i++];
		size--;
	}
	str[j] = '\0';
	free(s1);
	return (str);
}


char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	int				ret;
	int				eol;
	char			*line;

line = ft_strdup("");
while ((ft_strichr(line, '\n') == -1)&& ret != 0)	// boucle tant que pas de \n ou ret 0 TODO:
	{
		eol = ft_strichr(buf);
		if (eol == -1)
			eol = BUFFER_SIZE; 
		ret = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (ret <= 0)
			return (0);
		buf[ret] = '\0';
		line = ft_strjoin_gnl(line, buf, BUFFER_SIZE, eol);
		//if ()
	
	}
	
	return(line);
}
