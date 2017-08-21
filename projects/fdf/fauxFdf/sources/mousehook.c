/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 15:47:23 by jocarol           #+#    #+#             */
/*   Updated: 2017/08/21 16:03:43 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		zoom_in(t_env *env)
{
	ZOOM += 1;
}

void		zoom_out(t_env *env)
{
	ZOOM -= 1;
}

int			mouse(int button, int x, int y, void *param)
{
	cleaner(param);
	if (button == 4)
		zoom_in(param);
	else if (button == 5)
		unzoom(param);
	painter(param);
	return (0);
}
