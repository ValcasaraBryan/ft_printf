/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dotoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 04:57:50 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/26 04:57:53 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_recursive_power(int nb, int power)
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

static int		ft_unite(unsigned int nb)
{
	while (nb > 9)
		nb = nb / 10;
	return (nb);
}

char	*ft_dotoa(double nb, unsigned int precision)
{
	char *str;
	unsigned int i;
	int neg;

	neg = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		neg = 1;
	}
	if (nb > 9)
	{
		str = ft_strdup(ft_lltoa(nb));
		i = (int)ft_strlen(str) - 1;
		while (i)
			nb -= (ft_recursive_power(10, i--) * ft_unite(nb));
		nb -= ft_unite(nb);
	}
	if (str)
		add_caractere(str, 1, '.');
	else
		str = ft_strdup("0.");
	if (nb < 1 && nb > 0)
	{
		while (precision--)
			nb *= 10;
		if (nb - (int)nb >= 0.6 && nb - (int)nb < 1)
			nb += 1;
		ft_strcat(str, ft_strdup(ft_lltoa(nb)));
	}
	if (neg)
		str = add_caractere_start(str, 1, '-');
	return (str);
}

