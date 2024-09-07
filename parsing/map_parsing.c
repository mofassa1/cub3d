/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 14:21:28 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/16 16:44:20 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	line_rules(t_mlx *mlx_data)
{
	int	i;

	i = -1;
	while (mlx_data->map_info.line[++i])
	{
		if (!ft_strchr("10NSEWD \n", mlx_data->map_info.line[i]))
			return (0);
	}
	mlx_data->map_info.mapstr = ft_strjoin(mlx_data->map_info.mapstr,
			mlx_data->map_info.line);
	return (1);
}

void	parsing_map(t_mlx *mlx_data)
{
	mlx_data->map_info.map_index = 0;
	mlx_data->map_info.mapstr = NULL;
	while (!ft_strcmp(mlx_data->map_info.line, "\n"))
	{
		free(mlx_data->map_info.line);
		mlx_data->map_info.line = get_next_line(mlx_data->map_file.fd);
	}
	if (!mlx_data->map_info.line)
		ft_free_one(mlx_data, mlx_data->map_info.line, "no map");
	while (1)
	{
		check_errors(mlx_data);
		free(mlx_data->map_info.line);
		mlx_data->map_info.line = get_next_line(mlx_data->map_file.fd);
		if (!mlx_data->map_info.line)
			break ;
	}
	map_rules(mlx_data);
}
