/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 17:48:22 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/09 17:48:23 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <wchar.h>

int		main(int argc, char **argv)
{
	int ret;
	int ret_2;


	ret = 0;
	ret_2 = 0;

	const char format[50] = "coucou|%s|%S|%s";
	const char format_2[50] = "%p";
	const char format_3[50] = "%.5C";
	const char format_4[50] = "%.4s";
	const char format_5[50] = "%4.15s";
	const char format_6[50] = "%4.1s";
	const char format_7[50] = "%5p";
	const char format_8[50] = "%#.5x";

	printf("%s\n", format_4);
	ret = ft_printf(format_4, "42");
	printf("| %d\n", ret);
	ret_2 = printf(format_4, "42");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_5);
	ret = ft_printf(format_5, "42");
	printf("| %d\n", ret);
	ret_2 = printf(format_5, "42");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_6);
	ret = ft_printf(format_6, "42");
	printf("| %d\n", ret);
	ret_2 = printf(format_6, "42");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_2);
	ret = ft_printf(format_2, 0);
	printf("| %d\n", ret);
	ret_2 = printf(format_2, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_7);
	ret = ft_printf(format_7, 0);
	printf("| %d\n", ret);
	ret_2 = printf(format_7, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_8);
	ret = ft_printf(format_8, 1);
	printf("| %d\n", ret);
	ret_2 = printf(format_8, 1);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_8);
	ret = ft_printf(format_8, 1);
	printf("| %d\n", ret);
	ret_2 = printf(format_8, 1);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);








	printf("%s\n", format);
	ret = ft_printf(format, "salut", "salut", "salut");
	printf("| %d\n", ret);
	ret_2 = printf(format, "salut", "salut", "salut");
	printf("| %d\n\n", ret_2);
	//if (ret == ret_2)
	//{
	//	printf("len -- OK --\n\n");
	//}
	//else
	//	printf("len // NO // %d != %d\n\n", ret, ret_2);
	

	
	printf("%s\n", format_3);
	ret = ft_printf(format_3, L"我");
	printf("| %d\n", ret);
	ret_2 = printf(format_3, L"我");
	printf("| %d\n", ret_2);
	//if (ret == ret_2)
	//{
	//	printf("len -- OK --\n\n");
	//}
	//else
	//	printf("len // NO // %d != %d\n\n", ret, ret_2);

	return (0);
}
