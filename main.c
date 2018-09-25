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

#include "includes/ft_printf.h"

int		main(int argc, char **argv)
{
	int ret;
	int ret_2;
	char *str;
	const char format[500] = "@moulitest: %5.x %5.0x";

	(void)argc;
	(void)argv;
	ret = 0;
	ret_2 = 0;
	str = NULL;

	printf("%s\n", format);
	ret = ft_printf(format, 0, 0);
	printf("| %d\n", ret);
	ret_2 =  printf(format, 0, 0);
	printf("| %d\n", ret_2);


	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	return (0);
}

//	SOUC
//	#

//	Bonus :
//	b
