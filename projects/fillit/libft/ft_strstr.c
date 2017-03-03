/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 08:33:20 by agrau             #+#    #+#             */
/*   Updated: 2017/01/19 18:21:54 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char *ptr_str;
	char *ptr_to_find;

	if (*to_find == 0)
		return (str);
	while (*str)
	{
		ptr_str = str;
		ptr_to_find = to_find;
		while (*ptr_to_find++ == *ptr_str++)
			if (*ptr_to_find == 0)
				return (str);
		str++;
	}
	return (0);
}
