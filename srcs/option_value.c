/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 16:16:57 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/18 16:16:58 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char					*flag_int_sign(t_string list, va_list ap)
{
	t_conv				flag[6];
	int					i;
	int					j;

	i = -1;
	flag[0].tab = list.tab[INT_LONG_LONG - 1];
	flag[0].fonction = &conv_long_long;
	flag[1].tab = list.tab[INT_LONG - 1];
	flag[1].fonction = &conv_long;
	flag[2].tab = list.tab[Z_FLAG - 1];
	flag[2].fonction = &conv_ssize_t;
	flag[3].tab = list.tab[J_FLAG - 1];
	flag[3].fonction = &conv_intmax;
	flag[4].tab = list.tab[INT_SHORT_SHORT - 1];
	flag[4].fonction = &conv_char;
	flag[5].tab = list.tab[INT_SHORT - 1];
	flag[5].fonction = &conv_short;
	while (++i < 6)
	{
		j = -1;
		while (++j < LENGHT_TAB - 1)
			if (flag[i].tab == list.tab[j] && list.tab[j] > 0)
				return (flag[i].fonction(ap));
	}
	return (conv_int(ap));
}

char					*flag_int_unsigned(t_string list, va_list ap,
						char *hexa)
{
	t_conv_base			flag[6];
	int					i;
	int					j;

	i = -1;
	flag[0].tab = list.tab[INT_LONG_LONG - 1];
	flag[0].fonction = &conv_ulong_long;
	flag[1].tab = list.tab[INT_LONG - 1];
	flag[1].fonction = &conv_ulong;
	flag[2].tab = list.tab[Z_FLAG - 1];
	flag[2].fonction = &conv_size_t;
	flag[3].tab = list.tab[J_FLAG - 1];
	flag[3].fonction = &conv_uintmax;
	flag[4].tab = list.tab[INT_SHORT_SHORT - 1];
	flag[4].fonction = &conv_uchar;
	flag[5].tab = list.tab[INT_SHORT - 1];
	flag[5].fonction = &conv_ushort;
	while (++i < 6)
	{
		j = -1;
		while (++j < LENGHT_TAB - 1)
			if (flag[i].tab == list.tab[j] && list.tab[j] > 0)
				return (flag[i].fonction(ap, hexa));
	}
	return (conv_uint(ap, hexa));
}

void					unsigned_value(va_list ap, char c, t_string *list)
{
	char				*hexa;

	hexa = NULL;
	if (c == 'u')
		hexa = DECIMAL;
	else if (c == 'o')
		hexa = OCTAL;
	else if (c == 'x')
		hexa = HEXA_MIN;
	else if (c == 'X')
		hexa = HEXA_MAJ;
	else if (c == 'p')
	{
		list->tab[HASHTAG - 1] = HASHTAG;
		list_add_conversion(conv_void(ap, HEXA_MIN), list);
		return ;
	}
	list_add_conversion(flag_int_unsigned(*list, ap, hexa), list);
}

int						option_char(t_string *list, char c)
{
	int					i;

	i = 0;
	if (list->tab[LEFT - 1] == LEFT)
	{
		i += ft_putchar(c);
		if (list->tab[LARGEUR] > 0 && list->tab[ZERO - 1] == ZERO)
			i += ft_putchar_len('0', list->tab[LARGEUR] - 1, list->fd);
		else if (list->tab[LARGEUR] > 0 && list->tab[ZERO - 1] == 0)
			i += ft_putchar_len(' ', list->tab[LARGEUR] - 1, list->fd);
	}
	else if (list->tab[LEFT - 1] == 0)
	{
		if (list->tab[LARGEUR] > 0 && list->tab[ZERO - 1] == ZERO)
			i += ft_putchar_len('0', list->tab[LARGEUR] - 1, list->fd);
		else if (list->tab[LARGEUR] > 0 && list->tab[ZERO - 1] == 0)
			i += ft_putchar_len(' ', list->tab[LARGEUR] - 1, list->fd);
		i += ft_putchar(c);
	}
	return (i);
}

void					reset_tab_int(t_string *list, int len)
{
	int					i;

	i = -1;
	while (++i < len)
		list->tab[i] = 0;
}
