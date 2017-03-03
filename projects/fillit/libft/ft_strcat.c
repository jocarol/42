/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 00:08:31 by agrau             #+#    #+#             */
/*   Updated: 2017/01/13 05:30:03 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	char *ptr_dst;

	ptr_dst = dst + ft_strlen(dst);
	while (*src)
		*ptr_dst++ = *src++;
	*ptr_dst = '\0';
	return (dst);
}
