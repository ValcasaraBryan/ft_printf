/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:32:38 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/05 17:32:40 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int		ret;
	int		i;
	va_list ap;
	va_start(ap, format);
	char *str;
	ret = 0;
	i = 1;
	while (format[ret] != '%')
	{
		if (format[ret] == '\0')
			return (ret);
		write(1, format + ret++, 1);
	}
	str = va_arg(ap, char *);
	ft_putstr(str);
	ret += 2;
	while(format[ret])
	{
		write(1, format + ret++, 1);
	}
	va_end(ap);

	return (ret + 3);
}
