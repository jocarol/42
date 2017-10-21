/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:51:25 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:44:14 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_str;
	char	*save;

	if (s && f)
	{
		if (!(new_str = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		save = new_str;
		while (*s)
		{
			*new_str = f(*s);
			new_str++;
			s++;
		}
		*new_str = '\0';
		return (save);
	}
	return (NULL);
}
