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

char			conv_char(va_list ap)
{
	int		c;

	c = va_arg(ap, int);
	return (c);
}

unsigned char	conv_uchar(va_list ap)
{
	unsigned int c;

	c = va_arg(ap, unsigned int);
	return (c);
}

intmax_t	conv_intmax(va_list ap)
{
	intmax_t	c;

	c = va_arg(ap, intmax_t);
	return (c);
}

uintmax_t	conv_uintmax(va_list ap)
{
	uintmax_t	c;

	c = va_arg(ap, uintmax_t);
	return (c);
}

size_t	conv_size_t(va_list ap)
{
	size_t	c;

	c = va_arg(ap, size_t);
	return (c);
}

ssize_t	conv_ssize_t(va_list ap)
{
	ssize_t	c;

	c = va_arg(ap, ssize_t);
	return (c);
}
