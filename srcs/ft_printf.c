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

#include "../includes/ft_printf.h"

int			binary_flag(int *tab , int len)
{
	int		i;
	int		j;

	i = -1;
	j = 0;
	if (!tab)
		return (0);
	while (++i <= len)
		if (tab[i] > -1 && tab[i] <= len)
			++j;
	return (j);
}

void	print_tab(t_string l, int len, char *arg)
{
	int i;

	i = 0;
	printf("\n");
	printf("l.tab[|%s|] = ", arg);
	while (i < len)
			printf("%5d", i++);
	i = 0;
	printf("\n");
	printf("l.tab[|%s|] = ", arg);
	while (len-- > 0)
		printf("%5d", l.tab[i++]);
	printf("\n");
}

void	add_caractere(t_string *l, unsigned char caractere, int len)
{
	char *buf;

	if (len <= 0)
		len = 1;
	if (!(buf = ft_memalloc(len + 1)))
		return ;
	ft_memset(buf, caractere, len);
	if (l->len > 0)
		ft_strcat(l->str + l->len, buf);
	else
		l->str = ft_strdup(buf);
	l->len += len;
}

void	change_string(t_string *l, t_tab *list)
{
	if (!l->str && !l->len)
		l->str = ft_strdup("");
	if (binary_flag(l->tab, LENGHT_TAB + 1))
	{
		if (params(list->c, "oxd"))
			precision(l, list);
		else if (params(list->c, "s"))
			precision_string(l, list);
		add_precision(l, list);
	}
	else
	{
		ft_strcat(l->str + l->len, list->f);
		l->len += list->len;
	}
}

char	*flag_int_sign(t_string l, va_list ap)
{
	t_conv flag[6];
	int		i;
	int		j;

	i = -1;
	flag[0].tab = l.tab[INT_LONG - 1];
	flag[0].fonction = &conv_long;
	flag[1].tab = l.tab[INT_LONG_LONG - 1];
	flag[1].fonction = &conv_long_long;
	flag[2].tab = l.tab[INT_SHORT - 1];
	flag[2].fonction = &conv_short;
	flag[3].tab = l.tab[INT_SHORT_SHORT - 1];
	flag[3].fonction = &conv_char;
	flag[4].tab = l.tab[J_FLAG - 1];
	flag[4].fonction = &conv_intmax;
	flag[5].tab = l.tab[Z_FLAG - 1];
	flag[5].fonction = &conv_ssize_t;
	while (++i < 6)
	{
		j = -1;
		while (++j < LENGHT_TAB - 1)
			if (flag[i].tab == l.tab[j] && l.tab[j] != -1)
				return (flag[i].fonction(ap));
	}
	return (conv_int(ap));
}

char	*flag_int_unsigned(t_string l, va_list ap, char *hexa)
{
	t_conv_base flag[6];
	int			i;
	int			j;

	i = -1;
	flag[0].tab = l.tab[INT_LONG - 1];
	flag[0].fonction = &conv_ulong;
	flag[1].tab = l.tab[INT_LONG_LONG - 1];
	flag[1].fonction = &conv_ulong_long;
	flag[2].tab = l.tab[INT_SHORT - 1];
	flag[2].fonction = &conv_ushort;
	flag[3].tab = l.tab[INT_SHORT_SHORT - 1];
	flag[3].fonction = &conv_uchar;
	flag[4].tab = l.tab[J_FLAG - 1];
	flag[4].fonction = &conv_uintmax;
	flag[5].tab = l.tab[Z_FLAG - 1];
	flag[5].fonction = &conv_size_t;
	while (++i < 6)
	{
		j = -1;
		while (++j < LENGHT_TAB - 1)
			if (flag[i].tab == l.tab[j] && l.tab[j] != -1)
				return (flag[i].fonction(ap, hexa));
	}
	return (conv_uint(ap, hexa));
}

t_tab	*unsigned_value(va_list ap, char c, t_string l)
{
	char *hexa;

	hexa = NULL;
	if (c == 'u')
		hexa = DECIMAL;
	else if (c == 'o')
		hexa = OCTAL;
	else if (c == 'x')
		hexa = HEXA_MIN;
	else if (c == 'X')
		hexa = HEXA_MAJ;
	return (list_add_conversion(c, flag_int_unsigned(l, ap, hexa)));
}

t_tab	*init_list(va_list ap, char c, t_string l)
{
	if (c == 'D' || c == 'O' || c == 'U')
	{
		c = c + 32;
		l.tab[INT_LONG - 1] = INT_LONG;
	}
	if (c == 's')
		return (list_add_conversion(c, string_s(ap)));
	else if (c == 'd' || c == 'i')
		return (list_add_conversion(c, flag_int_sign(l, ap)));
	else if (c == 'c')
		return (list_add_conversion(c, NULL));
	else if (c == 'f')
	{
		if (l.tab[POINT - 1] != POINT)
			l.tab[POINT] = 6;
		return (list_add_conversion(c, conv_float(ap, l.tab[POINT])));
	}
	else if (c == 'p')
		return (list_add_conversion(c, conv_void(ap, HEXA_MIN)));
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X')
		return (unsigned_value(ap, c, l));
	else
		return (list_add_conversion(c, NULL));
}

t_tab	*parsing_arg(char *argument, va_list ap, int len, t_string *l)
{
	if (params(argument[len - 1], CONV))
	{
		flag_optional(argument, l);
		return (init_list(ap, argument[len - 1], *l));
	}
	else
		return (init_list(ap, 0, *l));
}

void	option_char(t_string *l, char c)
{
	if (l->tab[LEFT - 1] == LEFT)
	{
		add_caractere(l, c, 1);
		if (l->tab[LARGEUR] != -1 && l->tab[ZERO - 1] == ZERO)
			add_caractere(l, '0', l->tab[LARGEUR] - 1);
		else if (l->tab[LARGEUR] != -1 && l->tab[ZERO - 1] == -1)
			add_caractere(l, ' ', l->tab[LARGEUR] - 1);
	}
	else
	{
		if (l->tab[LARGEUR] != -1 && l->tab[ZERO - 1] == ZERO)
			add_caractere(l, '0', l->tab[LARGEUR] - 1);
		else if (l->tab[LARGEUR] != -1 && l->tab[ZERO - 1] == -1)
			add_caractere(l, ' ', l->tab[LARGEUR] - 1);
		add_caractere(l, c, 1);
	}
}

void	add_arg(t_string *l, t_tab *list, va_list ap)
{
	if (list->c != 'c' && list->c != '%')
	{
		if (list->c == 'u')
		{
			l->tab[BLANK - 1] = -1;
			l->tab[SIGN - 1] = -1;
		}
		change_string(l, list);
	}
	if (list->c == 'c')
		option_char(l, conv_c(ap));
	else if (list->c == '%')
		option_char(l, '%');
}

int		inter_percent(const char *format, t_string *l, int i_of_format, int tmp)
{
	ft_strcat(l->str + l->len, ft_strndup(format + i_of_format, tmp));
	l->len += tmp;
	return (tmp);
}

char	*end_of_format(t_string *l, t_tab *list, const char *format, int i_of_format)
{
	char	*tmp;
	int		len_format;
	int		i;

	len_format = ft_strlen(format);
	if (i_of_format <= len_format)
	{
		i = ft_strlen(format + i_of_format);
		tmp = (char *)ft_memjoin((void *)l->str, l->len, (void *)format + i_of_format, i);
		free(l->str);
		l->str = tmp;
		l->len += i;
		return (l->str);
	}
	l->len = -1;
	return (NULL);
}

void	parsing(const char *format, t_string *l, t_tab *list, va_list ap)
{
	int		i_of_format;
	int		len_arg;
	char	*arg;

	i_of_format = p_of_params((char *)format);
	if (i_of_format > 0)
		l->str = ft_strndup(format, (l->len = i_of_format));
	else
		l->str = NULL;
	while (l->nb_percent--)
	{
		reset_tab_int(l, LENGHT_TAB);
		len_arg = parsing_params((char *)format + i_of_format++);
		arg = ft_strndup(format + i_of_format, len_arg);
		list = parsing_arg(arg, ap, len_arg, l);
		i_of_format += len_arg;
		add_arg(l, list, ap);
		if (l->nb_percent)
			i_of_format += inter_percent(format, l, i_of_format, p_of_params((char *)format + i_of_format));
	}
	l->str = end_of_format(l, list, format, i_of_format);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	t_string	l;
	t_tab		list;

	l.len = 0;
	l.nb_percent = nb_percent((char *)format);
	if (l.nb_percent)
	{
		va_start(ap, format);
		parsing(format, &l, &list, ap);
	}
	else
		return (no_arguments(format, ap, l));
	va_end(ap);
	ft_putstr_len(l.str, l.len, 1);
	return (l.len);	
}

























t_tab		*list_add_conversion(char c, char *string)
{
	t_tab	*tmp;

	if (!(tmp = ft_memalloc(sizeof(t_tab))))
		return (NULL);
	tmp->c = c;
	if (!string)
	{
		tmp->f = ft_strdup("(null)");
		tmp->len = 6;
	}
	else if (c != 'c' && c != '%')
	{
		tmp->f = string;
		tmp->len = ft_strlen(string);
	}
	else
		tmp->len = 1;
	return (tmp);
}

void		largeur_of_camp(char *arg, t_string *l, int i)
{
	if (l->tab[LARGEUR] == -1)
		if (arg[i] >= '1' && arg[i] <= '9' && !(arg[i - 1] == '.'))
			l->tab[LARGEUR] = ft_atoll(arg + i);
}

int		flag_optional_suit(char *arg, t_string *l, int i)
{
	if (arg[i] == 'z')
		l->tab[Z_FLAG - 1] = Z_FLAG;
	if (arg[i] == 'l' && l->tab[INT_LONG - 1] == -1 && l->tab[INT_LONG_LONG - 1] == -1)
	{
	if (arg[i] == 'l' && arg[i + 1] == 'l')
		{
			l->tab[INT_LONG_LONG - 1] = INT_LONG_LONG;
			i++;
		}
		else
			l->tab[INT_LONG - 1] = INT_LONG;
	}
	if (arg[i] == 'h' && l->tab[INT_SHORT - 1] == -1 && l->tab[INT_SHORT_SHORT - 1] == -1)
	{
		if (arg[i] == 'h' && arg[i + 1] == 'h')
		{
			l->tab[INT_SHORT_SHORT - 1] = INT_SHORT_SHORT;
			i++;
		}
		else
			l->tab[INT_SHORT - 1] = INT_SHORT;
	}
	return (i);
}

void		flag_optional(char *arg, t_string *l)
{
	int		i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '-')
			l->tab[LEFT - 1] = LEFT;
		if (arg[i] == '0' && !((arg[i - 1] <= '9' && arg[i - 1] >= '0')) && !(arg[i - 1] == '.'))
			l->tab[ZERO - 1] = ZERO;
		if (arg[i] == ' ')
			l->tab[BLANK - 1] = BLANK;
		if (arg[i] == '+')
			l->tab[SIGN - 1] = SIGN;
		if (arg[i] == '#')
			l->tab[HASHTAG - 1] = HASHTAG;
		if (arg[i] == '.')
		{
			l->tab[POINT - 1] = POINT;
			l->tab[POINT] = ft_atoll(arg + i + 1);
		}
		if (arg[i] == 'j')
			l->tab[J_FLAG - 1] = J_FLAG;
		i = flag_optional_suit(arg, l, i);
		largeur_of_camp(arg, l, i);
	}
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
					return (x);
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
	ft_putstr_len(format, l.len, 1);
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

void		reset_tab_int(t_string *l, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		l->tab[i] = -1;
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
