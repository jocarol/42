/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:52:35 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/09 23:52:36 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	j;
	size_t	c;
	char	*str;

	if (s)
	{
		j = ft_strlen(s) - 1;
		i = 0;
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i])
			i++;
		while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > i)
			j--;
		if (j < i || !*s)
			return (ft_strnew(0));
		if (!(str = ft_strnew(j - i + 1)))
			return (NULL);
		c = 0;
		while (i <= j)
			str[c++] = s[i++];
		str[c] = '\0';
		return (str);
	}
	return (NULL);
}
