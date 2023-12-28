/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:45:48 by anlima            #+#    #+#             */
/*   Updated: 2023/12/28 20:28:19 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void		raycaster(void);
static void	dda(void);
static void	step(void);
static void	init_raycasting(void);
static void	calculate_height(void);

// draw those textures
void	raycaster(void)
{
	init_raycasting();
	step();
	dda();
	pos()->x++;
}

static void	init_raycasting(void)
{
	pos()->hit = 0;
	pos()->cam_x = (2 * pos()->x) / (double)(WIDTH)-1;
	pos()->ray_dir_x = pos()->dir_x + pos()->plane_x * pos()->cam_x;
	pos()->ray_dir_y = pos()->dir_y + pos()->plane_y * pos()->cam_x;
	pos()->map_x = (int)(pos()->pos_x);
	pos()->map_y = (int)(pos()->pos_y);
	pos()->delta_dist_x = fabs(1 / pos()->ray_dir_x);
	pos()->delta_dist_y = fabs(1 / pos()->ray_dir_y);
}

static void	step(void)
{
	if (pos()->ray_dir_x < 0)
	{
		pos()->step_x = -1;
		pos()->side_dist_x = (pos()->pos_x - pos()->map_x)
			* pos()->delta_dist_x;
	}
	else
	{
		pos()->step_x = 1;
		pos()->side_dist_x = (pos()->pos_x + 1.0 - pos()->map_x)
			* pos()->delta_dist_x;
	}
	if (pos()->step_y < 0)
	{
		pos()->step_y = -1;
		pos()->side_dist_y = (pos()->pos_y - pos()->map_y)
			* pos()->delta_dist_y;
	}
	else
	{
		pos()->step_y = 1;
		pos()->side_dist_y = (pos()->pos_y + 1.0 - pos()->map_y)
			* pos()->delta_dist_y;
	}
}

static void	dda(void)
{
	while (!pos()->hit)
	{
		if (pos()->side_dist_x < pos()->side_dist_y)
		{
			pos()->side_dist_x += pos()->delta_dist_x;
			pos()->map_x += pos()->step_x;
			if (pos()->step_x == -1)
				pos()->side = 4;
			else
				pos()->side = 3;
		}
		else
		{
			pos()->side_dist_y += pos()->delta_dist_y;
			pos()->map_y += pos()->step_y;
			if (pos()->step_y == -1)
				pos()->side = 2;
			else
				pos()->side = 1;
		}
		if (map()->map[pos()->map_x][pos()->map_y] == '1')
			pos()->hit = 1;
	}
}

static void	calculate_height(void)
{
	if (pos()->side == WEST || pos()->side == EAST)
		pos()->wall_x = ((double)pos()->map_x - pos()->pos_x + (1
				- pos()->step_x) / 2) / pos()->ray_dir_x;
	else
		pos()->wall_x = ((double)pos()->map_y - pos()->pos_y + (1
				- pos()->step_y) / 2) / pos()->ray_dir_y;
	pos()->line_height = HEIGHT / pos()->wall_x;
	pos()->draw_start = -pos()->line_height / 2 + ((HEIGHT / 2) * pos()->cam_y);
	if (pos()->draw_start <= 0)
		pos()->draw_start = 0;
	pos()->draw_end = pos()->line_height / 2 + ((HEIGHT / 2) * pos()->cam_y);
	if (pos()->draw_end >= HEIGHT)
		pos()->draw_end = HEIGHT - 1;
	line()->x = pos()->x;
}
