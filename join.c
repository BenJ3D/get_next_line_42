#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

// void ft_join(char ***dst, char *src1, char *src2)
//  {
// 	int	i;
// 	int	j;
// 	int	srcslen;

// 	i = 0;
// 	while(src1[i])
// 		i++;
// 	srcslen = i;
// 	while(src2[i])
// 		i++;
// 	srcslen = srcslen + i;
// 	dst = malloc(sizeof(char) * srcslen + 1);
// 	j = 0;
// 	i = 0;
// 	while (src1[i])
// 		**dst[j++] = src1[i++];
// 	i = 0;
// 	while (src2[i])
// 		**dst[j++] = src2[i++];
// 	**dst[j] = '\0';
//  }

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return(i);
}

char	modify(char *str)
{
	int	i;

	i = 0;
	str = malloc(sizeof(char) * 600);
	while (str[i])
	{
		str[i] = 'A';
		i++;
	}
}

int main()
{
	char    message[] = "salut les gens, ";
	char    sms[] = "comment allez vous";
	int		total;
	char	*dstjoin;

	
	// printf("%s\n", message);
	// printf("%s\n", sms);
	// ft_join(&dstjoin, message, sms);
	// printf("le join %s\n", dstjoin[0][0]);

	total = 
	printf("le join %s\n", dstjoin);
	dstjoin = modify(dstjoin);
	printf("le join %s\n", dstjoin);
	//free(dstjoin);
	return (0);
}