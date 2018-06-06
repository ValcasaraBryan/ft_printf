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

typedef struct		s_fonc
{
	char			c;
	void			*result;
	struct s_fonc	*next;
}					t_tab;

int					ft_printf(const char *format, ...);
char				*string_s(va_list ap);
void				*return_list(char c, va_list ap);
t_tab				*init_list_start(t_tab *list, va_list ap);
t_tab				*init_list_next(t_tab *list, va_list ap);
t_tab				*init_list_rest(t_tab *list, va_list ap);
int					parsing_params(char *arg);
int					params(char comp);

#endif
