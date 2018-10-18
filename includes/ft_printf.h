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
# define LEFT				1	// 0		+++
# define ZERO				2	// 1		++
# define SIGN				3	// 2		+++
# define BLANK				4	// 3		+
# define HASHTAG			5	// 4		++
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
# define NO_C				"sSpdDioOuUxXfFeEaAn"
# define FLAG				"lhjz-+. #0123456789"
# define ENT				"dDioOuUxX"
# define HEXA_MIN			"0123456789abcdef"
# define HEXA_MAJ			"0123456789ABCEDF"
# define OCTAL				"01234567"
# define DECIMAL			"0123456789"
# define TAB				list->tab
# define DATA				list->data
# define LEN				list->len
# define ARG				list->char_of_arg
# define LIST				t_string *list

# define RIGHT_				(TAB[LEFT - 1] == 0)
# define LEFT_				(TAB[LEFT - 1] == LEFT)
# define ZERO_				(TAB[ZERO - 1] == ZERO)
# define ZERO_NO			(TAB[ZERO - 1] == 0)
# define SIGN_				(TAB[SIGN - 1] == SIGN)
# define SIGN_NO			(TAB[SIGN - 1] == 0)
# define BLANK_				(TAB[BLANK - 1] == BLANK)
# define BLANK_NO			(TAB[BLANK - 1] == 0)
# define HASHTAG_			(TAB[HASHTAG - 1] == HASHTAG)
# define HASHTAG_NO			(TAB[HASHTAG - 1] == 0)
# define POINT_				(TAB[POINT - 1] == POINT)
# define POINT_NO			(TAB[POINT - 1] == 0)
# define LARGEUR_NO			(TAB[LARGEUR] == 0)
# define LARGEUR_			(TAB[LARGEUR] > 0)

# define NO_SHORT			(TAB[INT_SHORT - 1] == 0)
# define NO_SHORT_			(TAB[INT_SHORT_SHORT - 1] == 0)
# define NO_LONG			(TAB[INT_LONG - 1] == 0)
# define NO_LONG_			(TAB[INT_LONG_LONG - 1] == 0)

typedef struct				s_string
{
	char					char_of_arg;
	char					*data;
	int						len;
	int						tab[LENGHT_TAB];
	int						index;
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
int							parsing(const char *format, t_string *list, va_list ap, unsigned int);
void						parsing_arg(char *argument, va_list ap, int len, t_string *list);


void						init_list(va_list ap, char c, t_string *list);
void						list_add_conversion(char *string, t_string *list);


int							p_of_params(char *format);
int							parsing_params(char *arg);
unsigned int				nb_percent(const char *format);
int							no_arguments(const char *format);

int							precision_params(char *param);
void						reset_tab_int(t_string *l, int len);
void						flag_optional(char *param, t_string *l);
int							flag_optional_suit(char *param, t_string *l, int i);
int							params(char comp, const char *list);

int							change_string(t_string *list);
int							add_precision(t_string *list);
void						option(t_string *list);

void						precision(t_string *list);
void						precision_string(t_string *list);
int							binary_flag(int *tab , int len);
void						priority_flag(t_string *list);

char						*string_s(va_list ap);
char						*conv_int(va_list ap);
char						conv_c(va_list ap);
int							conv_long_c(va_list ap);
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
char						*conv_void(va_list ap, char *hexa);
char						*conv_uint(va_list ap, char *hexa);
char						*conv_ulong(va_list ap, char *hexa);
char						*conv_ulong_long(va_list ap, char *hexa);
char						*conv_ushort(va_list ap, char *hexa);

#endif
