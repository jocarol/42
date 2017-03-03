/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 02:37:38 by agrau             #+#    #+#             */
/*   Updated: 2017/01/22 13:41:51 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*ptr_dst;
	const unsigned char	*ptr_src;

	if (n)
	{
		ptr_dst = dst;
		ptr_src = src;
		while (n--)
			if ((*ptr_dst++ = *ptr_src++) == (unsigned char)c)
				return (ptr_dst);
	}
	return (NULL);
}
