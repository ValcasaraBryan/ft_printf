/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_four.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:42:13 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:42:14 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*conv_ulong_long(va_list ap, char *hexa)
{
	unsigned long long	c;

	c = va_arg(ap, unsigned long long);
	return (ft_ulltoa_base(c, hexa));
}

char					*conv_short(va_list ap)
{
	int					c;

	c = va_arg(ap, int);
	return (ft_lltoa((short)c));
}

char					*conv_ushort(va_list ap, char *hexa)
{
	int					c;

	c = va_arg(ap, int);
	return (ft_ulltoa_base((unsigned short)c, hexa));
}

char					*conv_void(va_list ap, char *hexa)
{
	void				*c;

	c = va_arg(ap, void *);
	return (ft_ulltoa_base((long long)c, hexa));
}