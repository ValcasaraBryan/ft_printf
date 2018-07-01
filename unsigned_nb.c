/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_nb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:01:32 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/25 22:01:34 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_u_precision(char *string, int i, int len, int *flag)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(i + len + 1)))
			return (NULL);
	if (i < len)
		i = len;
	tmp = option_u_right(ft_uitoa(ft_atoui(string)), i, len, flag);
	return (tmp);
}

char		*option_u_right(char *string, int i, int len, int *flag)
{
	char	*space;
	char	*sign;
	char	*tmp;

	sign = NULL;
	if (!(space = ft_memalloc(i + 1)))
		return (NULL);
	if (!value_pos(0, flag, LEFT))
	{
		if (value_pos(0, flag, ZERO))
			add_caractere(space, i - len, '0');					// NO SIGN + NO LEFT + ZERO
		else
			add_caractere(space, i - len, ' ');					// NO SIGN + NO LEFT + NO ZERO
		if (!tmp)
			ft_strcat(tmp, string);
		tmp = ft_strcat(space, tmp);
		return (tmp);
	}
	else
	{
		if (!tmp)
			ft_strcat(tmp, string);
		add_caractere(space, i - len, ' ');	
		ft_strcat(tmp, space);
		return (tmp);
	}
	return (NULL);
}

