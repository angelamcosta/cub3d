/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:45:48 by anlima            #+#    #+#             */
/*   Updated: 2023/12/22 15:58:25 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void		raycaster(void);
static void	dda(void);
static void	step(void);
static void	init_raycasting(void);

// draw those textures
void	raycaster(void)
{
	init_raycasting();
	step();
	dda();
	pos()->x++;
}

void	init_raycasting(void)
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

void	step(void)
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

void	dda(void)
{
	while (!pos()->hit)
	{
		if (pos()->side_dist_x < pos()->side_dist_y)
		{
			pos()->side_dist_x += pos()->delta_dist_x;
			pos()->map_x += pos()->step_x;
			pos()->side = 0;
		}
		else
		{
			pos()->side_dist_y += pos()->delta_dist_y;
			pos()->map_y += pos()->step_y;
			pos()->side = 1;
		}
	}
}
