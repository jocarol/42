/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 05:22:06 by agrau             #+#    #+#             */
/*   Updated: 2017/01/19 18:27:58 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char		*ptr_dst;
	const char	*ptr_src;
	size_t		dst_size;

	dst_size = ft_strlen(dst);
	ptr_src = src;
	ptr_dst = dst + dst_size;
	dst_size = (n < dst_size) ? n : dst_size;
	while (((dst + n) - ptr_dst) - 1 > 0 && *ptr_src)
		*ptr_dst++ = *ptr_src++;
	*ptr_dst = '\0';
	return (dst_size + ft_strlen(src));
}
