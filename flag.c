/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 21:37:06 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/23 21:37:08 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_int(char *res, int i, int number)
{
	int		j;

	j = (int)ft_strlen(ft_itoa(number));
	if (i > j && i > 0)
	{
		i = i - j;
		add_caractere(res, i, 32);		// si il y a une precision, l'ajoute avec le caractere 32
	}
	ft_strcat(res, ft_itoa(number));
	return (res);
}

char	*flag_string(char *res, int i, char *string)
{
	int		j;

	j = (int)ft_strlen(string);
	if (i > j && i > 0)
	{
		i = i - j;
		add_caractere(res, i, 32);		// si il y a une precision, l'ajoute avec le caractere 32
	}
	ft_strcat(res, string);	// ajout de la conversion
	return (res);
}

char	*flag_char(char *res, int i, char caractere)
{
	if (i > 1)
		add_caractere(res, i - 1, 32);	// si il y a une precision, l'ajoute avec le caractere 32
	add_caractere(res, 1, caractere);
	return (res);
}
