/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:52:32 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/09 23:52:33 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*str;

	if (!s)
		return (NULL);
	if (!(str = ft_strnew(len)))
		return (NULL);
	ft_memcpy(str, s + start, len);
	return (str);
}
