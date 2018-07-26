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

	if (c == 's' || c == 'S')
	{
		if (c == 'S')
			z[INT_LONG - 1] = INT_LONG;
		list = list_add_conversion(c, string_s(ap));
	}
	else if (c == 'c' || c == 'C')
	{
		if (c == 'C')
			z[INT_LONG - 1] = INT_LONG;
		list = list_add_conversion(c, conv_c(ap));
	}
	else if (c == 'd' || c == 'i' || c == 'D')
	{
		if (c == 'D')
			z[INT_LONG - 1] = INT_LONG;
		list = flag(c, list, z, ap);
	}
	else if (c == 'o' || c == 'O')
	{		
		if (c == 'O')
			z[INT_LONG - 1] = INT_LONG;
		list = flag_x(c, list, z, ap);
		if (z[HASHTAG - 1] == HASHTAG)
			list->f = ft_strcat(add_prefix('\0'), list->f);
	}
	else
		return (init_list_next(list, ap, c, z));
	return (list);
}

t_tab		*init_list_next(t_tab *list, va_list ap, char c, int *z)
{
	if (c == 'u' || c == 'U')
	{
		if (c == 'U')
			z[INT_LONG - 1] = INT_LONG;
		list = flag_u(c, list, z, ap);
	}
	else if (c == 'x' || c == 'X' || c == 'p')
	{
		list = flag_x(c, list, z, ap);
		if (z[HASHTAG - 1] == HASHTAG && *list->f != 48)
			list->f = ft_strcat(add_prefix(c), list->f);
		if (c == 'p')
			list->f = ft_strcat(add_prefix('x'), list->f);
	}
	else if (c == '%')
		list = list_add_conversion('%', NULL);
	else
		list = list_add_conversion(c, ft_strdup(""));
	return (list);
}

t_tab		*list_add_conversion(char c, char *string)
{
	t_tab	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	tmp->c = c;
	tmp->f = string;
	return (tmp);
}
