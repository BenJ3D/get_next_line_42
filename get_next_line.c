/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/11/29 14:35:26 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/libft.h"
#include "get_next_line.h"
#define BUFFER_SIZE 21

// static int	find_char(char *str)
// {
// 	return (0);

// }


char	*get_next_line(int fd)
{	
	size_t				ret;
	char				buf[BUFFER_SIZE + 1];
	static int			i = 0;
	char				*tmp;
	int					bool;

	tmp = ft_strdup("");
	while (tmp[i] != '\n')	
	{
		ret = read(fd, buf, BUFFER_SIZE);
		tmp = ft_strjoin_gnl(buf, tmp);
		i++;
	}

	buf[ret] = '\0';
	return (tmp);
}

int	main(void)
{
	int			fd;
	static char	path1[] = "./42";

	fd = open(path1, O_RDONLY);
	//fd = 2;
	printf("BUFFER_SIZE = : %d\n", BUFFER_SIZE);
	printf("fd : %d\n\n", fd);
	printf("1er appel :\n%s\n\n", get_next_line(fd));
	// printf("2nd appel :\n%s\n\n", get_next_line(fd));
	// printf("3me appel :\n%s\n", get_next_line(fd));
	return (0);
}	
