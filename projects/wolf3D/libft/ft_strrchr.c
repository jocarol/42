/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:52:23 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/09 23:52:24 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	char	*buff;

	save = NULL;
	buff = (char *)s;
	while (*buff)
	{
		if (*buff == (char)c)
			save = buff;
		buff++;
	}
	if (c == 0)
		return (buff);
	return (save);
}
