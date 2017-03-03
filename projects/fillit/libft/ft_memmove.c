/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 03:09:25 by agrau             #+#    #+#             */
/*   Updated: 2017/01/22 13:49:19 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char *ptr_dst;

	ptr_dst = dst;
	if (src > dst)
		while (n--)
			*(unsigned char*)dst++ = *(const unsigned char*)src++;
	else
		while (n--)
			*((unsigned char*)dst + n) = *((const unsigned char*)src + n);
	return ((void*)ptr_dst);
}
