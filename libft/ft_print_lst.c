/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:19:05 by brvalcas          #+#    #+#             */
/*   Updated: 2018/05/09 16:19:07 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int		ft_print_lst(t_list *list)
{
	t_list *head;

	if (list)
	{
		head = list;
		printf("t_list->[%p]", list);
		while (list->next)
		{
			printf("->[%p]", list->next);
			list = list->next;
		}
		printf("->[%p]\n            ", list->next);
		list = head;
		while (list)
		{
			printf("[%s]          ", (char *)list->content);
			list = list->next;
		}
		printf("\n");
		list = head;
		return (0);
	}
	ft_putstr("\n--- Aucun Maillon ---\n");
	return (-1);
}
