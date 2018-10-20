/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_to_str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:32:49 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/19 18:32:50 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	*tab_unix(int octet, int len, wchar_t *str)
{
	int		*tab;

	tab = ft_putval_tab(ft_set_unichar(ft_set_octet(octet), len + 1, *str),
		octet);
	return (tab);
}

char		*ft_unicode_to_str(wchar_t *str)
{
	char	*data;
	char	*tmp;
	int		len;
	int		octet;
	int		*tab;

	data = NULL;
	if (str)
		while (*str)
		{
			len = ft_wchar_len(*str);
			octet = ft_wset_plage_byte(len);
			tmp = ft_strnew(octet);
			tab = tab_unix(octet, len, str);
			if (octet > 1)
				while (octet-- > 0)
					*(tmp + octet) = *(tab + octet);
			else
				*tmp = *tab;
			free(tab);
			data = (data) ? ft_strjoin_free(data, tmp, 3) : tmp;
			str++;
		}
	return (data);
}
