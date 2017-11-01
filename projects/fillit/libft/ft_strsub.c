/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 23:35:30 by agrau             #+#    #+#             */
/*   Updated: 2017/01/19 18:19:54 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ptr_dst;
	int		i;

	i = 0;
	ptr_dst = NULL;
	if (s && (ptr_dst = ft_strnew(len)))
		while (len-- && *(s + start))
			*(ptr_dst + i++) = *((s++) + start);
	return (ptr_dst);
}
