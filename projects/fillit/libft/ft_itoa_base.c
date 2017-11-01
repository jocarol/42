/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 02:14:22 by agrau             #+#    #+#             */
/*   Updated: 2017/01/22 09:13:53 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(int nb, int base)
{
	char	*str;
	size_t	len;
	char	*chars;

	chars = ft_strdup("0123456789abcdefghijklmnopqrstuvwxyz");
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_intlen_base(nb, base) + (nb < 0 ? 1 : 0);
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nb < 0)
		*str = '-';
	nb = ft_abs(nb);
	*(str + len) = '\0';
	while (len > 0 && nb != 0)
	{
		*(str + --len) = *(chars + (nb % base));
		nb = (nb - (nb % base)) / base;
	}
	return (str);
}
