/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ousabbar <ousabbar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 23:11:27 by afadouac          #+#    #+#             */
/*   Updated: 2024/07/27 21:06:35 by ousabbar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	get_texel(t_texture texture, int x, int y)
{
	char	*pixel;

	if (x < 0 || y < 0 || x >= texture.width || y >= texture.height)
		return (0);
	pixel = texture.addr + (y * texture.line_length + x * \
		(texture.bits_per_pixel / 8));
	return (*(unsigned int *)pixel);
}

t_texture	*init_texture(t_mlx *data, t_cordonate Intersection)
{
	t_texture	*tex;
	int			i;
	int			numb;

	if (Intersection.is_door == 1)
		numb = 2;
	else
		numb = 1;
	tex = malloc(sizeof(t_texture) * numb);
	i = 0;
	while (i < numb)
	{
		if (Intersection.view == UP)
			tex[i] = data->no;
		else if (Intersection.view == DOWN)
			tex[i] = data->so;
		else if (Intersection.view == LEFT)
			tex[i] = data->ea;
		else if (Intersection.view == RIGHT)
			tex[i] = data->we;
		i++;
	}
	if (Intersection.is_door == 1)
		tex[1] = data->door;
	return (tex);
}

int	puttexel(t_texture *texture,
	t_cordonate tex_cord[], int is_door)
{
	int	color[2];

	color[0] = get_texel(texture[0], tex_cord[0].x, tex_cord[0].y);
	if (is_door == 1)
	{
		color[1] = get_texel(texture[1], tex_cord[1].x, tex_cord[1].y);
		color[0] = max(color[0], color[1]);
	}
	return (color[0]);
}

void	init_texture_coords(t_cordonate Intersection,
	t_texture *textures, t_cordonate tex_cord[2])
{
	if (Intersection.view == LEFT || Intersection.view == RIGHT)
	{
		tex_cord[0].x = fabs(fmod(Intersection.y, SCALE) / SCALE)
			* textures[0].width;
		if (Intersection.is_door == 1)
			tex_cord[1].x = fabs(fmod(Intersection.y, SCALE) / SCALE)
				* textures[1].width;
	}
	else
	{
		tex_cord[0].x = fabs(fmod(Intersection.x, SCALE) / SCALE)
			* textures[0].width;
		if (Intersection.is_door == 1)
			tex_cord[1].x = fabs(fmod(Intersection.x, SCALE) / SCALE)
				* textures[1].width;
	}
}

void	putingtexture(t_mlx *data, double wall, t_cordonate Intersection, int x)
{
	int			color;
	t_cordonate	tex_cord[2];
	t_cordonate	point;
	t_texture	*textuere;

	textuere = init_texture(data, Intersection);
	init_texture_coords(Intersection, textuere, tex_cord);
	point.x = (HEIGHT / 2) - wall + data->jump;
	point.y = 0;
	while (point.x < (HEIGHT / 2) + wall + data->jump)
	{
		tex_cord[0].y = (point.y * textuere[0].height) / (2 * wall);
		if (Intersection.is_door == 1)
			tex_cord[1].y = (point.y * textuere[1].height) / (2 * wall);
		color = puttexel(textuere, tex_cord, Intersection.is_door);
		color = shadding(color, Intersection.dist, 1);
		my_mlx_pixel_put(data, x, point.x, color);
		point.x++;
		point.y++;
	}
	free(textuere);
}
