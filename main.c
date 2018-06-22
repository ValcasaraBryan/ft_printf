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
//	ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
//	printf("retour = [%d]\n\n", ret);
	ret = ft_printf("salut j'ai %d ans, %s je vais bien, %s oui j'ai un %cccent%c\n", 15, "oui", "et toi ?", 'a', '.');
	printf("retour = [%d]\n\n", ret);

	ret = printf("salut j'ai %d ans, %s je vais bien, %s oui j'ai un %cccent%c\n", 15, "oui", "et toi ?", 'a', '.');
	printf("retour = [%d]\n", ret);
	return (0);
}
