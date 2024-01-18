/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:29:47 by marvin            #+#    #+#             */
/*   Updated: 2024/01/18 18:39:29 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void		set_camera(void);
static void	set_camera_ns(void);
static void	set_camera_ew(void);
void		apply_texture(t_img *img, int x);

// applies the selected texture to the pixels of
// the vertical line representing a wall
void	apply_texture(t_img *img, int x)
{
	int	y;

	img->pos_x = (int)(pos()->wall_x * img->width);
	if ((pos()->side == 0 && pos()->ray_dir.x < 0) || (pos()->side == 1
			&& pos()->ray_dir.y > 0))
		img->pos_x = img->width - img->pos_x - 1;
	img->img_step = (double)img->width / pos()->line_height;
	img->img_pos = (pos()->draw_start - HEIGHT / 2 + pos()->line_height / 2)
		* img->img_step;
	y = pos()->draw_start;
	while (y < pos()->draw_end)
	{
		img->pos_y = (int)img->img_pos & (img->width - 1);
		img->img_pos += img->img_step;
		if (img->px_data[img->width * img->pos_y + img->pos_x] > 0)
			win()->pixel_data[y][x] = img->px_data[img->width * img->pos_y
			+ img->pos_x];
		y++;
	}
}

void	set_camera(void)
{
	if (map()->player == 'S' || map()->player == 'N')
		set_camera_ns();
	else if (map()->player == 'E' || map()->player == 'W')
		set_camera_ew();
}

static void	set_camera_ns(void)
{
	if (map()->player == 'S')
	{
		pos()->dir.x = 0;
		pos()->dir.y = 1;
		pos()->plane.x = -0.66;
		pos()->plane.y = 0;
	}
	else if (map()->player == 'N')
	{
		pos()->dir.x = 0;
		pos()->dir.y = -1;
		pos()->plane.x = 0.66;
		pos()->plane.y = 0;
	}
}

static void	set_camera_ew(void)
{
	if (map()->player == 'E')
	{
		pos()->dir.x = 1;
		pos()->dir.y = 0;
		pos()->plane.x = 0;
		pos()->plane.y = 0.66;
	}
	else if (map()->player == 'W')
	{
		pos()->dir.x = -1;
		pos()->dir.y = 0;
		pos()->plane.x = 0;
		pos()->plane.y = -0.66;
	}
}
