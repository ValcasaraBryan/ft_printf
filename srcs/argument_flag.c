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

int						change_string(t_string *list)
{
	if (binary_flag(TAB, LENGHT_TAB))
	{
		priority_precision_largeur_sign_hashtag(list);
		priority_precision_largeur(list);
		return (add_precision(list));
	}
	else
	{
		LEN = (params(ARG, "dip") && *DATA == '0') ? 0 : LEN;
		return (ft_putstr_len(DATA, LEN, FD));
	}
}

void					priority_precision_largeur_sign_hashtag(t_string *list)
{
	if (SIGN_ && *DATA == '-')
		LEN--;
	if (HASHTAG_)
	{
		TAB[POINT] = (params(ARG, "oO") && POINT_) ? TAB[POINT] - 1 :
			TAB[POINT];
		TAB[LARGEUR] = (params(ARG, "oO") && LARGEUR_) ? TAB[LARGEUR] - 1 :
			TAB[LARGEUR];
		TAB[HASHTAG - 1] = (params(ARG, "oO") && LARGEUR_NO && POINT_NO
			&& *DATA == '0') ? 0 : TAB[HASHTAG - 1];
		TAB[HASHTAG - 1] = (params(ARG, "Xx") && *DATA == '0') ? 0 :
			TAB[HASHTAG - 1];
	}
	if (POINT_)
	{
		LEN = (params(ARG, "oOXxdiuUp") && *DATA == '0') ? 0 : LEN;
		LEN = ((LEN > TAB[POINT]) && params(ARG, "sS")) ? TAB[POINT] :
			LEN;
		TAB[POINT] = ((LEN < TAB[POINT]) && params(ARG, "sS")) ? LEN :
			TAB[POINT];
		TAB[POINT] = ((LEN > TAB[POINT])) ? LEN : TAB[POINT];
	}
	if (HASHTAG_)
		TAB[LARGEUR] = ((params(ARG, "oO") == 0) && LARGEUR_ &&
			(TAB[LARGEUR] + 2) > LEN) ? TAB[LARGEUR] - 2 : TAB[LARGEUR];
}

void					priority_precision_largeur(t_string *list)
{
	if (LARGEUR_ && POINT_NO)
		TAB[LARGEUR] = (TAB[LARGEUR] > LEN) ? TAB[LARGEUR] - LEN : 0;
	else if (LARGEUR_ && POINT_)
	{
		TAB[LARGEUR] = (TAB[LARGEUR] > TAB[POINT]) ? TAB[LARGEUR]
			- TAB[POINT] : 0;
		TAB[POINT] = (LEN < TAB[POINT]) ? TAB[POINT] - LEN : 0;
	}
	else if (LARGEUR_NO && POINT_)
		TAB[POINT] = (LEN < TAB[POINT]) ? TAB[POINT] - LEN : 0;
}

int						add_precision(t_string *list)
{
	int					len_write;
	int					sign;

	sign = (SIGN_ || BLANK_) ? 1 : 0;
	len_write = 0;
	if (RIGHT_ && LARGEUR_ && ZERO_NO)
		len_write += ft_putchar_len(' ', TAB[LARGEUR] - sign, FD);
	len_write += ft_putchar_len(add_sign(list), sign, FD);
	if (HASHTAG_ && params(ARG, "oO"))
		len_write += ft_putstr_len("0", 1, FD);
	if (HASHTAG_ && params(ARG, "xp"))
		len_write += ft_putstr_len("0x", 2, FD);
	if (HASHTAG_ && params(ARG, "X"))
		len_write += ft_putstr_len("0X", 2, FD);
	if (RIGHT_ && LARGEUR_ && ZERO_)
		len_write += ft_putchar_len('0', TAB[LARGEUR] - sign, FD);
	if (POINT_ && params(ARG, "oOxXdiuUp"))
		len_write += ft_putchar_len('0', TAB[POINT], FD);
	len_write = (*DATA == '-') ? len_write + ft_putstr_len(DATA + 1, LEN, FD) :
		len_write + ft_putstr_len(DATA, LEN, FD);
	if (LEFT_ && LARGEUR_)
		len_write += ft_putchar_len(' ', TAB[LARGEUR] - sign, FD);
	return (len_write);
}

char					add_sign(t_string *list)
{
	char				c;

	if (SIGN_)
	{
		if (*DATA == '-')
			c = '-';
		else
			c = '+';
	}
	else if (BLANK_)
		c = ' ';
	return (c);
}
