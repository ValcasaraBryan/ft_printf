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
	char *str;

	(void)argc;
	(void)argv;
	ret = 0;
	ret_2 = 0;
	str = NULL;
	ret = ft_printf("[%d][%D][%s%2%][%-2Ccccent%2c][%-11p][%-4x%%][%-#4x][%-3X][%-#4X][%-u][%-25UU][%-3o][%-17O][%15p]\n",
			214847480, 15, "et toi ?", 97, '.',      "salut", 5115451,      5115451,    5115451,     5115451,     15,     1,    8,       50,     &str);
	ret_2 =  printf("[%d][%D][%s%2%][%-2Ccccent%2c][%-11p][%-4x%%][%-#4x][%-3X][%-#4X][%-u][%-25UU][%-3o][%-17O][%15p]\n",
			214847480, 15, "et toi ?", 97, '.',      "salut", 5115451,      5115451,    5115451,     5115451,     15,     1,    8,       50,     &str);
	if (ret == ret_2)
		printf("len -- OK --\n\n");
	else
		printf("len // NO //\n\n");

	ft_printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	printf("%c%c%c%c%c\n", 's', 'a', 'l', 'u', 't');
	return (0);
}
