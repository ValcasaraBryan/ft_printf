/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 17:32:42 by brvalcas          #+#    #+#             */
/*   Updated: 2018/06/05 17:32:45 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/includes/libft.h"
# define LEFT				1	// 0
# define ZERO				2	// 1
# define SIGN				3	// 2
# define BLANK				4	// 3
# define HASHTAG			5	// 4
# define INT_LONG			6	// 5
# define INT_LONG_LONG		7	// 6
# define INT_SHORT			8	// 7
# define INT_SHORT_SHORT	9	// 8
# define J_FLAG				10	// 9
# define Z_FLAG				11	// 10
# define POINT				12	// 11
								// 12   PRECISION
# define LARGEUR			13	// 13	LARGEUR
# define LENGHT_TAB 		14	// 14

# define CONV				"sSpdDioOuUxXcCfFeEaAn%"
# define FLAG				"lhjz-+. #0123456789"
# define ENT				"dDioOuUxX"
# define HEXA_MIN			"0123456789abcdef"
# define HEXA_MAJ			"0123456789ABCEDF"
# define OCTAL				"01234567"
# define DECIMAL			"0123456789"

typedef struct				s_fonc
{
	char					c;
	char					*f;
	int						len;
}							t_tab;

typedef struct				s_string
{
	char					*str;
	int						len;
	unsigned int			nb_percent;
	int						tab[LENGHT_TAB];
}							t_string;

typedef struct				s_conver
{
	int						tab;
	char					*(*fonction)(va_list ap);
}							t_conv;

typedef struct				s_conver_base
{
	int						tab;
	char					*(*fonction)(va_list ap, char *hexa);
}							t_conv_base;

int							ft_printf(const char *format, ...);
void						parsing(const char *format, t_string *l, t_tab *list, va_list ap);
t_tab						*parsing_arg(char *argument, va_list ap, int len, t_string *l);


t_tab						*init_list(va_list ap, char c, t_string l);
t_tab						*list_add_conversion(char c, char *string);


int							p_of_params(char *format);
int							parsing_params(char *arg);
unsigned int				nb_percent(char *format);
int							no_arguments(const char *format, va_list ap, t_string l);

int							precision_params(char *param);
void						reset_tab_int(t_string *l, int len);
void						flag_optional(char *param, t_string *l);
int							flag_optional_suit(char *param, t_string *l, int i);
int							params(char comp, const char *list);

void						change_string(t_string *l, t_tab *list);
void						add_precision(t_string *l, t_tab *list);
void						option_right(t_string *l, t_tab *list);
void						option_left(t_string *l, t_tab *list);
char						*option_zero_space(char *sign, char *tmp, t_string *l, t_tab *list);
char						*option_space_zero(t_string *l, t_tab *list);
int							value_pos(int i, int *tab, int flag);

char						*add_caractere_start(char *params, int len, unsigned char caractere);
void						precision(t_string *l, t_tab *list);

char						*string_s(va_list ap);
char						*conv_int(va_list ap);
char						conv_c(va_list ap);
char						*conv_float(va_list ap, unsigned int precision);
char						*conv_long(va_list ap);
char						*conv_long_long(va_list ap);
char						*conv_short(va_list ap);
char						*conv_char(va_list ap);
char						*conv_uchar(va_list ap, char *hexa);
char						*conv_intmax(va_list ap);
char						*conv_uintmax(va_list ap, char *hexa);
char						*conv_size_t(va_list ap, char *hexa);
char						*conv_ssize_t(va_list ap);

char						*conv_uint(va_list ap, char *hexa);
char						*conv_ulong(va_list ap, char *hexa);
char						*conv_ulong_long(va_list ap, char *hexa);
char						*conv_ushort(va_list ap, char *hexa);

long long					ft_atoll(const char *str);
char						*ft_lltoa(long long n);
char						*ft_dotoa(double nb, unsigned int precision);
char						*ft_ulltoa_base(unsigned long long nb, const char *base);

int							ft_putstr_len(const char *str, size_t len, int fd);

#endif
