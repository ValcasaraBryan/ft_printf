/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:18:53 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:18:55 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int						p_of_params(char *format)
{
	int					i;

	i = -1;
	if (!format)
		return (-1);
	while (format[++i])
		if (format[i] == '%')
			return (i);
	return (-1);
}

void					parsing_arg(char *argument, va_list ap, int len, LIST)
{
	if (len > 0)
	{
		flag_optional(argument, list);
		ARG = argument[len - 1];
	}
	else
	{
		flag_optional(argument, list);
		ARG = argument[len];
	}
	init_list(ap, ARG, list);
	if (LEFT_ || (POINT_ && params(ARG, ENT)))
		TAB[ZERO - 1] = 0;
	if (*DATA == '-')
		TAB[SIGN - 1] = SIGN;
	if (SIGN_)
		TAB[BLANK - 1] = 0;
}

void					init_list(va_list ap, char c, t_string *list)
{
	TAB[INT_LONG - 1] = (c == 'D' || c == 'O' || c == 'U' ||
		c == 'C') ? INT_LONG : TAB[INT_LONG - 1];
	c = (c == 'D' || c == 'O' || c == 'U') ? c + 32 : c;
	if (c == 's')
		list_add_conversion(string_s(ap), list);
	else if (c == 'S')
		list_add_conversion(string_unix(ap), list);
	else if (c == 'd' || c == 'i')
		list_add_conversion(flag_int_sign(*list, ap), list);
	else if (c == 'c')
		list_add_conversion("", list);
	else if (c == 'f')
	{
		if (POINT_NO)
			TAB[POINT] = 6;
		list_add_conversion(conv_float(ap, TAB[POINT]), list);
	}
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'p')
		return (unsigned_value(ap, c, list));
	else
		list_add_conversion("", list);
}

int						add_arg(LIST, va_list ap)
{
	if (params(ARG, NO_C))
	{
		if (params(ARG, ENT) == 0 || params(ARG, "uUoOxX"))
		{
			TAB[BLANK - 1] = 0;
			TAB[SIGN - 1] = 0;
		}
		return (change_string(list));
	}
	if ((ARG == 'c' && TAB[INT_LONG - 1] == INT_LONG) || ARG == 'C')
		return (conv_long_c(ap));
	else if (ARG == 'c')
		return (option_char(list, conv_c(ap)));
	else if (ft_isprint(ARG))
		return (option_char(list, ARG));
	return (0);
}

int						inter_flag(const char *format, int *len_write,
						t_string *list, int *len_arg)
{
	int				i;
	int				j;

	i = *len_arg;
	j = *len_write;
	i = p_of_params((char *)format);
	j += ft_putstr_len(format, i, FD);
	*len_arg = i;
	*len_write = j;
	return (i);
}
