/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 19:41:58 by brvalcas          #+#    #+#             */
/*   Updated: 2018/08/08 19:41:59 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"








t_tab	*parsign_arg(char *argument, va_list ap, int len, t_string l)
{
	if (params(argument[len - 1], CONV))
	{
		flag_optional(argument, l);
		return (init_list(ap, argument[len - 1], l.tab));
	}
}



void	parsing(const char *format, t_string l, t_tab *list, va_list ap)
{
	int		i_of_format;
	int		len_arg;
	char	*arg;

	i_of_format = p_of_params((char *)format);
	while (l.nb_percent--)
	{
		len_arg = parsing_params((char *)format + i_of_format++);
		arg = ft_strndup(format + i_of_format, len_arg);
		list = parsing_arg(arg, ap, len_arg, l);
	}
}


int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_string	l;
	t_tab		list;

	l.len = 0;
	va_start(ap, format);
	l.nb_percent = nb_percent((char *)format);
	if (l.nb_percent)
		parsing(format, l, &list, ap);
	else
		return (no_arguments(format, ap, l));
	va_end(ap);
	ft_putstr_len(l.str, l.len);
	return (l.len);	
}












































int			p_of_params(char *format)
{
	int		i;

	i = -1;
	if (!format)
		return (-1);
	while (format[++i])
		if (format[i] == '%')
			return (i);
	return (-1);
}

int			parsing_params(char *arg)
{
	int		i;
	int		j;
	int		x;

	i = -1;
	j = 0;
	x = 0;
	if (!arg)
		return (-1);
	while (arg[++i])
		if (arg[i] == '%')
			while (arg[i + (++j)])
			{
				if (params(arg[i + j], CONV) > 0)
					return (j);
				if (params(arg[i + j], FLAG) == 0)
					return (x + 1);
				x++;
			}
	return (0);
}

unsigned int	nb_percent(char *format)
{
	int		i;
	int		j;
	int		nb_percent;

	i = -1;
	nb_percent = 0;
	if (!format)
		return (-1);
	while (format[++i])
		if (format[i] == '%')
		{
			if ((j = parsing_params(format + i)) && format[i + j] == '%')
				i += j;
			++nb_percent;
		}
	return (nb_percent);
}

int		no_arguments(const char *format, va_list ap, t_string l)
{
	l.len = (int)ft_strlen(format);
	ft_putstr_len(format, l.len);
	va_end(ap);
	return (l.len);
}

int			precision_params(char *param)
{
	if (*param > 48 && *param <= 57
		&& *param - 1 != '.')
		return (ft_atoi(param));
	return (0);
}

void			reset_tab_int(t_string l, int len)
{
	int		i;

	i = -1;
	while (++i <= len)
		l.tab[i] = 0;
}

void			flag_optional_two(char *param, t_string l, int *i)
{
	if (param[*i] == 'j')
		l.tab[J_FLAG - 1] = J_FLAG;
	if (param[*i] == 'z')
		l.tab[Z_FLAG - 1] = Z_FLAG;
	if (param[*i] == 'l' && l.tab[INT_LONG - 1] == 0 && l.tab[INT_LONG_LONG - 1] == 0)
	{
		if (param[*i] == 'l' && param[*i + 1] == 'l')
		{
			l.tab[INT_LONG_LONG - 1] = INT_LONG_LONG;
			*i++;
		}
		else
			l.tab[INT_LONG - 1] = INT_LONG;
	}
	if (param[*i] == 'h' && l.tab[INT_SHORT - 1] == 0 && l.tab[INT_SHORT_SHORT - 1] == 0)
	{
		if (param[*i] == 'h' && param[*i + 1] == 'h')
	{
			l.tab[INT_SHORT_SHORT - 1] = INT_SHORT_SHORT;
			*i++;
		}
		else
			l.tab[INT_SHORT - 1] = INT_SHORT;
	}
}

void			flag_optional(char *param, t_string l)
{
	int		i;

	i = -1;
	reset_tab_int(l, LENGHT_TAB);
	while (param[++i])
	{
		if (param[i] == '-')
			l.tab[LEFT - 1] = LEFT;
		if (param[i] == '0' && !((param[i - 1] <= '9' && param[i - 1] >= '0')) && !(param[i - 1] == '.'))
			l.tab[ZERO - 1] = ZERO;
		if (param[i] == '+')
			l.tab[SIGN - 1] = SIGN;
		if (param[i] == ' ')
			l.tab[BLANK - 1] = BLANK;
		if (param[i] == '#')
			l.tab[HASHTAG - 1] = HASHTAG;
		if (param[i] == '.')
		{
			l.tab[POINT - 1] = POINT;
			l.tab[POINT] = ft_atoll(param + i + 1);
		}
		l.tab[LARGEUR - 1] = precision_params(param + i);
		flag_optional_two(param, l, &i);
		flag_optional_three(param, l, &i);
	}
}

int			params(char comp, const char *list)
{
	int		i;

	i = -1;
	while (list[++i])
		if (list[i] == comp)
			return (i + 1);
	return (0);
}
