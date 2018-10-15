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

void	print_tab(t_string list, int len, char *arg)
{
	int i;

	i = 0;
	printf("\n");
	printf("l.tab[%s] = ", arg);
	while (i < len)
			printf("%5d", i++);
	i = 0;
	printf("\n");
	printf("l.tab[%s] = ", arg);
	while (len-- > 0)
		printf("%5d", list.tab[i++]);
	printf("\n");
}

void	add_caractere(t_string *list, unsigned char caractere, int len)
{
	char *buf;

	if (len <= 0)
		len = 1;
	if (!(buf = ft_memalloc(len + 1)))
		return ;
	ft_memset(buf, caractere, len);
	if (list->len > 0)
		ft_strcat(list->data+ list->len, buf);
	else
		list->data = ft_strdup(buf);
	list->len += len;
}

int		change_string(t_string *list)
{
	if (binary_flag(list->tab, LENGHT_TAB + 1))
	{
		if (params(list->char_of_arg, "OoxXdiup"))
			precision(list);
		else if (params(list->char_of_arg, "s"))
			precision_string(list);
		add_precision(list);
		return (1);
	}
	else
		return (1);
}

char	*flag_int_sign(t_string list, va_list ap)
{
	t_conv flag[6];
	int		i;
	int		j;

	i = -1;
	flag[0].tab = list.tab[INT_LONG - 1];
	flag[0].fonction = &conv_long;
	flag[1].tab = list.tab[INT_LONG_LONG - 1];
	flag[1].fonction = &conv_long_long;
	flag[2].tab = list.tab[INT_SHORT - 1];
	flag[2].fonction = &conv_short;
	flag[3].tab = list.tab[INT_SHORT_SHORT - 1];
	flag[3].fonction = &conv_char;
	flag[4].tab = list.tab[J_FLAG - 1];
	flag[4].fonction = &conv_intmax;
	flag[5].tab = list.tab[Z_FLAG - 1];
	flag[5].fonction = &conv_ssize_t;
	while (++i < 6)
	{
		j = -1;
		while (++j < LENGHT_TAB - 1)
			if (flag[i].tab == list.tab[j] && list.tab[j] != -1)
				return (flag[i].fonction(ap));
	}
	return (conv_int(ap));
}

char	*flag_int_unsigned(t_string list, va_list ap, char *hexa)
{
	t_conv_base flag[6];
	int			i;
	int			j;

	i = -1;
	flag[0].tab = list.tab[INT_LONG - 1];
	flag[0].fonction = &conv_ulong;
	flag[1].tab = list.tab[INT_LONG_LONG - 1];
	flag[1].fonction = &conv_ulong_long;
	flag[2].tab = list.tab[INT_SHORT - 1];
	flag[2].fonction = &conv_ushort;
	flag[3].tab = list.tab[INT_SHORT_SHORT - 1];
	flag[3].fonction = &conv_uchar;
	flag[4].tab = list.tab[J_FLAG - 1];
	flag[4].fonction = &conv_uintmax;
	flag[5].tab = list.tab[Z_FLAG - 1];
	flag[5].fonction = &conv_size_t;
	while (++i < 6)
	{
		j = -1;
		while (++j < LENGHT_TAB - 1)
			if (flag[i].tab == list.tab[j] && list.tab[j] != -1)
				return (flag[i].fonction(ap, hexa));
	}
	return (conv_uint(ap, hexa));
}

void	unsigned_value(va_list ap, char c, t_string *list)
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
	else if (c == 'p')
	{
		list->tab[HASHTAG - 1] = HASHTAG;
		list_add_conversion(conv_void(ap, HEXA_MIN), list);
		return ;
	}
	list_add_conversion(flag_int_unsigned(*list, ap, hexa), list);
}

void	init_list(va_list ap, char c, t_string *list)
{
	if (c == 'D' || c == 'O' || c == 'U')
	{
		c = c + 32;
		list->tab[INT_LONG - 1] = INT_LONG;
	}
	if (c == 's')
		list_add_conversion(string_s(ap), list);
	else if (c == 'S')
		list_add_conversion("", list);
	else if (c == 'C')
		list_add_conversion("", list);
	else if (c == 'd' || c == 'i')
		list_add_conversion(flag_int_sign(*list, ap), list);
	else if (c == 'c')
		list_add_conversion("", list);
	else if (c == 'f')
	{
		if (list->tab[POINT - 1] != POINT)
			list->tab[POINT] = 6;
		list_add_conversion(conv_float(ap, list->tab[POINT]), list);
	}
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'p')
		return (unsigned_value(ap, c, list));
	else
		list_add_conversion("", list);
}

void	parsing_arg(char *argument, va_list ap, int len, t_string *list)
{
	if (len > 0)
	{
		flag_optional(argument, list);
		list->char_of_arg = argument[len - 1];
	}
	else
	{
		flag_optional(argument, list);
		list->char_of_arg = argument[len];
	}
	init_list(ap, list->char_of_arg, list);
}

int		option_char(t_string *list, char c)
{
	if (list->tab[LEFT - 1] == LEFT)
	{
		add_caractere(list, c, 1);
		if (list->tab[LARGEUR] != -1 && list->tab[ZERO - 1] == ZERO)
			add_caractere(list, '0', list->tab[LARGEUR] - 1);
		else if (list->tab[LARGEUR] != -1 && list->tab[ZERO - 1] == -1)
			add_caractere(list, ' ', list->tab[LARGEUR] - 1);
	}
	else
	{
		if (list->tab[LARGEUR] != -1 && list->tab[ZERO - 1] == ZERO)
			add_caractere(list, '0', list->tab[LARGEUR] - 1);
		else if (list->tab[LARGEUR] != -1 && list->tab[ZERO - 1] == -1)
			add_caractere(list, ' ', list->tab[LARGEUR] - 1);
		add_caractere(list, c, 1);
	}
	return (1);
}

int		add_arg(t_string *list, va_list ap)
{
	if (params(list->char_of_arg, NO_C))
	{
		if (params(list->char_of_arg, ENT) == 0 || params(list->char_of_arg, "uoxX"))
		{
			list->tab[BLANK - 1] = -1;
			list->tab[SIGN - 1] = -1;
		}
		return (change_string(list));
	}
	if (list->char_of_arg == 'c')
		return (option_char(list, conv_c(ap)));
	//if (list->char_of_arg == 'C')
	//	return (option_char(list, conv_c(ap)));
	else if (ft_isprint(list->char_of_arg))
		return (option_char(list, list->char_of_arg));
	return (-1);
}

char	*end_of_format(t_string *list, const char *format, int i_of_format)
{
	char	*tmp;
	int		len_format;
	int		i;

	len_format = ft_strlen(format);
	if (i_of_format <= len_format)
	{
		i = ft_strlen(format + i_of_format);
		ft_putstr_len((void *)format + i_of_format, i, 1);
		list->len += i;
	}
	return (NULL);
}

int		parsing(const char *format, t_string *list, va_list ap, unsigned int nb_percent)
{
	int		i_of_format;
	int		len_arg;
	char	*arg;
	int		len_write;

	i_of_format = p_of_params((char *)format);
	len_write = 0;
	if (i_of_format > 0)
		len_write = ft_putstr_len(format, i_of_format, list->fd);
	while (nb_percent--)
	{
		reset_tab_int(list, LENGHT_TAB);
		len_arg = parsing_params((char *)format + i_of_format++);
		arg = ft_strndup(format + i_of_format, len_arg);
		parsing_arg(arg, ap, len_arg, list);
		i_of_format += len_arg;
		//print_tab(*list, LENGHT_TAB, arg);
		if (!(add_arg(list, ap)))
			return (-1);
		len_write += ft_putstr_len(list->data, list->len, list->fd);
		if (nb_percent)
		{
			len_arg = p_of_params((char *)format + i_of_format);
			len_write += ft_putstr_len(format + i_of_format, len_arg, list->fd);
			i_of_format += len_arg;
		}
	}
	if (format + i_of_format)
		len_write += ft_putstr_len(format + i_of_format, ft_strlen(format + i_of_format), list->fd);
	return (len_write);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_string		list;
	int				ret;
	unsigned int	percent;

	list.len = 0;
	percent = nb_percent((char *)format);
	if (percent)
	{
		va_start(ap, format);
		list.fd = 1;
		if (!(ret = parsing(format, &list, ap, percent)))
			return (ret);
	}
	else
		return (no_arguments(format, ap, list));
	va_end(ap);
	return (ret);
}




















/*
typedef struct				s_string
{
	char					char_of_arg;
	char					*data;
	int						len;
	int						tab[LENGHT_TAB];
	struct s_string			*next;
}							t_string;
*/


void	list_add_conversion(char *string, t_string *list)
{
	if (string)
	{
		list->data = ft_strdup(string);
		list->len = ft_strlen(string);
	}
	else
	{
		list->data = ft_strdup("(null)");
		list->len = 6;		
	}
}

void		largeur_of_camp(char *arg, t_string *list, int i)
{
	if (list->tab[LARGEUR] == -1)
		if (arg[i] >= '1' && arg[i] <= '9' && !(arg[i - 1] == '.'))
			list->tab[LARGEUR] = ft_atoll(arg + i);
}

int		flag_optional_suit(char *arg, t_string *list, int i)
{
	if (arg[i] == 'z')
		list->tab[Z_FLAG - 1] = Z_FLAG;
	if (arg[i] == 'l' && list->tab[INT_LONG - 1] == -1 && list->tab[INT_LONG_LONG - 1] == -1)
	{
	if (arg[i] == 'l' && arg[i + 1] == 'l')
		{
			list->tab[INT_LONG_LONG - 1] = INT_LONG_LONG;
			i++;
		}
		else
			list->tab[INT_LONG - 1] = INT_LONG;
	}
	if (arg[i] == 'h' && list->tab[INT_SHORT - 1] == -1 && list->tab[INT_SHORT_SHORT - 1] == -1)
	{
		if (arg[i] == 'h' && arg[i + 1] == 'h')
		{
			list->tab[INT_SHORT_SHORT - 1] = INT_SHORT_SHORT;
			i++;
		}
		else
			list->tab[INT_SHORT - 1] = INT_SHORT;
	}
	return (i);
}

void		flag_optional(char *arg, t_string *list)
{
	int		i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '-')
			list->tab[LEFT - 1] = LEFT;
		if (arg[i] == '0' && !((arg[i - 1] <= '9' && arg[i - 1] >= '0')) && !(arg[i - 1] == '.'))
			list->tab[ZERO - 1] = ZERO;
		if (arg[i] == ' ')
			list->tab[BLANK - 1] = BLANK;
		if (arg[i] == '+')
			list->tab[SIGN - 1] = SIGN;
		if (arg[i] == '#')
			list->tab[HASHTAG - 1] = HASHTAG;
		if (arg[i] == '.')
		{
			list->tab[POINT - 1] = POINT;
			list->tab[POINT] = ft_atoll(arg + i + 1);
		}
		if (arg[i] == 'j')
			list->tab[J_FLAG - 1] = J_FLAG;
		i = flag_optional_suit(arg, list, i);
		largeur_of_camp(arg, list, i);
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

int		no_arguments(const char *format, va_list ap, t_string list)
{
	list.len = (int)ft_strlen(format);
	ft_putstr_len(format, list.len, 1);
	va_end(ap);
	return (list.len);
}

int			precision_params(char *param)
{
	if (*param > 48 && *param <= 57
		&& *param - 1 != '.')
		return (ft_atoi(param));
	return (0);
}

void		reset_tab_int(t_string *list, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		list->tab[i] = -1;
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
