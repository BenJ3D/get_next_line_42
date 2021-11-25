/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/11/25 17:56:06 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "get_next_line.h"
#define BUFFER_SIZE 12

char	*get_next_line(int fd)
{	
	int			ret;
	static char	buffer[BUFFER_SIZE + 1];

	ret = read(fd, buffer, BUFFER_SIZE);
	buffer[ret] = '\0';
	return (buffer);
}

int	main(void)
{
	int		fd;
	//int		ret;
	//char	buffer[BUFFER_SIZE + 1];
	char	path[] = "./42";

	fd = open(path, O_RDONLY);
		printf("BUFFER_SIZE = : %d\n", BUFFER_SIZE);
		printf("fd : %d\n\n\n", fd);
	// ret = read(fd, buffer, BUFFER_SIZE);
	// buffer[ret] = '\0';
		
		printf("%s\n", get_next_line(fd));
		//printf("%s\n", buffer);

	return (0);
}	




//ret = read(fd, buffer, BUFFER_SIZE);
