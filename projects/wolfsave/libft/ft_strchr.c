/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:50:31 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:37:00 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*save;

	save = (char*)s;
	while (*save)
	{
		if (*save == (char)c)
			return (save);
		save++;
	}
	if (*save == c)
		return (save);
	return (NULL);
}
