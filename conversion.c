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

void				*string_s(va_list ap)
{
	void			*str;

	str = (void *)va_arg(ap, char *);
	return (str);
}

int					conv_c(va_list ap)
{
	int				c;

	c = va_arg(ap, int);
	return (c);
}

unsigned int		d_uns_int(va_list ap)
{
	unsigned int	d;

	d = va_arg(ap, unsigned int);
	return (d);
}

long long			d_long_long(va_list ap)
{
	long long			d;

	d = va_arg(ap, long long);
	return (d);
}
