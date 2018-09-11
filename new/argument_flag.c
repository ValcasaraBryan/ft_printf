/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:01:32 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/25 22:01:34 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*signe(long long val, char *string, char **sign)
{
	if (val < 0)
	{
		++string;
		*sign[0] = '-';
	}
	return (string);
}

void		add_precision(t_string *l, t_tab *list)
{
	if (!value_pos(0, l->tab, LEFT))
		option_right(l, list);
	else
		option_left(l, list);
}

char		*option_right(t_string *l, t_tab *list)
{
	char	*space;
	char	*sign;
	char	*tmp;

	sign = NULL;
	tmp = NULL;
//	if (!(space = ft_memalloc(i + 1)))
//		return (NULL);
	sign = ft_strdup("+");
	if (value_pos(0, l->tab, SIGN) || list->f[0] == '-')
	{
		list->f = signe(ft_atoll(list->f), list->f, &sign);
//		tmp = option_zero_space(sign, tmp, i - len, l->tab);
		return (ft_strcat(tmp, list->f));
	}
//	if (value_pos(0, l->tab, BLANK) && ft_atoll(list->f) != 0
//		&& !value_pos(0, l->tab, ZERO))
//		tmp = blank_option(list->f, &i, l->tab);
//	if (value_pos(0, l->tab, BLANK) && ft_atoll(list->f) != 0
//		&& value_pos(0, l->tab, ZERO))
//		space = blank_option(list->f, &i, l->tab);
//	option_space_zero(space, i, len, l->tab);
	if (tmp)
		return (ft_strcat(space, tmp));
	else
		return (ft_strcat(space, list->f));
}

char		*option_left(t_string *l, t_tab *list)
{
	char	*space;
	char	*sign;
	char	*tmp;

	sign = NULL;
//	if (!(space = ft_memalloc(i + 1)))
//		return (NULL);
	sign = ft_strdup("+");
	if (value_pos(0, l->tab, SIGN) || list->f[0] == '-')
	{
		list->f = signe(ft_atoll(list->f), list->f, &sign);
//		ft_memset(space, ' ', i - len);
		tmp = ft_strcat(tmp, space);
		tmp = ft_strcat(list->f, tmp);
		return (ft_strcat(sign, tmp));
	}
//	if (value_pos(0, l->tab, BLANK) && ft_atoll(list->f))
//		tmp = blank_option(list->f, &i, l->tab);
	ft_strcat(tmp, list->f);
//	ft_memset(space, ' ', i - len);
	return (ft_strcat(tmp, space));
}

char		*option_zero_space(char *sign, char *tmp, int i, int *flag)
{
	char	*space;

	if (!(space = ft_memalloc(i + 1)))
		return (NULL);
	if (value_pos(0, flag, ZERO))
	{
		ft_memset(space, '0', i);
		tmp = ft_strcat(sign, space);
	}
	else
	{
		ft_memset(space, ' ', i);
		tmp = ft_strcat(space, sign);
	}
	return (tmp);
}

int			value_pos(int i, int *tab, int flag)
{
	int		j;

	j = -1;
	while (++j < LENGHT_TAB - 1)
	{
		if (tab[j] == flag)
		{
			if (i)
				return (i);
			else
				return (1);
		}
	}
	return (i);
}
