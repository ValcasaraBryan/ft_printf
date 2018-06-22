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
# define BUFF_SIZE	1024

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
char				*add_caractere(char *params, int start, int len,
					int caractere);
int					nb_percent(char *format);
int					p_of_params(char *format);

void				*string_s(va_list ap);
int					conv_c(va_list ap);
int					d_int(va_list ap);

#endif
