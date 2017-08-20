/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:51:16 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/10 00:42:08 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	cat_point;
	size_t	new_str;

	cat_point = ft_strlen(dst);
	new_str = ft_strlen(src) + (size < cat_point ? size : cat_point);
	dst += cat_point;
	while ((++cat_point) < size && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (new_str);
}
