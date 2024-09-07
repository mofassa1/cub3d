/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:13:58 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/24 20:18:33 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	get_door_addr(t_mlx *mlx_data)
{
	mlx_data->door.addr = mlx_get_data_addr(mlx_data->door.img,
			&mlx_data->door.bits_per_pixel, &mlx_data->door.line_length,
			&mlx_data->door.endian);
	if (!mlx_data->door.addr)
		freeing(mlx_data);
}

void	eighth_door_frame(t_mlx *mlx_data, int frame)
{
	if (frame < 80)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/16.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 85)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/17.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 90)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/18.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
}

void	ninth_door_frame(t_mlx *mlx_data, int frame)
{
	if (frame < 95)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/19.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 100)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/20.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 105)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/21.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
}

int	tenth_door_frame(t_mlx *mlx_data, int frame)
{
	if (frame < 110)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/22.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 115)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/23.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
		if (frame == 114)
			frame = 0;
	}
	return (frame);
}
