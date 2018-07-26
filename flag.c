/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:37:06 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/23 21:37:08 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*flag_string(char *res, int i, char *string, int *flag)
{
	int		*tab;
	char	*tmp;

	if (!flag)
		return (res);
	if (binary(flag))
	{
		tmp = add_precision(string, value_pos(i, tab, SIGN),
			(int)ft_strlen(string), flag);
		ft_strcat(res, tmp);
		return (res);
	}
	tmp = add_precision(string, i, (int)ft_strlen(string), flag);
	ft_strcat(res, tmp);
	return (res);
}

char		*flag_char(char *res, int i, char caractere, int *flag)
{
	char	*tmp;

	if (i > 1 && (!value_pos(0, flag, LEFT)))
	{
		if (value_pos(0, flag, ZERO))
			add_caractere(res, i - 1, '0');
		else
			add_caractere(res, i - 1, ' ');
	}
	else if (i > 1)
	{
		if (!(tmp = ft_memalloc(i + 1)))
			return (NULL);
		add_caractere(tmp, i, ' ');
		tmp = (char *)ft_memset(tmp, caractere, 1);
		res = strcat(res, tmp);
		return (res);
	}
	add_caractere(res, 1, caractere);
	return (res);
}

int			*flag_optional(char *param)
{
	int		*tab;
	int		i;

	i = -1;
	if (!(tab = (int *)malloc(sizeof(int) * LENGTH_TAB + 1)))
		return (0);
	if (!param)
		return (reset_tab_int(tab, LENGTH_TAB));
	while (param[++i])
	{
		if (param[i] == '-')
			tab[LEFT - 1] = LEFT;
		if (param[i] == '0' && !((param[i - 1] <= '9' && param[i - 1] >= '0')))
			tab[ZERO - 1] = ZERO;
		if (param[i] == '+')
			tab[SIGN - 1] = SIGN;
		if (param[i] == ' ')
			tab[BLANK - 1] = BLANK;
		if (param[i] == '#')
			tab[HASHTAG - 1] = HASHTAG;
		if (param[i] == '.')
			tab[POINT - 1] = POINT;
		tab = flag_long_short(tab, &i, param);
		tab = flag_z_j(tab, &i, param);
	}
	return (tab);
}

int			binary(int *tab)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!tab)
		return (0);
	while (++i < LENGTH_TAB)
		if (tab[i] > 0 && tab[i] <= LENGTH_TAB)
			++j;
	return (j);
}

int			precision_params_point(char *param)
{
	int		i;

	i = -1;
	if (!param)
		return (-1);
	while (param[++i])
	{
		if (param[i] > 48 && param[i] <= 57
			&& param[i - 1] == '.')
			return (ft_atoi(param + i));
	}
	return (0);
}

int		*flag_z_j(int *tab, int *index, char *param)
{
	int	i;

	i = *index;
	if (param[i] == 'j')
		tab[J_FLAG - 1] = J_FLAG;
	if (param[i] == 'z')
		tab[Z_FLAG - 1] = Z_FLAG;
	*index = i;
	return (tab);
}
