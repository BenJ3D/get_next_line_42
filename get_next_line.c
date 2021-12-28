/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/28 17:25:43 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strichr_nl(char *str, size_t ret)
{	
	size_t	i;
	
	if (BUFFER_SIZE == 1 && str[0] == '\n')		//renvoi -3 si nl trouvé avec buffsize a 1 // FIXME:
		return (-3);
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
		if (str[i] != '\0')		//renvoi -1 si char trouvé sans nl
			return (-1);
		i++;
	}
	ret = 1;
	return (-2); // renvoi -2 si completement vide
}

int	ft_buf_process(char *bufp) // met des zero jusquau \n
{
	size_t	i;
	size_t	j;


	i = 0;
	// while (*bufp != '\n')
	// {
	// 	if (i == BUFFER_SIZE) //FIXME: attention
	// 		break ;
	// 	*bufp = '\0';
	// 	bufp++;
	// 	i++;
	// }
	// *bufp = '\0';
	while (bufp[j] != '\n')
	
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
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
	if(ret2 == 0 && start_buf != BUFFER_SIZE)  // FIXME: pour segfaut de une ligne
		return (0);
	if (chr_result == -3)
		chr_result = 1;
	if (chr_result == -2) // buf est vide
	{
		chr_result = ft_strlen(*line); // FIXME: = startbuf
		if (chr_result != 0)
			return (0);
	}
	if(ret2 == 0 && chr_result == 0)  // FIXME: pour segfaut de une ligne
		return (0);
	ft_strjoin_gnl(&*line, *line, buf, chr_result);
	return(ret2);
}

// static int	ft_read(int	fd, int ret2, char *buf, char **line)
// {
// 	int	chr_result;
// 	int	start_buf;

// 	chr_result = ft_strichr_nl(buf, ret2); // check etat buf 
// 	if (chr_result == -2) // si buf vide, on le rempli
// 		ret2 = read(fd, buf, BUFFER_SIZE);
// 	start_buf = 0;
// 	while (*buf == '\0' && start_buf < BUFFER_SIZE)
// 		start_buf++;
// 	chr_result = ft_strichr_nl(buf, ret2); // check etat buf 
// 	while ((chr_result < 0 && chr_result != -3 && ret2 > 0) || chr_result == -1) // si pas de new line, read et joint jusqua new line
// 	{
// 		if (chr_result == -1)
// 			chr_result = BUFFER_SIZE;
// 		ft_strjoin_gnl(&*line, *line, buf, chr_result);
// 		ret2 = read(fd, buf, BUFFER_SIZE);
// 		chr_result = ft_strichr_nl(buf, ret2);
// 	}
// 	if(ret2 == 0 && start_buf != BUFFER_SIZE)  // FIXME: pour segfaut de une ligne
// 		return (0);
// 	if (chr_result == -3)
// 		chr_result = 1;
// 	if (chr_result == -2) // buf est vide
// 	{
// 		chr_result = ft_strlen(*line); // FIXME: = startbuf
// 		if (chr_result != 0)
// 			return (0);
// 	}
// 	if(ret2 == 0 && chr_result == 0)  // FIXME: pour segfaut de une ligne
// 		return (0);
// 	ft_strjoin_gnl(&*line, *line, buf, chr_result);
// 	return(ret2);
// }

char	*get_next_line(int fd)
{	
	static char 	buf[BUFFER_SIZE + 1];
	char			*line;
	int				ret;

	 if (read(fd, buf, 0) < 0)
		return (NULL);
	if (BUFFER_SIZE == 0 || fd < 0)
		return (NULL);
	line = ft_strdup("");
	ret = 0;
	ret = ft_read(fd, ret, buf, &line);
	ret = ft_strlen(line);
	if (ret == 0)
	{
		if (line)
			free(line);
		return(NULL);
	}
	return(line);
}