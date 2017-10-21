/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:51:45 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:46:17 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	char			*save;
	unsigned int	i;

	if (s && f)
	{
		i = 0;
		new_str = ft_strnew(ft_strlen(s));
		if (!new_str)
			return (NULL);
		save = new_str;
		while (*s)
		{
			*new_str = f(i, *s);
			new_str++;
			s++;
			i++;
		}
		*new_str = '\0';
		return (save);
	}
	return (NULL);
}
