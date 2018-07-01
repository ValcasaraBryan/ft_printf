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
	int 		h;
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
	h = 0;
	nb = (unsigned int)nb_percent((char *)format);
	if (nb == 0)
	{
		ft_putstr(format);
		return (ft_strlen(format));
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
		if (ft_strlen(param) == 1)
			list = return_list(*param, ap);		// initialise le parametre arg[2]
		else
		{
			z = flag_optional(param);
			j = binary(z);
			i = precision_params(param);// donne à i la longueur de precision
			if (ft_strlen(ft_itoa(i)) > 0 && i > 0)
				list = return_list(param[(j + ft_strlen(ft_itoa(i)))], ap);
			else
				list = return_list(param[j], ap);
		}
		if (test-- > 0 && format[0] != '%')
			res = ft_strncpy(res, format, ret - 1); 	// ajout le debut de format avant '%' a res
		if (list->c == '%')
			flag_char(res, i, '%', z);
		if (list->c == 's')							// ajout de l'arg[2] a la string final
			flag_string(res, i, (char *)list->f, z);
		if (list->c == 'c')							// ajout de l'arg[2] a la string final
			flag_char(res, i, (char)list->f, z);
		if (list->c == 'd' || list->c == 'i')							// ajout de l'arg[2] a la string final
			flag_string(res, i, ft_itoa((int)list->f), z);
		if (list->c == 'u')
			flag_u_string(res, i, ft_uitoa((unsigned int)list->f), z); // conversion int en unsigned int
		i = 0;
		z = flag_optional(NULL);
		if (nb)						// s'il y a plusieurs arguments et qu'il y a du texte 
		{							// entre ceux ci, l'ajoute au resultat final
			if (!(list->c == '%'))
			{
				ft_strncpy(res + ft_strlen(res), format + len_param, p_of_params((char *)format + len_param));
				ret += p_of_params((char *)format + ret);
			}
			else
			{
				if (p_of_params((char *)format + ret++ + 1))
				{
					ft_strncpy(res + ft_strlen(res), format + len_param, p_of_params((char *)format + len_param + 1) + 1);
					ret += p_of_params((char *)format + len_param + 1) + 1;
				}
				else if (!parsing_params((char *)format + ret))
					ft_strncpy(res + ft_strlen(res), format + len_param, p_of_params((char *)format + len_param + 1));
			}
		}
	}
	ft_strcat(res, format + len_param); 	// ajout la fin de format apres les flags
	ft_putstr_len(res, ft_strlen(res));					// affiche la nouvelle string avec conversion
	va_end(ap);						// reset ap à start
	return (ft_strlen(res));		// renvoi la longueur de la nouvelle string
}


int		flag_long_short(char *param)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (param[++i])
	{
		if (param[i] == 'l')
		{
			++j;
			if (param[i + j] == 'l')
				++j;
			return (j);
		}
		if (param[i] == 'h')
		{
			++j;
			if (param[i + j] == 'h')
				++j;
			return (j);
		}
	}
	return (0);
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
