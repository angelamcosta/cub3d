/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 12:45:48 by anlima            #+#    #+#             */
/*   Updated: 2024/01/09 21:23:37 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void	raycaster(t_pos *pos);
static void	dda(t_pos *pos);
static void	step(t_pos *pos, t_player *player);
static void	init_raycasting(t_pos *pos, t_player *player);
static void	calculate_height(t_pos *pos, t_player *player);

void	raycaster(t_pos *pos)
{
	t_player	*player;

	player = win()->player;
	init_raycasting(pos, player);
	step(pos, player);
	dda(pos);
	calculate_height(pos, player);
	img_scaling(pos, player);
	pos->curr_x++;
}

static void	init_raycasting(t_pos *pos, t_player *player)
{
	pos->cam_x = (2 * pos->curr_x) / (double) WIDTH - 1;
	pos->ray_dir_x = player->dir_vect.x + player->cam_plane_vect.x * pos->cam_x;
	pos->ray_dir_y = player->dir_vect.y + player->cam_plane_vect.y * pos->cam_x;
	pos->map_x = (int) player->pos.x;
	pos->map_y = (int) player->pos.y;
	pos->delta_dist_x = fabs(1 / pos->ray_dir_x);
	pos->delta_dist_y = fabs(1 / pos->ray_dir_y);
	pos->hit = 0;
}

static void	step(t_pos *pos, t_player *player)
{
	if (pos->ray_dir_x < 0)
	{
		pos->step_x = -1;
		pos->side_dist_x = (player->pos.x - pos->map_x) * pos->delta_dist_x;
	}
	else
	{
		pos->step_x = 1;
		pos->side_dist_x = (pos->map_x + 1.0 - player->pos.x)
			* pos->delta_dist_x;
	}
	if (pos->ray_dir_y < 0)
	{
		pos->step_y = -1;
		pos->side_dist_y = (player->pos.y - pos->map_y) * pos->delta_dist_y;
	}
	else
	{
		pos->step_y = 1;
		pos->side_dist_y = (pos->map_y + 1.0 - player->pos.y)
			* pos->delta_dist_y;
	}
}

static void	dda(t_pos *pos)
{
	while (!pos->hit)
	{
		if (pos->side_dist_x < pos->side_dist_y)
		{
			pos->side_dist_x += pos->delta_dist_x;
			pos->map_x += pos->step_x;
			if (pos->step_x == -1)
				pos->side = EAST;
			else
				pos->side = WEST;
		}
		else
		{
			pos->side_dist_y += pos->delta_dist_y;
			pos->map_y += pos->step_y;
			if (pos->step_y == -1)
				pos->side = SOUTH;
			else
				pos->side = NORTH;
		}
		if (map()->map[pos->map_y][pos->map_x] == '1')
			pos->hit = 1;
	}
}

static void	calculate_height(t_pos *pos, t_player *player)
{
	if (pos->side == WEST || pos->side == EAST)
		pos->prep_wall_dist = ((double) pos->map_x - player->pos.x
				+ (1 - pos->step_x) / 2) / pos->ray_dir_x;
	else
		pos->prep_wall_dist = ((double) pos->map_y - player->pos.y
				+ (1 - pos->step_y) / 2) / pos->ray_dir_y;
	pos->line_height = HEIGHT / pos->prep_wall_dist;
	pos->draw_start = -(pos->line_height / 2) + ((HEIGHT / 2) * player->cam_height);
	if (pos->draw_start <= 0)
		pos->draw_start = 0;
	pos->draw_end = pos->line_height / 2 + ((HEIGHT / 2) * player->cam_height);
	if (pos->draw_end >= HEIGHT)
		pos->draw_end = HEIGHT - 1;
}

	// printf("DEBUG: prep_wall_dist => %f\n", pos->prep_wall_dist);
	// printf("DEBUG: map_x => %d, map_y => %d\n", pos->map_x, pos->map_y);
    // printf("DEBUG: player_pos_x => %f, player_pos_y => %f\n", player->pos.x, player->pos.y);
    // printf("DEBUG: step_x => %d, step_y => %d\n", pos->step_x, pos->step_y);
    // printf("DEBUG: ray_dir_x => %f, ray_dir_y => %f\n", pos->ray_dir_x, pos->ray_dir_y);
	// printf("DEBUG: draw_start => %d\n", pos->draw_start);