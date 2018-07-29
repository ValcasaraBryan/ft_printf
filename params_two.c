/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 16:55:18 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/22 16:55:20 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			p_of_params(char *format)
{
	int		i;

	i = -1;
	if (!format)
		return (-1);
	while (format[++i])
		if (format[i] == '%')
			return (i);
	return (-1);
}

char		*option_space_zero(char *space, int i, int len, int *flag)
{
	if (value_pos(0, flag, ZERO))
		add_caractere(space, i - len, '0');
	else
		add_caractere(space, i - len, ' ');
	return (space);
}

char		*add_caractere_start(char *params, int len, unsigned char caractere)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(len + 1)))
		return (NULL);
	if (*params && (len >= 0))
	{
		tmp = (char *)ft_memset(tmp, caractere, len);
		tmp = ft_strcat(tmp, params);
		return (tmp);
	}
	else if (!*params && (len >= 0))
	{
		ft_memset(params, caractere, len);
		return (params);
	}
	return (params);
}