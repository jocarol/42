/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 01:22:02 by agrau             #+#    #+#             */
/*   Updated: 2017/01/23 12:51:02 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		len;
	int		begin;
	int		end;
	char	*dst;

	dst = NULL;
	if (s)
	{
		begin = 0;
		end = 0;
		len = (ft_strlen(s));
		while (ft_isspace(*(s + begin)))
			begin++;
		while (ft_isspace(*(s + (len - end) - 1)))
			end++;
		if (end == len || begin == len)
			return (ft_strdup("\0"));
		if ((dst = ft_strnew(len - end - begin)))
			ft_strncpy(dst, s + begin, len - end - begin);
	}
	return (dst);
}
