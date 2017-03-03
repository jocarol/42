/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 16:36:36 by agrau             #+#    #+#             */
/*   Updated: 2017/01/13 02:13:15 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	char	*str_dup;
	char	*ptr_str_dup;

	if (!(str_dup = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	ptr_str_dup = str_dup;
	while (*str)
		*(ptr_str_dup++) = *(str++);
	*ptr_str_dup = '\0';
	return (str_dup);
}
