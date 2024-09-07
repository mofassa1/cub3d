/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PlayerHelpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:17:12 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/27 19:19:17 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	isplayer(char c)
{
	if (c == 'N' || c == 'S' \
		|| c == 'E' || c == 'W')
	{
		return (1);
	}
	return (0);
}

t_cordonate	getplayerposition(char **map)
{
	t_cordonate	pos;
	int			i;
	int			j;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (isplayer(map[i][j]))
			{
				pos.x = (j * SCALE) + 2;
				pos.y = (i * SCALE) + 2;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}
