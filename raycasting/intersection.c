/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:13:21 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/27 19:01:23 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_cordonate	init_h_intersection(t_cordonate P, double angle, t_cordonate *deff)
{
	t_cordonate	a;

	if (tan(angle) == 0)
	{
		a.x = 0;
		a.y = 0;
		a.dist = INT_MAX * 1.;
		return (a);
	}
	if (angle >= 0 && angle < M_PI)
	{
		a.view = DOWN;
		a.y = floor(P.y / SCALE) * SCALE + SCALE;
		deff->y = SCALE;
	}
	else
	{
		a.view = UP;
		a.y = floor(P.y / SCALE) * SCALE - 0.0000001;
		deff->y = -1 * SCALE;
	}
	a.x = ((a.y - P.y) / tan(angle)) + P.x;
	deff->x = deff->y / tan(angle);
	return (a);
}

t_cordonate	h_inter(t_mlx *data, double angle_dif)
{
	t_cordonate	a;
	t_cordonate	p;
	t_cordonate	deff;
	double		angle;

	p.x = data->player.x ;
	p.y = data->player.y ;
	angle = (data->map_info.direction + angle_dif);
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	a.view = angle;
	a = init_h_intersection(p, angle, &deff);
	a.x = ((a.y - p.y) / tan (angle)) + p.x;
	deff.x = deff.y / tan(angle);
	while (!is_wall(data, &a))
	{
		a.x += deff.x;
		a.y += deff.y;
	}
	a.dist = sqrt((a.x - p.x) * (a.x - p.x) + (a.y - p.y) * (a.y - p.y));
	return (a);
}

void	init_v_intersection(t_cordonate P,
	double angle, t_cordonate *A, t_cordonate *deff)
{
	if (angle > M_PI_2 && angle < 3 * M_PI_2)
	{
		A->view = LEFT;
		deff->x = -1 * SCALE;
		A->x = floor(P.x / SCALE) * SCALE - 0.0000001;
	}
	else
	{
		A->view = RIGHT;
		deff->x = SCALE;
		A->x = floor(P.x / SCALE) * SCALE + SCALE;
	}
	A->y = P.y - (P.x - A->x) * tan(angle);
	deff->y = deff->x * tan(angle);
}

t_cordonate	v_inter(t_mlx *data, double angle_dif)
{
	t_cordonate	a;
	t_cordonate	p;
	t_cordonate	deff;
	double		angle;

	p.x = data->player.x ;
	p.y = data->player.y ;
	angle = (data->map_info.direction + angle_dif);
	if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	init_v_intersection(p, angle, &a, &deff);
	a.y = p.y - (p.x - a.x) * tan(angle);
	deff.y = deff.x * tan(angle);
	while (!is_wall(data, &a))
	{
		a.x += deff.x;
		a.y += deff.y;
	}
	a.dist = sqrt((a.x - p.x) * (a.x - p.x) + (a.y - p.y) * (a.y - p.y));
	return (a);
}
