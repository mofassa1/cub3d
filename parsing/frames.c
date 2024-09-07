/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frames.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:13:02 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/25 09:38:21 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	first_door_frame(t_mlx *mlx_data, int frame)
{
	if (frame < 5)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/1.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 10)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/2.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 15)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/3.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
}

void	second_door_frame(t_mlx *mlx_data, int frame)
{
	if (frame < 20)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/4.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 25)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/5.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 30)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/6.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
}

void	third_door_frame(t_mlx *mlx_data, int frame)
{
	if (frame < 35)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/7.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 40)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/8.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 45)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/9.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
}

void	fifth_door_frame(t_mlx *mlx_data, int frame)
{
	if (frame < 50)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/10.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 55)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/11.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 60)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/12.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
}

void	sixth_door_frame(t_mlx *mlx_data, int frame)
{
	if (frame < 65)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/13.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 70)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/14.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
	else if (frame < 75)
	{
		mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
				"./textures/game_texture/15.xpm", &mlx_data->door.width,
				&mlx_data->door.height);
		if (!mlx_data->door.img)
			freeing(mlx_data);
	}
}
