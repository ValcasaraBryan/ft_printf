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

long	ft_set_unichar(long masque_byte, int nb_octet, int len, wchar_t c)
{
	int index_puissance;
	long soustraction;
	long mask;
	long tmp;
	int i;

	i = 0;
	tmp = 1;
	mask = 1;
	printf("masque %ld\n", masque_byte);
	printf("val = %d|%d\n", c, len);
	while (i + 6 <= len)
	{
		printf("%d, %ld\n", c, mask);
		index_puissance = 0;
		while (index_puissance++ < 6)
		{
			if (mask == 63)
				mask = mask << 2;
			else if (mask <= 63)
			{
				tmp = tmp * 2;
				mask += tmp;
				i++;
			}
			if (mask > 251)
			{
				mask = mask << 6;
				i += 6;
			}
		}
		tmp = c & mask;
		c = c - tmp;
		c = c << 2;
		soustraction =  masque_byte + tmp;
	}
	printf("%ld\n", soustraction);
	return (soustraction);
}

int main(void)
{
	unsigned char a;
	int d;

	d = L'α';
	printf("unichar = %ld\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wset_plage_byte(ft_wchar_len(d)), ft_wchar_len(d), d));
	printf("unichar = %#lX\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wset_plage_byte(ft_wchar_len(d)), ft_wchar_len(d), d));
	d = 0x2FFFF;
	printf("unichar = %ld\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wset_plage_byte(ft_wchar_len(d)), ft_wchar_len(d), d));
	printf("unichar = %#lX\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wset_plage_byte(ft_wchar_len(d)), ft_wchar_len(d), d));
	d = L'𐀀';
	printf("unichar = %ld\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wset_plage_byte(ft_wchar_len(d)), ft_wchar_len(d), d));
	printf("unichar = %#lX\n", ft_set_unichar(ft_set_octet(ft_wset_plage_byte(ft_wchar_len(d))), ft_wset_plage_byte(ft_wchar_len(d)), ft_wchar_len(d), d));

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
