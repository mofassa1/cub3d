/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:18:02 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/27 17:32:05 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	map_height_width(t_mlx *mlx_data)
{
	int	max;
	int	len;

	max = 0;
	mlx_data->map_info.height = 0;
	while (mlx_data->map_info.map[mlx_data->map_info.height])
	{
		len = ft_strlen(mlx_data->map_info.map[mlx_data->map_info.height]);
		if (len >= max)
			max = len;
		mlx_data->map_info.height++;
	}
	if (mlx_data->map_info.height <= 2)
	{
		printf("map is so small can't fit\n");
		exit(1);
	}
	return (max);
}

void	check_player_count(t_mlx *mlx_data, int count)
{
	if (count != 1)
	{
		printf("invalid player count\n");
		ft_free_two(mlx_data);
	}
}

void	ft_free_two(t_mlx *mlx_data)
{
	free(mlx_data->map_info.mapstr);
	free_split(mlx_data->map_info.map);
	free_infos(mlx_data);
	free(mlx_data->map_info.line);
	close(mlx_data->map_file.fd);
	free(mlx_data->map_file.av);
	exit(1);
}

void	check_errors(t_mlx *mlx_data)
{
	if (!line_rules(mlx_data))
	{
		free(mlx_data->map_info.mapstr);
		ft_free_one(mlx_data, mlx_data->map_info.line,
			"invalid character in map");
	}
}

void	check_player_conditions(int x, int y, t_mlx *mlx_data)
{
	if (mlx_data->map_info.map[y][x] == 'N'
		|| mlx_data->map_info.map[y][x] == 'W'
		|| mlx_data->map_info.map[y][x] == 'S'
		|| mlx_data->map_info.map[y][x] == 'E')
	{
		if (!mlx_data->map_info.map[y + 1]
			|| (mlx_data->map_info.map[y + 1][x] != '1'
			&& mlx_data->map_info.map[y + 1][x] != '0'
			&& mlx_data->map_info.map[y + 1][x] != 'D')
			|| (mlx_data->map_info.map[y - 1][x] != '1'
			&& mlx_data->map_info.map[y - 1][x] != '0'
			&& mlx_data->map_info.map[y - 1][x] != 'D'))
		{
			printf("invalid player postion\n");
			ft_free_two(mlx_data);
		}
		mlx_data->vars.count++;
	}
}
