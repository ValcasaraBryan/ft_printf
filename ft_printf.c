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
		list = list_param(&i, ap, param, &z);
		if (test-- > 0 && format[0] != '%')
			res = ft_strncpy(res, format, ret - 1); 	// ajout le debut de format avant '%' a res
		if (list->c == '%')
			flag_char(res, i, '%', z);
		if (list->c == 's')							// ajout de l'arg[2] a la string final
			flag_string(res, i, (char *)list->f, z);
		if (list->c == 'c')							// ajout de l'arg[2] a la string final
			flag_char(res, i, (char)list->f, z);

		flag_h(res, i, list, z);
		flag_l(res, i, list, z);
		i = 0;
		if (nb)						// s'il y a plusieurs arguments et qu'il y a du texte 
		{							// entre ceux ci, l'ajoute au resultat final
			if (!(list->c == '%'))
			{
				ft_strncpy(res + ft_strlen(res), format + len_param, p_of_params((char *)format + len_param));
				ret += p_of_params((char *)format + ret);
			}
			else
				res = inter_flag_of_conv(format, res, &ret, len_param);
		}
		reset_tab_int(z, LENGTH_TAB);
	}
	ft_strcat(res, format + len_param); 	// ajout la fin de format apres les flags
	ft_putstr_len(res, ft_strlen(res));					// affiche la nouvelle string avec conversion
	va_end(ap);						// reset ap à start
	return (ft_strlen(res));		// renvoi la longueur de la nouvelle string
}

char	*flag_h(char *res, int i, t_tab *list, int *z)
{
	if (valid_flag_short(z) && list->c == 'd')
		flag_string(res, i, ft_lltoa((short int)list->f), z);
	else if (valid_flag_short_short(z) && list->c == 'd')
		flag_string(res, i, ft_lltoa((char)list->f), z);
	else if (valid_flag_long(z) && list->c == 'd')
		flag_string(res, i, ft_lltoa((long)list->f), z);
	else if (valid_flag_long_long(z) && list->c == 'd')
		flag_string(res, i, ft_lltoa((long long)list->f), z);
	else if (list->c == 'd')
		flag_string(res, i, ft_lltoa((int)list->f), z);
	return (res);
}

char	*flag_l(char *res, int i, t_tab *list, int *z)
{
	if (valid_flag_short(z) && list->c == 'u')
		flag_u_string(res, i, ft_lltoa((unsigned short int)list->f), z);
	else if (valid_flag_short_short(z) && list->c == 'u')
		flag_string(res, i, ft_lltoa((unsigned char)list->f), z);
	else if (valid_flag_long(z) && list->c == 'u')
		flag_string(res, i, ft_ulltoa((unsigned long)list->f), z);
	else if (valid_flag_long_long(z) && list->c == 'u')
		flag_string(res, i, ft_ulltoa((unsigned long long)list->f), z);
	else if (list->c == 'u')
		flag_u_string(res, i, ft_ulltoa((unsigned int)list->f), z);
	return (res);
}

int		valid_flag_short(int *tab)
{
	if (tab[7] == INT_SHORT)
		return (1);
	return (0);
}

int		valid_flag_short_short(int *tab)
{
	if (tab[8] == INT_SHORT_SHORT)
		return (1);
	return (0);
}

int		valid_flag_long(int *tab)
{
	if (tab[5] == INT_LONG)
		return (1);
	return (0);
}

int		valid_flag_long_long(int *tab)
{
	if (tab[6] == INT_LONG_LONG)
		return (1);
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
