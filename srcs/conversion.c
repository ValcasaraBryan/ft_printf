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

int					conv_long_c(va_list ap)
{
	long		c;
	int			len;
	int			octet;
	int			*tab;

	c = va_arg(ap, long);
	len = ft_wchar_len(c);
	octet = ft_wset_plage_byte(len);
	tab = ft_putval_tab(ft_set_unichar(ft_set_octet(octet), len + 1, c), octet);
	return (ft_putwchar(tab, octet));
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
	return (ft_lltoa((char)c));
}

char			*conv_uchar(va_list ap, char *hexa)
{
	int c;

	c = va_arg(ap, int);
	return (ft_ulltoa_base((unsigned char)c, hexa));
}

char			*conv_intmax(va_list ap)
{
	intmax_t	c;

	c = va_arg(ap, intmax_t);
	return (ft_lltoa(c));
}

char			*conv_uintmax(va_list ap, char *hexa)
{
	uintmax_t	c;

	c = va_arg(ap, uintmax_t);
	return (ft_ulltoa_base(c, hexa));
}

char			*conv_size_t(va_list ap, char *hexa)
{
	size_t	c;

	c = va_arg(ap, size_t);
	return (ft_ulltoa_base(c, hexa));
}

char			*conv_ssize_t(va_list ap)
{
	ssize_t	c;

	c = va_arg(ap, ssize_t);
	return (ft_lltoa(c));
}

char			*conv_float(va_list ap, unsigned int precision)
{
	double	c;
	char	*str;

	c = va_arg(ap, double);
	str = ft_dotoa(c, precision);
	return (str);
}

char				*conv_uint(va_list ap, char *hexa)
{
	unsigned int	c;

	c = va_arg(ap, unsigned int);
	return (ft_ulltoa_base(c, hexa));
}

char				*conv_ulong(va_list ap, char *hexa)
{
	unsigned long	c;

	c = va_arg(ap, unsigned long);
	return (ft_ulltoa_base(c, hexa));
}

char				*conv_ulong_long(va_list ap, char *hexa)
{
	unsigned long long	c;

	c = va_arg(ap, unsigned long long);
	return (ft_ulltoa_base(c, hexa));
}

char				*conv_short(va_list ap)
{
	int			c;

	c = va_arg(ap, int);
	return (ft_lltoa((short)c));
}

char				*conv_ushort(va_list ap, char *hexa)
{
	int	c;

	c = va_arg(ap, int);
	return (ft_ulltoa_base((unsigned short)c, hexa));
}

char				*conv_void(va_list ap, char *hexa)
{
	void			*c;

	c = va_arg(ap, void *);
	return (ft_ulltoa_base((long long)c, hexa));
}
