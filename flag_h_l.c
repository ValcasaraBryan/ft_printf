/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_h_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 01:45:31 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/04 01:45:32 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab	*flag(char c, t_tab *list, int *z, va_list ap)
{
	if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short(z))
		list = list_add_conversion(c, short_int(ap));
	else if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short_short(z))
		list = list_add_conversion(c, uns_short_int(ap));
	else if (valid_flag_long(z))
		list = list_add_conversion(c, d_long(ap));
	else if (valid_flag_long_long(z))
		list = list_add_conversion(c, d_long_long(ap));
	else
		list = list_add_conversion(c, conv_int(ap));
	return (list);
}

t_tab	*flag_u(char c, t_tab *list, int *z, va_list ap)
{
	if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short(z))
		list = list_add_conversion(c, uns_short_int(ap));
	else if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short_short(z))
		list = list_add_conversion(c, short_int(ap));
	else if (valid_flag_long(z))
		list = list_add_conversion(c, d_uns_long(ap));
	else if (valid_flag_long_long(z))
		list = list_add_conversion(c, d_uns_long_long(ap));
	else
		list = list_add_conversion(c, d_uns_int(ap));
	return (list);
}
