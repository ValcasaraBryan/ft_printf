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

	ret = ft_printf("[%d][%D][%s%5%][%-2Ccccent%2c][%-11pp][%-4xx%%][%-#4xx][%-3XX][%-#4XX][%-10uu][%-15UU][%-3oo][%-17OO]\n",
			214847480, 15, "et toi ?", 97, '.',      "salut", 80,      80,    80,     80,     9,     1,    8,     8);
	ret_2 =  printf("[%d][%D][%s%5%][%-2Ccccent%2c][%-11pp][%-4xx%%][%-#4xx][%-3XX][%-#4XX][%-10uu][%-15UU][%-3oo][%-17OO]\n",
			214847480, 15, "et toi ?", 97, '.',      "salut", 80,      80,    80,     80,     9,     1,    8,     8);
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	return (0);
}
