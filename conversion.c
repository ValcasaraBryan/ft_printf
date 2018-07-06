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

#include "ft_printf.h"

#define STR_ 0

char 				*string_s(va_list ap)
{
	char			*str;

	str = va_arg(ap, char *);
	return (str);
}

char				*conv_c(va_list ap)
{
	int				c;
	char			*tmp;

	c = va_arg(ap, int);
	tmp = ft_strdup("");
	tmp[0] = (char)c;
	return (tmp);
}

char				*d_uns_int(va_list ap)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	return (ft_ulltoa(d));
}

char				*d_long_long(va_list ap)
{
	long long			d;

	d = va_arg(ap, long long);
	return (ft_lltoa(d));
}

char				*d_long(va_list ap)
{
	long			d;

	d = va_arg(ap, long);
	return (ft_lltoa(d));
}

char				*conv_int(va_list ap)
{
	int			d;

	d = va_arg(ap, int);
	return (ft_lltoa(d));
}

char				*d_uns_long(va_list ap)
{
	unsigned long	d;

	d = va_arg(ap, unsigned long);
	return (ft_ulltoa(d));
}

char				*d_uns_long_long(va_list ap)
{
	unsigned long long	d;

	d = va_arg(ap, unsigned long long);
	return (ft_ulltoa(d));
}

char				*short_int(va_list ap)
{
	short int	d;

	d = va_arg(ap, int);
	return (ft_lltoa((short)d));
}

char				*uns_short_int(va_list ap)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	return (ft_lltoa((char)d));
}
