/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrumbac <agrumbac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 17:11:27 by agrumbac          #+#    #+#             */
/*   Updated: 2016/12/25 09:17:41 by agrumbac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_intlen(int n)
{
	if (n == -2147483648)
		return (11);
	if (n < 0)
		return (1 + ft_intlen(-n));
	if (n < 10)
		return (1);
	else
		return (1 + ft_intlen(n / 10));
}