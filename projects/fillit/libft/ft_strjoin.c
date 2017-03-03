/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 01:10:50 by agrau             #+#    #+#             */
/*   Updated: 2017/01/19 18:36:47 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;
	char	*ptr_dst;

	if (s1 && s2 && (ptr_dst = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		dst = ptr_dst;
		while (*s1)
			*ptr_dst++ = *s1++;
		while (*s2)
			*ptr_dst++ = *s2++;
		return (dst);
	}
	return (NULL);
}
