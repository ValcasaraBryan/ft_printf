/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:56:25 by brvalcas          #+#    #+#             */
/*   Updated: 2018/02/11 19:31:45 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_recursive_power(int nb, int power)
{
	int nb_init;

	nb_init = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	if (power > 0)
		return (nb_init * ft_recursive_power(nb, (power - 1)));
	return (0);
}
