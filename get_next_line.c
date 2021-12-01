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
	static char		buf[BUFFER_SIZE + 1];
	size_t		i;
	char		*tmp;
	int			bool;
	int			j;

	i = 0;
	j = 1;
	bool = 0;
	tmp = ft_strdup("");
	ret = read(fd, buf, BUFFER_SIZE);
	printf ("buf : %s\n", buf);
	while (j > 0)
	{
		i = 0;
		while (i < ret)
		{
			if (buf[i] == '\n' || i == ret)
			{
				bool = 1;
				buf[i + 1] = '\0';
				tmp = ft_strjoin_gnl(tmp, buf);
				return (tmp);
				break ;
			}
			//printf(" %c : %d\n", buf[i], bool);
			i++;
		}
		//printf("bool = %d \n", bool);
		if (bool != 1)
		{
		tmp = ft_strjoin_gnl(tmp, buf);
		// ret = read(fd, buf, BUFFER_SIZE);
		i = 0;
		j++;
		}
	}
	tmp = ft_strjoin_gnl(tmp, buf);
	//tmp = ft_strjoin_gnl(tmp, "coucou");
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
