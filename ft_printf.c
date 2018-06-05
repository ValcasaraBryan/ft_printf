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
	int			ret;
	int			i;
	va_list		ap;
	char		*str;
	int			len_parm;

	va_start(ap, format);
	ret = 0;
	i = 0;
	while (format[ret] != '%')
	{
		if (format[ret] == '\0')
			return (ret);
		write(1, format + ret++, 1);
	}
	str = va_arg(ap, char *);
	while (str[i])
	{
		write(1, str + i++, 1);
	}
	len_parm = parsing((char *)format + ret);


	ret += len_parm;
	while (format[ret])
	{
		write(1, format + ret++, 1);
	}
	va_end(ap);
	return (ret + (int)ft_strlen(str) - len_parm);
}

int		parsing(char *arg)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] == '%')
			while (arg[i + j] && parms(arg[i + j]))
				j++;
		i++;
	}
	return (j);
}

int		parms(char comp)
{
	char	*list;
	int		i;

	i = 0;
	list = "sSpdDioOuUxXcC%#0-+ hljz";
	while (list[i])
	{
		if (list[i] == comp)
			return (1);
		i++;
	}
	return (0);
}

/*
** • Vous devez gérer les conversions suivantes : sSpdDioOuUxXcC
** • Vous devez gérer le %%
** • Vous devez gérer les flags #0-+ et espace
** • Vous devez gérer la taille minimum du champ
** • Vous devez gérer la précision
** • Vous devez gérer les flags hh h l ll j z
*/
/*
**	essaie pour 1 argument char *
*/








