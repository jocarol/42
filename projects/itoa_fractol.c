/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:47:59 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/25 17:20:56 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		  *itoa_fractol(uintmax_t n)
{
	static char	  str[11];
	char          *pt;
	int           i;

	i = 10;
	str[10] = '\0';
	pt = &str[10];
	if (!n)
	{
		str[9] = '0';
		pt = &str[9];
		i--;
	}
	while (n && i > 0)
	{
		--pt;
		*pt = '0' + n % 10;
		n /= 10;
		i--;
	}
	return (pt);
}
