/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:56:31 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/11 14:54:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>	
# include <unistd.h>
//# include "./includes/libft.h"

char			*get_next_line(int fd);
char			*ft_strjoin_gnl(char *s1, char *s2, int buf_end);
int				ft_buf_process(char *bufp);
int				ft_strichr(char *s, int c);
//static size_t	ft_strlen(const char *str);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
void			*ft_memset(void *b, int c, size_t len);

#endif