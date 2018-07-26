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
# define BUFF_SIZE_			1024
# define LEFT				1
# define ZERO				2
# define SIGN				3
# define BLANK				4
# define HASHTAG			5
# define INT_LONG			6
# define INT_LONG_LONG		7
# define INT_SHORT			8
# define INT_SHORT_SHORT	9
# define J_FLAG				10
# define Z_FLAG				11
# define POINT				12
# define LENGTH_TAB 		POINT
# define CONV				"sSpdDioOuUxXcCfFeEaAn%"
# define FLAG				"lhjz-+.#0123456789"

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
int							params(char comp, const char *list);
int							params_int(char *param);
t_tab						*list_add_conversion(char c, char *string);
void						list_add(t_tab	**list, t_tab *new);
int							precision_params(char *param);
int							precision_params_point(char *param);
char						*add_caractere(char *params, int len,
							long caractere);
char						*add_caractere_start(char *params, int len,
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
int							*flag_z_j(int *tab, int *index, char *param);
int							valid_flag_short(int *tab);
int							valid_flag_short_short(int *tab);
int							valid_flag_long(int *tab);
int							valid_flag_long_long(int *tab);
t_tab						*flag(char c, t_tab *list, int *z, va_list ap);
t_tab						*flag_u(char c, t_tab *list, int *z, va_list ap);
t_tab						*flag_x(char c, t_tab *list, int *z, va_list ap);
char						*add_prefix(char c);

char						*string_s(va_list ap);
char						*conv_c(va_list ap);
int							conv_int(va_list ap);
long						conv_long(va_list ap);
long long					conv_long_long(va_list ap);
unsigned int				conv_uint(va_list ap);
unsigned long				conv_ulong(va_list ap);
unsigned long long			conv_ulong_long(va_list ap);
short						conv_short(va_list ap);
unsigned short				conv_ushort(va_list ap);
char						conv_char(va_list ap);
unsigned char				conv_uchar(va_list ap);
intmax_t					conv_intmax(va_list ap);
uintmax_t					conv_uintmax(va_list ap);
size_t						conv_size_t(va_list ap);
ssize_t						conv_ssize_t(va_list ap);

void						ft_putstr_len(const char *str, size_t len);
int							ft_buff_printf(char **str, int fd, const char *format, ...);

long long					ft_atoll(const char *str);
unsigned long long			ft_atoull(const char *str);

char						*ft_lltoa(long long n);
char						*ft_ulltoa(unsigned long long n);
char						*ft_lltoa_base(long long nb, const char *base);
char						*ft_ulltoa_base(unsigned long long nb, const char *base);

#endif
