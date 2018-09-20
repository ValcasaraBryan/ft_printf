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
	const char format[500] = " [%s]%% %c %% %5c    %% %c    %%     %c %.5f   %10.5d  %i";

	(void)argc;
	(void)argv;
	ret = 0;
	ret_2 = 0;
	str = NULL;

	ret = ft_printf(format, "salut", 'A', 0, 65,  0, 10.5, 10, -5);
	ret_2 =  printf(format, "salut", 'A', 0, 65,  0, 10.5, 10, -5);
	printf("|\n");
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	return (0);
}

//	SpDoOuUxXC
//	#
//	hh, h, l, ll, j, et z

//	Bonus :
//	b
