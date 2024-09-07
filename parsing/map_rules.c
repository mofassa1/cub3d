/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rules.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 12:03:08 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/27 17:32:55 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	check_player(t_mlx *mlx_data)
{
	int	x;
	int	y;

	mlx_data->vars.count = 0;
	y = 0;
	while (mlx_data->map_info.map[y])
	{
		x = 0;
		while (mlx_data->map_info.map[y][x])
		{
			check_player_conditions(x, y, mlx_data);
			x++;
		}
		y++;
	}
	check_player_count(mlx_data, mlx_data->vars.count);
}

void	check_empty_blocks(t_mlx *mlx_data)
{
	int	x;
	int	y;

	y = 1;
	x = 0;
	while (y < mlx_data->map_info.height - 1)
	{
		x = 0;
		while (mlx_data->map_info.map[y][x])
		{
			if (mlx_data->map_info.map[y][x] == '0'
				|| mlx_data->map_info.map[y][x] == 'D')
			{
				if (!ft_strchr("10NWSED", mlx_data->map_info.map[y - 1][x])
					|| !ft_strchr("10NWSED", mlx_data->map_info.map[y + 1][x]))
				{
					printf("map should be surrounded by walls\n");
					ft_free_two(mlx_data);
				}
			}
			x++;
		}
		y++;
	}
}

void	check_line(t_mlx *mlx_data, char **split)
{
	int	i;
	int	length;
	int	x;

	i = 0;
	while (split[i])
	{
		x = 0;
		while (split[i][x])
		{
			length = ft_strlen(split[i]) - 1;
			if ((split[i][x] == '0' || split[i][x] == 'N'
				|| split[i][x] == 'S' || split[i][x] == 'E'
				|| split[i][x] == 'W' || split[i][x] == 'D')
				&& (x == 0 || mlx_data->vars.y == 0 || x == length
				|| mlx_data->vars.y == mlx_data->map_info.height - 1))
			{
				printf("map should be surrounded walls 1\n");
				free_split(split);
				ft_free_two(mlx_data);
			}
			x++;
		}
		i++;
	}
}

void	surrounded_by_wall_check(t_mlx *mlx_data)
{
	int		i;
	char	**split;

	i = 0;
	mlx_data->vars.y = 0;
	while (mlx_data->map_info.map[mlx_data->vars.y])
	{
		split = ft_split(mlx_data->map_info.map[mlx_data->vars.y], ' ');
		if (!split)
			ft_free_two(mlx_data);
		check_line(mlx_data, split);
		free_split(split);
		i = 0;
		mlx_data->vars.y++;
	}
}

void	map_rules(t_mlx *mlx_data)
{
	mlx_data->map_info.map = ft_split(mlx_data->map_info.mapstr, '\n');
	if (!mlx_data->map_info.map)
	{
		free(mlx_data->map_info.mapstr);
		ft_free_one(mlx_data, mlx_data->map_info.mapstr, "split failed\n");
	}
	mlx_data->map_info.height = ft_arrlen(mlx_data->map_info.map) - 1;
	mlx_data->map_info.width = map_height_width(mlx_data);
	surrounded_by_wall_check(mlx_data);
	check_empty_blocks(mlx_data);
	check_player(mlx_data);
}
