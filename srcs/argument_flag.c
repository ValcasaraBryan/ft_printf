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


void	hashtag_option_before(t_string *list, char c)
{
	char	*tmp;

	if (!(tmp = ft_memalloc(2 + list->len + 1)))
		return ;
	if ((c == 'x' || c == 'X') && ((list->tab[LARGEUR] == -1
		|| list->tab[LEFT - 1] == LEFT) && list->tab[POINT - 1] == -1) && ft_atoi(list->data) > 0)
	{
		tmp[0] = '0';
		tmp[1] = c;
		tmp = ft_memjoin(tmp, 2, list->data, list->len);
		list->len += 2;
		free(list->data);
		list->data = tmp;
		list->tab[HASHTAG - 1] = -1;
	}
	else if (c == 'o' && ft_atoi(list->data) > 0)
	{
		tmp[0] = '0';
		tmp = ft_memjoin(tmp, 1, list->data, list->len);
		free(list->data);
		list->data = tmp;
		list->len += 1;
	}
}
void	hashtag_option_after(t_string *list, char c)
{
	int		i;

	i = 0;
	if ((c == 'x' || c == 'X') && list->tab[LARGEUR] == list->len && list->tab[POINT - 1] == -1)
	{
		while (list->data[i] == ' ' && list->data[i])
			i++;
		if (list->data[i - 2] == ' ' && list->data[i - 1] == ' ')
		{
			list->data[i - 2] = '0';
			list->data[i - 1] = c;
		}
		else
			list->data[1] = c;
		list->tab[HASHTAG - 1] = -1;
	}
	else if (c == 'o' && list->len == 0)
	{
		list->data[0] = '0';
		list->len = 1;
		list->tab[HASHTAG - 1] = -1;
	}
}

void	precision(t_string *list)
{
	if (list->data && list->tab[POINT] == 0 && list->len == 1 && ft_atoi(list->data) == 0)
		list->len = 0;
	if (list->data && list->tab[POINT] >= 0 && list->len == 1 && ft_atoi(list->data) == 0 && list->char_of_arg == 'p')
		list->len = 1;
}

void		precision_string(t_string *list)
{
	char	*tmp;

	if (list->data && list->tab[POINT - 1] != -1 && list->tab[POINT] < list->len)
	{
		tmp = ft_strndup(list->data, list->tab[POINT]);
		list->data = tmp;
		list->len = list->tab[POINT];
	}
}

void	hashtag_p(t_string *list)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_memalloc(2 + list->len + 1)))
		return ;
	if (list->char_of_arg == 'p')
	{
		while (list->data[i] == ' ' && list->data[i])
				i++;
		if (i-- > -1 && ((list->tab[POINT] > list->tab[LARGEUR] && list->tab[LARGEUR] < list->len) || list->tab[POINT] == list->len) && ft_atoi(list->data) > 0)
		{
			tmp[1] = 'x';
			tmp[0] = '0';
			tmp = ft_memjoin(tmp, 2, list->data, list->len);
			free(list->data);
			list->data = tmp;
			list->len += 2;
			list->tab[HASHTAG - 1] = -1;
		}
	}
	if (list->tab[POINT] >= 0 && list->char_of_arg == 'p')
		list->tab[POINT] += 2;
}

void		priority_flag_p(t_string *list)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!(tmp = ft_memalloc(3)))
		return ;
	while (i++ <= list->len)
		if (i < list->len - 1 && list->data[i] == '0' && list->data[i + 1] == '0')
		{
			list->data[i + 1] = 'x';
			list->tab[HASHTAG - 1] = -1;
			return ;
		}
		else if (i < list->len - 1 && list->data[i] == '0' && list->data[i - 1] == ' ' && list->data[i - 2] == ' ')
		{
			list->data[i - 1] = 'x';
			list->data[i - 2] = '0';
			list->tab[HASHTAG - 1] = -1;
			return ;
		}
	tmp[0] = '0';
	tmp[1] = 'x';
	free(list->data);
	list->data = tmp;
	list->len += 2;
}

void		add_precision(t_string *list)
{
	if (list->tab[HASHTAG - 1] == HASHTAG)
		hashtag_option_before(list, list->char_of_arg);
	priority_flag(list);
	if (list->tab[HASHTAG - 1] == HASHTAG && list->char_of_arg == 'p')
		hashtag_p(list);
	option(list);
	if (list->tab[HASHTAG - 1] == HASHTAG && list->char_of_arg == 'p')
		priority_flag_p(list);
	if (list->tab[HASHTAG - 1] == HASHTAG)
		hashtag_option_after(list, list->char_of_arg);
	if (list->tab[LARGEUR] > list->len)
		list->len += list->tab[LARGEUR];
}

void	priority_flag(t_string *list)
{
	if ((list->tab[LEFT  - 1] == LEFT || (((list->tab[LARGEUR] > list->tab[POINT]
		&& list->tab[POINT] > list->len) || (list->tab[LARGEUR] > list->tab[POINT]
		&& list->tab[POINT] <= list->len && list->tab[POINT] != -1))))
		&& params(list->char_of_arg, "s") == 0)
		list->tab[ZERO - 1] = -1;
	if (*list->data == '-')
	{
		list->tab[SIGN - 1] = SIGN;
		list->len--;
	}
	if (params(list->char_of_arg, "s") && list->tab[POINT] > list->len)
		list->tab[POINT] = list->len;
	if (list->tab[LARGEUR] < list->len)
		list->tab[LARGEUR] = list->len;
	if (list->tab[POINT] > list->tab[LARGEUR] && params(list->char_of_arg, "s") == 0)
		list->tab[LARGEUR] = list->tab[POINT];
	if (list->tab[POINT] < list->len)
		list->tab[POINT] = list->len;
	if (list->tab[LARGEUR] == list->len &&  list->tab[LEFT - 1] == LEFT
		&& (list->tab[SIGN - 1] == SIGN || list->tab[BLANK - 1] == BLANK))
		list->tab[LARGEUR] = list->len + 1;
	if ((list->tab[BLANK - 1] == BLANK && list->tab[ZERO - 1] == ZERO
		&& list->tab[LARGEUR] < list->len) || (list->tab[SIGN - 1] == SIGN
		|| *list->data == '-'))
		list->tab[BLANK - 1] = -1;
}

char		sign_of_tmp(t_string *list)
{
	char	c;

	c = 0;
	if (*list->data == '-')
		c = '-';
	else if (list->tab[SIGN - 1] == SIGN)
		c = '+';
	list->tab[SIGN - 1] = -1;
	return (c);
}

int		conditionnal(t_string *list, int zero)
{
	if (list->tab[BLANK - 1] == BLANK)
	{
		list->tab[BLANK - 1] = -1;
		return (1);
	}
	if ((((list->tab[ZERO - 1] == ZERO && zero > 0)
		|| (list->tab[ZERO - 1] == -1 && zero <= 1))
		|| list->tab[LEFT - 1] == LEFT)
		&& list->tab[SIGN - 1] == SIGN)
		return (2);
	if (list->tab[ZERO - 1] == -1
		&& list->tab[SIGN - 1] == SIGN && list->tab[LEFT - 1] == -1)
		return (3);
	if (list->tab[ZERO - 1] == ZERO && list->tab[SIGN - 1] == -1)
		return (4);
	return (-1);
}

int 	set_option(t_string *list, int zero, char *tmp)
{
	int index_of_tmp;

	index_of_tmp = 0;
	while (list->tab[BLANK - 1] == BLANK || list->tab[ZERO - 1] == ZERO
		|| list->tab[SIGN - 1] == SIGN)
	{
		if (conditionnal(list, zero) == 1)
		{
			ft_memset(tmp + index_of_tmp++, ' ', 1);
			zero--;
		}
		if (conditionnal(list, zero) == 2)
		{
			ft_memset(tmp + index_of_tmp++, sign_of_tmp(list), 1);
			zero--;
		}
		else if (conditionnal(list, zero) == 3 && zero-- > 0)
			ft_memset(tmp + index_of_tmp++, ' ', 1);
		else if (conditionnal(list, zero) == 4 && zero-- > 0)
			ft_memset(tmp + index_of_tmp++, '0', 1);
		if (zero <= 0)
			list->tab[ZERO - 1] = -1;
	}
	return (index_of_tmp);
}

char	*add_arg_to_option(char *tmp, int index_of_tmp, t_string *list)
{
	char	*str;

	if (index_of_tmp >= 0 && list->len >= 0)
	{
		if (!(str = ft_memalloc(index_of_tmp + list->len + 1)))
			return (NULL);
		if (*list->data == '-')
			str = ft_memjoin(tmp, index_of_tmp, list->data + 1, list->len);
		else
			str = ft_memjoin(tmp, index_of_tmp, list->data, list->len);
		//free(tmp);
		return (str);
	}
	else
		return (NULL);
}

void		option(t_string *list)
{
	char	*tmp;
	int		index_of_tmp;
	int		zero;
	int		plus;

	plus = (list->tab[SIGN - 1] == SIGN || list->tab[BLANK - 1] == BLANK) ? 1 : 0;
	zero = (list->tab[POINT] > list->len) ? list->tab[LARGEUR] - list->tab[POINT] : list->tab[LARGEUR] - list->len;
	if (!(tmp = ft_memalloc(list->tab[LARGEUR] + plus + 1)))
		return ;
	index_of_tmp = set_option(list, zero, tmp);
	if (index_of_tmp < (list->tab[LARGEUR] - list->tab[POINT] - plus) && list->tab[LEFT - 1] == -1)
	{
		ft_memset(tmp + index_of_tmp, ' ', list->tab[LARGEUR] - list->tab[POINT] - plus);
		index_of_tmp += list->tab[LARGEUR] - list->tab[POINT] - plus;
	}
	if (list->tab[POINT - 1] == POINT && list->tab[SIGN - 1] == -1 && list->len > 0)
	{
		ft_memset(tmp + index_of_tmp, '0', list->tab[POINT] - list->len);
		index_of_tmp += list->tab[POINT] - list->len;
	}
	else if ((list->tab[POINT] < list->len || list->tab[POINT] < list->tab[LARGEUR]) && list->tab[SIGN - 1] == -1)
	{
		ft_memset(tmp + index_of_tmp, ' ', list->tab[POINT] - list->len);
		index_of_tmp += list->tab[POINT] - list->len;
	}
	tmp = add_arg_to_option(tmp, index_of_tmp, list);
	index_of_tmp += list->len;
	if (list->tab[LEFT - 1] == LEFT && index_of_tmp < list->tab[LARGEUR])
	{
		ft_memset(tmp + index_of_tmp, ' ', list->tab[LARGEUR] - index_of_tmp);
		index_of_tmp += list->tab[LARGEUR] - index_of_tmp;
	}
	list->len = index_of_tmp;
	free(list->data);
	list->data = tmp;
}
