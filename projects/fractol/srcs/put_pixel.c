/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 06:48:27 by jocarol           #+#    #+#             */
/*   Updated: 2017/10/25 07:43:30 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_pixel(t_env *z, int x, int y, int color)
{
	int		i;

	if (x >= IMG_SIZE || y >= IMG_SIZE || x < 0 || y < 0)
		return ;
	i = z->linesize * y + x * (z->bpp / 8);
	z->data[i] = color & 0xff;
	z->data[++i] = color >> 8 & 0xff;
	z->data[++i] = color >> 16;
}
