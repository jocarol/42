/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 18:19:02 by agrau             #+#    #+#             */
/*   Updated: 2017/01/19 17:35:34 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;

	dst = NULL;
	i = 0;
	if (s && f)
		if ((dst = ft_strnew(ft_strlen(s))))
			while (*(s + i))
			{
				*(dst + i) = f(*(s + i));
				i++;
			}
	return (dst);
}
