/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:06:05 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/24 21:15:45 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*pixel;

	if (x < 0 || y < 0)
		return ;
	if (x > WIDTH || y > HEIGHT)
		return ;
	pixel = data->addr3d + (y * data->line_length3d + x * \
		(data->bits_per_pixel3d / 8));
	*(unsigned int *)pixel = color;
}
