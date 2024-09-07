/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 10:44:17 by oussama           #+#    #+#             */
/*   Updated: 2024/07/28 11:38:28 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	parse_color(char **texture, t_mlx *mlx_data)
{
	if (!ft_strncmp(texture[0], "F", 1))
	{
		if (mlx_data->map_info.f || !texture[1] || !ft_strcmp(texture[1], "\n")
			|| !check_rgb(texture[1]))
			return (printf("no texture for F "), 0);
		mlx_data->map_info.texture_number++;
		mlx_data->map_info.f = ft_strdup(texture[1]);
		if (!floor_color_value(mlx_data))
			return (0);
		return (1);
	}
	else if (!ft_strncmp(texture[0], "C", 2))
	{
		if (mlx_data->map_info.c || !texture[1] || !ft_strcmp(texture[1], "\n")
			|| !check_rgb(texture[1]))
			return (printf("no texture for C "), 0);
		mlx_data->map_info.texture_number++;
		mlx_data->map_info.c = ft_strdup(texture[1]);
		if (!ceil_color_value(mlx_data))
			return (0);
		return (1);
	}
	return (0);
}

int	parse_texture_part_one(char **texture, t_mlx *mlx_data)
{
	if (!ft_strncmp(texture[0], "NO", 2))
	{
		if (mlx_data->map_info.no || !texture[1]
			|| !ft_strcmp(texture[1], "\n"))
			return (printf("no texture for NO "), 0);
		mlx_data->map_info.texture_number++;
		texture[1][ft_strlen(texture[1]) - 1] = '\0';
		if (open(texture[1], O_RDWR) == -1)
			return (0);
		mlx_data->map_info.no = ft_strdup(texture[1]);
		return (1);
	}
	if (!ft_strncmp(texture[0], "SO", 2))
	{
		if (mlx_data->map_info.so || !texture[1]
			|| !ft_strcmp(texture[1], "\n"))
			return (printf("no texture for SO "), 0);
		mlx_data->map_info.texture_number++;
		texture[1][ft_strlen(texture[1]) - 1] = '\0';
		if (open(texture[1], O_RDWR) == -1)
			return (0);
		mlx_data->map_info.so = ft_strdup(texture[1]);
		return (1);
	}
	return (0);
}

int	parst_texture_part_two(char **texture, t_mlx *mlx_data)
{
	if (!ft_strncmp(texture[0], "WE", 2))
	{
		if (mlx_data->map_info.we || !texture[1]
			|| !ft_strcmp(texture[1], "\n"))
			return (printf("no texture for WE "), 0);
		mlx_data->map_info.texture_number++;
		texture[1][ft_strlen(texture[1]) - 1] = '\0';
		if (open(texture[1], O_RDWR) == -1)
			return (0);
		mlx_data->map_info.we = ft_strdup(texture[1]);
		return (1);
	}
	if (!ft_strncmp(texture[0], "EA", 2))
	{
		if (mlx_data->map_info.ea || !texture[1]
			|| !ft_strcmp(texture[1], "\n"))
			return (printf("no texture for EA "), 0);
		mlx_data->map_info.texture_number++;
		texture[1][ft_strlen(texture[1]) - 1] = '\0';
		if (open(texture[1], O_RDWR) == -1)
			return (0);
		mlx_data->map_info.ea = ft_strdup(texture[1]);
		return (1);
	}
	return (0);
}

int	parse_texture(char **texture, t_mlx *mlx_data)
{
	if (parse_texture_part_one(texture, mlx_data))
		return (1);
	if (parst_texture_part_two(texture, mlx_data))
		return (1);
	return (0);
}

void	parse_line(t_mlx *mlx_data, char *line)
{
	char	**texture;

	if (!ft_strcmp(line, "\n"))
		return ;
	texture = ft_split(line, ' ');
	if (!texture)
		ft_free_one(mlx_data, line, "split failed");
	if ((!parse_texture(texture, mlx_data)
			&& !parse_color(texture, mlx_data)) || texture[2])
	{
		free_split(texture);
		ft_free_one(mlx_data, line, "invalid texture");
	}
	free_split(texture);
}
