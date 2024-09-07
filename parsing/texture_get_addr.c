/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_get_addr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:40:31 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/27 18:59:06 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	wall_texture_get_img_addr(t_mlx *mlx_data)
{
	mlx_data->no.addr = mlx_get_data_addr(mlx_data->no.img,
			&mlx_data->no.bits_per_pixel, &mlx_data->no.line_length,
			&mlx_data->no.endian);
	if (!mlx_data->no.addr)
		freeing(mlx_data);
	mlx_data->we.addr = mlx_get_data_addr(mlx_data->we.img,
			&mlx_data->we.bits_per_pixel, &mlx_data->we.line_length,
			&mlx_data->we.endian);
	if (!mlx_data->we.addr)
		freeing(mlx_data);
	mlx_data->so.addr = mlx_get_data_addr(mlx_data->so.img,
			&mlx_data->so.bits_per_pixel, &mlx_data->so.line_length,
			&mlx_data->so.endian);
	if (!mlx_data->so.addr)
		freeing(mlx_data);
	mlx_data->ea.addr = mlx_get_data_addr(mlx_data->ea.img,
			&mlx_data->ea.bits_per_pixel, &mlx_data->ea.line_length,
			&mlx_data->ea.endian);
	if (!mlx_data->ea.addr)
		freeing(mlx_data);
	mlx_data->door.addr = mlx_get_data_addr(mlx_data->door.img,
			&mlx_data->door.bits_per_pixel, &mlx_data->door.line_length,
			&mlx_data->door.endian);
	if (!mlx_data->door.addr)
		freeing(mlx_data);
}

void	torch_texture_get_img_addr(t_mlx *mlx_data)
{
	int	i;

	i = 0;
	while (i < 12)
	{
		if (i == 2)
			i++;
		mlx_data->torch[i].addr = mlx_get_data_addr(mlx_data->torch[i].img,
				&mlx_data->torch[i].bits_per_pixel,
				&mlx_data->torch[i].line_length,
				&mlx_data->torch[i].endian);
		if (!mlx_data->torch[i].addr)
			freeing(mlx_data);
		i++;
	}
}

void	get_img_addr(t_mlx *mlx_data)
{
	wall_texture_get_img_addr(mlx_data);
	torch_texture_get_img_addr(mlx_data);
}
