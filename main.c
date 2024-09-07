/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afadouac <afadouac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 17:13:00 by ousabbar          #+#    #+#             */
/*   Updated: 2024/07/28 16:28:04 by afadouac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char *av[])
{
	t_mlx	mlx_data;

	if (ac != 2 || ft_check_extension((char *)av[1], ".cub") == 0)
		return (printf("invalid argument\n"), 1);
	mlx_data.map_file.av = ft_strdup(av[1]);
	mlx_data.mlx = mlx_init();
	parsing(&mlx_data);
	initialize(&mlx_data);
	mlx_data.player = getplayerposition(mlx_data.map_info.map);
	mlx_loop_hook(mlx_data.mlx, mouse_move, &mlx_data);
	mlx_hook(mlx_data.win3d, 2, 1l >> 0, key_hook, &mlx_data);
	mlx_hook(mlx_data.win3d, 17, 0, close_win, &mlx_data);
	mlx_clear_window(mlx_data.mlx, mlx_data.win3d);
	mlx_loop(mlx_data.mlx);
	free(mlx_data.map_file.av);
	free_infos(&mlx_data);
	free(mlx_data.map_info.mapstr);
	free_split(mlx_data.map_info.map);
	return (0);
}
