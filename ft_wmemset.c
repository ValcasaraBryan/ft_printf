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

int		ft_wchar_len(wchar_t c)
{
	unsigned int quatre_bit;
	int i;

	quatre_bit = 2147483648;
	i = 32;
	while (!(quatre_bit & c) && quatre_bit)
	{
		quatre_bit /= 2;
		i--;
	}
	return (i);
}

int		ft_wset_plage_byte(int len)
{
	if (len < 8)
		return (1);
	else if (len >= 8 && len <= 11)
		return (2);
	else if (len >= 12 && len <= 16)
		return (3);
	else if (len >= 17 && len <= 21)
		return (4);
	else
		return (-1);
}

int		ft_putwchar(wchar_t c)
{
	return (write(1, &c, 1));
}

long 	ft_set_octet(int octet)
{
	long multiple;
	long multi_byte;
	long mask;
	int i;
	
	i = 0;
	multi_byte = 1;
	multiple = 8 * octet - 1;
	while (multiple > i++)
		multi_byte *= 2;
	mask = multi_byte;
	i = 0;
	while (i++ < octet - 1)
		mask += multi_byte >> i;
	i = 0;
	while (i++ <= octet)
		mask += multi_byte >> (8 * i);
	return (mask);
}

long	ft_set_unichar(long masque_byte, int len, wchar_t c)
{
	long	soustraction;
	int		i;

	while (len-- > 0)
	{
		i = 0;
		soustraction = 1;
		while (i++ < len - 1)
			soustraction = soustraction * 2;
		if (soustraction <= c)
		{
			c -= soustraction;
			if (len > 18 && len <= 21)
				masque_byte += soustraction << 6;
			else if (len > 12)
				masque_byte += soustraction << 4;
			else if (len > 6)
				masque_byte += soustraction << 2;
			else if (len <= 6)
				masque_byte += soustraction;
		}
	}
	if (c == 1)
		masque_byte++;
	return (masque_byte);
}

//262143

int main(void)
{
	unsigned char a;
	int d;

	d = L'α';
	printf("unichar = %ld\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wchar_len(d) + 1, d));
	printf("unichar = %lX\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wchar_len(d) + 1, d));
	printf("----------------------------------------\n");
	d = 0x2FFFF;
	printf("unichar = %ld\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wchar_len(d) + 1, d));
	printf("unichar = %lX\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wchar_len(d) + 1, d));
	printf("----------------------------------------\n");
	d = L'𐀀';
	printf("unichar = %ld\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wchar_len(d) + 1, d));
	printf("unichar = %lX\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wchar_len(d) + 1, d));

	//      11 10110001
	//11001110 10110001
	//	0xCE 	0xB1
	a = 0xCE;
	ft_putwchar(a);
	a = 0xB1;
	ft_putwchar(a);
	a = '\n';// 0x0A
	ft_putwchar(a);

	//00000000 00101111   111111   111111
	//11110000 10101111 10111111 10111111
	//	0xF0 	0xAF 	0xBF 		0xBF
	a = 0xF0;
	ft_putwchar(a);
	a = 0xAF;
	ft_putwchar(a);
	a = 0xBF;// 0x0A
	ft_putwchar(a);
	a = 0xBF;// 0x0A
	ft_putwchar(a);
	a = '\n';// 0x0A
	ft_putwchar(a);
	
	//            10000   000000   000000
	//11110000 10010000 10000000 10000000
	//	0xF0 	0x90 	0x80 		0x80
	unsigned char c;
    c = 0xF0;
	ft_putwchar(c);
    c = 0x90;
	ft_putwchar(c);
    c = 0x80;
	ft_putwchar(c);
    c = 0x80;
	ft_putwchar(c);
    c = '\n';// 0x0A
	ft_putwchar(c);
	return (0);
}
