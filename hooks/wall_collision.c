/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_collision.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:32:15 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/28 16:50:08 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	wall_distance(t_mlx *data, t_cordonate *step, int keycode)
{
	double	dist;
	double	dx;
	double	dy;

	dx = step->x - data->player.x;
	dy = step->y - data->player.y;
	dist = sqrt(dx * dx + dy * dy);
	if (keycode == W_KEY && dist < data->mouves.up - 3)
		return (1);
	if (keycode == S_KEY && dist < (data->mouves.down - 3))
		return (1);
	if (keycode == S_KEY && dist > (data->mouves.down - 3)
		&& dist > data->mouves.up - 3)
		return (1);
	if (keycode == D_KEY && dist < data->mouves.right - 3)
		return (1);
	if (keycode == A_KEY && dist < data->mouves.left - 3)
		return (1);
	return (0);
}

int	wall_collision_norm(t_mlx *data,
	t_cordonate *step, char **map)
{
	step->y -= sin(data->map_info.direction)
		* PLAYERVET;
	if (map[(long long)(step->y / SCALE)]
		[(long long)((step->x + 3) / SCALE)] == '1')
		return (0);
	if (map[(long long)(step->y / SCALE)]
		[(long long)((step->x - 3) / SCALE)] == '1')
		return (0);
	return (1);
}

int	wall_collision_norm_1(t_mlx *data,
	t_cordonate *step, char **map)
{
	step->x -= cos(data->map_info.direction)
		* PLAYERVET;
	if (map[(long long)((step->y + 3) / SCALE)]
		[(long long)(step->x / SCALE)] == '1')
		return (0);
	if (map[(long long)((step->y - 3) / SCALE)]
		[(long long)(step->x / SCALE)] == '1')
		return (0);
	return (1);
}

int	wall_collision(t_mlx *data, t_cordonate *step, int keycode, char **map)
{
	if (keycode == 119)
	{
		if (data->face == DOWN || data->face == UP)
		{
			if (wall_collision_norm(data, step, map))
				return (1);
		}
		else if (data->face == RIGHT || data->face == LEFT)
		{
			if (wall_collision_norm_1(data, step, map))
				return (1);
		}
	}
	return (0);
}

int	checkwalls(t_mlx *data, char **map, t_cordonate *step, int keycode)
{
	if (keycode != W_KEY && keycode != S_KEY
		&& keycode != D_KEY && keycode != A_KEY)
		return (0);
	if (wall_distance(data, step, keycode))
		return (1);
	if (wall_collision(data, step, keycode, map))
		return (1);
	return (0);
}
