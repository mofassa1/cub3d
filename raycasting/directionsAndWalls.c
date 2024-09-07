/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directionsAndWalls.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:20:07 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/27 19:01:23 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	ranging(int *x0, int *y0, int *x1, int *y1)
{
	if (*x0 < 0)
		*x0 = 0;
	if (*x0 > WIDTH)
		*x0 = WIDTH;
	if (*x1 < 0)
		*x1 = 0;
	if (*x1 > WIDTH)
		*x1 = WIDTH;
	if (*y0 < 0)
		*y0 = 0;
	if (*y0 > HEIGHT)
		*y0 = HEIGHT;
	if (*y1 < 0)
		*y1 = 0;
	if (*y1 > HEIGHT)
		*y1 = HEIGHT;
}

int	is_neer(t_cordonate *A, t_cordonate Player)
{
	double	dist;
	double	diff_x;
	double	diff_y;

	diff_x = A->x - Player.x;
	diff_y = A->y - Player.y;
	dist = sqrt(diff_x * diff_x + diff_y * diff_y);
	return (dist >= DISTDOOR);
}

int	is_wall(t_mlx *data, t_cordonate *A)
{
	long long	x;
	long long	y;
	char		**map;

	map = data->map_info.map;
	A->is_door = 0;
	x = A->x / SCALE;
	y = A->y / SCALE;
	if (x < 0 || y < 0 || x >= data->map_info.width
		|| y >= data->map_info.height || map[y][x] == '1')
		return (1);
	A->is_door = 0;
	if (map[y][x] == 'D' && is_neer(A, data->player))
	{
		A->is_door = 1;
		return (1);
	}
	return (0);
}

void	fillmouves(t_mlx *data)
{
	t_cordonate	sect;
	double		i;

	i = M_PI;
	sect = min_of(h_inter(data, i), v_inter(data, i));
	if (sect.x < 0 || sect.y < 0)
		sect = max_of(h_inter(data, i), v_inter(data, i));
	data->mouves.down = sect.dist;
	i = 0;
	sect = min_of(h_inter(data, i), v_inter(data, i));
	if (sect.x < 0 || sect.y < 0)
		sect = max_of(h_inter(data, i), v_inter(data, i));
	data->mouves.up = sect.dist;
	i = -1 * M_PI_2;
	sect = min_of(h_inter(data, i), v_inter(data, i));
	if (sect.x < 0 || sect.y < 0)
		sect = max_of(h_inter(data, i), v_inter(data, i));
	data->mouves.left = sect.dist;
	i = M_PI_2;
	sect = min_of(h_inter(data, i), v_inter(data, i));
	if (sect.x < 0 || sect.y < 0)
		sect = max_of(h_inter(data, i), v_inter(data, i));
	data->mouves.right = sect.dist;
}
