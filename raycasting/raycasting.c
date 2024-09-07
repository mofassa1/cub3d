/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:31:10 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/27 10:49:54 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	raycasting(t_mlx *data)
{
	t_cordonate	intersection;
	double		i;
	double		wall;
	int			x;

	i = -0.523599;
	x = 0;
	fillmouves(data);
	drow_floor(data, data->floor.color);
	while (i <= 0.523599)
	{
		intersection = min_of(h_inter(data, i), v_inter(data, i));
		if (i <= 0.000409 && i >= -0.000410)
			data->face = intersection.view;
		wall = (SCALE / 3 * HEIGHT / intersection.dist) / cos(fabs(i));
		drow_ciell(data, x, (HEIGHT / 2) - wall + data->jump, data->ceil.color);
		putingtexture(data, wall, intersection, x);
		i += (M_PI / 3) / (WIDTH - 1.);
		x++;
	}
}

void	standardmap(t_mlx *data)
{
	raycasting(data);
	drowminimap(data);
	if (data->map_info.maptype == 1)
	{
		adddirection(data, MINIW, MINIH);
	}
	else
	{
		adddirection(data, MINIW2, MINIH2);
	}
	mlx_put_image_to_window(data->mlx, data->win3d, data->img3d, 0, 0);
}
