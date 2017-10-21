/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:49:06 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/09 23:49:07 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *save1;
	unsigned char *save2;

	save1 = (unsigned char *)s1;
	save2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (n-- > 1 && *save1 == *save2)
	{
		++save1;
		++save2;
	}
	return (*save1 - *save2);
}
