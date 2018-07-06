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

	ret = ft_printf("[j'ai [%d] ans, [%D] je vais bien,\n [%s%10%] oui j'ai un [%Ccccent%c][%p]\n",
		214847480, 15, "et toi ?", 97, '.', "salut");
	ret_2 = printf("[j'ai [%d] ans, [%D] je vais bien,\n [%s%10%] oui j'ai un [%Ccccent%c][%p]\n",
		214847480, 15, "et toi ?", 97, '.', "salut");
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

//	ret = ft_printf("[j'ai [%p] ans, [%D] je vais bien,\n [%s] oui j'ai un [%Ccccent%c]\n",
//		4294967296, 15, "et toi ?", 'a', '.');
//	ret_2 = printf("[j'ai [%p] ans, [%D] je vais bien,\n [%s] oui j'ai un [%Ccccent%c]\n",
//		4294967296, 15, "et toi ?", 'a', '.');
//	if (ret == ret_2)
//		printf("len -- OK --\n\n");
//	else
//		printf("len // NO //\n\n");

	ft_printf("%s \n", "salut");
	printf("%s \n", "salut");
	printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	return (0);
}
