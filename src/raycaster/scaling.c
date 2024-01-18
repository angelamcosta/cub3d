/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:57:58 by anlima            #+#    #+#             */
/*   Updated: 2024/01/18 18:36:49 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	dda(void);
void	step(void);
void	prep_draw_line(void);
void	camera_distance(void);
t_img	*select_texture(void);

// calculates the distance from the player
// to the wall
void	camera_distance(void)
{
	if (pos()->side == 0)
		pos()->prep_wall_dist = (pos()->side_dist.x - pos()->delta_dist.x);
	else
		pos()->prep_wall_dist = (pos()->side_dist.y - pos()->delta_dist.y);
}

// Digital Differential Analyzer algorithm for ray casting
// steps through the map grid until it hits a wall
void	dda(void)
{
	pos()->hit = 0;
	while (pos()->hit == 0)
	{
		if (pos()->side_dist.x < pos()->side_dist.y)
		{
			pos()->side_dist.x += pos()->delta_dist.x;
			pos()->map_x += pos()->step_x;
			pos()->side = 0;
		}
		else
		{
			pos()->side_dist.y += pos()->delta_dist.y;
			pos()->map_y += pos()->step_y;
			pos()->side = 1;
		}
		if (map()->map[pos()->map_y][pos()->map_x] == '1')
			pos()->hit = 1;
	}
}

// calculates the step and initial side
// distances for ray casting
void	step(void)
{
	if (pos()->ray_dir.x < 0)
	{
		pos()->step_x = -1;
		pos()->side_dist.x = (pos()->pos.x - pos()->map_x)
		* pos()->delta_dist.x;
	}
	else
	{
		pos()->step_x = 1;
		pos()->side_dist.x = (pos()->map_x + 1.0 - pos()->pos.x)
		* pos()->delta_dist.x;
	}
	if (pos()->ray_dir.y < 0)
	{
		pos()->step_y = -1;
		pos()->side_dist.y = (pos()->pos.y - pos()->map_y)
		* pos()->delta_dist.y;
	}
	else
	{
		pos()->step_y = 1;
		pos()->side_dist.y = (pos()->map_y + 1.0 - pos()->pos.y)
		* pos()->delta_dist.y;
	}
}

// prepares variables for drawing a vertical line representing a wall
void	prep_draw_line(void)
{
	pos()->line_height = (int)(HEIGHT / pos()->prep_wall_dist);
	pos()->draw_start = -(pos()->line_height) / 2 + HEIGHT / 2;
	if (pos()->draw_start < 0)
		pos()->draw_start = 0;
	pos()->draw_end = pos()->line_height / 2 + HEIGHT / 2;
	if (pos()->draw_end >= HEIGHT)
		pos()->draw_end = HEIGHT - 1;
	if (pos()->side == 0)
		pos()->wall_x = pos()->pos.y + pos()->prep_wall_dist * pos()->ray_dir.y;
	else
		pos()->wall_x = pos()->pos.x + pos()->prep_wall_dist * pos()->ray_dir.x;
	pos()->wall_x -= floor((pos()->wall_x));
}

// selects the texture based on the side and direction
// of the wall hit by the ray.
t_img	*select_texture(void)
{
	if (pos()->side == 1 && pos()->ray_dir.y > 0)
		return (win()->south);
	if (pos()->side == 1 && pos()->ray_dir.y <= 0)
		return (win()->north);
	if (pos()->side == 0 && pos()->ray_dir.x >= 0)
		return (win()->east);
	if (pos()->side == 0 && pos()->ray_dir.x < 0)
		return (win()->west);
	return (NULL);
}
