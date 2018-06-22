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
	int			j;
	t_tab		*list;
	int			len_param;
	char		*param;
	char		*res;
	va_list		ap;

	va_start(ap, format);			// initialise ap a partir de format pour lire
									// chaque params suivant
	ret = -1;
	i = 0;
	j = 0;
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
	if (ft_strlen(param) == 1)
		list = return_list(*param, ap);
	else if ((i = precision_params(param)) >= 0)// donne à i la longueur de precision
	{
		j = ft_strlen(ft_itoa(i));
		list = return_list(param[j], ap);		// initialise le parametre arg[2]
	}
	if (!(res = ft_memalloc(BUFF_SIZE)))		// alloue la longueur de la string final
		return (0);
	res = ft_strncpy(res, format, ret - 1); 	// ajout le debut de format avant '%' a res
	if (list->c == 's')							// ajout de l'arg[2] a la string final
	{
		j = (int)ft_strlen((char *)list->f);
		if (i > j && i > 0)
		{
			i = i - j;							// fait la difference entre la longueur de la
												// string et la longueur de la precision
			add_caractere(res, ret, i, 32);		// si il y a une precision, l'ajoute avec le caractere 32
		}
		res = ft_strcat(res, (char *)list->f);	// ajout de la conversion
	}
	if (list->c == 'c')							// ajout de l'arg[2] a la string final
	{
		if (i > 1)
			add_caractere(res, ret, i - 1, 32);	// si il y a une precision, l'ajoute avec le caractere 32
		add_caractere(res, ret + i, 1, (int)list->f); // ajout de la conversion
	}
	if (list->c == 'd')
	{
		j = ft_strlen(ft_itoa((int)list->f));
		if (i > j && i > 0)
		{
			i = i - j;
			add_caractere(res, ret, i, 32);		// si il y a une precision, l'ajoute avec le caractere 32
		}
		ft_strcat(res, ft_itoa((int)list->f));
	}
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
