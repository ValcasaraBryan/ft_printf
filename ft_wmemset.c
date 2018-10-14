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
#include <stdlib.h>

int					ft_wchar_len(wchar_t c)
{
	unsigned int	quatre_bit;
	int				i;

	quatre_bit = 2147483648;
	i = 32;
	while (!(quatre_bit & c) && quatre_bit)
	{
		quatre_bit /= 2;
		i--;
	}
	return (i);
}

int					ft_wset_plage_byte(int len)
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

int					*ft_putval_tab(wchar_t c, int *octet)
{
	int				*tab;
	long			soustraction;
	long			mask;
	int				val_octet;
	int				i;

	if (!(tab = (int *)malloc(sizeof(int) * 4)))
		return (0);
	i = -1;
	val_octet = *octet;
	mask = 4278190080;
	while (++i < 4 - *octet)
		mask = mask >> 8;
	i = -1;
	while (val_octet > 0)
	{
		soustraction = c & mask;
		c -= soustraction;
		soustraction = soustraction >> (((val_octet-- - 1) * 8));
		tab[++i] = (int)soustraction;
		mask = mask >> 8;
	}
	return (tab);
}

long				ft_set_octet(int octet)
{
	long			multiple;
	long			multi_byte;
	long			mask;
	int				i;
	
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

long				ft_set_unichar(long masque_byte, int len, wchar_t c)
{
	long			soustraction;
	int				i;

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

int					ft_putwchar(int *tab, int len)
{
	int				i;
	int				ret;
	char			c;

	i = -1;
	ret = 0;
	while (++i < len)
	{
		c = tab[i];
		if (write(1, &c, 1) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}

int main(void)
{
	unsigned char a;
	int octet;
	int len;
	int d;
	long mask;
	long valeur_total;
	int *tab;

	d = L'α';
	len = ft_wchar_len(d);
	octet = ft_wset_plage_byte(len);
	mask = ft_set_octet(octet);
	valeur_total = ft_set_unichar(mask, len + 1, d);
	tab = ft_putval_tab(valeur_total, &octet);
	ft_putwchar(tab, 4);
	ft_putchar(' ');
	
	d = 0x2FFFF;
	len = ft_wchar_len(d);
	octet = ft_wset_plage_byte(len);
	mask = ft_set_octet(octet);
	valeur_total = ft_set_unichar(mask, len + 1, d);
	tab = ft_putval_tab(valeur_total, &octet);
	ft_putwchar(tab, 4);
	ft_putchar(' ');
	ft_putchar(' ');
	d = L'𐀀';
	len = ft_wchar_len(d);
	octet = ft_wset_plage_byte(len);
	mask = ft_set_octet(octet);
	valeur_total = ft_set_unichar(mask, len + 1, d);
	tab = ft_putval_tab(valeur_total, &octet);
	ft_putwchar(tab, 4);
	ft_putchar('\n');
	return (0);
}
