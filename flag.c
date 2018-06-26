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

char	*flag_int(char *res, int i, int number, int *flag)
{
	unsigned int j;
	int			y;
	char 		*tmp;
	int *tab;

	j = 1;
	if (binary(flag))
	{
		j += (unsigned int)binary(flag);
		tab = binary_flag(flag);
		while (j--)
		{
			tmp = add_precision(ft_itoa(number), i, (int)ft_strlen(ft_itoa(number)), *tab);
			if (j != 1)
				tab++;
		}
		ft_strcat(res, tmp);
		return (res);
	}
	tmp = add_precision(ft_itoa(number), i, (int)ft_strlen(ft_itoa(number)), 0);
	ft_strcat(res, tmp);
	return (res);
}

char	*flag_string(char *res, int i, char *string, int *flag)
{
	unsigned int j;
	int 		*tab;
	char *tmp;

	j = 1;
	if (binary(flag))
	{
		j += (unsigned int)binary(flag);
		tab = binary_flag(flag);
		while (j--)
		{
			tmp = add_precision(string, i, (int)ft_strlen(string), *tab);
			if (j != 1)
				tab++;
		}
		ft_strcat(res, tmp);
		return (res);
	}
	tmp = add_precision(string, i, (int)ft_strlen(string), 0);
	ft_strcat(res, tmp);
	return (res);
}

char	*flag_char(char *res, int i, char caractere)
{
	if (i > 1)
		add_caractere(res, i - 1, 32);
	add_caractere(res, 1, caractere);
	return (res);
}

int		*flag_optional(char *param)
{
	int		*tab;

	if (!(tab = (int *)malloc(sizeof (int) * 6)))
		return (0);
	while (*param == '-' || *param == '0' || *param == '+'
		|| *param == ' ' || *param == '#')
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

int		binary(int *tab)
{
	int		i;
	int		len;
	int		j;

	i = -1;
	len = 6;
	j = 0;
	if (!tab)
		return (0);
	while (++i < len)
		if (tab[i] > 0 && i < len)
			++j;
	return (j);
}