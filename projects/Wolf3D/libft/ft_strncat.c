/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:51:48 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:43:48 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t cat_point;
	size_t j;

	j = 0;
	cat_point = ft_strlen(s1);
	while (s2[j] && j < n)
	{
		s1[cat_point] = s2[j];
		j++;
		cat_point++;
	}
	s1[cat_point] = '\0';
	return (s1);
}
