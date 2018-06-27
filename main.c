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
	ret = ft_printf("j'ai %d ans, %s je vais bien,\n%s oui j'ai un %cccent%c\n",
		26, "oui", "et toi ?", 'a', '.');
	printf("retour = [%d]\n\n", ret);
	printf("---------\nprintf\n---------\n");
	ret = printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	ret = printf("j'ai %d ans, %s je vais bien,\n%s oui j'ai un %cccent%c\n",
		26, "oui", "et toi ?", 'a', '.');
	printf("retour = [%d]\n", ret);
	return (0);
}
