/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 18:54:32 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/27 17:34:49 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	torch_puts(t_mlx *mlx_data, int pic_num, int up)
{
	int	i;
	int	x;
	int	color;

	i = 0;
	while (i < 800)
	{
		x = 0;
		while (x < 800)
		{
			color = get_texel(mlx_data->torch[pic_num], x, i);
			if (color != 0 && color != -16777216)
				my_mlx_pixel_put(mlx_data, x - 400, i + up, color);
			x++;
		}
		i++;
	}
}

int	frame_num_one(t_mlx *mlx_data, int frame)
{
	if (frame < 5)
		torch_puts(mlx_data, 0, 50);
	else if (frame < 10)
		torch_puts(mlx_data, 1, 55);
	else if (frame < 15)
		torch_puts(mlx_data, 3, 60);
	else if (frame < 20)
		torch_puts(mlx_data, 4, 65);
	else if (frame < 25)
		torch_puts(mlx_data, 5, 70);
	else if (frame < 30)
		torch_puts(mlx_data, 6, 65);
	return (frame);
}

int	frame_num_two(t_mlx *mlx_data, int frame)
{
	if (frame < 35)
		torch_puts(mlx_data, 7, 60);
	else if (frame < 40)
	{
		torch_puts(mlx_data, 8, 55);
		if (frame == 39)
			frame = 0;
	}
	return (frame);
}

int	torch_animation(t_mlx *mlx_data)
{
	static int	frame;

	if (frame < 30)
		frame = frame_num_one(mlx_data, frame);
	else if (frame < 40)
		frame = frame_num_two(mlx_data, frame);
	frame++;
	return (0);
}

int	gate_animation(t_mlx *mlx_data)
{
	static int	frame = 0;

	mlx_destroy_image(mlx_data->mlx, mlx_data->door.img);
	if (frame < 15)
		first_door_frame(mlx_data, frame);
	else if (frame < 30)
		second_door_frame(mlx_data, frame);
	else if (frame < 45)
		third_door_frame(mlx_data, frame);
	else if (frame < 60)
		fifth_door_frame(mlx_data, frame);
	else if (frame < 75)
		sixth_door_frame(mlx_data, frame);
	else if (frame < 90)
		eighth_door_frame(mlx_data, frame);
	else if (frame < 100)
		ninth_door_frame(mlx_data, frame);
	else if (frame < 115)
		frame = tenth_door_frame(mlx_data, frame);
	get_door_addr(mlx_data);
	frame++;
	return (0);
}
