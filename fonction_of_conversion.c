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

t_tab		*return_list(char c, va_list ap)
{
	t_tab	*list;

	list = init_list(ap, c);
	return (list);
}

t_tab		*init_list(va_list ap, char c)
{
	t_tab	*list;

	if (c == 's')
		list = list_add_conversion('s', (void *)string_s(ap));
	else if (c == 'S')
		list = list_add_conversion('S', NULL);	// 'NULL' a remplir avec la fonction conversion
	else if (c == 'c')
		list = list_add_conversion('c', (void *)conv_c(ap));
	else if (c == 'C')
		list = list_add_conversion('C', NULL);	// 'NULL' a remplir avec la fonction conversion
	else if (c == 'p')
		list = list_add_conversion('p', NULL);	// 'NULL' a remplir avec la fonction conversion
	else if (c == 'd' || c == 'i')
		list = list_add_conversion('d', (void *)d_int(ap));
	else if (c == 'D')
		list = list_add_conversion('D', NULL);	// 'NULL' a remplir avec la fonction conversion
	else if (c == 'o')
		list = list_add_conversion('o', NULL);	// 'NULL' a remplir avec la fonction conversion
	else if (c == 'O')
		list = list_add_conversion('O', NULL);	// 'NULL' a remplir avec la fonction conversion
	else
		return (init_list_next(list, ap, c));
	return (list);
}

t_tab		*init_list_next(t_tab *list, va_list ap, char c)
{
	if (c == 'u')
		list = list_add_conversion('u', (void *)d_uns_int(ap));	// 'NULL' a remplir avec la fonction conversion
	else if (c == 'U')
		list = list_add_conversion('U', NULL);	// 'NULL' a remplir avec la fonction conversion
	else if (c == 'x')
		list = list_add_conversion('x', NULL);	// 'NULL' a remplir avec la fonction conversion
	else if (c == 'X')
		list = list_add_conversion('X', NULL);	// 'NULL' a remplir avec la fonction conversion
	return (list);
}

t_tab		*list_add_conversion(char c, void (*f)(va_list))
{
	t_tab	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	if (c)
	{
		tmp->c = c;
		tmp->f = f;
	}
	else
	{
		tmp->c = 0;
		tmp->f = NULL;
	}
	return (tmp);
}
