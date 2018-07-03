/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mid_body.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:32:38 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/05 17:32:40 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_tab		*list_param(int *index, va_list ap, char *param, int **z)
{
	int		j;
	int		i;
	t_tab	*list;

	i = *index;
	list = NULL;
	if (ft_strlen(param) == 1 && params(*param))
		list = return_list(*param, ap, *z);		// initialise le parametre arg[2]
	else if (params(param[ft_strlen(param) - 1]))
	{
		*z = flag_optional(param);
		j = binary(*z);
		i = precision_params(param);// donne à i la longueur de precision
		if ((j + ft_strlen(ft_itoa_l_l(i))) == ft_strlen(param) - 1)
			list = return_list(param[(j + ft_strlen(ft_itoa_l_l(i)))], ap, *z);
		else if (!i && (j == (int)ft_strlen(param) - 1))
			list = return_list(param[j], ap, *z);
		else
			list = return_list(param[ft_strlen(param) - 1], ap, *z);
		*index = i;
	}
	return (list);
}

char	*inter_flag_of_conv(const char *format, char *string, int *index, int len_param)
{
	char	*res;
	int		ret;

	res = string;
	ret = *index;
	if (p_of_params((char *)format + ret++ + 1))
	{
		ft_strncpy(res + ft_strlen(res), format + len_param, p_of_params((char *)format + len_param + 1) + 1);
		ret += p_of_params((char *)format + len_param + 1) + 1;
	}
	else if (!parsing_params((char *)format + ret))
		ft_strncpy(res + ft_strlen(res), format + len_param, p_of_params((char *)format + len_param + 1));
	*index = ret;
	return (string);
}

int		*reset_tab_int(int *tab, int len)
{
	int i;

	i = -1;
	if (tab)
	{
		while (++i < len)
			tab[i] = 0;
		return (tab);
	}
	return (0);
}

int		*flag_long_short(int *tab, int *index, char *param)
{
	int i;

	i = *index;
	if (param[i] == 'l' && tab[5] == 0 && tab[6] == 0)
	{
		if (param[i] == 'l' && param[i + 1] == 'l')
		{
			tab[6] = INT_LONG_LONG;
			i++;
		}
		else
			tab[5] = INT_LONG;
	}
	if (param[i] == 'h' && tab[7] == 0 && tab[8] == 0)
	{
		if (param[i] == 'h' && param[i + 1] == 'h')
		{
			tab[8] = INT_SHORT_SHORT;
			i++;
		}
		else
			tab[7] = INT_SHORT;
	}
	*index = i;
	return (tab);
}
