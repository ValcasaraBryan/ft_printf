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
# include "../libft/libft.h"
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
								// 12  PRECISION
# define LARGEUR			13	// 12
								// 13  LARGUEUR
# define LENGHT_TAB 		14	// 14

# define CONV				"sSpdDioOuUxXcCfFeEaAn%"
# define FLAG				"lhjz-+. #0123456789"
# define ENT				"dDioOuUxX"

typedef struct				s_fonc
{
	char					c;
	char					*f;
}							t_tab;

typedef struct				s_string
{
	char					*str;
	int						len;
	unsigned int			nb_percent;
	int						tab[LENGHT_TAB];
}							t_string;

int							ft_printf(const char *format, ...);
void						parsing(const char *format, t_string l, t_tab *list, va_list ap);
t_tab						*parsign_arg(char *argument, va_list ap, int len, t_string l)


int							p_of_params(char *format)
int							parsing_params(char *arg);
unsigned int				nb_percent(char *format);
int							no_arguments(const char *format, va_list ap, t_string l);

int							precision_params(char *param)
void						reset_tab_int(t_string l, int len)
void						flag_optional_two(char *param, t_string l, int *i)
void						flag_optional(char *param, t_string l)
int							params(char comp, const char *list)

#endif
