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

int					conv_int(va_list ap)
{
	int				c;

	c = va_arg(ap, int);
	return (c);
}

long				conv_long(va_list ap)
{
	long			c;

	c = va_arg(ap, long);
	return (c);
}

long long			conv_long_long(va_list ap)
{
	long long		c;

	c = va_arg(ap, long long);
	return (c);
}
