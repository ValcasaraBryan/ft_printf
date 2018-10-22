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

void					free_data(t_string *list, unsigned int nb_percent)
{
	while (nb_percent--)
		if (params(list[nb_percent].char_of_arg, NO_C))
			free(list[nb_percent].data);
}

char					add_sign(t_string *list)
{
	char				c;

	if (list->tab[SIGN - 1] == SIGN)
	{
		if (*list->data == '-')
			c = '-';
		else
			c = '+';
	}
	else if (list->tab[BLANK - 1] == BLANK)
		c = ' ';
	return (c);
}

int						ft_fprintf(const char *format, int fd, ...)
{
	va_list				ap;
	t_string			*list;
	int					ret;
	int					i;
	unsigned int		percent;

	i = 0;
	if ((percent = nb_percent((char *)format)) == -1)
		return (-1);
	if (percent)
	{
		va_start(ap, fd);
		if (!(list = (t_string *)malloc(sizeof(t_string) * percent)))
			return (-1);
		while (i < percent)
			list[i++].fd = fd;
		ret = parsing(format, list, ap, percent);
		free_data(list, percent);
		free(list);
		va_end(ap);
	}
	else
		return (ft_putstr_len(format, ft_strlen(format), fd));
	return (ret);
}
