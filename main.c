#include "get_next_line.h"


int	main(void)
{
	int			fd;
	char	path1[] = "./42";
    static char    *buff;
    int     ret;
    char temp[BUFFER_SIZE + 1];


	// char	test2[] = " les coupains";
	// char	test[] = "coucou";
	// char	yo[100];

	fd = open(path1, O_RDONLY);
	//fd = 2;
	printf("BUFFER_SIZE = : %d\n", BUFFER_SIZE);
	printf("fd : %d\n\n", fd);
	//printf("%s\n\n", get_next_line(fd));
	//printf("debugg ===>>%s\n\n", ft_strjoin_gnl(test, test2));

	printf("1er appel :\n%s\n\n", get_next_line(fd));
	printf("2nd appel :\n%s\n\n", get_next_line(fd));
	printf("3me appel :\n%s\n", get_next_line(fd));
	printf("4me appel :\n%s\n", get_next_line(fd));
//     temp = ft_strdup("");
//     buff = ft_strdup("");
//     ret = read(fd, buff, BUFFER_SIZE);
//     printf("1 : %s\n", buff);
//     temp = ft_strjoin(buff + ret, temp);
//      read(fd, buff, BUFFER_SIZE);
//    printf("2 : %s ; %s \n", buff, temp);
//       read(fd, buff, BUFFER_SIZE);
//     printf("3 : %s\n", buff);
	return (0);
}	