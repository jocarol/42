/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:48:54 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:23:58 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char const		*from;
	unsigned char			*to;

	from = src;
	to = dst;
	while (n--)
	{
		*to = *from;
		if (*to == (unsigned char)c)
			return (to + 1);
		++to;
		++from;
	}
	return (NULL);
}
