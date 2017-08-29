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

#include "fdf.h"

void		zoom_in(t_env *env)
{
	ZOOM += 1;
}

void		zoom_out(t_env *env)
{
	ZOOM -= 1;
}

int			mouse(int button, void *param)
{
	eraser(param);
	if (button == 4)
		zoom_in(param);
	else if (button == 5)
		zoom_out(param);
	tracing(param);
	return (0);
}
