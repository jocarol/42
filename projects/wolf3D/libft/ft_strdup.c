/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:50:52 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:40:13 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_str;
	char	*save;

	new_str = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!new_str)
		return (NULL);
	save = new_str;
	while (*s1)
	{
		*new_str = *s1;
		new_str++;
		s1++;
	}
	*new_str = *s1;
	return (save);
}
