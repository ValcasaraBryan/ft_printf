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
#define ANSI_COLOR_RESET   "\033[0;30m"
#define ANSI_COLOR_RED     "\033[0;31m"


void	hashtag_option_before(t_string *l, t_tab *list, char c)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(2 + list->len + 1)))
		return ;
	if ((c == 'x' || c == 'X') && ((l->tab[LARGEUR] == -1
		|| l->tab[LEFT - 1] == LEFT) && l->tab[POINT - 1] == -1) && ft_atoi(list->f) > 0)
	{
		tmp[0] = '0';
		tmp[1] = c;
		tmp = ft_memjoin(tmp, 2, list->f, list->len);
		list->len += 2;
		free(list->f);
		list->f = tmp;
		l->tab[HASHTAG - 1] = -1;
	}
	else if (c == 'o' && ft_atoi(list->f) > 0)
	{
		tmp[0] = '0';
		tmp = ft_memjoin(tmp, 1, list->f, list->len);
		free(list->f);
		list->f = tmp;
		list->len += 1;
	}
}
void	hashtag_option_after(t_string *l, t_tab *list, char c)
{
	int		i;

	i = 0;
	if ((c == 'x' || c == 'X') && l->tab[LARGEUR] == list->len && l->tab[POINT - 1] == -1)
	{
		while (list->f[i] == ' ' && list->f[i])
			i++;
		if (list->f[i - 2] == ' ' && list->f[i - 1] == ' ')
		{
			list->f[i - 2] = '0';
			list->f[i - 1] = c;
		}
		else
			list->f[1] = c;
		l->tab[HASHTAG - 1] = -1;
	}
	else if (c == 'o' && list->len == 0)
	{
		list->f[0] = '0';
		list->len = 1;
		l->tab[HASHTAG - 1] = -1;
	}
}

void	precision(t_string *l, t_tab *list)
{
	if (list->f && l->tab[POINT] == 0 && list->len == 1 && ft_atoi(list->f) == 0)
		list->len = 0;
	if (list->f && l->tab[POINT] >= 0 && list->len == 1 && ft_atoi(list->f) == 0 && list->c == 'p')
		list->len = 1;
}

void		precision_string(t_string *l, t_tab *list)
{
	char	*tmp;

	if (list->f && l->tab[POINT - 1] != -1 && l->tab[POINT] < list->len)
	{
		tmp = ft_strndup(list->f, l->tab[POINT]);
		list->f = tmp;
		list->len = l->tab[POINT];
	}
}

void	hashtag_p(t_string *l, t_tab *list)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_memalloc(2 + list->len + 1)))
		return ;
	if (list->c == 'p')
	{
		while (list->f[i] == ' ' && list->f[i])
				i++;
		if (i-- > -1 && ((l->tab[POINT] > l->tab[LARGEUR] && l->tab[LARGEUR] < list->len) || l->tab[POINT] == list->len) && ft_atoi(list->f) > 0)
		{
			tmp[1] = 'x';
			tmp[0] = '0';
			tmp = ft_memjoin(tmp, 2, list->f, list->len);
			free(list->f);
			list->f = tmp;
			list->len += 2;
			l->tab[HASHTAG - 1] = -1;
		}
	}
	if (l->tab[POINT] >= 0 && list->c == 'p')
		l->tab[POINT] += 2;
}

void		priority_flag_p(t_string *l, t_tab *list)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!(tmp = ft_memalloc(3)))
		return ;
	while (i++ <= list->len)
		if (i < list->len - 1 && list->f[i] == '0' && list->f[i + 1] == '0')
		{
			list->f[i + 1] = 'x';
			l->tab[HASHTAG - 1] = -1;
			return ;
		}
		else if (i < list->len - 1 && list->f[i] == '0' && list->f[i - 1] == ' ' && list->f[i - 2] == ' ')
		{
			list->f[i - 1] = 'x';
			list->f[i - 2] = '0';
			l->tab[HASHTAG - 1] = -1;
			return ;
		}
	tmp[0] = '0';
	tmp[1] = 'x';
	free(list->f);
	list->f = tmp;
	list->len += 2;
}

void		add_precision(t_string *l, t_tab *list)
{
	if (l->tab[HASHTAG - 1] == HASHTAG)
		hashtag_option_before(l, list, list->c);
	priority_flag(l, list);
//	printf("%d, %d, %d\n", l->tab[LARGEUR], l->tab[POINT], list->len);
	if (l->tab[HASHTAG - 1] == HASHTAG && list->c == 'p')
		hashtag_p(l, list);
	option(l, list);
//	printf("%d, %d, %d\n", l->tab[LARGEUR], l->tab[POINT], list->len);
	if (l->tab[HASHTAG - 1] == HASHTAG && list->c == 'p')
		priority_flag_p(l, list);
	if (l->tab[HASHTAG - 1] == HASHTAG)
		hashtag_option_after(l, list, list->c);
	ft_strcat(l->str + l->len, list->f);
	if (l->tab[LARGEUR] > list->len)
		l->len += l->tab[LARGEUR];
	else
		l->len += list->len;
}

void	priority_flag(t_string *l, t_tab *list)
{
	if ((l->tab[LEFT  - 1] == LEFT || (((l->tab[LARGEUR] > l->tab[POINT]
		&& l->tab[POINT] > list->len) || (l->tab[LARGEUR] > l->tab[POINT]
		&& l->tab[POINT] <= list->len && l->tab[POINT] != -1))))
		&& params(list->c, "s") == 0)
		l->tab[ZERO - 1] = -1;
	if (*list->f == '-')
	{
		l->tab[SIGN - 1] = SIGN;
		list->len--;
	}
	if (params(list->c, "s") && l->tab[POINT] > list->len)
		l->tab[POINT] = list->len;
	if (l->tab[LARGEUR] < list->len)
		l->tab[LARGEUR] = list->len;
	if (l->tab[POINT] > l->tab[LARGEUR] && params(list->c, "s") == 0)
		l->tab[LARGEUR] = l->tab[POINT];
	if (l->tab[POINT] < list->len)
		l->tab[POINT] = list->len;
	if (l->tab[LARGEUR] == list->len &&  l->tab[LEFT - 1] == LEFT
		&& (l->tab[SIGN - 1] == SIGN || l->tab[BLANK - 1] == BLANK))
		l->tab[LARGEUR] = list->len + 1;
	if ((l->tab[BLANK - 1] == BLANK && l->tab[ZERO - 1] == ZERO
		&& l->tab[LARGEUR] < list->len) || (l->tab[SIGN - 1] == SIGN
		|| *list->f == '-'))
		l->tab[BLANK - 1] = -1;
}

char		sign_of_tmp(t_string *l, t_tab *list)
{
	char	c;

	c = 0;
	if (*list->f == '-')
		c = '-';
	else if (l->tab[SIGN - 1] == SIGN)
		c = '+';
	l->tab[SIGN - 1] = -1;
	return (c);
}

int		conditionnal(t_string *l, int zero)
{
	if (l->tab[BLANK - 1] == BLANK)
	{
		l->tab[BLANK - 1] = -1;
		return (1);
	}
	if ((((l->tab[ZERO - 1] == ZERO && zero > 0)
		|| (l->tab[ZERO - 1] == -1 && zero <= 1))
		|| l->tab[LEFT - 1] == LEFT)
		&& l->tab[SIGN - 1] == SIGN)
		return (2);
	if (l->tab[ZERO - 1] == -1
		&& l->tab[SIGN - 1] == SIGN && l->tab[LEFT - 1] == -1)
		return (3);
	if (l->tab[ZERO - 1] == ZERO && l->tab[SIGN - 1] == -1)
		return (4);
	return (-1);
}

int 	set_option(t_string *l, t_tab *list, int zero, char *tmp)
{
	int index_of_tmp;

	index_of_tmp = 0;
	while (l->tab[BLANK - 1] == BLANK || l->tab[ZERO - 1] == ZERO
		|| l->tab[SIGN - 1] == SIGN)
	{
		if (conditionnal(l, zero) == 1)
		{
			ft_memset(tmp + index_of_tmp++, ' ', 1);
			zero--;
		}
		if (conditionnal(l, zero) == 2)
		{
			ft_memset(tmp + index_of_tmp++, sign_of_tmp(l, list), 1);
			zero--;
		}
		else if (conditionnal(l, zero) == 3 && zero-- > 0)
			ft_memset(tmp + index_of_tmp++, ' ', 1);
		else if (conditionnal(l, zero) == 4 && zero-- > 0)
			ft_memset(tmp + index_of_tmp++, '0', 1);
		if (zero <= 0)
			l->tab[ZERO - 1] = -1;
	}
	return (index_of_tmp);
}

char	*add_arg_to_option(t_tab *list, char *tmp, int index_of_tmp, t_string *l)
{
	char	*str;

	if (index_of_tmp >= 0 && list->len >= 0)
	{
		if (!(str = ft_memalloc(index_of_tmp + list->len + 1)))
			return (NULL);
		if (*list->f == '-')
			str = ft_memjoin(tmp, index_of_tmp, list->f + 1, list->len);
		else
			str = ft_memjoin(tmp, index_of_tmp, list->f, list->len);
		//free(tmp);
		return (str);
	}
	else
		return (NULL);
}

void		option(t_string *l, t_tab *list)
{
	char	*tmp;
	int		index_of_tmp;
	int		zero;
	int		plus;

	plus = (l->tab[SIGN - 1] == SIGN || l->tab[BLANK - 1] == BLANK) ? 1 : 0;
	zero = (l->tab[POINT] > list->len) ? l->tab[LARGEUR] - l->tab[POINT] : l->tab[LARGEUR] - list->len;
	if (!(tmp = ft_memalloc(l->tab[LARGEUR] + plus + 1)))
		return ;
	index_of_tmp = set_option(l, list, zero, tmp);
	if (index_of_tmp < (l->tab[LARGEUR] - l->tab[POINT] - plus) && l->tab[LEFT - 1] == -1)
	{
		ft_memset(tmp + index_of_tmp, ' ', l->tab[LARGEUR] - l->tab[POINT] - plus);
		index_of_tmp += l->tab[LARGEUR] - l->tab[POINT] - plus;
	}
	//printf("%d, %d\n", l->tab[LARGEUR], list->len);
	if (l->tab[POINT - 1] == POINT && l->tab[SIGN - 1] == -1 && list->len > 0)
	{
		ft_memset(tmp + index_of_tmp, '0', l->tab[POINT] - list->len);
		index_of_tmp += l->tab[POINT] - list->len;
	}
	else if ((l->tab[POINT] < list->len || l->tab[POINT] < l->tab[LARGEUR]) && l->tab[SIGN - 1] == -1)
	{
		ft_memset(tmp + index_of_tmp, ' ', l->tab[POINT] - list->len);
		index_of_tmp += l->tab[POINT] - list->len;
	}
	tmp = add_arg_to_option(list, tmp, index_of_tmp, l);
	index_of_tmp += list->len;
	if (l->tab[LEFT - 1] == LEFT && index_of_tmp < l->tab[LARGEUR])
	{
		ft_memset(tmp + index_of_tmp, ' ', l->tab[LARGEUR] - index_of_tmp);
		index_of_tmp += l->tab[LARGEUR] - index_of_tmp;
	}
	list->len = index_of_tmp;
	free(list->f);
	list->f = tmp;
}
