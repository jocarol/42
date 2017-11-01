/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:51:55 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/09 23:51:56 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	char	*save;

	i = 0;
	save = dst;
	while (i < n && *src)
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	while (i < n)
	{
		*dst = '\0';
		dst++;
		i++;
	}
	return (save);
}
