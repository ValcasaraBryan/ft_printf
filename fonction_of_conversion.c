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

#include "ft_printf.c"

void	*return_list(char c, va_list ap)
{
	t_tab	*list;

	if (!(list = malloc(sizeof(t_tab) * 15)))
		return (NULL); 
	list = init_list_start(list, ap);
	while (list)
	{
		if (list->c == c)
			return (list->result);
		list = list->next;
	}
	return (NULL);
}

t_tab	*init_list_start(t_tab *list, va_list ap)
{
	t_tab *head;

	head = list;
	list->c = 's';
	list->result = (void *)string_s(ap);
	list = list->next;
	list->c = 'S';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'c';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'C';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'p';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'd';
	list->result = (void *)(ap);
	list = list->next;
	list = init_list_next(list, ap);
	return (head);
}

t_tab	*init_list_next(t_tab *list, va_list ap)
{
	list->c = 'D';
	list->result = (void *)(ap);
	list = list->next;
 	list->c = 'i';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'o';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'O';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'u';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'U';
	list->result = (void *)(ap);
	list = list->next;
	list->c = 'x';
	list->result = (void *)(ap);
	list = list->next;
	list = init_list_rest(list, ap);
	return (list);
}

t_tab	*init_list_rest(t_tab *list, va_list ap)
{
	list->c = 'X';
	list->result = (void *)(ap);
	list->next = NULL;
	return (list);
}
