/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 20:27:36 by agrau             #+#    #+#             */
/*   Updated: 2017/01/17 20:49:59 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ptr_s;

	ptr_s = NULL;
	while (*s || (char)c == '\0')
	{
		if (*s == (char)c)
		{
			ptr_s = (char*)s;
			if (c == '\0')
				return (ptr_s);
		}
		s++;
	}
	return (ptr_s);
}
