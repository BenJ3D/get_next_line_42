/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/06 15:04:51 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/libft.h"
#include "get_next_line.h"

static char	*ft_copy_after_n(char *str) //// !!!!!!!!!!!!!
{
	static int		i;
	int		len;
	char	*cpy;

	len = ft_strlen(&str[i]);
	if (!str)
		return (NULL);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (0);
	i = 0;
	while (str[i] != '\n')
		i++;
	if (str[i + 1] != '\0')
		i++;
	ft_strlcpy(cpy, &str[i], len);
	cpy[len] = '\0';
	return (cpy);
}
char	*get_next_line(int fd)
{	
	size_t			ret;
	char			buf[BUFFER_SIZE + 1];
	size_t			i;
	char			*tmp;
	int				bool;
	static char		*after_n = NULL;

	printf ("%s\n", after_n);
	i = 0;
	bool = 0;
	if (!tmp)
		tmp = ft_strdup("");
	ft_bzero(buf, BUFFER_SIZE);
	printf ("buf init: %s\n", buf);
	if (after_n != NULL)
	{
		tmp = ft_strjoin_gnl(after_n, tmp, i);
		after_n = ft_copy_after_n(tmp);
		printf("\nRESTANT after1:%s\n", after_n);
		return (tmp);
	}
	while (1/*&& after_n == NULL*/)   // boucle principale, decoupe au premier \n
	{
		if (ft_strchr(after_n, '\n'))
			buf = ft_copy_after_n(after_n);
		if (!ft_strchr(after_n, '\n'))
		{
			ret = read(fd, buf, BUFFER_SIZE);
			buf[ret] = '\0';
		}
		after_n = ft_copy_after_n(buf);
		printf("\nRESTANT :%s\n", after_n);
		printf ("\nBUFFER :%s\n", buf);
		i = 0;
		while (i <= ret && after_n != NULL)
		{
			if (buf[i] == '\n')
			{
				bool = 1;
				i++;
				tmp = ft_strjoin_gnl(tmp, buf, i);
				printf("tmp = %s\n", tmp);
				return (tmp);
				break ;
			}
			if (i == ret)
			{
				tmp = ft_strjoin_gnl(tmp, buf, i);
				printf("tmp = %s\n", tmp);
				return (tmp);
				break ;
			}
			i++;
		}
		if (bool == 1) // si \n trouvé
		{
			printf("tmp = %s\n", tmp);
			tmp = ft_strjoin_gnl(tmp, buf, i);
			printf("tmp = %s\n", tmp);
			ft_copy_after_n(tmp);
			return (tmp);
			i = 0;
		}
		tmp = ft_strjoin_gnl(tmp, buf, i);
		bool = 0;
	}


	tmp = ft_strjoin_gnl(tmp, buf, i);
	return (tmp);
}

static char	*manage_n(char *str)
{
	int		i;
	char	*tmp2;

	i = 0;
	tmp2 = ft_calloc(BUFFER_SIZE, sizeof(char));
	while (str[i])
	{
		if (str[i] ==  '\n')
		{
			ft_strlcpy(tmp2, str, i);
			return (tmp2);
		}
	}
	return (tmp2);
}

// if (read(fd, buf, 0) < 0)
// 		return (NULL);
// 	while (!ft_strchr(str, '\n') && i != 0)
// 	{
// 		i = read(fd, buf, BUFFER_SIZE);
// 		if (i < 0)
// 			return (0);
// 		buf[i] = '\0';
// 		str = ft_strjoin(str, buf);
// 		if (!str)
// 			return (0);
// 	}
// 	if (ft_strchr(str, '\n'))
// 		return (extract_nl(&str));