/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:56:31 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/31 00:40:41 by bducrocq         ###   ########.fr       */
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

char			*get_next_line(int fd);
void			ft_strjoin_gnl(char **dst, char *src1, char *src2, size_t buf_end);
int				ft_buf_process(char *bufp);
int				ft_strichr_nl(char *str);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *str);
void			*ft_memset(void *b, int c, size_t len);

#endif