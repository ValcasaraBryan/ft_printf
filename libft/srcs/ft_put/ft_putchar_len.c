/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/16 12:35:51 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/16 12:35:53 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int			ft_putchar_len(char c, int len, int fd)
{
	int		i;
	int		ret;

	i = -1;
	while (++i < len)
		if ((ret = write(fd, &c, 1)) == -1)
			return (ret);
	return (i);
}
