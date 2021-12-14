/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:31:54 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/14 18:14:41 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PATH path1
#include "get_next_line.h"
// /*fonctions pour changer couleur des print f*/
void red () { printf("\033[1;31m"); }
void yellow () { printf("\033[1;33m"); }
void green (){  printf("\033[0;32m");}
void blue (){  printf("\033[0;34m");}
void black (){  printf("\033[0;30m");}
void purple (){  printf("\033[1;35m");}
void cyan (){  printf("\033[0;36m");}
void white (){  printf("\033[0;37m");}
void reset (){  printf("\033[0m");}

int	main(void)
{
	int			fd;
	char	path2[] = "./bible.txt";
	char	path3[] = "./a";
	char	path1[] = "./42";
	int	i = 1; // compte les lignes
	char *str;

	fd = open(PATH, O_RDONLY);
	// fd = 2;
		purple();
	printf("\nBUFFER_SIZE = : %d\n", BUFFER_SIZE);
		printf("fd : %d\n\n", fd);

	reset();
	while((str = get_next_line(fd)) /*&& i < 13*/)
	{
		cyan();
		printf("%.2d |", i);
		reset();
		printf("%s", str);
		free(str);
		i++;
	}
	printf("%s", str);
	close(fd);
	// printf("1er appel :\n%s\n", get_next_line(fd));
	// printf("2nd appel :\n%s\n", get_next_line(fd));
	// printf("3me appel :\n%s\n", get_next_line(fd));
	// printf("4me appel :\n%s\n", get_next_line(fd));
	return (0);
}	