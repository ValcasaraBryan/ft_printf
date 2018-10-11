/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wset_plage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:26:01 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/04 18:50:35 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <locale.h>
#include <unistd.h>

int		ft_wset_plage(wchar_t c)
{
	if (c <= 0x7F && c >= 0)
		return (0);
	else if (c <= 0xFF && c > 0x7F)
		return (1);
	else if (c <= 0xFFFF && c > 0xFF)
		return (2);
	else if (c <= 0x6FE && c > 0xFFFF)
		return (3);
	else if (c <= 0x2FFFF && c > 0x6FE)
		return (4);
	return (-1);
}

int main(void)
{
	unsigned char a;

	int lil = 0;
	int i;
	printf("%-3d|%-7d|%-6X\n", ft_wset_plage(L'α'), L'α', L'α');
	printf("%-3d|%-7d|%-6X\n", ft_wset_plage(0x2FFFF), 0x2FFFF, 0x2FFFF);
	printf("%-3d|%-7d|%-6X\n", ft_wset_plage(L'𐀀'), L'𐀀', L'𐀀');
	//11101100 01

	//11001110 10110001
	//	0xCE 	0xB1
	a = 0xCE;
	write(1, &a, 1);
	a = 0xB1;
	write(1, &a, 1);
	a = '\n';// 0x0A
	write(1, &a, 1);

	//           101111   111111   111111
	//11110000 10101111 10111111 10111111
	//	0xF0 	0xAF 	0xBF 		0xBF
	a = 0xF0;
	write(1, &a, 1);
	a = 0xAF;
	write(1, &a, 1);
	a = 0xBF;// 0x0A
	write(1, &a, 1);
	a = 0xBF;// 0x0A
	write(1, &a, 1);
	a = '\n';// 0x0A
	write(1, &a, 1);
	
	//            10000   000000   000000
	//11110000 10010000 10000000 10000000
	//	0xF0 	0x90 	0x80 		0x80
	unsigned char c;
    c = 0xF0;
    write(1, &c, 1);
    c = 0x90;
    write(1, &c, 1);
    c = 0x80;
    write(1, &c, 1);
    c = 0x80;
    write(1, &c, 1);
    c = '\n';// 0x0A
    write(1, &c, 1);
	return (0);
}
