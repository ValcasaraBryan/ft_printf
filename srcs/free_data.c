/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 14:24:01 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/19 14:24:06 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void						free_data(t_string *list, unsigned int nb_percent)
{
	while (nb_percent--)
		if (params(list[nb_percent].char_of_arg, "spdDioOuUxXfFeEaAn"))
			free(list[nb_percent].data);
}
