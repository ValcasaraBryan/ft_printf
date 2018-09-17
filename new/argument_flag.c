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

void	precision(t_string *l, t_tab *list)
{
	char *sign;
	int i;

	i = -1;
	while (list->f[++i])
		if (list->f[i] == '.')
			return ;
	sign = ft_strdup("");
	if (l->tab[POINT] >= list->len)
	{
		if (*list->f == '-')
		{
			sign[0] = '-';
			list->f++;
			l->tab[POINT]++;
		}
		list->f = add_caractere_start(list->f, l->tab[POINT] - list->len, '0');
		list->f = ft_strcat(sign, list->f);
		list->len = l->tab[POINT];
	}
}

char		*add_caractere_start(char *params, int len, unsigned char caractere)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(len + 1)))
		return (NULL);
	if (*params && (len >= 0))
	{
		tmp = (char *)ft_memset(tmp, caractere, len);
		tmp = ft_strcat(tmp, params);
		return (tmp);
	}
	else if (!*params && (len >= 0))
	{
		ft_memset(params, caractere, len);
		return (params);
	}
	return (params);
}

char		*option_space_zero(t_string *l, t_tab *list)
{
	char *space;

	if (!(space = ft_memalloc(l->tab[LARGEUR] + 1)))
		return (NULL);
	if (l->tab[LARGEUR] < list->len)
		l->tab[LARGEUR] = list->len;
	if (value_pos(0, l->tab, ZERO))
		ft_memset(space, '0', l->tab[LARGEUR] - list->len);
	else
		ft_memset(space, ' ', l->tab[LARGEUR] - list->len);
	return (space);
}

char		*option_zero_space(char *sign, char *tmp, t_string *l, t_tab *list)
{
	char	*space;

	if (!(space = ft_memalloc(l->tab[LARGEUR] + 1)))
		return (NULL);
	if (l->tab[LARGEUR] < list->len)
		l->tab[LARGEUR] = list->len;
	if (value_pos(0, l->tab, ZERO))
	{
		ft_memset(space, '0', l->tab[LARGEUR] - list->len);
		tmp = ft_strcat(sign, space);
	}
	else
	{
		ft_memset(space, ' ', l->tab[LARGEUR] - list->len);
		tmp = ft_strcat(space, sign);
	}
	return (tmp);
}

char		*blank_option(char *string, t_tab *list)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(2)))
		return (NULL);
	list->len++;
	ft_memset(tmp, ' ', 1);
	return (ft_strcat(tmp, string));
}

char		*signe(long long val, t_tab *list, char **sign, t_string *l)
{
	char *tmp;

	tmp = NULL;
	if (val < 0)
	{
		tmp = ft_strdup(list->f + 1);
		free(list->f);
		*sign[0] = '-';
		return (tmp);
	}
	if (!(l->tab[LARGEUR]))
		l->len++;
	if (*sign[0] == '+')
		list->len++;
	return (list->f);
}

void		add_precision(t_string *l, t_tab *list)
{
	if (l->tab[LARGEUR] < list->len)
		l->tab[LARGEUR] = list->len;
	if (!value_pos(0, l->tab, LEFT))
		option_right(l, list);
	else
		option_left(l, list);
	ft_strcat(l->str + l->len, list->f);
	l->len += l->tab[LARGEUR];
}

void		option_right(t_string *l, t_tab *list)
{
	char	*space;
	char	*sign;
	char	*tmp;

	tmp = NULL;
	space = NULL;
	sign = ft_strdup("+");
	if ((value_pos(0, l->tab, SIGN) || list->f[0] == '-') && ft_atoll(list->f))
	{
		list->f = signe(ft_atoll(list->f), list, &sign, l);
		tmp = option_zero_space(sign, tmp, l, list);
		list->f = ft_strjoin(tmp, list->f);
		return ;
	}
	if (value_pos(0, l->tab, BLANK) && ft_atoll(list->f) != 0
		&& !value_pos(0, l->tab, ZERO))
		tmp = blank_option(list->f, list);
	if (value_pos(0, l->tab, BLANK) && ft_atoll(list->f) != 0
		&& value_pos(0, l->tab, ZERO))
		tmp = blank_option(space, list);
	space = option_space_zero(l, list);
	if (tmp && !value_pos(0, l->tab, BLANK))
	{
		space = ft_strcat(tmp, space);
		list->f = ft_strcat(space, list->f);
	}
	else if (space && tmp)
		list->f = ft_strcat(space, tmp);
	else
		list->f = ft_strcat(space, list->f);
}

void		option_left(t_string *l, t_tab *list)
{
	char	*space;
	char	*sign;
	char	*tmp;

	tmp = NULL;
	if (!(space = ft_memalloc(l->tab[LARGEUR] - list->len + 1)))
		return ;
	sign = ft_strdup("+");
	if ((value_pos(0, l->tab, SIGN) || list->f[0] == '-') && ft_atoll(list->f))
	{
		list->f = signe(ft_atoll(list->f), list, &sign, l);
		ft_memset(space, ' ', l->tab[LARGEUR] - list->len);
		tmp = ft_strjoin(list->f, space);
		ft_strjoin(list->f, tmp);
		list->f = ft_strcat(sign, tmp);
		return ;
	}
	if (value_pos(0, l->tab, BLANK) && ft_atoll(list->f))
		tmp = blank_option(list->f,list);
	ft_memset(space, ' ', l->tab[LARGEUR] - list->len);
	if (!tmp)
		tmp = ft_strjoin(list->f, space);
	else
		tmp = ft_strjoin(tmp, space);
	list->f = tmp;
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
