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

	if (!(tmp = ft_memalloc(2 + LEN + 1)))
		return ;
	if ((c == 'x' || c == 'X') && ((TAB[LARGEUR] == -1
		|| TAB[LEFT - 1] == LEFT) && TAB[POINT - 1] == -1) && ft_atoi(DATA) > 0)
	{
		tmp[0] = '0';
		tmp[1] = c;
		tmp = ft_memjoin(tmp, 2, DATA, LEN);
		LEN += 2;
		free(DATA);
		DATA = tmp;
		TAB[HASHTAG - 1] = -1;
	}
	else if (c == 'o' && ft_atoi(DATA) > 0)
	{
		tmp[0] = '0';
		tmp = ft_memjoin(tmp, 1, DATA, LEN);
		free(DATA);
		DATA = tmp;
		LEN += 1;
	}
}
void	hashtag_option_after(t_string *list, char c)
{
	int		i;

	i = 0;
	if ((c == 'x' || c == 'X') && TAB[LARGEUR] == LEN && TAB[POINT - 1] == -1)
	{
		while (DATA[i] == ' ' && DATA[i])
			i++;
		if (DATA[i - 2] == ' ' && DATA[i - 1] == ' ')
		{
			DATA[i - 2] = '0';
			DATA[i - 1] = c;
		}
		else
			DATA[1] = c;
		TAB[HASHTAG - 1] = -1;
	}
	else if (c == 'o' && LEN == 0)
	{
		DATA[0] = '0';
		LEN = 1;
		TAB[HASHTAG - 1] = -1;
	}
}

void	precision(t_string *list)
{
	if (DATA && TAB[POINT] == 0 && LEN == 1 && ft_atoi(DATA) == 0)
		LEN = 0;
	if (DATA && TAB[POINT] >= 0 && LEN == 1 && ft_atoi(DATA) == 0 && ARG == 'p')
		LEN = 1;
}

void		precision_string(t_string *list)
{
	char	*tmp;

	if (DATA && TAB[POINT - 1] != -1 && TAB[POINT] < LEN)
	{
		tmp = ft_strndup(DATA, TAB[POINT]);
		DATA = tmp;
		LEN = TAB[POINT];
	}
}

void	hashtag_p(t_string *list)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_memalloc(2 + LEN + 1)))
		return ;
	if (ARG == 'p')
	{
		while (DATA[i] == ' ' && DATA[i])
				i++;
		if (i-- > -1 && ((TAB[POINT] > TAB[LARGEUR] && TAB[LARGEUR] < LEN) || TAB[POINT] == LEN) && ft_atoi(DATA) > 0)
		{
			tmp[1] = 'x';
			tmp[0] = '0';
			tmp = ft_memjoin(tmp, 2, DATA, LEN);
			free(DATA);
			DATA = tmp;
			LEN += 2;
			TAB[HASHTAG - 1] = -1;
		}
	}
	if (TAB[POINT] >= 0 && ARG == 'p')
		TAB[POINT] += 2;
}

void		priority_flag_p(t_string *list)
{
	int		i;
	char	*tmp;

	i = -1;
	if (!(tmp = ft_memalloc(3)))
		return ;
	while (i++ <= LEN)
		if (i < LEN - 1 && DATA[i] == '0' && DATA[i + 1] == '0')
		{
			DATA[i + 1] = 'x';
			TAB[HASHTAG - 1] = -1;
			return ;
		}
		else if (i < LEN - 1 && DATA[i] == '0' && DATA[i - 1] == ' ' && DATA[i - 2] == ' ')
		{
			DATA[i - 1] = 'x';
			DATA[i - 2] = '0';
			TAB[HASHTAG - 1] = -1;
			return ;
		}
	tmp[0] = '0';
	tmp[1] = 'x';
	free(DATA);
	DATA = tmp;
	LEN += 2;
}

void		add_precision(t_string *list)
{
	if (TAB[HASHTAG - 1] == HASHTAG)
		hashtag_option_before(list, ARG);
	priority_flag(list);
	if (TAB[HASHTAG - 1] == HASHTAG && ARG == 'p')
		hashtag_p(list);
	option(list);
	if (TAB[HASHTAG - 1] == HASHTAG && ARG == 'p')
		priority_flag_p(list);
	if (TAB[HASHTAG - 1] == HASHTAG)
		hashtag_option_after(list, ARG);
	if (TAB[LARGEUR] > LEN)
		LEN += TAB[LARGEUR];
}

void	priority_flag(t_string *list)
{
	if ((TAB[LEFT  - 1] == LEFT || (((TAB[LARGEUR] > TAB[POINT]
		&& TAB[POINT] > LEN) || (TAB[LARGEUR] > TAB[POINT]
		&& TAB[POINT] <= LEN && TAB[POINT] != -1))))
		&& params(ARG, "s") == 0)
		TAB[ZERO - 1] = -1;
	if (*DATA == '-')
	{
		TAB[SIGN - 1] = SIGN;
		LEN--;
	}
	if (params(ARG, "s") && TAB[POINT] > LEN)
		TAB[POINT] = LEN;
	if (TAB[LARGEUR] < LEN)
		TAB[LARGEUR] = LEN;
	if (TAB[POINT] > TAB[LARGEUR] && params(ARG, "s") == 0)
		TAB[LARGEUR] = TAB[POINT];
	if (TAB[POINT] < LEN)
		TAB[POINT] = LEN;
	if (TAB[LARGEUR] == LEN &&  TAB[LEFT - 1] == LEFT
		&& (TAB[SIGN - 1] == SIGN || TAB[BLANK - 1] == BLANK))
		TAB[LARGEUR] = LEN + 1;
	if ((TAB[BLANK - 1] == BLANK && TAB[ZERO - 1] == ZERO
		&& TAB[LARGEUR] < LEN) || (TAB[SIGN - 1] == SIGN
		|| *DATA == '-'))
		TAB[BLANK - 1] = -1;
}

char		sign_of_tmp(t_string *list)
{
	char	c;

	c = 0;
	if (*DATA == '-')
		c = '-';
	else if (TAB[SIGN - 1] == SIGN)
		c = '+';
	TAB[SIGN - 1] = -1;
	return (c);
}

int		conditionnal(t_string *list, int zero)
{
	if (TAB[BLANK - 1] == BLANK)
	{
		TAB[BLANK - 1] = -1;
		return (1);
	}
	if ((((TAB[ZERO - 1] == ZERO && zero > 0)
		|| (TAB[ZERO - 1] == -1 && zero <= 1))
		|| TAB[LEFT - 1] == LEFT)
		&& TAB[SIGN - 1] == SIGN)
		return (2);
	if (TAB[ZERO - 1] == -1
		&& TAB[SIGN - 1] == SIGN && TAB[LEFT - 1] == -1)
		return (3);
	if (TAB[ZERO - 1] == ZERO && TAB[SIGN - 1] == -1)
		return (4);
	return (-1);
}

int 	set_option(t_string *list, int zero, char *tmp)
{
	int index_of_tmp;

	index_of_tmp = 0;
	while (TAB[BLANK - 1] == BLANK || TAB[ZERO - 1] == ZERO
		|| TAB[SIGN - 1] == SIGN)
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
			TAB[ZERO - 1] = -1;
	}
	return (index_of_tmp);
}

char	*add_arg_to_option(char *tmp, int index_of_tmp, t_string *list)
{
	char	*str;

	if (index_of_tmp >= 0 && LEN >= 0)
	{
		if (!(str = ft_memalloc(index_of_tmp + LEN + 1)))
			return (NULL);
		if (*DATA == '-')
			str = ft_memjoin(tmp, index_of_tmp, DATA + 1, LEN);
		else
			str = ft_memjoin(tmp, index_of_tmp, DATA, LEN);
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

	plus = (TAB[SIGN - 1] == SIGN || TAB[BLANK - 1] == BLANK) ? 1 : 0;
	zero = (TAB[POINT] > LEN) ? TAB[LARGEUR] - TAB[POINT] : TAB[LARGEUR] - LEN;
	if (!(tmp = ft_memalloc(TAB[LARGEUR] + plus + 1)))
		return ;
	index_of_tmp = set_option(list, zero, tmp);
	if (index_of_tmp < (TAB[LARGEUR] - TAB[POINT] - plus) && TAB[LEFT - 1] == -1)
	{
		ft_memset(tmp + index_of_tmp, ' ', TAB[LARGEUR] - TAB[POINT] - plus);
		index_of_tmp += TAB[LARGEUR] - TAB[POINT] - plus;
	}
	if (TAB[POINT - 1] == POINT && TAB[SIGN - 1] == -1 && LEN > 0)
	{
		ft_memset(tmp + index_of_tmp, '0', TAB[POINT] - LEN);
		index_of_tmp += TAB[POINT] - LEN;
	}
	else if ((TAB[POINT] < LEN || TAB[POINT] < TAB[LARGEUR]) && TAB[SIGN - 1] == -1)
	{
		ft_memset(tmp + index_of_tmp, ' ', TAB[POINT] - LEN);
		index_of_tmp += TAB[POINT] - LEN;
	}
	tmp = add_arg_to_option(tmp, index_of_tmp, list);
	index_of_tmp += LEN;
	if (TAB[LEFT - 1] == LEFT && index_of_tmp < TAB[LARGEUR])
	{
		ft_memset(tmp + index_of_tmp, ' ', TAB[LARGEUR] - index_of_tmp);
		index_of_tmp += TAB[LARGEUR] - index_of_tmp;
	}
	LEN = index_of_tmp;
	free(DATA);
	DATA = tmp;
}
