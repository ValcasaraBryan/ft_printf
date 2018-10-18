/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:18:14 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/06 20:18:15 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*string_s(va_list ap)
{
	char				*str;

	str = va_arg(ap, char *);
	return (str);
}

char					conv_c(va_list ap)
{
	int					c;

	c = va_arg(ap, int);
	return ((unsigned char)c);
}

int						conv_long_c(va_list ap)
{
	long				c;
	int					len;
	int					octet;
	int					*tab;

	c = va_arg(ap, long);
	len = ft_wchar_len(c);
	octet = ft_wset_plage_byte(len);
	if (octet > 1)
	{
		tab = ft_putval_tab(ft_set_unichar(ft_set_octet(octet), len + 1, c),
			octet);
		return (ft_putwchar(tab, octet));
	}
	else
		return (ft_putchar(c));
}

char					*conv_int(va_list ap)
{
	int					c;

	c = va_arg(ap, int);
	return (ft_lltoa(c));
}

char					*conv_long(va_list ap)
{
	long				c;

	c = va_arg(ap, long);
	return (ft_lltoa(c));
}
