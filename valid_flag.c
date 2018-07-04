/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 01:47:18 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/04 01:47:19 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		valid_flag_short(int *tab)
{
	if (tab[7] == INT_SHORT)
		return (1);
	return (0);
}

int		valid_flag_short_short(int *tab)
{
	if (tab[8] == INT_SHORT_SHORT)
		return (1);
	return (0);
}

int		valid_flag_long(int *tab)
{
	if (tab[5] == INT_LONG)
		return (1);
	return (0);
}

int		valid_flag_long_long(int *tab)
{
	if (tab[6] == INT_LONG_LONG)
		return (1);
	return (0);
}
