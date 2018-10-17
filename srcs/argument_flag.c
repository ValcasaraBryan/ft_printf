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

char	add_sign(LIST)
{
	char c;

	if (SIGN_)
	{
		if (*DATA == '-')
			c = '-';
		else
			c = '+';
	}
	if (BLANK_)
		c = ' ';
	return (c);
}

int		add_precision(LIST)
{
	int len_write;
	int sign;

	sign = (SIGN_ || BLANK_) ? 1 : 0;
	len_write = 0;
	if (RIGHT_ && LARGEUR_ && ZERO_NO)
		len_write += ft_putchar_len(' ', TAB[LARGEUR] - sign, 1);
	if (SIGN_ || BLANK_)
		len_write += ft_putchar(add_sign(list));
	if (HASHTAG_ && params(ARG, "Oo"))
		len_write += ft_putstr_len("0", 1, 1);
	if (HASHTAG_ && params(ARG, "xp"))
		len_write += ft_putstr_len("0x", 2, 1);
	if (HASHTAG_ && params(ARG, "X"))
		len_write += ft_putstr_len("0X", 2, 1);
	if (RIGHT_ && LARGEUR_ && ZERO_)
		len_write += ft_putchar_len('0', TAB[LARGEUR] - sign, 1);
	if (POINT_ && params(ARG, "oOxXdiup"))
		len_write += ft_putchar_len('0', TAB[POINT], 1);
	len_write = (*DATA == '-') ? len_write + ft_putstr_len(DATA + 1, LEN, 1) :
		len_write + ft_putstr_len(DATA, LEN, 1);
	if (LEFT_ && LARGEUR_)
		len_write += ft_putchar_len(' ', TAB[LARGEUR] - sign, 1);
	return (len_write);
}
