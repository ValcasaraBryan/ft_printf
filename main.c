
#include <stdio.h>
#include "ft_printf.h"

int main(int argc, char **argv)
{
	int ret;
	ret = printf("salut\n");
	printf("%d\n", ret);
	ret = ft_printf("salut\n");
	printf("%d\n", ret);
	ret = printf("salut [%s]\n", "cava");
	printf("%d\n", ret);
	ret = ft_printf("salut [%s]\n", "cava");
	printf("%d\n", ret);
	return (0);
}