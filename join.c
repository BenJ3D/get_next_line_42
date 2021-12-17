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