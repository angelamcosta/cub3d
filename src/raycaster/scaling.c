/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:57:58 by anlima            #+#    #+#             */
/*   Updated: 2023/12/28 20:39:53 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void		img_scaling(void);
static void	paint_texture(void);
static void	paint_line(int color);

void	img_scaling(void)
{
	if (map()->map[pos()->map_y][pos()->map_x] == '1')
		paint_texture();
	line()->y0 = 0;
	line()->y1 = pos()->draw_start;
	paint_line(win()->ceiling);
	line()->y0 = HEIGHT;
	line()->y1 = pos()->draw_end;
	paint_line(win()->floor);
}

void	paint_texture(void)

{
	t_img	*img;
	int		tex_x;

	img = &win()->north;
	if (pos()->side == EAST)
		img = &win()->east;
	else if (pos()->side == WEST)
		img = &win()->west;
	else if (pos()->side == SOUTH)
		img = &win()->south;
	tex_x = (int)(pos()->wall_x * (double)img->width);
	if ((pos()->side == WEST || pos()->side == EAST) && pos()->ray_dir_x > 0)
		tex_x = img->width - tex_x - 1;
	else if ((pos()->side == NORTH || pos()->side == SOUTH)
		&& pos()->ray_dir_y < 0)
		tex_x = img->width - tex_x - 1;
	line()->y0 = pos()->draw_start;
	line()->y1 = pos()->draw_end;
	line()->tex_x = tex_x;
	draw_texture_image(img);
}

void	paint_line(int color)
{
	int	i;
	int	j;

	if (line()->y0 < line()->y1)
	{
		i = line()->y0;
		j = line()->y1;
	}
	else
	{
		i = line()->y1;
		j = line()->y0;
	}
	if (i >= 0)
	{
		while (i < j)
			img_pix_put(line()->x, i++, color);
	}
}
