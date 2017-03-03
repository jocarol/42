/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:30:54 by agrau             #+#    #+#             */
/*   Updated: 2017/01/23 12:09:37 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *list;
	t_list *new_list;
	t_list *tmp_list;

	list = lst;
	new_list = NULL;
	while (list)
	{
		if (!(tmp_list = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		tmp_list = f(list);
		ft_lstadd_tail(&new_list, tmp_list);
		list = list->next;
	}
	return (new_list);
}
