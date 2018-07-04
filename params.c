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

char		*add_caractere(char *params, int len, int caractere)
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
		if (param[i] > 48 && param[i] <= 57)
			return (ft_atoi(param + i));
	}
	return (0);
}

int			parsing_params(char *arg)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!arg)
		return (-1);
	while (arg[++i])
		if (arg[i] == '%')
			while (arg[i + (++j)])
				if (params(arg[i + j]) > 0)
					return (j);
	return (0);
}

int			params(char comp)
{
	char	*list;
	int		i;

	i = -1;
	list = "sSpdDioOuUxXcC%";
	while (list[++i])
		if (list[i] == comp)
			return (i + 1);
	return (0);
}

int			nb_percent(char *format)
{
	int		i;
	int		nb_percent;

	i = -1;
	nb_percent = 0;
	while (format[++i])
		if (format[i] == '%' && params(format[i]))
		{
			if (format[i + 1] == '%')
				i++;
			++nb_percent;
		}
	return (nb_percent);
}
