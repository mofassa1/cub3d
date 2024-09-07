/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparaison.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:18:08 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/26 16:33:51 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_cordonate	min_of(t_cordonate H, t_cordonate V)
{
	if (H.dist < V.dist)
		return (H);
	return (V);
}

t_cordonate	max_of(t_cordonate H, t_cordonate V)
{
	if (H.dist > V.dist)
		return (H);
	return (V);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
