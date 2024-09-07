/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:21:47 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/28 12:54:09 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	floor_color_value(t_mlx *data)
{
	char	**split;

	split = ft_split(data->map_info.f, ',');
	if (!split)
	{
		printf("split faild");
		return (free_split(split), 0);
	}
	if (ft_strlen(split[0]) - 1 > 3 || ft_strlen(split[1]) - 1 > 3
		|| ft_strlen(split[2]) - 1 > 3
		|| ft_atoi(split[0]) > 255 || ft_atoi(split[1]) > 255
		|| ft_atoi(split[2]) > 255)
		return (free_split(split), 0);
	data->floor.r = ft_atoi(split[0]);
	data->floor.g = ft_atoi(split[1]);
	data->floor.b = ft_atoi(split[2]);
	data->floor.color = (data->floor.r << 16)
		| (data->floor.g << 8) | data->floor.b;
	return (free_split(split), 1);
}

int	ceil_color_value(t_mlx *data)
{
	char	**split;

	split = ft_split(data->map_info.c, ',');
	if (!split)
	{
		printf("split faild");
		return (free_split(split), 0);
	}
	if (ft_strlen(split[0]) - 1 > 3 || ft_strlen(split[1]) - 1 > 3
		|| ft_strlen(split[2]) - 1 > 3
		|| ft_atoi(split[0]) > 255 || ft_atoi(split[1]) > 255
		|| ft_atoi(split[2]) > 255)
		return (free_split(split), 0);
	data->ceil.r = ft_atoi(split[0]);
	data->ceil.g = ft_atoi(split[1]);
	data->ceil.b = ft_atoi(split[2]);
	data->ceil.color = (data->ceil.r << 16)
		| (data->ceil.g << 8) | data->ceil.b;
	return (free_split(split), 1);
}
