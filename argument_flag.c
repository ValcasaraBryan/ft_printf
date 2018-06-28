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

char	*add_precision(char *string, int i, int len, int *flag)
{
	char *tmp;
	char *space;

	if (!(tmp = ft_memalloc(i + len + 1)))
			return (NULL);
	if (!(space = ft_memalloc((i - len) + 1)))
			return (NULL);
	if (i > len && i > 0)
		add_caractere(space, i - len, ' ');
	if (value_pos(0, flag, SIGN))
		add_caractere(tmp, 1, '+');
	if (value_pos(0, flag, ZERO) && !value_pos(0, flag, LEFT))
		tmp = (char *)ft_memset(space, '0', i - len);
	else if (!value_pos(0, flag, LEFT))
		tmp = ft_strcat(space, tmp);
	if (tmp)
		string = ft_strcat(tmp, string);
	if (value_pos(0, flag, LEFT))
		ft_strcat(tmp, space);
	return (string);
}

 // modifier la longueur de champ a la fin

int		*binary_flag(int *tab)
{
	int		i;
	int		j;
	int 	*val;

	i = -1;
	j = -1;
	if (!tab)
		return (0);
	if (!(val = (int *)malloc(sizeof (int) * LENGTH_TAB + 1)))
		return (0);
	while (++i < LENGTH_TAB)
	{
		if (tab[i] > 0 && i < LENGTH_TAB)
			val[++j] = tab[i];
	}
	return (val);
}

int		value_pos(int i, int *tab, int flag)
{
	int j;

	j = -1;
	while (++j < LENGTH_TAB)
		if (tab[j] == flag)
		{
			if (i)
				return (i - 1);
			else
				return (1);
		}
	return (i);
}

