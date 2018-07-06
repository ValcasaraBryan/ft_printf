/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 05:23:15 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/06 05:23:18 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
