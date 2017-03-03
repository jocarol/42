/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:52:18 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:50:05 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	char	*tmp1;
	char	*tmp2;
	char	*tmp3;
	size_t	len;

	tmp1 = (char *)s1;
	len = ft_strlen(s2);
	if (!*s2)
		return ((char *)s1);
	while (*tmp1 && n-- >= len)
	{
		tmp3 = tmp1;
		tmp2 = (char *)s2;
		while (*tmp2 && *tmp2 == *tmp3)
		{
			tmp2++;
			tmp3++;
		}
		if (!*tmp2)
			return (tmp1);
		tmp1++;
	}
	return (NULL);
}
