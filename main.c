/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:31:54 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/06 16:52:42 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// int	main(void)
// {
// 	char	str[] = "Mon Ami Est Un Genie\nJules Delavigne";
// 	char	str2[100];
// 	int	i;

// 	i = 0;
// 	while (str[i] != '\n')
// 		i++;

// 	printf("%s\n", &str[i]);
// 	printf("%zu\n", ft_strlen(str));

// 	printf("%zu\n", ft_strlen(&str[i]));

// 	return (0);
// }	

int	main(void)
{
	int			fd;
	char	path1[] = "./42";
    static char    *buff;
    int     ret;
    char temp[BUFFER_SIZE + 1];

	// char	test2[] = " les coupains";
	// char	test[] = "coucou";
	// char	yo[100];

	fd = open(path1, O_RDONLY);
	//fd = 2;
	printf("BUFFER_SIZE = : %d\n", BUFFER_SIZE);
	printf("fd : %d\n\n", fd);
	//printf("%s\n\n", get_next_line(fd));
	//printf("debugg ===>>%s\n\n", ft_strjoin_gnl(test, test2));

	printf("1er appel :\n%s||\n\n", get_next_line(fd));
	printf("2nd appel :\n%s||\n\n", get_next_line(fd));
	// printf("3me appel :\n%s\n", get_next_line(fd));
	// printf("4me appel :\n%s\n", get_next_line(fd));
	return (0);
}	