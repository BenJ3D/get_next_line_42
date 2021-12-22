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

	i = 0;
	if (BUFFER_SIZE == 1 && str[i] == '\n')		//renvoi -3 si nl trouvé avec buffsize a 1 // FIXME:
		return (-3);
	i = 0;
	while (i < BUFFER_SIZE)  // FIXME:
	{
		if (str[i] == '\n')		//renvoi i si nl trouvé
			return (i);
		i++;
	}
	if (i != BUFFER_SIZE)
		i = 0;
	while (i < BUFFER_SIZE && i != BUFFER_SIZE)
	{
		if (str[i] != '\0')		//renvoi -1 si char trouvé
			return (-1);
		i++;
	}
	if (ret == BUFFER_SIZE) //TODO: sortir de la fonction
	{
		i = BUFFER_SIZE;
		while (str[i])
		{
			i--;
			if (str[i] != '\0')
				return(i);
		}
	}
	while(i <)
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
// int	ft_read(int	fd, int ret, char *buf, char **line)
// {
// 	int	chr_result;

// 	chr_result = -1;
// 	while(chr_result < 0)
// 	{
// 		if (ft_strichr_nl(buf) >= 0 || ft_strichr_nl(buf) == -1)
// 		{
// 			ft_strjoin_gnl(&*line, *line, buf, BUFFER_SIZE);
// 			ft_buf_process(buf, 0);
// 		}
// 		//////
// 		ret = read(fd, buf, BUFFER_SIZE);
// 		chr_result = ft_strichr_nl(buf);		// return >= 0 pour position \n // -1 si char trouvé sans nl // -2 si vide
// 		if (ret < BUFFER_SIZE && *line[0] != '\0') // moins de char lu que buffer_size donc fin de fichier
// 		{
// 			ft_strjoin_gnl(&*line, *line, buf, BUFFER_SIZE);
// 			return(1); // pour ne pas end of text
// 		}
// 		if ((chr_result >= 0 || chr_result == -3) && ret >= BUFFER_SIZE)
// 		{
// 			ft_strjoin_gnl(&*line, *line, buf, chr_result);
// 			ft_buf_process(buf, ret);
// 			break ; // FIXME:
// 		} // nl trouvé
// 		if (chr_result == -1 && ret >= BUFFER_SIZE) // char trouvé sans nl
// 		{
// 			ft_strjoin_gnl(&*line, *line, buf, BUFFER_SIZE); // renvoi -3 si nl trouvé // -1 si char trouvé sans nlFIXME:
// 			ft_buf_process(buf, ret);
// 		}
// 		if (chr_result == -2 && ret >= BUFFER_SIZE) // chaine vide
// 			*line = ft_strdup("buf est NULL");
// 	}
// 	return(ret);
// }
static int	ft_read(int	fd, int ret2, char *buf, char **line)
{
	int	chr_result;
	int	ret;
	int	start_buf;

	chr_result = ft_strichr_nl(buf, ret); // check etat buf 
	if (chr_result == -2) // si buf vide, on le rempli
		ret = read(fd, buf, BUFFER_SIZE);
	// ft_up_to_char(buf);
	while (*buf == '\0' && start_buf < BUFFER_SIZE)
		start_buf++;
	chr_result = ft_strichr_nl(buf, ret);
	while (chr_result < 0 && chr_result != -3 && ret > 0) // si pas de new line, read et joint jusqua new line
	{
		ft_strjoin_gnl(&*line, *line, buf, chr_result);
		ret = read(fd, buf, BUFFER_SIZE);
		chr_result = ft_strichr_nl(buf, ret);
	}
	ft_strjoin_gnl(&*line, *line, buf, chr_result);
	return(ret);
}

char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	char			*line;
	int				ret;

	if (BUFFER_SIZE == 0)
		return(NULL);
	line = ft_strdup("");
	ret = ft_read(fd, ret, buf, &line);
	if (ft_strlen(line) < BUFFER_SIZE && ret == 0)
	{
		if (line)
			free(line);
		return(NULL);
	}
	return(line);
}
//TODO: penser a dl strdup // gerer le segfault de fin, voir malloc dans gnl