/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoui.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:22:53 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:22:56 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int		ft_atoui(const char *str)
{
	long long	rep;

	rep = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str >= 48 && *str <= 57)
	{
		rep = rep * 10 + *str - '0';
		str++;
	}
	return (rep);
}
