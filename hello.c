#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void ft_join(char *dst, char *src1, char *src2)
 {
	int	i;
	int	j;
	int	srclen;
	int src2len;

	i = 0;
	while(src1[i])
		i++;
	srclen = i;
	i = 0;
	while(src2[i])
		i++;
	src2len = i;
	dst = malloc(sizeof(char) * (srclen + src2len + 1));
	j = 0;
	i = 0;
	while (src1[i])
		dst[j++] = src1[i++];
	i = 0;
	while (src2[i])
		dst[j++] = src2[i++];
	dst[j] = '\0';
 }

int main()
{
	char    message[] = "salut les gens, ";
	char    sms[] = "comment allez vous";
	char	*dstjoin;

	printf("%s\n", message);
	printf("%s\n", sms);
	ft_join(dstjoin, message, sms);
	printf("le join %s\n", dstjoin);
	return (0);
}