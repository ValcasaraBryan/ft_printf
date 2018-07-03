/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:32:52 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/05 17:32:54 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		main(int argc, char **argv)
{
	int ret;
	int ret_2;

	(void)argc;
	(void)argv;
	ret = 0;
	ret_2 = 0;
	ret = ft_printf("[j'ai [%+010d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, -15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%+010d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, -15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%+010d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, -15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%+010d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, -15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%010d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, -15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%010d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, -15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%010d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, -15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%010d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, -15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%010d] ans, [%s] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		-26, "oui", "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%010d] ans, [%s] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		-26, "oui", "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%0+10d] ans, [%s] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		-26, "oui", "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%0+10d] ans, [%s] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		-26, "oui", "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%+-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%+-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%+-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%+-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%-10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		+26, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%10d] ans, [%d] je vais bien,\n[%s] oui j'ai un [%cccent%c]\n",
		26, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%10hld] ans, [%d] je vais bien,\n[%-10s] oui j'ai un [%cccent%c]\n",
		99999, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%10hld] ans, [%d] je vais bien,\n[%-10s] oui j'ai un [%cccent%c]\n",
		99999, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");
	
	ret = ft_printf("[j'ai [%10hhd] ans, [%d] je vais bien,\n[%-10s] oui j'ai un [%cccent%c]\n",
		130, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%10hhd] ans, [%d] je vais bien,\n[%-10s] oui j'ai un [%cccent%c]\n",
		130, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%10ld] ans, [%d] je vais bien,\n[%-10s] oui j'ai un [%cccent%c]\n",
		4294967296, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%10ld] ans, [%d] je vais bien,\n[%-10s] oui j'ai un [%cccent%c]\n",
		4294967296, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%10lld] ans, [%d] je vais bien,\n[%-10s] oui j'ai un [%cccent%c]\n",
		9223372036854775808, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%10lld] ans, [%d] je vais bien,\n[%-10s] oui j'ai un [%cccent%c]\n",
		9223372036854775808, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ret = ft_printf("[j'ai [%hhu] ans, [%d] je vais bien,\n [%s] oui j'ai un [%ccccent%c]\n",
		0, 15, "et toi ?", 'a', '.');
	ret_2 = printf("[j'ai [%hhu] ans, [%d] je vais bien,\n [%s] oui j'ai un [%ccccent%c]\n",
		0, 15, "et toi ?", 'a', '.');
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");
	printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	return (0);
}
