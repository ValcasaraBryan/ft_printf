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
	long	mask;
	long	mask_byte;

	if (!(mask = ft_set_octet(octet)))
		return (0);
	if (!(mask_byte = ft_set_unichar(mask, len + 1, *str)))
		return (0);
	if (!(tab = ft_putval_tab(mask_byte, octet)))
		return (0);
	return (tab);
}

char		*ft_unicode_to_str(wchar_t *str)
{
	char	*data;
	char	*tmp;
	int		len;
	int		octet;
	int		*tab;

	if (!str)
		return (NULL);
	data = ft_strdup("");
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
			*tmp = *str;
		free(tab);
		data = (data) ? ft_strjoin_free(data, tmp, 3) : tmp;
		str++;
	}
	return (data);
}
