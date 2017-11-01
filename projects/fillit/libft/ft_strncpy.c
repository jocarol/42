/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/31 15:30:22 by agrau             #+#    #+#             */
/*   Updated: 2017/01/19 18:10:53 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *ptr_dst;

	ptr_dst = dst;
	while (n--)
	{
		if (*src)
			*dst++ = *src++;
		else
			*dst++ = '\0';
	}
	return (ptr_dst);
}
