/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_option.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:17:58 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:17:59 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void					flag_optional(char *arg, t_string *list)
{
	int				i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '-')
			TAB[LEFT - 1] = LEFT;
		if (arg[i] == '0' && !((arg[i - 1] <= '9' && arg[i - 1] >= '0'))
				&& !(arg[i - 1] == '.'))
			TAB[ZERO - 1] = ZERO;
		if (arg[i] == ' ')
			TAB[BLANK - 1] = BLANK;
		if (arg[i] == '+')
			TAB[SIGN - 1] = SIGN;
		if (arg[i] == '#')
			TAB[HASHTAG - 1] = HASHTAG;
		if (arg[i] == 'j')
			TAB[J_FLAG - 1] = J_FLAG;
		i = largeur_of_camp(arg, list, i);
		i = flag_optional_suit(arg, list, i);
	}
}

int						largeur_of_camp(char *arg, t_string *list, int i)
{
	if (LARGEUR_NO)
		if (arg[i] >= '1' && arg[i] <= '9' && !(arg[i - 1] == '.'))
		{
			TAB[LARGEUR] = ft_atoll(arg + i);
			i += ft_strlen(ft_lltoa(TAB[LARGEUR]));
		}
	if (POINT_NO)
		if (arg[i] == '.')
		{
			TAB[POINT - 1] = POINT;
			TAB[POINT] = ft_atoll(arg + i + 1);
			i += ft_strlen(ft_lltoa(TAB[POINT]));
		}
	return (i);
}

int						flag_optional_suit(char *arg, t_string *list, int i)
{
	if (arg[i] == 'z')
		TAB[Z_FLAG - 1] = Z_FLAG;
	if (arg[i] == 'l' && NO_LONG && NO_LONG_)
	{
		if (arg[i] == 'l' && arg[i + 1] == 'l')
		{
			TAB[INT_LONG_LONG - 1] = INT_LONG_LONG;
			i++;
		}
		else
			TAB[INT_LONG - 1] = INT_LONG;
	}
	if (arg[i] == 'h' && NO_SHORT && NO_SHORT_)
	{
		if (arg[i] == 'h' && arg[i + 1] == 'h')
		{
			TAB[INT_SHORT_SHORT - 1] = INT_SHORT_SHORT;
			i++;
		}
		else
			TAB[INT_SHORT - 1] = INT_SHORT;
	}
	return (i);
}

void					list_add_conversion(char *string, t_string *list)
{
	if (string)
	{
		DATA = ft_strdup(string);
		LEN = ft_strlen(string);
	}
	else
	{
		DATA = ft_strdup("(null)");
		LEN = 6;
	}
}

int						binary_flag(int *tab, int len)
{
	int					i;
	int					j;

	i = -1;
	j = 0;
	if (!tab)
		return (0);
	while (++i < len)
		if (tab[i] > 0)
			++j;
	return (j);
}
