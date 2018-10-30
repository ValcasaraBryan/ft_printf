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

void					free_data(t_string *list, unsigned int nb_percent,
						const char *str)
{
	while (nb_percent--)
		if (params(list[nb_percent].char_of_arg, str))
			free(list[nb_percent].data);
	if (list)
		free(list);
}

int						print_zero_space_char(t_string *list, int octet)
{
	if (list->tab[LARGEUR] > 0 && list->tab[ZERO - 1] == ZERO)
		return (ft_putchar_len('0', list->tab[LARGEUR] - octet, list->fd));
	else if (list->tab[LARGEUR] > 0 && list->tab[ZERO - 1] == 0)
		return (ft_putchar_len(' ', list->tab[LARGEUR] - octet, list->fd));
	else
		return (0);
}

int						retour_err(int *len_write, int f)
{
	int					read;

	read = *len_write;
	if (f == -1)
		return (-1);
	read += f;
	*len_write = read;
	return (f);
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
		if ((ret = parsing(format, list, ap, percent)) == -1)
			return (-1);
		free_data(list, percent, FLAG);
		free(list);
		va_end(ap);
	}
	else
		return (ft_putstr_len(format, ft_strlen(format), fd));
	return (ret);
}
