/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drowers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:14:54 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/27 21:35:25 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	shadding(unsigned int color, double dist, int factor)
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;

	dist /= DARKFACTOR * factor;
	if (dist > 255)
		dist = 255;
	if (dist < 1.1)
		dist = 1.1;
	r = ((color >> 16) & 0xFF) / dist;
	g = ((color >> 8) & 0xFF) / dist;
	b = (color & 0xFF) / dist;
	return ((r << 16) | (g << 8) | b);
}

void	drow_floor(t_mlx *mlx, int color)
{
	double	dist;
	int		x;
	int		y;
	int		collor;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			dist = sqrt((x - (WIDTH / 2) + WIDTH / 4)
					* (x - (WIDTH / 2) + WIDTH / 4)
					+ (y - HEIGHT) * (y - HEIGHT));
			collor = shadding(color, dist, 8);
			my_mlx_pixel_put(mlx, x, y, collor);
			x++;
		}
		y++;
	}
}

void	drow_ciell(t_mlx *mlx, int x, int y, int color)
{
	double	pos;

	pos = 0;
	while (pos < y)
	{
		my_mlx_pixel_put(mlx, x, pos, color);
		pos++;
	}
}
