/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:47:59 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/09 10:40:32 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char		  *itoa_fractol(uintmax_t n)
{
  static char	  str[11];
  char          *pt;
  int           i;

  i = 10;
// printf("--> %ju\n", n);
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
  // printf("%s\n", pt);
	return (pt);
}
