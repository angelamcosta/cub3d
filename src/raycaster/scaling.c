/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpedroso <mpedroso@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 18:57:58 by anlima            #+#    #+#             */
/*   Updated: 2024/01/14 23:12:33 by mpedroso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	dda(void);
void	step(void);
void	prep_draw_line(void);
void	camera_distance(void);
t_img	*select_texture(void);

void	camera_distance(void)
{
	if (pos()->side == 0)
		pos()->prep_wall_dist = (pos()->side_dist.x - pos()->delta_dist.x);
	else
		pos()->prep_wall_dist = (pos()->side_dist.y - pos()->delta_dist.y);
	// printf("DEBUG: C_DIST\n");
	// printf("DEBUG: side dist x: %f\tdelta x: %f\n", pos()->side_dist.x, pos()->delta_dist.x);
	// printf("DEBUG: side dist y: %f\tdelta y: %f\n\n", pos()->side_dist.y, pos()->delta_dist.y);
	// exit(1);
}

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
	// printf("DEBUG: DDA\n");
	// printf("DEBUG: side dist x: %f\tdelta x: %f\n", pos()->side_dist.x, pos()->delta_dist.x);
	// printf("DEBUG: side dist y: %f\tdelta y: %f\n\n", pos()->side_dist.y, pos()->delta_dist.y);
	// exit(1);
}

void	step(void)
{
	if (pos()->ray_dir.x < 0)
	{
		pos()->step_x = -1;
		pos()->side_dist.x = (pos()->pos.x - pos()->map_x) * pos()->delta_dist.x;
	}
	else
	{
		pos()->step_x = 1;
		pos()->side_dist.x = (pos()->map_x + 1.0 - pos()->pos.x) * pos()->delta_dist.x;
	}
	if (pos()->ray_dir.y < 0)
	{
		pos()->step_y = -1;
		pos()->side_dist.y = (pos()->pos.y - pos()->map_y) * pos()->delta_dist.y;
	}
	else
	{
		pos()->step_y = 1;
		pos()->side_dist.y = (pos()->map_y + 1.0 - pos()->pos.y) * pos()->delta_dist.y;
	}
}

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
