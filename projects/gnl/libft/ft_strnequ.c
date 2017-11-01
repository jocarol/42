/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:51:58 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/09 23:51:59 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((!s1 && s2) || (s1 && !s2))
		return (0);
	if ((!s1 && !s2) || !ft_strncmp(s1, s2, n))
		return (1);
	else
		return (0);
}
