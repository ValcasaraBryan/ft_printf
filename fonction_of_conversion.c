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

void	*return_list(char c, va_list ap)
{
	t_tab	*list;

	list = init_list(ap);
	while (list)
	{
		if (list->c == c)
			return (list->f);
		list = list->next;
	}
	return (NULL);
}

t_tab	*init_list(va_list ap)
{
	t_tab	*list;
	t_tab	*tmp;

	list = list_add_conversion('s', (void *)string_s(ap));
	//tmp = list_add_conversion('S', NULL);
	//list_add(&list, tmp);
	tmp = list_add_conversion('c', (void *)conv_c(ap));
	list_add(&list, tmp);
//	list = list_add_conversion('C', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('p', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('d', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('D', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('i', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('o', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('O', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('u', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('U', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('x', NULL);
//	list_add(&list, tmp);
//	list = list_add_conversion('X', NULL);
//	list_add(&list, tmp);
	return (list);
}

t_tab	*list_add_conversion(char c, void (*f)(va_list))
{
	t_tab	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	if (c && f)
	{
		tmp->c = c;
		tmp->f = f;
	}
	else
	{
		tmp->c = 0;
		tmp->f = NULL;
	}
	tmp->next = NULL;
	return (tmp);
}

void	list_add(t_tab	**list, t_tab *new)
{
	if (new)
	{
		new->next = *list;
		*list = new;
	}
}