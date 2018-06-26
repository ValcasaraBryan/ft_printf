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

char	*add_precision(char *string, int i, int len, int flag)
{
	char *tmp;

	if (!(tmp = ft_memalloc(i + len + 1)))
			return (NULL);
	if (flag == 0 && i > len && i > 0)
	{
		i = i - len;
		add_caractere(tmp, i, 32);
		string = ft_strcat(tmp, string);
	}
	if (flag == 2)
	{
		if (i > len && i > 0)
		{
			ft_strcpy(tmp, string);
			add_caractere(tmp + len, i - len, 32);
			string = tmp;
		}
	}
	if (flag == 3)
	{
		if (i > len && i > 0)
		{
			i = i - len;
			add_caractere(tmp, i, 48);
			string = ft_strcat(tmp, string);
		}
	}
	if (flag == 4)
	{
		if (i > (len + 1) && i > 0)
		{
			add_caractere(tmp, i - (len + 1), 32);
			ft_memset(tmp + (i - (len + 1)), 43, 1);
			string = ft_strcat(tmp, string);
		}
	}
	return (string);
}

 // modifier la longueur de champ a la fin

int		*binary_flag(int *tab)
{
	int		i;
	int		j;
	int 	len;
	int 	*val;

	i = -1;
	len = 6;
	j = 0;
	if (!tab)
		return (0);
	if (!(val = (int *)malloc(sizeof (int) * 6)))
		return (0);
	while (++i < len)
		if (tab[i] > 0 && i < len)
			val[j++] = tab[i];
	return (val);
}