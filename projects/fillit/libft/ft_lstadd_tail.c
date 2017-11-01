/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_tail.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/22 11:25:26 by agrau             #+#    #+#             */
/*   Updated: 2017/01/23 12:17:32 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_tail(t_list **alst, t_list *new)
{
	t_list *list;

	if (!*alst)
		*alst = new;
	else
	{
		list = *alst;
		while (list->next)
			list = list->next;
		list->next = new;
	}
}
