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

	(void)argc;
	(void)argv;
	ret = 0;
	printf("---------\nft_printf\n---------\n");
	ret = ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = ft_printf("[j'ai [%+010d] ans, [%-10d] je vais bien,\n[%10s] oui j'ai un [%5cccent%-10c]\n",
		26, -15, "et toi ?", 'a', '.');
	printf("retour = [%d]\n\n", ret);
	printf("---------\nprintf\n---------\n");
	ret = printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = printf("[j'ai [%+010d] ans, [%-10d] je vais bien,\n[%10s] oui j'ai un [%5cccent%-10c]\n",
		26, -15, "et toi ?", 'a', '.');
	printf("retour = [%d]\n", ret);


	printf("---------\nft_printf\n---------\n");
	ret = ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = ft_printf("[j'ai [%010d] ans, [%-10s] je vais bien,\n[%10s] oui j'ai un [%5cccent%-10c]\n",
		-26, "oui", "et toi ?", 'a', '.');
	printf("retour = [%d]\n\n", ret);
	printf("---------\nprintf\n---------\n");
	ret = printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = printf("[j'ai [%010d] ans, [%-10s] je vais bien,\n[%10s] oui j'ai un [%5cccent%-10c]\n",
		-26, "oui", "et toi ?", 'a', '.');
	printf("retour = [%d]\n", ret);
	


	printf("---------\nft_printf\n---------\n");
	ret = ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = ft_printf("[j'ai [%+10d] ans, [%-10d] je vais bien,\n[%10s] oui j'ai un [%5cccent%-10c]\n",
		+26, -15, "et toi ?", 'a', '.');
	printf("retour = [%d]\n\n", ret);
	printf("---------\nprintf\n---------\n");
	ret = printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = printf("[j'ai [%+10d] ans, [%-10d] je vais bien,\n[%10s] oui j'ai un [%5cccent%-10c]\n",
		+26, -15, "et toi ?", 'a', '.');
	printf("retour = [%d]\n", ret);

	printf("---------\nft_printf\n---------\n");
	ret = ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = ft_printf("[j'ai [%+-10d] ans, [%-+10d] je vais bien,\n[%10s] oui j'ai un [%5cccent%-10c]\n",
		+26, 15, "et toi ?", 'a', '.');
	printf("retour = [%d]\n\n", ret);
	printf("---------\nprintf\n---------\n");
	ret = printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = printf("[j'ai [%+-10d] ans, [%-+10d] je vais bien,\n[%10s] oui j'ai un [%5cccent%-10c]\n",
		+26, 15, "et toi ?", 'a', '.');
	printf("retour = [%d]\n", ret);
	
	return (0);
}

