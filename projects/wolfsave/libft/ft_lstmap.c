/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 23:48:27 by jocarol           #+#    #+#             */
/*   Updated: 2017/01/09 23:48:45 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*newlst;
	t_list	*save;
	t_list	*prev;

	if (!lst)
		return (NULL);
	save = NULL;
	prev = NULL;
	while (lst)
	{
		newlst = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		if (!newlst)
			return (NULL);
		if (prev)
			prev->next = newlst;
		if (save == NULL)
			save = newlst;
		prev = newlst;
		lst = lst->next;
	}
	return (save);
}
