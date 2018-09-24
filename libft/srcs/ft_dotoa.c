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

#include "../includes/libft.h"

static int			ft_recursive_power(int nb, int power)
{
	int				nb_init;

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

static int			ft_unite(unsigned int nb)
{
	while (nb > 9)
		nb = nb / 10;
	return (nb);
}

static char			*add_char(char *params, int len, unsigned char caractere)
{
	char			*tmp;

	if (!(tmp = ft_memalloc(len + 1)))
		return (NULL);
	if (*params && (len >= 0))
	{
		tmp = (char *)ft_memset(tmp, caractere, len);
		ft_strcat(params, tmp);
		return (params);
	}
	else if (!*params && (len >= 0))
	{
		ft_memset(params, caractere, len);
		return (params);
	}
	return (NULL);
}

static void			add_prec(char **str, unsigned int precision,
					double nb, int neg)
{
	char			*tmp;

	tmp = NULL;
	if (nb < 1 && nb >= 0)
	{
		while (precision--)
		{
			nb *= 10;
			if (ft_unite(nb) == 0)
				add_char(*str, 1, ft_unite(nb) + 48);
		}
		if (nb - (int)nb > 0.5 && nb - (int)nb < 1)
			nb += 1;
		if (nb > 1)
			ft_strcat(*str, ft_lltoa(nb));
	}
	if (neg)
	{
		if (!(tmp = ft_memalloc(2)))
			return ;
		tmp = (char *)ft_memset(tmp, '-', 1);
		tmp = ft_strcat(tmp, *str);
	}
}

char				*ft_dotoa(double nb, unsigned int precision)
{
	char			*str;
	unsigned int	i;
	int				neg;

	neg = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		neg = 1;
	}
	if (nb > 1)
	{
		str = ft_strdup(ft_lltoa(nb));
		i = (int)ft_strlen(str) - 1;
		while (i)
			nb -= (ft_recursive_power(10, i--) * ft_unite(nb));
		nb -= ft_unite(nb);
	}
	if (str)
		add_char(str, 1, '.');
	else
		str = ft_strdup("0.");
	add_prec(&str, precision, nb, neg);
	return (str);
}
