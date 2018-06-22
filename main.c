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
	ret = ft_printf("salut [%11s] hey|\n", "cava");
	ret = ft_printf("salut [%11c] hey|\n", 'l');
	ret = ft_printf("salut [%11d] hey|\n", 48);
	ret = ft_printf("salut [%11d] hey|\n", 0);
	ret = ft_printf("salut [%11d] hey|\n", -1);
	ret = ft_printf("salut [%11d] hey|\n", 1234567890);
	ret = ft_printf("salut [%11d] hey|\n", -1234567890);
	printf("retour = [%d]\n\n", ret);

	ret = printf("salut [%11s] hey|\n", "cava");
	ret = printf("salut [%11c] hey|\n", 'l');
	ret = printf("salut [%11d] hey|\n", 48);
	ret = printf("salut [%11d] hey|\n", 0);
	ret = printf("salut [%11d] hey|\n", -1);
	ret = printf("salut [%11d] hey|\n", 1234567890);
	ret = printf("salut [%11d] hey|\n", -1234567890);
	printf("retour = [%d]\n", ret);
	return (0);
}
