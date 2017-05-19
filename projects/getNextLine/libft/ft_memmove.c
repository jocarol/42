/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 00:27:11 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:33:27 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	void	*save;

	save = dst;
	if (dst > src)
		while (len--)
			*((unsigned char *)(dst + len)) = *((unsigned char *)(src + len));
	else if (dst < src)
		while (len--)
			*(unsigned char *)dst++ = *(unsigned char *)src++;
	return (save);
}
