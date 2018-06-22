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

void	*string_s(va_list ap)
{
	void	*str;

	str = (void *)va_arg(ap, char *);
	return (str);
}

int		conv_c(va_list ap)
{
	int		c;

	c = va_arg(ap, int);
	return (c);
}

int		d_int(va_list ap)
{
	int		d;

	d = va_arg(ap, int);
	return (d);
}