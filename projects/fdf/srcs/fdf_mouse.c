/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mouse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 12:02:12 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/23 12:35:00 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"

void		zoom(t_env *env)
{
	ZOOM += 1;
}

void		unzoom(t_env *env)
{
	if (ZOOM > 1)
		ZOOM -= 1;
}

int			mouse(int button, int x, int y, void *param)
{
	(void)x;
	(void)y;
	eraser(param);
	if (button == 4)
		zoom(param);
	else if (button == 5)
		unzoom(param);
	tracing(param);
	return (0);
}
