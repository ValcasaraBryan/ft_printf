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

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# define BUFF_SIZE			1024
# define LEFT				1
# define ZERO				2
# define SIGN				3
# define BLANK				4
# define HASHTAG			5
# define INT_LONG			6
# define INT_LONG_LONG		7
# define INT_SHORT			8
# define INT_SHORT_SHORT	9
# define LENGTH_TAB 		9

typedef struct				s_fonc
{
	char					c;
	char					*f;
}							t_tab;

int							ft_printf(const char *format, ...);
t_tab						*return_list(char c, va_list ap, int *flag);
t_tab						*init_list(va_list ap, char c, int *z);
t_tab						*init_list_next(t_tab *list, va_list ap, char c,
							int *z);
int							parsing_params(char *arg);
int							params(char comp);
t_tab						*list_add_conversion(char c, char *string);
void						list_add(t_tab	**list, t_tab *new);
int							precision_params(char *param);
char						*add_caractere(char *params, int len,
							long caractere);
int							nb_percent(char *format);
int							p_of_params(char *format);
char						*flag_string(char *res, int i, char *string,
							int *flag);
char						*flag_char(char *res, int i, char caractere,
							int *flag);
int							*flag_optional(char *param);
int							binary(int *tab);
char						*add_precision(char *string, int i, int len,
							int *flag);
int							value_pos(int i, int *tab, int flag);
char						*option_right(char *string, int i, int len,
							int *flag);
char						*option_left(char *string, int i, int len,
							int *flag);
char						*option_zero_space(char *sign, char *tmp, int i,
							int *flag);
char						*option_space_zero(char *space, int i, int len,
							int *flag);
char						*signe(long long val, char *string, char **sign,
							int *i);
char						*blank_option(char *string, int *i, int *flag);
int							*reset_tab_int(int *tab, int len);
t_tab						*list_param(int *index, va_list ap,
							char *param, int **z);
char						*inter_flag_of_conv(const char *format,
							char *string, int *index, int len_param);
int							*flag_long_short(int *tab, int *index, char *param);
int							valid_flag_short(int *tab);
int							valid_flag_short_short(int *tab);
int							valid_flag_long(int *tab);
int							valid_flag_long_long(int *tab);
t_tab						*flag(char c, t_tab *list, int *z, va_list ap);
t_tab						*flag_u(char c, t_tab *list, int *z, va_list ap);
char						*add_prefix(char c);

char						*string_s(va_list ap);
char						*conv_c(va_list ap);
char						*conv_long_c(va_list ap);
char						*d_uns_int(va_list ap);
char						*d_long_long(va_list ap);
char						*d_long(va_list ap);
char						*conv_int(va_list ap);
char						*d_uns_long(va_list ap);
char						*d_uns_long_long(va_list ap);
char						*short_int(va_list ap);
char						*uns_short_int(va_list ap);
char						*conv_hexa(va_list ap);
char						*conv_hexa_l(va_list ap);
char						*conv_hexa_l_l(va_list ap);
char						*conv_octal_l_l(va_list ap);

void						ft_putstr_len(const char *str, size_t len);

long long					ft_atoll(const char *str);
unsigned long long			ft_atoull(const char *str);

char						*ft_lltoa(long long n);
char						*ft_ulltoa(unsigned long long n);
char						*ft_itoa_base(long long nb, const char *base);

#endif
