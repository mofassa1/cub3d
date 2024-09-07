/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:10:07 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/27 19:01:23 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	adddirection(t_mlx *data, int w, int h)
{
	t_cordonate	player;
	int			n;

	player.x = WIDTH - w / 2 - 5;
	player.y = HEIGHT - h / 2 - 5;
	n = 0;
	while (n < 20)
	{
		player.x += cos(data->map_info.direction);
		player.y += sin(data->map_info.direction);
		my_mlx_pixel_put(data, player.x, player.y, 0xFF);
		n++;
	}
}

int	is_in_range(t_cordonate Player, int maptype, int i, int j)
{
	int	w;
	int	h;

	if (maptype == 1)
	{
		w = MINIW;
		h = MINIH;
	}
	else
	{
		w = MINIW2;
		h = MINIH2;
	}
	return (i >= Player.y - h / 2 && i <= Player.y + h / 2
		&& j >= Player.x - w / 2 && j <= Player.x + w / 2);
}

void	fill_wh(t_cordonate *WH, int maptype)
{
	if (maptype == 1)
	{
		WH->x = MINIW;
		WH->y = MINIH;
	}
	else
	{
		WH->x = MINIW2;
		WH->y = MINIH2;
	}
}

void	putcolortomini(t_mlx *data, int i, int j)
{
	t_cordonate	wh;
	int			x;
	int			y;

	fill_wh(&wh, data->map_info.maptype);
	x = j - (data->player.x - wh.x / 2) + WIDTH - wh.x - 5;
	y = i - (data->player.y - wh.y / 2) + HEIGHT - wh.y - 5;
	if (i % SCALE == 0 || j % SCALE == 0)
		my_mlx_pixel_put(data, x, y, GRAY);
	else if (i >= data->player.y - 2 && i <= data->player.y + 2
		&& j >= data->player.x - 2 && j <= data->player.x + 2)
		my_mlx_pixel_put(data, x, y, 0xEE1D1D);
	else if (data->map_info.map[i / SCALE][j / SCALE] == '1')
		my_mlx_pixel_put(data, x, y, 0x00ff);
	else if ((i / SCALE) < data->map_info.height
		&& (j / SCALE) < data->map_info.width
		&& data->map_info.map[i / SCALE][j / SCALE] == '1')
		my_mlx_pixel_put(data, x, y, 0x00ff);
	else if (data->map_info.map[i / SCALE][j / SCALE] == '0'
			|| isplayer(data->map_info.map[i / SCALE][j / SCALE]))
		my_mlx_pixel_put(data, x, y, 0xFFFFFF);
	else if (data->map_info.map[i / SCALE][j / SCALE] == 'D')
		my_mlx_pixel_put(data, x, y, 0x00FFFF);
	else
		my_mlx_pixel_put(data, x, y, 0x0);
}

void	drowminimap(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_info.height * SCALE)
	{
		j = 0;
		while (j < data->map_info.width * SCALE)
		{
			if (is_in_range(data->player, data->map_info.maptype, i, j))
				putcolortomini(data, i, j);
			j++;
		}
		i++;
	}
}
