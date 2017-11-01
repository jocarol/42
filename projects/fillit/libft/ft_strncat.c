/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 02:53:04 by agrau             #+#    #+#             */
/*   Updated: 2017/01/13 05:38:52 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*ptr_dst;

	ptr_dst = dst + ft_strlen(dst);
	while (n-- && *src)
		*ptr_dst++ = *src++;
	*ptr_dst = '\0';
	return (dst);
}
