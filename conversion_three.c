/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 08:53:19 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/06 08:53:21 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*conv_long_c(va_list ap)
{
	long			c;
	char			*tmp;

	c = va_arg(ap, long);
	tmp = ft_strdup("");
	tmp[0] = (char)c;
	return (tmp);
}

char				*conv_hexa(va_list ap)
{
	int				c;

	c = va_arg(ap, int);
	return (ft_itoa_base(c, "0123456789abcdef"));
}

char				*conv_hexa_l_l_maj(va_list ap)
{
	int		c;

	c = va_arg(ap, int);
	return (ft_itoa_base(c, "0123456789ABCDEF"));
}

char				*conv_hexa_l_l(va_list ap)
{
	long long		c;

	c = va_arg(ap, long long);
	return (ft_itoa_base(c, "0123456789abcdef"));
}

char				*conv_octal_l(va_list ap)
{
	int		c;

	c = va_arg(ap, int);
	return (ft_itoa_base(c, "01234567"));
}

char				*conv_octal_l_l(va_list ap)
{
	long long		c;

	c = va_arg(ap, long long);
	return (ft_itoa_base(c, "01234567"));
}

char				*conv_void(va_list ap)
{
	void			*c;

	c = va_arg(ap, void *);
	return (ft_itoa_base((long)c, "0123456789abcdef"));
}