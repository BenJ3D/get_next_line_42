#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
/* fichier test fonctions */
void ft_join_gnl(char **dst, char *src1, char *src2)
 {
	int	i;
	int	j;
	int	srcslen;

	i = 0;
	while(src1[i])
		i++;
	srcslen = i;
	while(src2[i])
		i++;
	srcslen = srcslen + i;
	*dst = malloc(sizeof(char) * srcslen + 1);
	j = 0;
	i = 0;
	while (src1[i])
		dst[0][j++] = src1[i++];
	i = 0;
	while (src2[i])
		dst[0][j++] = src2[i++];
	dst[0][j] = '\0';
 }

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

void	modify(char **str)
{
	int		i;
	int		b = 5;


	i = 0;
	if(*str)
		free(*str);
	
	*str = malloc(sizeof(char) * (b + 1));
	while (i < b)
	{
		str[0][i] = 'A';
		i++;
	}
	str[0][i] = '\0';
//	printf("%s\n", str);
}

int main()
{
	char    message[] = "salut les gens, ";
	char    sms[] = "comment allez-vous ?";
	char	*dstjoin;

	
	printf("message 1 : %s\n", message);
	printf("message 2 : %s\n", sms);
	ft_join_gnl(&dstjoin, message, sms);
	printf("resultat join : %s\n", dstjoin);

	modify(&dstjoin);
	printf("ft modify met que des A : %s\n", dstjoin);
	free(dstjoin);
	return (0);
}