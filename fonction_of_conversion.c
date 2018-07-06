/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_of_conversion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:42:29 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/06 20:42:32 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*return_list(char c, va_list ap, int *flag)
{
	t_tab	*list;

	list = init_list(ap, c, flag);
	return (list);
}

t_tab		*init_list(va_list ap, char c, int *z)
{
	t_tab	*list;

	if (c == 's')
		list = list_add_conversion('s', string_s(ap));
	else if (c == 'S')
		list = list_add_conversion('S', string_s(ap));
	else if (c == 'c')
		list = list_add_conversion('c', conv_c(ap));
	else if (c == 'C')
		list = list_add_conversion('C', conv_long_c(ap));
	else if (c == 'p')
		list = list_add_conversion('p', add_prefix('x'));
	else if (c == 'd' || c == 'i' || c == 'D')
	{
		if (c == 'D')
			z[5] = INT_LONG;
		list = flag(c, list, z, ap);
	}
	else if (c == 'o')
		list = list_add_conversion('o', ft_strdup(""));
	else if (c == 'O')
		list = list_add_conversion('O', ft_strdup(""));
	else
		return (init_list_next(list, ap, c, z));
	return (list);
}

t_tab		*init_list_next(t_tab *list, va_list ap, char c, int *z)
{
	if (c == 'u' || c == 'U')
	{
		if (c == 'U')
			z[5] = INT_LONG;
		list = flag_u(c, list, z, ap);
	}
	else if (c == 'x' || c == 'X')
	{
		if (c == 'X')
			z[5] = INT_LONG;
		if (z[4] == HASHTAG)
			list = list_add_conversion(c, add_prefix(c));
		else
			list = list_add_conversion(c, ft_strdup(""));
	}
	else if (c == '%')
		list = list_add_conversion('%', ft_strdup(""));
	return (list);
}

t_tab		*list_add_conversion(char c, char *string)
{
	t_tab	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	if (c)
	{
		tmp->c = c;
		tmp->f = string;
	}
	else
	{
		tmp->c = 0;
		tmp->f = NULL;
	}
	return (tmp);
}
