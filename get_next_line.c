/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benasusmac <benasusmac@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/02 00:33:55 by benasusmac       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/libft.h"
#include "get_next_line.h"
// #define BUFFER_SIZE 4

// static int	find_char(char *str)
// {
// 	return (0);
// }
char	*get_next_line(int fd)
{	
	size_t		ret;
	char	buf[BUFFER_SIZE + 1];
	size_t		i;
	char		*tmp;
	int			bool;
	int			j;

	i = 0;
	j = 0;
	bool = 0;
	tmp = ft_strdup("");
	buf[0] = 'A';
	printf ("buf init: %s\n", buf);
	while (1)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		printf ("buf : %s\n", buf);
		i = 0;
		while (i < ret)
		{
			if (buf[i] == '\n')
			{
				bool = 1;
				buf[i] = '\0';
				tmp = ft_strjoin_gnl(tmp, buf);
				printf("bool = %d\n", bool);
				printf("tmp = %s\n", tmp);
				return (tmp);
				break ;
			}
			if (i == ret)
			{
				tmp = ft_strjoin_gnl(tmp, buf);
				printf("bool = %d\n", bool);
				printf("tmp = %s\n", tmp);
				return (tmp);
				break ;
			} // printf("i = %zu\n", i);
			i++;
		}
		if (bool == 1) // si \n trouvé
		{
			printf("tmp = %s\n", tmp);
			tmp = ft_strjoin_gnl(tmp, buf);
			printf("tmp = %s\n", tmp);
			return (tmp);
			i = 0;
		}
	tmp = ft_strjoin_gnl(tmp, buf);
		bool = 0;
		printf("j = %d\n", j);
		j++;
	}
	tmp = ft_strjoin_gnl(tmp, buf);
	return (tmp);
}

// int	main(void)
// {
// 	int			fd;
// 	static char	path1[] = "./42";
// 	// char	test2[] = " les coupains";
// 	// char	test[] = "coucou";
// 	// char	yo[100];

// 	fd = open(path1, O_RDONLY);
// 	//fd = 2;
// 	printf("BUFFER_SIZE = : %d\n", BUFFER_SIZE);
// 	printf("fd : %d\n\n", fd);
// 	printf("%s\n\n", get_next_line(fd));
// 	//printf("debugg ===>>%s\n\n", ft_strjoin_gnl(test, test2));

// 	// printf("1er appel :\n%s\n\n", get_next_line(fd));
// 	// printf("2nd appel :\n%s\n\n", get_next_line(fd));
// 	// printf("3me appel :\n%s\n", get_next_line(fd));
// 	return (0);
// }	
