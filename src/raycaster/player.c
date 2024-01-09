/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 20:47:08 by anlima            #+#    #+#             */
/*   Updated: 2024/01/09 20:54:18 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

void    add_player(void);
void	set_camera(double d_y, double p_x, double p_y);

void add_player(void)
{
    if (map()->pos[0] == 'N')
	{
		win()->player->dir_vect.x = 0.00;
		set_camera(-1.00, 0.66, 0.00);
	}
	else if (map()->pos[0] == 'S')
	{
		win()->player->dir_vect.x = 0.00;
		set_camera(1.00, -0.66, 0.00);
	}
	else if (map()->pos[0] == 'E')
	{
		win()->player->dir_vect.x = 1.00;
		set_camera(0.00, 0.00, 0.66);
	}
	else if (map()->pos[0] == 'W')
	{
		win()->player->dir_vect.x = -1;
		set_camera(0.00, 0.00, -0.66);
	}
	win()->player->pos.x = (double) map()->pos[2] + 0.5;
	win()->player->pos.y = (double) map()->pos[1] + 0.5;
}

void	set_camera(double d_y, double p_x, double p_y)
{
	win()->player->dir_vect.y = d_y;
	win()->player->cam_plane_vect.x = p_x;
	win()->player->cam_plane_vect.y = p_y;
}
