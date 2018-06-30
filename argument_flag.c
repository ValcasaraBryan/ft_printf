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

char		*add_precision(char *string, int i, int len, int *flag)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(i + len + 1)))
			return (NULL);
	if (i < len)
		i = len;
	if (value_pos(0, flag, BLANK) && value_pos(0, flag, SIGN) && i < len)
		i++;
	if (!value_pos(0, flag, LEFT))
		tmp = option_right(string, i, len, flag);
	else
		tmp = option_left(string, i, len, flag);
	return (tmp);
}

int			value_pos(int i, int *tab, int flag)
{
	int		j;

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

char		*option_right(char *string, int i, int len, int *flag)
{
	char	*space;
	char	*sign;
	char	*tmp;

	sign = NULL;
	if (!(space = ft_memalloc(i + 1)))
		return (NULL);
	sign = ft_strdup("+");
	if ((value_pos(0, flag, SIGN) || ft_atoi(string) < 0) && ft_atoi(string))
	{
		string = signe(ft_atoi(string), string, &sign, &i);
		tmp = option_zero_space(sign, tmp, i - len, flag);	// SIGN + NO LEFT + ZERO || NO ZERO
		return (ft_strcat(tmp, string));
	}
	if (value_pos(0, flag, BLANK) && ft_atoi(string) > 0 && !value_pos(0, flag, ZERO))
		tmp = blank_option(string, &i, flag);				// NO SIGN + NO LEFT + NO ZERO + BLANK
	if (value_pos(0, flag, BLANK) && ft_atoi(string) > 0 && value_pos(0, flag, ZERO))
		space = blank_option(string, &i, flag);				// NO SIGN + NO LEFT + ZERO    + BLANK
	if (value_pos(0, flag, ZERO))
		add_caractere(space, i - len, '0');					// NO SIGN + NO LEFT + ZERO
	else
		add_caractere(space, i - len, ' ');					// NO SIGN + NO LEFT + NO ZERO
	ft_strcat(tmp, string);
	tmp = ft_strcat(space, tmp);
	return (tmp);
}

char		*option_left(char *string, int i, int len, int *flag)
{
	char	*space;
	char	*sign;
	char	*tmp;

	sign = NULL;
	if (!(space = ft_memalloc(i + 1)))
		return (NULL);
	sign = ft_strdup("+");
	if (value_pos(0, flag, SIGN) && ft_atoi(string))
	{
		string = signe(ft_atoi(string), string, &sign, &i);
		add_caractere(space, i - len, ' ');
		tmp = ft_strcat(tmp, space);
		tmp = ft_strcat(string, tmp);
		tmp = ft_strcat(sign, tmp);
		return (tmp);					// SIGN + LEFT + NO ZERO
	}
	if (value_pos(0, flag, BLANK) && ft_atoi(string) > 0)	// NO SIGN + LEFT + NO ZERO + BLANK 
		tmp = blank_option(string, &i, flag);
	ft_strcat(tmp, string);
	add_caractere(space, i - len, ' ');	
	tmp = ft_strcat(tmp, space);
	return (tmp);						// NO SIGN + LEFT + NO ZERO
}

char		*option_zero_space(char *sign, char *tmp, int i, int *flag)
{
	char	*space;

	if (!(space = ft_memalloc(i + 1)))
		return (NULL);
	if (value_pos(0, flag, ZERO))
	{
		add_caractere(space, i, '0');
		tmp = ft_strcat(sign, space);
	}
	else
	{
		add_caractere(space, i, ' ');
		tmp = ft_strcat(space, sign);
	}
	return (tmp);
}
