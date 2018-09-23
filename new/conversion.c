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

char				*string_s(va_list ap)
{
	char			*str;

	str = va_arg(ap, char *);
	return (str);
}

char				conv_c(va_list ap)
{
	int				c;

	c = va_arg(ap, int);
	return ((unsigned char)c);
}

char				*conv_int(va_list ap)
{
	int				c;

	c = va_arg(ap, int);
	return (ft_lltoa(c));
}

char				*conv_long(va_list ap)
{
	long			c;

	c = va_arg(ap, long);
	return (ft_lltoa(c));
}

char				*conv_long_long(va_list ap)
{
	long long		c;

	c = va_arg(ap, long long);
	return (ft_lltoa(c));
}

char			*conv_char(va_list ap)
{
	int		c;

	c = va_arg(ap, int);
	return (ft_lltoa(c));
}

unsigned char	conv_uchar(va_list ap)
{
	unsigned int c;

	c = va_arg(ap, unsigned int);
	return (c);
}

char			*conv_intmax(va_list ap)
{
	intmax_t	c;

	c = va_arg(ap, intmax_t);
	return (ft_lltoa(c));
}

uintmax_t	conv_uintmax(va_list ap)
{
	uintmax_t	c;

	c = va_arg(ap, uintmax_t);
	return (c);
}

char			*conv_size_t(va_list ap)
{
	size_t	c;

	c = va_arg(ap, size_t);
	return (ft_lltoa(c));
}

ssize_t	conv_ssize_t(va_list ap)
{
	ssize_t	c;

	c = va_arg(ap, ssize_t);
	return (c);
}

double	conv_float(va_list ap)
{
	double	c;

	c = va_arg(ap, double);
	return (c);	
}

unsigned int		conv_uint(va_list ap)
{
	unsigned int	c;

	c = va_arg(ap, unsigned int);
	return (c);
}

unsigned long		conv_ulong(va_list ap)
{
	unsigned long	c;

	c = va_arg(ap, unsigned long);
	return (c);
}

unsigned long long	conv_ulong_long(va_list ap)
{
	unsigned long long	c;

	c = va_arg(ap, unsigned long long);
	return (c);
}

char				*conv_short(va_list ap)
{
	short			c;

	c = va_arg(ap, short);
	return (ft_lltoa(c));
}

//unsigned short		conv_ushort(va_list ap)
//{
//	unsigned short	c;
//
//	c = va_arg(ap, unsigned short);
//	return (c);
//}
