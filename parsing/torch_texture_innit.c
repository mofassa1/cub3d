/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch_texture_innit.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:35:25 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/22 17:26:44 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	torch_texture_innit_part_one(t_mlx *mlx_data)
{
	mlx_data->torch[0].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch1.xpm", &mlx_data->torch[0].width,
			&mlx_data->torch[0].height);
	if (!mlx_data->torch[0].img)
		freeing(mlx_data);
	mlx_data->torch[1].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch2.xpm", &mlx_data->torch[1].width,
			&mlx_data->torch[1].height);
	if (!mlx_data->torch[1].img)
		freeing(mlx_data);
	mlx_data->torch[3].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch4.xpm", &mlx_data->torch[3].width,
			&mlx_data->torch[3].height);
	if (!mlx_data->torch[3].img)
		freeing(mlx_data);
}

void	torch_texture_innit_part_two(t_mlx *mlx_data)
{
	mlx_data->torch[4].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch5.xpm", &mlx_data->torch[4].width,
			&mlx_data->torch[4].height);
	if (!mlx_data->torch[4].img)
		freeing(mlx_data);
	mlx_data->torch[5].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch6.xpm", &mlx_data->torch[5].width,
			&mlx_data->torch[5].height);
	if (!mlx_data->torch[5].img)
		freeing(mlx_data);
	mlx_data->torch[6].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch7.xpm", &mlx_data->torch[6].width,
			&mlx_data->torch[6].height);
	if (!mlx_data->torch[6].img)
		freeing(mlx_data);
	mlx_data->torch[7].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch8.xpm", &mlx_data->torch[7].width,
			&mlx_data->torch[7].height);
	if (!mlx_data->torch[7].img)
		freeing(mlx_data);
	mlx_data->torch[8].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch9.xpm", &mlx_data->torch[8].width,
			&mlx_data->torch[8].height);
	if (!mlx_data->torch[8].img)
		freeing(mlx_data);
}

void	torch_texture_innit_part_three(t_mlx *mlx_data)
{
	mlx_data->torch[9].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch10.xpm", &mlx_data->torch[9].width,
			&mlx_data->torch[9].height);
	if (!mlx_data->torch[9].img)
		freeing(mlx_data);
	mlx_data->torch[10].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch11.xpm", &mlx_data->torch[10].width,
			&mlx_data->torch[10].height);
	if (!mlx_data->torch[10].img)
		freeing(mlx_data);
	mlx_data->torch[11].img = mlx_xpm_file_to_image(mlx_data->mlx,
			"./textures/torch/torch12.xpm", &mlx_data->torch[11].width,
			&mlx_data->torch[11].height);
	if (!mlx_data->torch[11].img)
		freeing(mlx_data);
}

void	torch_texture_innit(t_mlx *mlx_data)
{
	torch_texture_innit_part_one(mlx_data);
	torch_texture_innit_part_two(mlx_data);
	torch_texture_innit_part_three(mlx_data);
}
