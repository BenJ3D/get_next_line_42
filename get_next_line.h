/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benasusmac <benasusmac@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:56:31 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/02 00:32:29 by benasusmac       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# define BUFFER_SIZE 60
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./includes/libft.h"

// typedef struct s_list
// {
// 	tmp			*content;
// 	struct s_list	*next;
// }					t_list;

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2);

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 2
// # endif

#endif