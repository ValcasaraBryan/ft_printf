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
#include <locale.h>

int		main(int argc, char **argv)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int ret;
	int ret_2;


	ret = 0;
	ret_2 = 0;

	const char format[50] = "coucou|%s|%S|%s";
	const char format_2[50] = "%p";
	const char format_3[50] = "%C";/////////////////////// UNICODE
	const char format_4[50] = "%.4s";
	const char format_5[50] = "%4.15s";
	const char format_6[50] = "%4.1s";
	const char format_7[50] = "%5p";
	const char format_8[50] = "%#.5x";
	const char format_9[50] = "{%30d}";
	const char format_10[50] = "{%-30d}";
	const char format_11[50] = "%#o";
	const char format_12[50] = "%#.3o";
	const char format_13[50] = "%#.o";
	const char format_14[50] = "%#.6o";
	const char format_15[50] = "%#x";
	const char format_16[50] = "%#.x, %#.0x";
	const char format_17[50] = "%lc";/////////////////////// UNICODE
	const char format_18[50] = "%C";/////////////////////// UNICODE
	const char format_19[50] = "%zj";
	const char format_20[50] = "%";
	const char format_21[50] = "%          ";
	const char format_22[50] = "%lhh";
	const char format_23[50] = "%S";


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

	printf("%s\n", format_9);
	ret = ft_printf(format_9, 10000);
	printf("| %d\n", ret);
	ret_2 = printf(format_9, 10000);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_10);
	ret = ft_printf(format_10, 10000);
	printf("| %d\n", ret);
	ret_2 = printf(format_10, 10000);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_11);
	ret = ft_printf(format_11, 0);
	printf("| %d\n", ret);
	ret_2 = printf(format_11, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_12);
	ret = ft_printf(format_12, 1);
	printf("| %d\n", ret);
	ret_2 = printf(format_12, 1);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_13);
	ret = ft_printf(format_13, 42);
	printf("| %d\n", ret);
	ret_2 = printf(format_13, 42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_14);
	ret = ft_printf(format_14, 42);
	printf("| %d\n", ret);
	ret_2 = printf(format_14, 42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_15);
	ret = ft_printf(format_15, 0);
	printf("| %d\n", ret);
	ret_2 = printf(format_15, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_16);
	ret = ft_printf(format_16, 0, 0);
	printf("| %d\n", ret);
	ret_2 = printf(format_16, 0, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);



	printf("%s\n", format_3);
	ret = ft_printf(format_3, 945);
	printf("| %d\n", ret);
	ret_2 = printf(format_3, 945);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_17);
	ret = ft_printf(format_17, 945);
	printf("| %d\n", ret);
	ret_2 = printf(format_17, 945);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_18);
	ret = ft_printf(format_18, 'c');
	printf("| %d\n", ret);
	ret_2 = printf(format_18, 'c');
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_19);
	ret = ft_printf(format_19, 9223372036854775807);
	printf("| %d\n", ret);
	ret_2 = printf(format_19, 9223372036854775807);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_20);
	ret = ft_printf(format_20);
	printf("| %d\n", ret);
	ret_2 = printf(format_20);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_21);
	ret = ft_printf(format_21);
	printf("| %d\n", ret);
	ret_2 = printf(format_21);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_22);
	ret = ft_printf(format_22, 2147483647);
	printf("| %d\n", ret);
	ret_2 = printf(format_22, 2147483647);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_23);
	ret = ft_printf(format_23, L"ݗݜशব");
	printf("| %d\n", ret);
	ret_2 = printf(format_23, L"ݗݜशব");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	return (0);
}
