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
# define BUFF_SIZE	1024
# define LEFT		1
# define ZERO		2
# define SIGN		3
# define BLANK		4
# define HASHTAG	5
# define LENGTH_TAB 5

typedef struct		s_fonc
{
	char			c;
	void			(*f)(va_list ap);
}					t_tab;

int					ft_printf(const char *format, ...);
t_tab				*return_list(char c, va_list ap);
t_tab				*init_list(va_list ap, char c);
t_tab				*init_list_next(t_tab *list, va_list ap, char c);
int					parsing_params(char *arg);
int					params(char comp);
t_tab				*list_add_conversion(char c, void (*f)(va_list));
void				list_add(t_tab	**list, t_tab *new);
int					precision_params(char *param);
char				*add_caractere(char *params, int len,
					int caractere);
int					nb_percent(char *format);
int					p_of_params(char *format);
char				*flag_string(char *res, int i, char *string, int *flag);
char				*flag_char(char *res, int i, char caractere, int *flag);
char				*flag_int(char *res, int i, int number, int *flag);
int					*flag_optional(char *param);
int					binary(int *tab);
char				*add_precision(char *string, int i, int len, int *flag);
int					value_pos(int i, int *tab, int flag);
char 				*option_right(char *string, int i, int len, int *flag);
char 				*option_left(char *string, int i, int len, int *flag);
char 				*option_zero_space(char *sign, char *tmp, int i, int *flag);
char 				*signe(int val, char *string, char **sign, int *i);
char				*blank_option(char *string, int *i, int *flag);

void				*string_s(va_list ap);
int					conv_c(va_list ap);
int					d_int(va_list ap);

void				ft_putstr_len(const char *str, size_t len);

#endif
