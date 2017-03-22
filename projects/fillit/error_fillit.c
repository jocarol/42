/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_fillit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocarol <jocarol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 02:58:11 by jocarol           #+#    #+#             */
/*   Updated: 2017/03/22 02:58:16 by jocarol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_check_size(char *tetri_data)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tetri_data[i])
	{
		if (tetri_data[i] == '\n')
		{
			i++;
			j++;
		}
		else
			i++;
	}
	if (j == 5 || j == 4 || i == 21)
		return (0);
	else
		return (1);
}

static int		ft_check_chars(char *tetri_char)
{
	int		i;
	int		point;
	int		tetro;
	int		nl;

	i = 0;
	point = 0;
	tetro = 0;
	nl = 0;
	while (tetri_char[i])
	{
		if (tetri_char[i] == '.')
			point++;
		else if (tetri_char[i] == '#')
			tetro++;
		else if (tetri_char[i] == '\n')
			nl++;
		else
			return (1);
		i++;
	}
	if (tetro != 4 || point != 12)
		return (1);
	else
		return (0);
}

static int		ft_check_nl(char *str)
{
	int		i;
	int		count;

	i = 4;
	count = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			count++;
		i += 5;
	}
	if (count != 4)
		return (1);
	else
		return (0);
}

static int		ft_check_ngb(char *str)
{
	int		i;
	int		ngb;

	i = 0;
	ngb = 0;
	while (str[i])
	{
		if (str[i] == '#')
		{
			if (str[i - 1] == '#' && i > 0)
				ngb++;
			if (str[i + 1] == '#' && i < 20)
				ngb++;
			if (str[i - 5] == '#' && i > 4)
				ngb++;
			if (str[i + 5] == '#' && i < 14)
				ngb++;
		}
		i++;
	}
	if (ngb == 6 || ngb == 8)
		return (0);
	else
		return (1);
}

int				ft_verif_tetri(char *str)
{
	if (!ft_check_size(str))
	{
		if (!ft_check_chars(str))
			if (!ft_check_nl(str))
				if (!ft_check_ngb(str))
					return (0);
	}
	return (1);
}
