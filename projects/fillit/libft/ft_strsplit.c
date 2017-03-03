/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 08:13:51 by agrau             #+#    #+#             */
/*   Updated: 2017/01/21 16:41:05 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbsplitby(char const *s, char c)
{
	int	i;

	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**dst;
	char	**ptr_dst;
	char	*ptr;
	int		n;

	if (s && c)
		n = ft_nbsplitby(s, c);
	if (!(s) || !(c) || !(dst = (char **)malloc(sizeof(char*) * (n + 1))))
		return (NULL);
	ptr_dst = dst;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0' && !(*ptr_dst = NULL))
			return (dst);
		n = (ft_strchr(s, c) ? ft_strchr(s, c) - s : ft_strlen(s));
		*(ptr_dst) = ft_strnew(n);
		ptr = *ptr_dst++;
		while (*s && *s != c)
			*ptr++ = *s++;
		*ptr = '\0';
	}
	*ptr_dst = NULL;
	return (dst);
}
