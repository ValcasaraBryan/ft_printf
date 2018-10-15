/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/15 17:50:24 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/15 17:50:25 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int					ft_putwchar(int *tab, int len)
{
	int				i;
	int				ret;
	char			c;

	i = -1;
	ret = 0;
	while (++i < len)
	{
		c = tab[i];
		if (write(1, &c, 1) == -1)
			return (-1);
		ret++;
	}
	return (ret);
}
