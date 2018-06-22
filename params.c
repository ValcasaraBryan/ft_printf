/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 19:39:46 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/06 19:39:47 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*add_caractere(char *params, int start, int len, int caractere)
{
	char	*tmp;

	if (*params && (len >= 0) && (start >= 0))
	{
		tmp = (char *)ft_memset((void *)params + start, caractere, len);
		params = ft_strcat(params, tmp);
		return (params);
	}
	return (NULL);
}

int		precision_params(char *param)
{
	int		i;

	i = -1;
	while (param[++i])
	{
		if (param[i] > 48 && param[i] <= 57)
			return (ft_atoi(param));
	}
	return (0);
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
