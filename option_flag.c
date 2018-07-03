/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:01:32 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/25 22:01:34 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*blank_option(char *string, int *i, int *flag)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(2)))
		return (NULL);
	i[0] -= 1;
	return (add_caractere(tmp, 1, ' '));
}

char		*signe(long long val, char *string, char **sign, int *i)
{
	if (val < 0)
	{
		string++;
		*sign[0] = '-';
	}
	else
		i[0] -= 1;
	return (string);
}
