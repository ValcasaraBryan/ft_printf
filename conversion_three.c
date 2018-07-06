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