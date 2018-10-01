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
	const char format_26[500] = "@moulitest: % 0-5d %4s";




	const char format_27[500] = "@moulitest: %d %4s";
	
	const char format_28[500] = "@moulitest: %+d %4s";
	const char format_29[500] = "@moulitest: % d %4s";
	const char format_30[500] = "@moulitest: %0d %4s";
	
	const char format_31[500] = "@moulitest: %+ d %4s";
	const char format_32[500] = "@moulitest: %+0d %4s";
	const char format_33[500] = "@moulitest: % 0d %4s";

	const char format_34[500] = "@moulitest: %+0 d %4s";
	const char format_35[500] = "@moulitest: %+0 5d %4s";
	
	const char format_36[500] = "@moulitest: %+10d %4s";
	const char format_37[500] = "@moulitest: % 10d %4s";
	const char format_38[500] = "@moulitest: %010d %4s";

	const char format_39[500] = "@moulitest: %+ 10d %4s";
	const char format_40[500] = "@moulitest: %+010d %4s";
	const char format_41[500] = "@moulitest: % 010d %4s";
	
	const char format_42[500] = "@moulitest: %+0 10d %4s";
	
	const char format_43[500] = "@moulitest: %-d %4s";
	
	const char format_44[500] = "@moulitest: %+-d %4s";
	const char format_45[500] = "@moulitest: % -d %4s";
	const char format_46[500] = "@moulitest: %0-d %4s";
	
	const char format_47[500] = "@moulitest: %+0-d %4s";
	const char format_48[500] = "@moulitest: % 0-d %4s";
	const char format_49[500] = "@moulitest: % +-d %4s";
	
	const char format_50[500] = "@moulitest: % +0-d %4s";
	const char format_51[500] = "@moulitest: % +0-5d %4s";
	const char format_52[500] = "@moulitest: % 0-5d %4s";

	const char format_53[500] = "%%";
	const char format_54[500] = "%-5d";

	const char format_55[500] = "%02.d";
	const char format_56[500] = "%+.10d";
	const char format_57[500] = "% 10.5d";
	const char format_58[500] = "%4.15d";

	const char format_59[500] = "%-.2s is a string";
	const char format_60[500] = "%+10.5d";
	const char format_61[500] = "%5.2s is a string";
	const char format_62[500] = "%03.2d";
	const char format_63[500] = "%-5.2s is a string";
	const char format_64[500] = "@moulitest: %.x %.0x";
	const char format_65[500] = "@moulitest: %.o %.0o";
	const char format_66[500] = "@moulitest: %.d %.0d";
	const char format_67[500] = "@moulitest: %#.o %#.0o";

	const char format_68[500] = "%#x";
	const char format_69[500] = "%#X";
	const char format_70[500] = "%#8x";
	const char format_71[500] = "%#08x";
	const char format_72[500] = "%#-08x";
	const char format_73[500] = "%#6o";
	const char format_74[500] = "%-#6o";
	const char format_75[500] = "%.5f";

	const char format_76[500] = "%";
	const char format_77[500] = "% Zoooo";
	const char format_78[500] = "{%}";


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

	printf("%s\n", format_26);
	ret = ft_printf(format_26, 5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_26, 5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);







	printf("%s\n", format_27);
	ret = ft_printf(format_27, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_27, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_28);
	ret = ft_printf(format_28, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_28, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_29);
	ret = ft_printf(format_29, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_29, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_30);
	ret = ft_printf(format_30, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_30, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	
	printf("%s\n", format_31);
	ret = ft_printf(format_31, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_31, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);
	

	printf("%s\n", format_32);
	ret = ft_printf(format_32, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_32, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_33);
	ret = ft_printf(format_33, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_33, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_34);
	ret = ft_printf(format_34, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_34, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_35);
	ret = ft_printf(format_35, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_35, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_36);
	ret = ft_printf(format_36, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_36, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_37);
	ret = ft_printf(format_37, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_37, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_38);
	ret = ft_printf(format_38, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_38, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_39);
	ret = ft_printf(format_39, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_39, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_40);
	ret = ft_printf(format_40, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_40, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_41);
	ret = ft_printf(format_41, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_41, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_42);
	ret = ft_printf(format_42, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_42, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_43);
	ret = ft_printf(format_43, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_43, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_44);
	ret = ft_printf(format_44, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_44, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_45);
	ret = ft_printf(format_45, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_45, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_46);
	ret = ft_printf(format_46, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_46, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_47);
	ret = ft_printf(format_47, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_47, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_48);
	ret = ft_printf(format_48, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_48, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_49);
	ret = ft_printf(format_49, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_49, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_50);
	ret = ft_printf(format_50, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_50, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_51);
	ret = ft_printf(format_51, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_51, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_52);
	ret = ft_printf(format_52, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_52, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_53);
	ret = ft_printf(format_53, -5, "salut");
	printf("| %d\n", ret);
	ret_2 =  printf(format_53, -5, "salut");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_54);
	ret = ft_printf(format_54, -42);
	printf("| %d\n", ret);
	ret_2 =  printf(format_54, -42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_55);
	ret = ft_printf(format_55, 1);
	printf("| %d\n", ret);
	ret_2 =  printf(format_55, 1);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_56);
	ret = ft_printf(format_56, 4242);
	printf("| %d\n", ret);
	ret_2 =  printf(format_56, 4242);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_57);
	ret = ft_printf(format_57, 4242);
	printf("| %d\n", ret);
	ret_2 =  printf(format_57, 4242);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_58);
	ret = ft_printf(format_58, 42);
	printf("| %d\n", ret);
	ret_2 =  printf(format_58, 42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);


	printf("%s\n", format_59);
	ret = ft_printf(format_59, "");
	printf("| %d\n", ret);
	ret_2 =  printf(format_59, "");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_60);
	ret = ft_printf(format_60, 4242);
	printf("| %d\n", ret);
	ret_2 =  printf(format_60, 4242);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_61);
	ret = ft_printf(format_61, "");
	printf("| %d\n", ret);
	ret_2 =  printf(format_61, "");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_62);
	ret = ft_printf(format_62, 0);
	printf("| %d\n", ret);
	ret_2 =  printf(format_62, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_63);
	ret = ft_printf(format_63, "this");
	printf("| %d\n", ret);
	ret_2 =  printf(format_63, "this");
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_64);
	ret = ft_printf(format_64, 0, 0);
	printf("| %d\n", ret);
	ret_2 =  printf(format_64, 0, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_65);
	ret = ft_printf(format_65, 0, 0);
	printf("| %d\n", ret);
	ret_2 =  printf(format_65, 0, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_66);
	ret = ft_printf(format_66, 0, 0);
	printf("| %d\n", ret);
	ret_2 =  printf(format_66, 0, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_67);
	ret = ft_printf(format_67, 0, 0);
	printf("| %d\n", ret);
	ret_2 =  printf(format_67, 0, 0);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_68);
	ret = ft_printf(format_68, 42);
	printf("| %d\n", ret);
	ret_2 =  printf(format_68, 42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_69);
	ret = ft_printf(format_69, 42);
	printf("| %d\n", ret);
	ret_2 =  printf(format_69, 42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_70);
	ret = ft_printf(format_70, 42);
	printf("| %d\n", ret);
	ret_2 =  printf(format_70, 42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_71);
	ret = ft_printf(format_71, 42);
	printf("| %d\n", ret);
	ret_2 =  printf(format_71, 42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_72);
	ret = ft_printf(format_72, 42);
	printf("| %d\n", ret);
	ret_2 =  printf(format_72, 42);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_73);
	ret = ft_printf(format_73, 2500);
	printf("| %d\n", ret);
	ret_2 =  printf(format_73, 2500);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_74);
	ret = ft_printf(format_74, 2500);
	printf("| %d\n", ret);
	ret_2 =  printf(format_74, 2500);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_75);
	ret = ft_printf(format_75, 25.655466);
	printf("| %d\n", ret);
	ret_2 =  printf(format_75, 25.655466);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_76);
	ret = ft_printf(format_76);
	printf("| %d\n", ret);
	ret_2 =  printf(format_76);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_77);
	ret = ft_printf(format_77);
	printf("| %d\n", ret);
	ret_2 =  printf(format_77);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	printf("%s\n", format_78);
	ret = ft_printf(format_78);
	printf("| %d\n", ret);
	ret_2 =  printf(format_78);
	printf("| %d\n", ret_2);
	if (ret == ret_2)
	{
		printf("len -- OK --\n\n");
	}
	else
		printf("len // NO // %d != %d\n\n", ret, ret_2);

	return (0);
}