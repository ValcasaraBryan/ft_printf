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
	if (!(res = ft_memalloc(BUFF_SIZE_)))		// alloue la longueur de la string final
			return (0);
	if (!(z = (int *)malloc(sizeof(int) * LENGHT_TAB + 1)))
		return (0);
	ret = p_of_params((char *)format);
	while (nb--)
	{
		len_param = parsing_params((char *)format + ret++); // recupere la longueur des flags
		param = ft_strndup(format + ret, len_param);		// recupere les flags
													//  + len_flag
		list = list_param(&i, ap, param, &z);
		if (z[POINT - 1] == POINT && params_int(param, ENT) && z[POINT])
		{
			list->f = precision(list->f, (int)ft_strlen(list->f), z[POINT]);
			if (z[ZERO - 1] == ZERO)
				z[ZERO - 1] = 0;
		}
		else if (z[POINT] == 0 && z[POINT - 1] == POINT)
			list->f = point_precision(list->f);

		if (z[POINT - 1] == POINT && list->c == 's')
			list->f = ft_strndup(list->f, z[POINT]);
		if (test-- > 0 && format[0] != '%')
			res = ft_strncpy(res, format, ret - 1); 	// ajout le debut de format avant '%' a res
		if (list->c == '%')
			flag_char(res, i, '%', z);
		else if (list->c == 'c' || list->c == 'C')
			flag_char(res, i, conv_c(ap), z);
		else if (list->f)
			flag_string(res, i, list->f, z);
		len_param += ret;							// met len_param a la longueur debut_format
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
		free(param);
		i = 0;
	}
	free(z);
	free(list);
	ft_strcat(res, format + len_param); 	// ajout la fin de format apres les flags
	va_end(ap);						// reset ap à start
	return (free_strlen(res));		// renvoi la longueur de la nouvelle string
}

int		free_strlen(char *res)
{
	int i;
	
	i = ft_strlen(res);
	ft_putstr_len(res, i);
	free(res);
	return (i);
}

char *point_precision(char *string)
{
	char *tmp;
	int i;

	i = 0;
	while (string[i] && string[i] != '.')
		i++;
	if (i)
	{
		tmp = ft_strndup(string, i);
		free(string);
		return (tmp);
	}
	else
		return (string);
}

// char *string()
/*
** • Vous devez gérer les flags #
** • Vous devez gérer la précision
** • Vous devez gérer les flags j z
*/
