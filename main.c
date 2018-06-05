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
	ret = printf("original = salut\n");
	printf("original = [%d] [17]\n", ret);
	ret = 0;
	ret = ft_printf("copie    = salut\n");
	printf("copie    = [%d] [17]\n", ret);
	ret = 0;
	ret = printf("original = salut [%s]\n", "cava");
	printf("original = [%d] [24]\n", ret);
	ret = 0;
	ret = ft_printf("copie    = salut [%s]\n", "cava");
	printf("copie    = [%d] [24]\n", ret);
	return (0);
}
