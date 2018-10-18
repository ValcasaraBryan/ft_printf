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
	while (++i < len)
		if (tab[i] > 0)
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

void	add_caractere(LIST, unsigned char caractere, int len)
{
	char *buf;

	if (len <= 0)
		len = 1;
	if (!(buf = ft_memalloc(len + 1)))
		return ;
	ft_memset(buf, caractere, len);
	if (LEN > 0)
		ft_strcat(DATA+ LEN, buf);
	else
		DATA = ft_strdup(buf);
	LEN += len;
}

void	priority_precision_largeur_sign_hashtag(LIST)
{
	if (SIGN_ && *DATA == '-')
		LEN--;
	if (HASHTAG_)
	{
		TAB[POINT] = (params(ARG, "oO") && POINT_) ? TAB[POINT] - 1 : TAB[POINT];
		TAB[LARGEUR] = (params(ARG, "oO") && LARGEUR_) ? TAB[LARGEUR] - 1 : TAB[LARGEUR];
		TAB[HASHTAG - 1] = (params(ARG, "oO") && LARGEUR_NO && POINT_NO && *DATA == '0') ? 0 : TAB[HASHTAG - 1];
		TAB[HASHTAG - 1] = (params(ARG, "Xx") && *DATA == '0') ? 0 : TAB[HASHTAG - 1];
	}
	if (POINT_)
	{
		LEN = (params(ARG, "oOXxdiup") && *DATA == '0') ? 0 : LEN;
		LEN = ((LEN > TAB[POINT]) && params(ARG, "s")) ? TAB[POINT] : LEN;
		TAB[POINT] = ((LEN < TAB[POINT]) && params(ARG, "s")) ? LEN : TAB[POINT];
		TAB[POINT] = ((LEN > TAB[POINT])) ? LEN : TAB[POINT];
	}
	if (HASHTAG_)
		TAB[LARGEUR] = ((params(ARG, "oO") == 0) && LARGEUR_ && (TAB[LARGEUR] + 2) > LEN) ? TAB[LARGEUR] - 2: TAB[LARGEUR];
	if (LARGEUR_ && POINT_NO)
		TAB[LARGEUR] = (TAB[LARGEUR] > LEN) ? TAB[LARGEUR] - LEN : 0;
	else if (LARGEUR_ && POINT_)
	{
		TAB[LARGEUR] = (TAB[LARGEUR] > TAB[POINT]) ? TAB[LARGEUR] - TAB[POINT] : 0;
		TAB[POINT] = (LEN < TAB[POINT]) ? TAB[POINT] - LEN : 0;
	}
	else if (LARGEUR_NO && POINT_)
		TAB[POINT] = (LEN < TAB[POINT]) ? TAB[POINT] - LEN : 0;
}

int		change_string(LIST)
{
	if (binary_flag(TAB, LENGHT_TAB))
	{
		priority_precision_largeur_sign_hashtag(list);
		return (add_precision(list));
	}
	else
	{
		LEN = (params(ARG, "dip") && *DATA == '0') ? 0 : LEN;
		return (ft_putstr_len(DATA, LEN, 1));
	}
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
			if (flag[i].tab == list.tab[j] && list.tab[j] > 0)
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
			if (flag[i].tab == list.tab[j] && list.tab[j] > 0)
				return (flag[i].fonction(ap, hexa));
	}
	return (conv_uint(ap, hexa));
}

void	unsigned_value(va_list ap, char c, LIST)
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
		TAB[HASHTAG - 1] = HASHTAG;
		list_add_conversion(conv_void(ap, HEXA_MIN), list);
		return ;
	}
	list_add_conversion(flag_int_unsigned(*list, ap, hexa), list);
}

void	init_list(va_list ap, char c, LIST)
{
	if (c == 'D' || c == 'O' || c == 'U')
	{
		c = c + 32;
		TAB[INT_LONG - 1] = INT_LONG;
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
		if (POINT_NO)
			TAB[POINT] = 6;
		list_add_conversion(conv_float(ap, TAB[POINT]), list);
	}
	else if (c == 'u' || c == 'o' || c == 'x' || c == 'X' || c == 'p')
		return (unsigned_value(ap, c, list));
	else
		list_add_conversion("", list);
}

void	parsing_arg(char *argument, va_list ap, int len, LIST)
{
	if (len > 0)
	{
		flag_optional(argument, list);
		ARG = argument[len - 1];
	}
	else
	{
		flag_optional(argument, list);
		ARG = argument[len];
	}
	init_list(ap, ARG, list);
	if (LEFT_ || (POINT_ && params(ARG, ENT)))
		TAB[ZERO - 1] = 0;
	if (*DATA == '-')
		TAB[SIGN - 1] = SIGN;
	if (SIGN_)
		TAB[BLANK - 1] = 0;
}

int		option_char(LIST, char c)
{
	int i;

	i = 0;
	if (LEFT_)
	{
		i += ft_putchar(c);
		if (LARGEUR_ && ZERO_)
			i += ft_putchar_len('0', TAB[LARGEUR] - 1, 1);
		else if (LARGEUR_ && ZERO_NO)
			i += ft_putchar_len(' ', TAB[LARGEUR] - 1, 1);
	}
	else
	{
		if (LARGEUR_ && ZERO_)
			i += ft_putchar_len('0', TAB[LARGEUR] - 1, 1);
		else if (LARGEUR_ && ZERO_NO)
			i += ft_putchar_len(' ', TAB[LARGEUR] - 1, 1);
		i += ft_putchar(c);
	}
	return (i);
}

int		add_arg(LIST, va_list ap)
{
	if (params(ARG, NO_C))
	{
		if (params(ARG, ENT) == 0 || params(ARG, "uoxX"))
		{
			TAB[BLANK - 1] = 0;
			TAB[SIGN - 1] = 0;
		}
		return (change_string(list));
	}
	if (ARG == 'c')
		return (option_char(list, conv_c(ap)));
	if (ARG == 'C')
		return (conv_long_c(ap));
	else if (ft_isprint(ARG))
		return (option_char(list, ARG));
	return (0);
}

int		parsing(const char *format, LIST, va_list ap, unsigned int nb_percent)
{
	int		i_of_format;
	int		len_arg;
	char	*arg;
	int		len_write;
	int		i;

	i_of_format = p_of_params((char *)format);
	len_write = 0;
	i = 0;
	if (i_of_format > 0)
		len_write = ft_putstr_len(format, i_of_format, 1);
	while (nb_percent--)
	{
		reset_tab_int(list + i, LENGHT_TAB);
		len_arg = parsing_params((char *)format + i_of_format++);
		arg = ft_strndup(format + i_of_format, len_arg);
		parsing_arg(arg, ap, len_arg, list + i);
		i_of_format += len_arg;
//print_tab(*list, LENGHT_TAB, arg);
		len_write += add_arg(list + i, ap);
		if (nb_percent)
		{
			len_arg = p_of_params((char *)format + i_of_format);
			len_write += ft_putstr_len(format + i_of_format, len_arg, 1);
			i_of_format += len_arg;
		}
		i++;
	}
	if (format + i_of_format)
		len_write += ft_putstr_len(format + i_of_format, ft_strlen(format + i_of_format), 1);
	return (len_write);
}

int		ft_printf(const char *format, ...)
{
	va_list			ap;
	t_string		*list;
	int				ret;
	unsigned int	percent;

	percent = nb_percent((char *)format);
	if (percent)
	{
		va_start(ap, format);
		if (!(list = (t_string *)malloc(sizeof(t_string) * percent)))
			return (-1);
		if (!(ret = parsing(format, list, ap, percent)))
			return (ret);
	}
	else
		return (no_arguments(format, ap, *list));
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


void	list_add_conversion(char *string, LIST)
{
	if (string)
	{
		DATA = ft_strdup(string);
		LEN = ft_strlen(string);
	}
	else
	{
		DATA = ft_strdup("(null)");
		LEN = 6;		
	}
}

int		largeur_of_camp(char *arg, LIST, int i)
{
	if (LARGEUR_NO)
		if (arg[i] >= '1' && arg[i] <= '9' && !(arg[i - 1] == '.'))
		{
			TAB[LARGEUR] = ft_atoll(arg + i);
			i += ft_strlen(ft_lltoa(TAB[LARGEUR]));
		}
	if (POINT_NO)
		if (arg[i] == '.')
		{
			TAB[POINT - 1] = POINT;
			TAB[POINT] = ft_atoll(arg + i + 1);
			i += ft_strlen(ft_lltoa(TAB[POINT]));
		}
	return (i);
}

int		flag_optional_suit(char *arg, LIST, int i)
{
	if (arg[i] == 'z')
		TAB[Z_FLAG - 1] = Z_FLAG;
	if (arg[i] == 'l' && NO_LONG && NO_LONG_)
	{
	if (arg[i] == 'l' && arg[i + 1] == 'l')
		{
			TAB[INT_LONG_LONG - 1] = INT_LONG_LONG;
			i++;
		}
		else
			TAB[INT_LONG - 1] = INT_LONG;
	}
	if (arg[i] == 'h' && NO_SHORT && NO_SHORT_)
	{
		if (arg[i] == 'h' && arg[i + 1] == 'h')
		{
			TAB[INT_SHORT_SHORT - 1] = INT_SHORT_SHORT;
			i++;
		}
		else
			TAB[INT_SHORT - 1] = INT_SHORT;
	}
	return (i);
}

void		flag_optional(char *arg, LIST)
{
	int		i;

	i = -1;
	while (arg[++i])
	{
		if (arg[i] == '-')
			TAB[LEFT - 1] = LEFT;
		if (arg[i] == '0' && !((arg[i - 1] <= '9' && arg[i - 1] >= '0')) && !(arg[i - 1] == '.'))
			TAB[ZERO - 1] = ZERO;
		if (arg[i] == ' ')
			TAB[BLANK - 1] = BLANK;
		if (arg[i] == '+')
			TAB[SIGN - 1] = SIGN;
		if (arg[i] == '#')
			TAB[HASHTAG - 1] = HASHTAG;
		if (arg[i] == 'j')
			TAB[J_FLAG - 1] = J_FLAG;
		i = largeur_of_camp(arg, list, i);
		i = flag_optional_suit(arg, list, i);
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
	va_end(ap);
	return (ft_putstr_len(format, ft_strlen(format), 1));
}

int			precision_params(char *param)
{
	if (*param > 48 && *param <= 57
		&& *param - 1 != '.')
		return (ft_atoi(param));
	return (0);
}

void		reset_tab_int(LIST, int len)
{
	int		i;

	i = -1;
	while (++i < len)
		TAB[i] = 0;
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
