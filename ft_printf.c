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
	int			*z;
	t_tab		*list;
	int			len_param;
	char		*param;
	char		*res;
	va_list		ap;
	unsigned int	nb;
	int				test;
	va_start(ap, format);			// initialise ap a partir de format pour lire
									// chaque params suivant
	ret = -1;
	i = 0;
	j = 0;
	test = 1;
	nb = (unsigned int)nb_percent((char *)format);
	if (nb == 0)
	{
		ft_putstr(format);
		return (ft_strlen((char *)format));
	}
	if (!(res = ft_memalloc(BUFF_SIZE)))		// alloue la longueur de la string final
			return (0);
	ret = p_of_params((char *)format);
	while (nb--)
	{
		len_param = parsing_params((char *)format + ret++); // recupere la longueur des flags
		param = ft_strndup(format + ret, len_param);		// recupere les flags
		len_param += ret;							// met len_param a la longueur debut_format
													//  + len_flag
		list = list_param(&i, ap, param, &z);
		if (test-- > 0 && format[0] != '%')
			res = ft_strncpy(res, format, ret - 1); 	// ajout le debut de format avant '%' a res
		if (list->c == '%')
			flag_char(res, i, '%', z);
		else if (list->f)
			flag_string(res, i, list->f, z);
		if (nb)						// s'il y a plusieurs arguments et qu'il y a du texte 
		{							// entre ceux ci, l'ajoute au resultat final
			if (!(list->c == '%'))
			{
				ft_strncpy(res + ft_strlen(res), format + len_param, p_of_params((char *)format + len_param));
				ret += p_of_params((char *)format + ret);
			}
			else if (list->c == '%' && i > 1)
			{
				ft_strncpy(res + ft_strlen(res), format + len_param, p_of_params((char *)format + len_param));
				ret += p_of_params((char *)format + ret  + ft_strlen(ft_itoa(i)) + 1) + ft_strlen(ft_itoa(i)) + 1;
			}
			else
				res = inter_flag_of_conv(format, res, &ret, len_param);
		}
		i = 0;
	}
	ft_strcat(res, format + len_param); 	// ajout la fin de format apres les flags
	ft_putstr_len(res, ft_strlen(res));					// affiche la nouvelle string avec conversion
	va_end(ap);						// reset ap à start
	return (ft_strlen(res));		// renvoi la longueur de la nouvelle string
}

// c, C, s, S,p, d, D, i, o, O, u, U,x X 

// char *string()
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
