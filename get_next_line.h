/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:56:31 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/20 23:43:57 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
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
void			ft_strjoin_gnl(char **dst, char *src1, char *src2, int buf_end);
int				ft_buf_process(char *bufp, int ret);
int				ft_strichr_nl(char *str);
//void			*ft_calloc(size_t count, size_t size);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(char *str);
//void			*ft_memset(void *b, int c, size_t len);

#endif