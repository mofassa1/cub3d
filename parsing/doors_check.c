/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 15:35:18 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/22 14:59:19 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	check_player_direction(t_mlx *mlx_data)
{
	int	i;
	int	j;

	j = 0;
	while (mlx_data->map_info.map[j])
	{
		i = 0;
		while (mlx_data->map_info.map[j][i])
		{
			if (mlx_data->map_info.map[j][i] == 'N')
				mlx_data->map_info.direction = (3. * M_PI) / 2.;
			else if (mlx_data->map_info.map[j][i] == 'W')
				mlx_data->map_info.direction = M_PI;
			else if (mlx_data->map_info.map[j][i] == 'S')
				mlx_data->map_info.direction = M_PI / 2.;
			else if (mlx_data->map_info.map[j][i] == 'E')
				mlx_data->map_info.direction = 0;
			i++;
		}
		j++;
	}
}

void	doors_check(t_mlx *mlx_data)
{
	int	i;
	int	j;

	i = -1;
	while (mlx_data->map_info.map[++i])
	{
		j = 0;
		while (mlx_data->map_info.map[i][j])
		{
			if (mlx_data->map_info.map[i][j] == 'D'
				&& ((mlx_data->map_info.map[i][j + 1] != '1'
					|| mlx_data->map_info.map[i][j - 1] != '1')
				&& (mlx_data->map_info.map[i + 1][j] != '1'
					|| mlx_data->map_info.map[i - 1][j] != '1')))
				ft_free_one(mlx_data, mlx_data->map_info.map[i], "Error");
			j++;
		}
	}
}
