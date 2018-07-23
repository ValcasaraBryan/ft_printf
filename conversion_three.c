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
