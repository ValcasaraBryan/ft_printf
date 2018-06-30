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

	if (binary(flag))
	{
		tmp = add_precision(string, value_pos(i, tab, SIGN), (int)ft_strlen(string), flag);
		ft_strcat(res, tmp);
		return (res);
	}
	tmp = add_precision(string, i, (int)ft_strlen(string), flag);
	if (tmp)
		ft_strcat(res, tmp);
	else
		ft_strcat(res, string);
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
			add_caractere(res, i - 1, 32);
	}
	else
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

	if (!(tab = (int *)malloc(sizeof (int) * LENGTH_TAB + 1)))
		return (0);
	while (param && (*param == '-' || *param == '0' || *param == '+'
		|| *param == ' ' || *param == '#'))
	{
		if (*param == '-')
			tab[0] = LEFT;
		if (*param == '0')
			tab[1] = ZERO;
		if (*param == '+')
			tab[2] = SIGN;
		if (*param == ' ')
			tab[3] = BLANK;
		if (*param == '#')
			tab[4] = HASHTAG;
		param++;
	}
	return (tab);
}

int			binary(int *tab)
{
	int		i;
	int		len;
	int		j;

	i = -1;
	len = LENGTH_TAB;
	j = 0;
	if (!tab)
		return (0);
	while (++i < LENGTH_TAB)
		if (tab[i] > 0 && tab[i] <= 5 && i < LENGTH_TAB)
			++j;
	return (j);
}
