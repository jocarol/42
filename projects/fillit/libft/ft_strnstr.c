/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 08:33:20 by agrau             #+#    #+#             */
/*   Updated: 2017/01/21 19:19:51 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *str, char *to_find, size_t n)
{
	char *ptr_str;
	char *ptr_to_find;

	if (*to_find == 0)
		return (str);
	while (*str && n--)
	{
		ptr_str = str;
		ptr_to_find = to_find;
		while (*ptr_str && ptr_str <= str + n && *ptr_to_find == *ptr_str)
		{
			ptr_to_find++;
			ptr_str++;
			if (*ptr_to_find == '\0')
				return (str);
		}
		str++;
	}
	return (NULL);
}
