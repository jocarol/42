/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrau <agrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:14:55 by agrau             #+#    #+#             */
/*   Updated: 2017/01/22 12:56:08 by agrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *tmp_list;

	list = *alst;
	while (list)
	{
		tmp_list = list;
		del(list->content, list->content_size);
		free(list);
		list = tmp_list->next;
	}
	*alst = NULL;
}
