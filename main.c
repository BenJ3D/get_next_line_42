/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:31:54 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/07 18:01:06 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int			fd;
	//char	path1[] = "./bible.txt";
	char	path1[] = "./42";
    static char    *buff;
    int     ret;
    char temp[BUFFER_SIZE + 1];

	fd = open(path1, O_RDONLY);
	//fd = 2;
	printf("BUFFER_SIZE = : %d\n", BUFFER_SIZE);
	printf("fd : %d\n\n", fd);


	printf("1er appel :\n%s\n", get_next_line(fd));
	printf("2nd appel :\n%s\n", get_next_line(fd));
	printf("3me appel :\n%s\n", get_next_line(fd));
	// printf("4me appel :\n%s\n", get_next_line(fd));
	return (0);
}	