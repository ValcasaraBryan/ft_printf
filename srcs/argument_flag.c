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

#include "../includes/ft_printf.h"

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

void		precision_string(t_string *l, t_tab *list)
{
	char	*tmp;

	if (list && l->tab[POINT - 1] && l->tab[POINT] < list->len)
	{
		tmp = ft_strndup(list->f, l->tab[POINT]);
		list->f = tmp;
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
		ft_memset(tmp, caractere, len);
		return (tmp);
	}
	return (params);
}

void		add_precision(t_string *l, t_tab *list)
{
	priority_flag(l, list);
	option(l, list);
	ft_strcat(l->str + l->len, list->f);
	if (l->tab[LARGEUR] > list->len)
		l->len += l->tab[LARGEUR];
	else
		l->len += list->len;
}

int			value_tab(int *tab, int len)
{
	int		i;
	int		ret;

	i = -1;
	if (len <= 0)
		return (-1);
	while (++i < len)
		if (tab[i] > 0 && tab[i] < len - 1 && i > -1 && i <= len)
		{
			ret = tab[i];
			tab[i] = -1;
			return (ret);
		}
	return (0);
}

void	priority_flag(t_string *l, t_tab *list)
{
	if (l->tab[LEFT  - 1] == LEFT)
		l->tab[ZERO - 1] = -1;
	if (l->tab[SIGN - 1] == SIGN || *list->f == '-')
	{
		l->tab[BLANK - 1] = -1;
		if (*list->f == '-')
		{
			l->tab[SIGN - 1] = SIGN;
			list->len--;
		}
	}
	if (l->tab[LARGEUR] < list->len)
		l->tab[LARGEUR] = list->len;
	else if (l->tab[LARGEUR] < l->tab[POINT])
		l->tab[LARGEUR] = l->tab[POINT];
	if (l->tab[LARGEUR] == list->len &&  l->tab[LEFT - 1] == LEFT
		&& (l->tab[SIGN - 1] == SIGN || l->tab[BLANK - 1] == BLANK))
		l->tab[LARGEUR] = list->len + 1;
}

char		sign_of_tmp(t_string *l, t_tab *list)
{
	if (*list->f == '-')
		return ('-');
	else if (l->tab[SIGN - 1] == SIGN)
		return ('+');
	return (-1);
}

int 	set_option(t_string *l, t_tab *list, int zero, char *tmp)
{
	int index_of_tmp;

	index_of_tmp = 0;
	while (l->tab[BLANK - 1] == BLANK || l->tab[ZERO - 1] == ZERO
		|| l->tab[SIGN - 1] == SIGN)
	{
		if (l->tab[BLANK - 1] == BLANK)
		{
			ft_memset(tmp + index_of_tmp++, ' ', 1);
			l->tab[BLANK - 1] = -1;
			zero--;
		}
		if ((((l->tab[ZERO - 1] == ZERO && zero > 0) ||
			(l->tab[ZERO - 1] == -1 && zero <= 1)) || l->tab[LEFT - 1] == LEFT)
			&& l->tab[SIGN - 1] == SIGN)
		{
			ft_memset(tmp + index_of_tmp++, sign_of_tmp(l, list), 1);
			l->tab[SIGN - 1] = -1;
			zero--;
		}
		else if (l->tab[ZERO - 1] == -1 && zero > 0 && l->tab[SIGN - 1] == SIGN
			&& l->tab[LEFT - 1] == -1)
			ft_memset(tmp + index_of_tmp++, ' ', zero--);
		else if (l->tab[ZERO - 1] == ZERO && zero > 0 && l->tab[SIGN - 1] == -1)
			ft_memset(tmp + index_of_tmp++, '0', zero--);
		if (zero <= 0)
			l->tab[ZERO - 1] = -1;
	}
	return (index_of_tmp);
}

void		option(t_string *l, t_tab *list)
{
	char	*tmp;
	int		index_of_tmp;
	int		zero;
	int		plus;

	plus = 0;
	if (l->tab[SIGN - 1] == SIGN || l->tab[BLANK - 1] == BLANK)
		plus++;
	zero = l->tab[LARGEUR] - list->len;
	if (!(tmp = ft_memalloc(l->tab[LARGEUR] + plus + 1)))
		return ;
	index_of_tmp = set_option(l, list, zero, tmp);
	if (index_of_tmp < (l->tab[LARGEUR] - list->len) && l->tab[LEFT - 1] == -1)
	{
		ft_memset(tmp + index_of_tmp, ' ', l->tab[LARGEUR] - list->len - plus);
		index_of_tmp += l->tab[LARGEUR] - list->len - plus;
	}
	if (*list->f == '-')
		tmp = ft_memjoin(tmp, index_of_tmp, list->f + 1, list->len);
	else
		tmp = ft_memjoin(tmp, index_of_tmp, list->f, list->len);
	index_of_tmp += list->len;
	if (l->tab[LEFT - 1] == LEFT && index_of_tmp < (l->tab[LARGEUR] - list->len))
	{
		ft_memset(tmp + index_of_tmp, ' ', l->tab[LARGEUR] - list->len - plus);
		index_of_tmp += l->tab[LARGEUR] - list->len - plus;
	}
	list->len = index_of_tmp;
	list->f = tmp;
	free(tmp);
}
