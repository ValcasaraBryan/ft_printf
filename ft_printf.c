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
	char		*str;
	int			len_param;
	char		*param;
	char		*res;
	va_list		ap;

	va_start(ap, format);			// initialise ap a partir de format pour lire
									// chaque params suivant
	ret = -1;
	i = 0;
	while (format[++ret] != '%')	// detecte s'il y a un flags
	{								// sinon affiche toute la string
		if (!format[ret])
		{
			ft_putstr(format);
			return (ret);
		}
	}
	str = va_arg(ap, char *); 					// recupere la string de l'arg ...
	len_param = parsing_params((char *)format + ret++); // recupere la longueur des flags
	param = ft_strndup(format + ret, len_param);		// recupere les flags
	len_param += ret;							// met len_param a la longueur debut_format
												//  + len_flag
	res = ft_memalloc(ret + ft_strlen(str) + ft_strlen(format + len_param));
									// malloc la longueur total
									// de la nouvelle chaine
	res = ft_strncpy(res, format, ret - 1); 	// ajout le debut de format avant '%' a res
	res = ft_strcat(res, str);					// ajout la conversion
	res = ft_strcat(res, format + len_param); 	// ajout la fin de format apres les flags
	ft_putstr(res);					// affiche la nouvelle string avec conversion
	va_end(ap);						// reset ap à start
	return (ft_strlen(res));		// renvoi la longueur de la nouvelle string
}

int		parsing_params(char *arg) 	// seulement la conversion
{									// c, C, s, S,p, d, D, i, o, O, u, U,x X 
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (arg[++i])
		if (arg[i] == '%')
			while (arg[i + (++j)])
				if (params(arg[i + j]) > 0)
					return (j);
	return (0);
}

int		params(char comp) 	// detecte si un paramettre est 
{							// rencontre et renvoi sa position
	char	*list;			// par rapport a la string list
	int		i;

	i = 0;
	list = "sSpdDioOuUxXcC%";
	while (list[i])
	{
		if (list[i] == comp)
			return (i + 1);
		i++;
	}
	return (0);
}


//char *string()
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
