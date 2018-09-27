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
	const char format[500] = "@moulitest: %d %4s";
	
	const char format_2[500] = "@moulitest: %+d %4s";
	const char format_3[500] = "@moulitest: % d %4s";
	const char format_4[500] = "@moulitest: %0d %4s";
	
	const char format_5[500] = "@moulitest: %+ d %4s";
	const char format_6[500] = "@moulitest: %+0d %4s";
	const char format_7[500] = "@moulitest: % 0d %4s";

	const char format_8[500] = "@moulitest: %+0 d %4s";
	const char format_9[500] = "@moulitest: %+0 5d %4s";
	
	const char format_10[500] = "@moulitest: %+10d %4s";
	const char format_11[500] = "@moulitest: % 10d %4s";
	const char format_12[500] = "@moulitest: %010d %4s";

	const char format_13[500] = "@moulitest: %+ 10d %4s";
	const char format_14[500] = "@moulitest: %+010d %4s";
	const char format_15[500] = "@moulitest: % 010d %4s";
	
	const char format_16[500] = "@moulitest: %+0 10d %4s";
	
	const char format_17[500] = "@moulitest: %-d %4s";
	
	const char format_18[500] = "@moulitest: %+-d %4s";
	const char format_19[500] = "@moulitest: % -d %4s";
	const char format_20[500] = "@moulitest: %0-d %4s";
	
	const char format_21[500] = "@moulitest: %+0-d %4s";
	const char format_22[500] = "@moulitest: % 0-d %4s";
	const char format_23[500] = "@moulitest: % +-d %4s";
	
	const char format_24[500] = "@moulitest: % +0-d %4s";
	const char format_25[500] = "@moulitest: % +0-5d %4s";



	(void)argc;
	(void)argv;
	ret = 0;
	ret_2 = 0;
	str = NULL;

	printf("%s\n", format);
	ret = ft_printf(format, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_2);
	ret = ft_printf(format_2, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_2, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_3);
	ret = ft_printf(format_3, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_3, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_4);
	ret = ft_printf(format_4, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_4, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_5);
	ret = ft_printf(format_5, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_5, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	

	printf("%s\n", format_6);
	ret = ft_printf(format_6, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_6, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_7);
	ret = ft_printf(format_7, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_7, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_8);
	ret = ft_printf(format_8, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_8, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_9);
	ret = ft_printf(format_9, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_9, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_10);
	ret = ft_printf(format_10, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_10, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_11);
	ret = ft_printf(format_11, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_11, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_12);
	ret = ft_printf(format_12, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_12, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_13);
	ret = ft_printf(format_13, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_13, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_14);
	ret = ft_printf(format_14, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_14, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_15);
	ret = ft_printf(format_15, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_15, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_16);
	ret = ft_printf(format_16, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_16, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_17);
	ret = ft_printf(format_17, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_17, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_18);
	ret = ft_printf(format_18, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_18, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_19);
	ret = ft_printf(format_19, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_19, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_20);
	ret = ft_printf(format_20, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_20, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_21);
	ret = ft_printf(format_21, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_21, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_22);
	ret = ft_printf(format_22, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_22, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_23);
	ret = ft_printf(format_23, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_23, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_24);
	ret = ft_printf(format_24, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_24, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_25);
	ret = ft_printf(format_25, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_25, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	return (0);
}