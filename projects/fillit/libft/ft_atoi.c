/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 20:52:17 by agrau             #+#    #+#             */
/*   Updated: 2017/01/19 18:25:40 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	nb;
	long	negativ;

	negativ = 1;
	nb = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	negativ = (*str == '-') ? -1 : 1;
	str = (*str == '-' || *str == '+') ? str + 1 : str;
	while (*str >= '0' && *str <= '9')
		nb = nb * 10 + *str++ - '0';
	return (nb * negativ);
}
