/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:22:53 by brvalcas          #+#    #+#             */
/*   Updated: 2018/04/04 16:22:56 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int		ft_u_len(unsigned int n)
{
	unsigned int		i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char					*ft_uitoa(unsigned int n)
{
	char				*str;
	unsigned int		i;

	i = ft_u_len(n);
	if (!(str = ft_memalloc(i + 2)))
		return (NULL);
	str[i + 1] = '\0';
	while (n > 9)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}
