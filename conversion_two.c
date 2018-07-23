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

short				conv_short(va_list ap)
{
	short			c;

	c = va_arg(ap, short);
	return (c);	
}

unsigned short		conv_ushort(va_list ap)
{
	unsigned short	c;

	c = va_arg(ap, unsigned short);
	return (c);
}