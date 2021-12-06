/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bducrocq <bducrocq@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:00:04 by bducrocq          #+#    #+#             */
/*   Updated: 2021/12/06 18:46:52 by bducrocq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "../libft/libft.h"
#include "get_next_line.h"

// static char	*ft_copy_after_n(char *str)
// {
// 	static int		i;
// 	int		len;
// 	char	*cpy;

// 	return (cpy);
// }

// static char	*extract_nl(char *str)
// {

	
// }
static char	*ft_copy_after_n(char *str) //// !!!!!!!!!!!!!
{
	static int	i = 0;
	int			len;
	char		*cpy;

	while (str[i] != '\n' && str[i + 1] != '\0')
		i++;
	len = ft_strlen(&str[i]);
	if (!str)
		return (NULL);
	cpy = malloc((len + 1) * sizeof(char));
	if (!cpy)
		return (0);
	//i = 0;
	// while (str[i] != '\n' && str[i + 1] != '\0')
	// 	i++;
	ft_strlcpy(cpy, &str[i+1], len);
	//cpy[len] = '\0';
	if (ft_strchr(str, '\n'))
		i = 0;	
	return (cpy);
}

char	*get_next_line(int fd)
{	
	char			buf[BUFFER_SIZE + 1];
	size_t			i;
	static char			*str = NULL;
	//static char		*after_n = NULL;

	if (read(fd, buf, 0) < 0)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)  // boucle tant que pas de \n ou ret 0
	{
		i = read(fd, buf, BUFFER_SIZE);	// protege un cas error si read -1
		if (i < 0)
			return (0);
		buf[i] = '\0';
		str = ft_strjoin(str, buf);
		if (!str)
			return (0);
	}
}

// static char	*manage_n(char *str)
// {
// 	int		i;
// 	char	*tmp2;

// 	i = 0;
// 	tmp2 = ft_calloc(BUFFER_SIZE, sizeof(char));
// 	while (str[i])
// 	{
// 		if (str[i] ==  '\n')
// 		{
// 			ft_strlcpy(tmp2, str, i);
// 			return (tmp2);
// 		}
// 	}
// 	return (tmp2);
// }

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