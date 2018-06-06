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
	void		*str;
	int			len_param;
	char		*param;
	char		*res;
	va_list		ap;

	va_start(ap, format);			// initialise ap a partir de format pour lire
									// chaque params suivant
	ret = -1;
	i = 0;
	while (format[++ret] != '%')	// detecte s'il y a un flags
		if (!format[ret])			// sinon affiche toute la string
		{
			ft_putstr(format);
			return (ret);
		}
	
	len_param = parsing_params((char *)format + ret++); // recupere la longueur des flags
	param = ft_strndup(format + ret, len_param);		// recupere les flags
	len_param += ret;							// met len_param a la longueur debut_format
												//  + len_flag
	if (!(str = ft_memalloc(100)))
		return (0);
	str = return_list(param[0], ap);
	
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

// c, C, s, S,p, d, D, i, o, O, u, U,x X 

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
