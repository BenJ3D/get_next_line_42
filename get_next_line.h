/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 19:56:31 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/09 19:19:18 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# define BUFFER_SIZE 10 // A SUPRIMER
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./includes/libft.h"

char	*get_next_line(int fd);
char	*ft_strjoin_gnl(char *s1, char *s2, int buf_end);
char	*get_line(char *str);
// char	*ft_strjoin_gnl(char *s1_line, char *s2_buf, int buf_end, int start_join);
int	ft_strichr(const char *s, int c);

#endif