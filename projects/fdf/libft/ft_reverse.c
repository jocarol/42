/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 19:56:11 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/12 19:58:31 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reverse(char *s)
{
	int		slen;
	int		j;

	if (s != NULL)
	{
		slen = ft_strlen(s) - 1;
		j = 0;
		while (j < slen)
		{
			ft_swap(&s[j], &s[slen]);
			j++;
			slen--;
		}
	}
}
