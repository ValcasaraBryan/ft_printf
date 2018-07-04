/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_h_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 01:45:31 by brvalcas          #+#    #+#             */
/*   Updated: 2018/07/04 01:45:32 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag(char *res, int i, t_tab *list, int *z)
{
	if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short(z) && list->c == 'd')
		flag_string(res, i, ft_lltoa((short int)list->f), z);
	else if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short_short(z) && list->c == 'd')
		flag_string(res, i, ft_lltoa((char)list->f), z);
	else if (valid_flag_long(z) && list->c == 'd')
		flag_string(res, i, ft_lltoa((long)list->f), z);
	else if (valid_flag_long_long(z) && list->c == 'd')
		flag_string(res, i, ft_lltoa((long long)list->f), z);
	else if (list->c == 'd')
		flag_string(res, i, ft_lltoa((int)list->f), z);
	return (res);
}

char	*flag_u(char *res, int i, t_tab *list, int *z)
{
	if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short(z) && list->c == 'u')
		flag_u_string(res, i, ft_lltoa((unsigned short int)list->f), z);
	else if (!valid_flag_long(z) && !valid_flag_long_long(z) &&
		valid_flag_short_short(z) && list->c == 'u')
		flag_string(res, i, ft_lltoa((unsigned char)list->f), z);
	else if (valid_flag_long(z) && list->c == 'u')
		flag_string(res, i, ft_ulltoa((unsigned long)list->f), z);
	else if (valid_flag_long_long(z) && list->c == 'u')
		flag_string(res, i, ft_ulltoa((unsigned long long)list->f), z);
	else if (list->c == 'u')
		flag_u_string(res, i, ft_ulltoa((unsigned int)list->f), z);
	return (res);
}
