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

void modifystr(char *str, char *dest)
{

    int i;
    
    i = 0;
    while(i < 10)
    {
        str[i] = 'A';
        dest[i] = 'B';
        i++;
    }
}

int main()
{
    static char    line[12];
    char    *dest;
    
    dest = malloc(sizeof(char) * 1000);
    printf("avant  %s\n", line);
    printf("avant  %s\n", dest);
    modifystr(line, dest);
    printf("apres  %s\n", line);
    printf("apres  %s\n", dest);

    return 0;
}
