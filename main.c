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


	ret = ft_printf("[%-.10d][%.5D][%5.2s %s%2%][%c%-2Ccccent%2c][%-11p][%-4x%%][%-#4x][%-3X][%-#4X][%-uu][%-25UU][%-#3oo][%-17OO][%15p][%20.0fsalut][%jd]\n", 
		-42, 15, NULL ,"et toi ?", 0,97, '.',	        "hey", 2,      2,    2,     2,     2,     2,      2,       2,     &str, 20.0000000015464979, 15);

	ret_2 =  printf("[%-.10d][%.5D][%5.2s %s%2%][%c%-2Ccccent%2c][%-11p][%-4x%%][%-#4x][%-3X][%-#4X][%-uu][%-25UU][%-#3oo][%-17OO][%15p][%20.0fsalut][%jd]\n", 
		-42, 15, NULL ,"et toi ?", 0,97, '.',	        "hey", 2,      2,    2,     2,     2,     2,      2,       2,     &str, 20.0000000015464979, 15);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	return (0);
}
