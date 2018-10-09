/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wmemset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brvalcas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 18:26:01 by brvalcas          #+#    #+#             */
/*   Updated: 2018/10/04 18:50:35 by brvalcas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>

wchar_t		*ft_wmemset(wchar_t *s, wchar_t c, size_t n)
{
	printf("%C\n", c);
	return (NULL);
}

int main(void)
{
	ft_wmemset("yo", 'l', 1);
	return (0);
}
