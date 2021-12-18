/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 19:59:46 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/15 19:59:49 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void modifystr(char *str, char **dest)
{

    int i;
    
    i = 0;
	// if(*dest)
	// 	free(*dest);
	*dest = malloc(sizeof(char) * 1000);
    while(i < 10)
    {
        str[i] = 'A';
        dest[0][i] = 'B';
        i++;
    }
	dest[0][i] = '\0';
}


void modifyint(int **n, int swap)
{
	**n = swap;
}
int main()
{
    static char    line[12];
    char    *dest;
	int		*nb;
    
	//nb[0] = 13;
    modifystr(line, &dest);
    printf("apres  %s\n", line);
    printf("apres  %s\n", dest);
	//free(dest);
    // printf("int  %d\n", *nb);
	// modifyint(&nb, 42);
    // printf("int  %d\n", *nb);
    return 0;
}
