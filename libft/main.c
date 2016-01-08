#include "Include/libft.h"
#include <stdio.h>

int main(void)
{
	char str[] = "toto:titi:tutu:toutou\0";
	char **ptr;

	dprintf(2, "On lance le test\n");
	ptr = ft_strsplit_v2(&str[0], ':');
	printf("test : %s, %s, %s, %s, %s\n", ptr[0], ptr[1], ptr[2], ptr[3], ptr[4]);
	return (0);
}
