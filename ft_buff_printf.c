/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buff_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/09 19:27:46 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/09 19:27:50 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../GNL/get_next_line.h"

int		ft_buff_printf(char **str, int fd, const char *format, ...)
{
	int ret;
	char *buf;

	if (!*str)
		*str = ft_strdup("");
	while ((ret = get_next_line(fd, &buf)))
	{
		ret = ft_strlen(buf);
		buf[ft_strlen(buf)] = '\n';
		buf[ret + 1] = '\0';
		ft_strcat(*str, buf);
	}
	return (ret);
}
