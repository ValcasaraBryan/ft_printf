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
		list = list_add_conversion(c, ft_lltoa(conv_short(ap)));
	else if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short_short(z))
		list = list_add_conversion(c, ft_lltoa(conv_char(ap)));
	else if (valid_flag_long(z))
		list = list_add_conversion(c, ft_lltoa(conv_long(ap)));
	else if (valid_flag_long_long(z))
		list = list_add_conversion(c, ft_lltoa(conv_long_long(ap)));
	else
		list = list_add_conversion(c, ft_lltoa(conv_int(ap)));
	return (list);
}

t_tab	*flag_u(char c, t_tab *list, int *z, va_list ap)
{
	if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short(z))
		list = list_add_conversion(c, ft_ulltoa(conv_ushort(ap)));
	else if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short_short(z))
		list = list_add_conversion(c, ft_ulltoa(conv_uchar(ap)));
	else if (valid_flag_long(z))
		list = list_add_conversion(c, ft_ulltoa(conv_ulong(ap)));
	else if (valid_flag_long_long(z))
		list = list_add_conversion(c, ft_ulltoa(conv_ulong_long(ap)));
	else
		list = list_add_conversion(c, ft_ulltoa(conv_uint(ap)));
	return (list);
}

t_tab	*flag_x(char c, t_tab *list, int *z, va_list ap)
{
	char hexa_min[17] = "0123456789abcdef";
	char hexa_maj[17] = "0123456789ABCEDF";
	char octa[10] = "01234567";
	char *hexa;

	if (c == 'x' || c == 'p')
		hexa = hexa_min;
	else if (c == 'X')
		hexa = hexa_maj;
	else if (c == 'o' || c == 'O')
		hexa = octa;
	if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short(z))
		list = list_add_conversion(c, ft_ulltoa_base(conv_ushort(ap), hexa));
	else if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short_short(z))
		list = list_add_conversion(c, ft_ulltoa_base(conv_uchar(ap), hexa));
	else if (valid_flag_long(z))
		list = list_add_conversion(c, ft_ulltoa_base(conv_ulong(ap), hexa));
	else if (valid_flag_long_long(z))
		list = list_add_conversion(c, ft_ulltoa_base(conv_ulong_long(ap), hexa));
	else if (c == 'p')
		list = list_add_conversion(c, ft_ulltoa_base((unsigned long long)va_arg(ap, void *), hexa));
	else
		list = list_add_conversion(c, ft_ulltoa_base(conv_uint(ap), hexa));
	return (list);
}
