/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/11/25 19:38:53 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../libft/libft.h"
#include "get_next_line.h"
#define BUFFER_SIZE 13

char	*get_next_line(int fd)
{	
	int			ret;
	static char	*buf[BUFFER_SIZE + 1];
	char		*tmp;

	// if (!buf)
	// 	*buf = NULL;
	ret = read(fd, buf, BUFFER_SIZE);
	buf[ret] = '\0';
	tmp = ft_strdup("");
	tmp = ft_strjoin_gnl(buf, tmp);
	return (buf);
}

int	main(void)
{
	int		fd;

	char	path[] = "./42";
	fd = open(path, O_RDONLY);
		printf("BUFFER_SIZE = : %d\n", BUFFER_SIZE);
		printf("fd : %d\n\n\n", fd);
		
		printf("%s\n", get_next_line(fd));

	return (0);
}	




//ret = read(fd, buf, BUFFER_SIZE);
