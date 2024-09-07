/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:13:53 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/27 18:59:06 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	freeing(t_mlx *mlx_data)
{
	if (mlx_data->door.img)
		mlx_destroy_image(mlx_data->mlx, mlx_data->door.img);
	if (mlx_data->no.img)
		mlx_destroy_image(mlx_data->mlx, mlx_data->no.img);
	if (mlx_data->so.img)
		mlx_destroy_image(mlx_data->mlx, mlx_data->so.img);
	if (mlx_data->we.img)
		mlx_destroy_image(mlx_data->mlx, mlx_data->we.img);
	if (mlx_data->ea.img)
		mlx_destroy_image(mlx_data->mlx, mlx_data->ea.img);
	if (mlx_data->door.img)
		mlx_destroy_image(mlx_data->mlx, mlx_data->door.img);
	ft_free_two(mlx_data);
}

void	wall_texture_innit(t_mlx *mlx_data)
{
	mlx_data->door.img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/game_texture/1.xpm",
			&mlx_data->door.width, &mlx_data->door.height);
	if (!mlx_data->door.img)
		freeing(mlx_data);
	mlx_data->no.img = mlx_xpm_file_to_image(mlx_data->mlx,
			mlx_data->map_info.no, &mlx_data->no.width, &mlx_data->no.height);
	if (!mlx_data->no.img)
		freeing(mlx_data);
	mlx_data->so.img = mlx_xpm_file_to_image(mlx_data->mlx,
			mlx_data->map_info.so, &mlx_data->so.width, &mlx_data->so.height);
	if (!mlx_data->so.img)
		freeing(mlx_data);
	mlx_data->we.img = mlx_xpm_file_to_image(mlx_data->mlx,
			mlx_data->map_info.we, &mlx_data->we.width, &mlx_data->we.height);
	if (!mlx_data->we.img)
		freeing(mlx_data);
	mlx_data->ea.img = mlx_xpm_file_to_image(mlx_data->mlx,
			mlx_data->map_info.ea, &mlx_data->ea.width, &mlx_data->ea.height);
	if (!mlx_data->ea.img)
		freeing(mlx_data);
}

void	texture_init(t_mlx *mlx_data)
{
	wall_texture_innit(mlx_data);
	torch_texture_innit(mlx_data);
	get_img_addr(mlx_data);
}
