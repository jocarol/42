/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/15 02:25:34 by agrau             #+#    #+#             */
/*   Updated: 2017/01/22 13:50:44 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr_s;

	ptr_s = s;
	while (n--)
		*ptr_s++ = (unsigned char)c;
	return (s);
}
