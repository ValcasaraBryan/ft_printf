/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:39:46 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/06 19:39:47 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_caractere(char *params, int len, long caractere)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(len + 1)))
		return (NULL);
	if (*params && (len >= 0))
	{
		tmp = (char *)ft_memset(tmp, caractere, len);
		ft_strcat(params, tmp);
		return (params);
	}
	else if (!*params && (len >= 0))
	{
		ft_memset(params, caractere, len);
		return (params);
	}
	return (NULL);
}

int			precision_params(char *param)
{
	int		i;

	i = -1;
	if (!param)
		return (-1);
	while (param[++i])
	{
		if (param[i] > 48 && param[i] <= 57
			&& param[i - 1] != '.')
			return (ft_atoi(param + i));
	}
	return (0);
}

int			parsing_params(char *arg)
{
	int		i;
	int		j;
	int		x;

	i = -1;
	j = 0;
	x = 0;
	if (!arg)
		return (-1);
	while (arg[++i])
		if (arg[i] == '%')
			while (arg[i + (++j)])
			{
				if (params(arg[i + j], CONV) > 0)
					return (j);
				if (params(arg[i + j], FLAG) == 0)
					return (x);
				x++;
			}
	return (0);
}

int			params(char comp, const char *list)
{
	int		i;

	i = -1;
	while (list[++i])
		if (list[i] == comp)
			return (i + 1);
	return (0);
}



int			nb_percent(char *format)
{
	int		i;
	int		j;
	int		nb_percent;

	i = -1;
	nb_percent = 0;
	if (!format)
		return (-1);
	while (format[++i])
		if (format[i] == '%')
		{
			if ((j = parsing_params(format + i)) && format[i + j] == '%')
				i += j;
			++nb_percent;
		}
	return (nb_percent);
}
