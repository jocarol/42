/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/19 03:35:10 by jocarol           #+#    #+#             */
/*   Updated: 2017/06/21 10:31:21 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include "dirent.h"

#define bool char
#define TRUE 1
#define FALSE 0

typedef struct		s_flag
{
	bool			all;
	bool			list;
	bool			rec;
	bool			rev;
	bool			time;
}					t_flag;

typedef struct		s_item
{
	bool			isFile;
	bool			isDir;
	int				type;
	char			inode;
	char			*name;
	const char		*path;
	struct s_item	*nxt;
}					t_item;

void				display(t_item *item/*, t_flag flag*/);
void				ft_parse(int ac, char **av, t_flag *flag, t_item *item);

#endif
